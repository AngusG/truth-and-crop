import cv2  # Tested with opencv version 3.0.0.
import os.path
import numpy as np
import argparse
from natsort import natsorted
from colorama import Fore, Back, Style
from skimage import exposure
from skimage.segmentation import slic
from skimage.segmentation import mark_boundaries

import sys
from PyQt4 import QtCore, QtGui, uic
from PyQt4.QtGui import *
from VOClabelcolormap import color_map

qtCreatorFile = "truth_and_crop_qt4.ui"

# Control flags
#DEBUG = False

# Constants
APP_NAME = 'Truth and Crop'
IMAGES_OUT_DIR = 'images/'
INT_MASKS_OUT_DIR = 'masks/'
RGB_MASKS_OUT_DIR = 'PASCALVOCmasks/'
FULL_MASKS_OUT_DIR = 'full-masks/'
VALID_EXT = '.JPG'  # File extension to consider valid when searching for prv/next image
IMAGE_EXT = '.jpg'  # Output file extension
MASK_EXT = '_mask.jpg'
PX_INTENSITY = 0.4
N_CHANNELS = 2

# Constants - class labels
NCLASSES = 5
CLASS_OTHER = 0
CLASS_MUSSEL = 1
CLASS_CIONA = 2
CLASS_STYELA = 3
CLASS_VOID = 4

T_INDEX_SEGMENT = 0
T_INDEX_LABEL = 1

OP_ADD = 0
OP_REMOVE = 1

Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)


class TruthAndCropApp(QtGui.QMainWindow, Ui_MainWindow):

    def __init__(self, debug=None):
        QtGui.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)
        self.setWindowIcon(QtGui.QIcon('images/icon.png'))

        # Init
        if debug:
            self.debug = True
        else:
            self.debug = False

        self.class_label = CLASS_OTHER

        # Init progressBar
        self.progressBar.setMinimum = 0
        self.progressBar.setMaximum = 100
        self.progressBarFloatValue = 0.0
        self.progressBar.setValue(0)

        #self.currentImageIndex = 0  # setting this automatically now
        self.cropping = False
        self.textEditMode.setText("Label")
        self.labeled_superpixel_list = []
        self.__init_lcds()
        self.w = self.wndBox.value()
        self.ds = self.dsBox.value()
        self.nseg = self.segmentsBox.value()
        self.sigma = self.sigmaBox.value()
        self.compactness = self.compactnessBox.value()

        self.cmap = color_map()

        self.enforceConnectivityBox.setChecked(True)
        self.enforce = self.enforceConnectivityBox.isChecked()

        self.groupBox.setStyleSheet(
            "QGroupBox { background-color: rgb(255, 255, 255); border:1px solid rgb(255, 170, 255); }")

        self.img_view.mousePressEvent = self.__handle_click

        # Connect handlers to signals from QPushButton(s)
        self.doneBtn.clicked.connect(self.__handle_done_btn)
        self.cropBtn.clicked.connect(self.__handle_crop_btn)
        self.refreshBtn.clicked.connect(self.load_new_image)
        self.toggleBtn.clicked.connect(self.__handle_toggle_btn)
        self.inFile.clicked.connect(self.get_input_file)
        self.outFile.clicked.connect(self.get_output_folder)
        self.nextBtn.clicked.connect(self.__handle_next_btn)
        self.previousBtn.clicked.connect(self.__handle_previous_btn)

        # Connect handlers to QSpinBox(es)
        self.wndBox.valueChanged.connect(self.__handle_wnd_box)
        self.dsBox.valueChanged.connect(self.__handle_ds_box)
        self.segmentsBox.valueChanged.connect(self.__handle_nseg_box)
        self.sigmaBox.valueChanged.connect(self.__handle_sigma_box)
        self.compactnessBox.valueChanged.connect(self.__handle_compactness_box)

        # Connect handler to QCheckBox
        self.enforceConnectivityBox.stateChanged.connect(
            self.__handle_enforce_cbox)

        # Connect handlers to QRadioButton(s)
        self.class_other.toggled.connect(
            lambda: self.btn_state(self.class_other))
        self.class_mussel.toggled.connect(
            lambda: self.btn_state(self.class_mussel))
        self.class_ciona.toggled.connect(
            lambda: self.btn_state(self.class_ciona))
        self.class_styela.toggled.connect(
            lambda: self.btn_state(self.class_styela))
        self.class_void.toggled.connect(
            lambda: self.btn_state(self.class_void))

    def __init_lcds(self):

        self.class_qty = np.zeros(NCLASSES)
        self.lcd_values = np.zeros(NCLASSES)

    def __reset_state(self):
        self.showSuperPx = False
        self.superPxGenerated = False
        self.drawing_list = []
        self.crop_list = []
        self.labeled_superpixel_list = []
        self.progressBarFloatValue = 0.0
        self.progressBar.reset()
        self.cropping = False
        self.textEditMode.setText("Label")

    def __handle_wnd_box(self, event):
        self.w = self.wndBox.value()

    def __handle_ds_box(self, event):
        self.ds = self.dsBox.value()

    def __handle_nseg_box(self, event):
        self.nseg = self.segmentsBox.value()
        self.__reset_state()

    def __handle_sigma_box(self, event):
        self.sigma = self.sigmaBox.value()

    def __handle_compactness_box(self, event):
        self.compactness = self.compactnessBox.value()

    def __handle_enforce_cbox(self, event):
        self.enforce = self.enforceConnectivityBox.isChecked()

    def __handle_next_btn(self, event):
        
        if self.currentImageIndex + 1 < len(self.imgList):
            self.currentImageIndex = self.currentImageIndex + 1
            self.currentImage = self.imgList[self.currentImageIndex]
            self.load_new_image()
        else:
            print(Fore.RED + 'No more images in directory! Currently at image %d of %d' % (
                    self.currentImageIndex + 1, len(self.imgList)))
            print(Style.RESET_ALL)

    def __handle_previous_btn(self, event):

        if self.currentImageIndex > 0:
            self.currentImageIndex = self.currentImageIndex - 1
            self.currentImage = self.imgList[self.currentImageIndex]
            self.load_new_image()
        else:
            print(Fore.RED + 'No previous image! Currently at image %d of %d' % (
                    self.currentImageIndex + 1, len(self.imgList)))
            print(Style.RESET_ALL)


    def __handle_crop_btn(self, event):
        self.cropping = not self.cropping
        if self.cropping == True:
            self.textEditMode.setText("Cropping")
        else:
            self.textEditMode.setText("Label")

    def __create_dir_if_not_exists(self, dir):
        if not os.path.exists(dir):
            os.makedirs(dir)

    # Save the output
    def __handle_done_btn(self, event):

        image_path = os.path.join(self.outputFolder, IMAGES_OUT_DIR)
        int_mask_path = os.path.join(self.outputFolder, INT_MASKS_OUT_DIR)
        rgb_mask_path = os.path.join(self.outputFolder, RGB_MASKS_OUT_DIR)
        full_mask_path = os.path.join(self.outputFolder, FULL_MASKS_OUT_DIR)

        self.__create_dir_if_not_exists(image_path)
        self.__create_dir_if_not_exists(int_mask_path)
        self.__create_dir_if_not_exists(rgb_mask_path)
        self.__create_dir_if_not_exists(full_mask_path)

        # Convert back to BGR so that OpenCV can write out properly
        if self.has_original_been_created == True:        
            output_image = cv2.cvtColor(self.original, cv2.COLOR_RGB2BGR).copy()
        else:
            output_image = cv2.cvtColor(self.cv_img, cv2.COLOR_RGB2BGR).copy()

        # Separate currentImage into dir and filename, can discard dir
        __, img_name = os.path.split(self.currentImage)

        for px, py, p_class in self.drawing_list:

            # Find superpixel that coord belongs to.
            super_px = self.segments[py, px]

            # Set all pixels in super_px to p_class.
            self.segmentation_mask[self.segments == super_px] = p_class

        # Make PASCAL fmt segmentation_mask as well

        height, width, __ = output_image.shape

        # Initialize empty RGB array
        # array = np.empty((height, width, self.cmap.shape[
        #                 1]), dtype=self.cmap.dtype)
        array = np.zeros((height, width, self.cmap.shape[
                         1]), dtype=self.cmap.dtype)

        array = cv2.cvtColor(array, cv2.COLOR_RGB2BGR)

        # Convert integers in segmentation_mask to rgb vals
        for i in range(NCLASSES - 1):
            array[self.segmentation_mask == i] = self.cmap[i]

        # If there were any void labels, map those separately
        if self.class_qty[CLASS_VOID] > 0:
            array[self.segmentation_mask == CLASS_VOID] = self.cmap[255]

        # Save the original mask before cropping
        cv2.imwrite(os.path.join(full_mask_path,
                                 img_name[:-4] + '_mask' + IMAGE_EXT), array)

        crop_list_len = len(self.crop_list)
        for i, (x, y) in enumerate(self.crop_list):

            # Detailed cropped image suffix.
            details = self.__generate_image_details(
                img_name, i + self.count, x, y)

            y_lwr = y - self.w > 0
            y_upr = y + self.w < height
            x_lwr = x - self.w > 0
            x_upr = x + self.w < width
            if y_lwr and y_upr and x_lwr and x_upr:

                cropped_image = output_image[
                    y - self.w:y + self.w, x - self.w:x + self.w, :]
                cropped_int_mask = self.segmentation_mask[
                    y - self.w:y + self.w, x - self.w:x + self.w]
                cropped_rgb_mask = array[
                    y - self.w:y + self.w, x - self.w:x + self.w]

                cv2.imwrite(os.path.join(
                    image_path, details + IMAGE_EXT), cropped_image)
                cv2.imwrite(os.path.join(
                    int_mask_path, details + IMAGE_EXT), cropped_int_mask)
                cv2.imwrite(os.path.join(
                    rgb_mask_path, details + IMAGE_EXT), cropped_rgb_mask)

                print('Success: cropped image at x=%d,y=%d with wnd=%d' %
                      (x, y, self.w))

            else:
                print(Fore.RED + 'Error: exceeded image dimensions, could not crop at x=%d,y=%d with wnd=%d' % (
                    x, y, self.w))
                print(Style.RESET_ALL)

        #for i in range(crop_list_len):
        #    crop_list.pop()
        if self.debug == True:
            print(self.crop_list)
            print(self.drawing_list)

        self.count += crop_list_len
        self.__reset_state()

    # Save the output
    def __handle_toggle_btn(self, event):

        if self.debug == True:
            print('Toggle')

        height, width, __ = self.cv_img.shape

        if self.has_original_been_created == False:
            if self.debug == True:
                print('Creating copy of image')
            '''this is an expensive operation, 
            so we do it here only once we begin labeling'''
            self.original = self.cv_img.copy()
            self.has_original_been_created = True

        self.showSuperPx = not self.showSuperPx

        # Show the in-progress image
        if self.showSuperPx == True:
            if self.superPxGenerated == False:
                self.run_slic() # Only compute superpixels once per image
                self.superPxGenerated = True
            self.update_canvas(self.cv_img, height, width)
        # Show the original
        else:
            self.update_canvas(self.original, height, width)


    def __handle_click(self, event):

        x = event.pos().x()
        y = event.pos().y()

        if self.debug == True:
            print('Pixel position = (' + str(x) +
                  ' , ' + str(y) + ')')

        if self.cropping == False:
            self.drawing_list.append((x, y, self.class_label))
            self.color_superpixel_by_class(x, y)

        else:
            if self.debug == True:
                print('Cropping')
            cv2.rectangle(self.cv_img, (x - self.w, y - self.w),
                          (x + self.w, y + self.w), (0, 255, 0), 3)
            self.crop_list.append((x, y))

        # Update the canvas if ground-truthing or cropping
        height, width, __ = self.cv_img.shape
        self.update_canvas(self.cv_img, height, width)

    def __update_label_balance(self, operation_type, label):

        if operation_type == OP_ADD:
            self.class_qty[label] += 1
        elif operation_type == OP_REMOVE:
            self.class_qty[label] -= 1
        else:
            pass

    def __refresh_lcds(self):

        n_labeled = np.sum(self.class_qty)

        if n_labeled > 0:
            for i in range(len(self.lcd_values)):
                self.lcd_values[i] = int(
                    100 * float(self.class_qty[i]) / n_labeled)
        else:
            self.lcd_values[:] = 0

        self.lcdNumber_0.display(self.lcd_values[0])
        self.lcdNumber_1.display(self.lcd_values[1])
        self.lcdNumber_2.display(self.lcd_values[2])
        self.lcdNumber_3.display(self.lcd_values[3])
        self.lcdNumber_4.display(self.lcd_values[4])

    def read_filelist(self):
        img_path, img_name = os.path.split(self.currentImage)
        imgList = [os.path.join(dirpath, f)
                   for dirpath, dirnames, files in os.walk(img_path)
                   for f in files if f.endswith(VALID_EXT)]
        self.imgList = natsorted(imgList)

        print(img_path)
        print(img_name)
        print(imgList[0])
        print(self.currentImage)

        self.currentImageIndex = self.imgList.index(self.currentImage)
        print("No of files: %i" % len(self.imgList))

    def load_new_image(self):
        self.imageField.setText(self.currentImage)
        self.load_opencv_to_canvas()
        self.__init_lcds()
        self.__refresh_lcds()
        self.__reset_state()
        self.count = 0

    def __generate_image_details(self, img_name, count, x, y):

        details = img_name[:-4] \
            + '_nseg' + str(self.nseg) \
            + '_sig' + str(self.sigma) \
            + '_ds' + str(self.ds) \
            + '_' + str(count) \
            + "_x" + str(x) \
            + "_y" + str(y)

        return details

    def color_superpixel_by_class(self, x, y):
        """Color superpixel according to class_label

        Keyword arguments:
        x,y -- pixel coordinates from MouseCallback
        class_label -- determines channel (B,G,R) whose intensity to set
        """
        # Are we trying to assign a new label to this superpixel?
        if (self.segments[y, x], self.class_label) not in self.labeled_superpixel_list:

            # If yes, remove previous superpixel-label entry
            for t in self.labeled_superpixel_list:
                if t[T_INDEX_SEGMENT] == self.segments[y, x]:
                    self.labeled_superpixel_list.remove(t)
                    self.__update_label_balance(OP_REMOVE, t[T_INDEX_LABEL])

            '''
            self.cv_img[:, :, N_CHANNELS - self.class_label][self.segments ==
                                                             self.segments[y, x]] = PX_INTENSITY * 255
            '''
            self.cv_img[self.segments == self.segments[
                y, x]] = self.cmap[self.class_label]

            # Add superpixel to list
            self.labeled_superpixel_list.append(
                (self.segments[y, x], self.class_label))

            # Update progress bar
            # The percentage is calculated by dividing the progress (value() -
            # minimum()) divided by maximum() - minimum().
            self.progressBarFloatValue += float(
                self.progressBar.maximum() / self.nseg)
            self.progressBar.setValue(self.progressBarFloatValue)

            self.__update_label_balance(OP_ADD, self.class_label)
            self.__refresh_lcds()

            if self.debug == True:
                print(self.labeled_superpixel_list)

    def btn_state(self, b):

        if b.text() == "Other":
            self.class_label = CLASS_OTHER

        if b.text() == "Mussel":
            self.class_label = CLASS_MUSSEL

        if b.text() == "Ciona":
            self.class_label = CLASS_CIONA

        if b.text() == "Styela":
            self.class_label = CLASS_STYELA

        if b.text() == "Void":
            self.class_label = CLASS_VOID

        if self.debug == True:
            if b.isChecked() == True:
                print(b.text() + " is selected")
            else:
                print(b.text() + " is deselected")

    def update_canvas(self, img, height, width):
        if self.debug == True:
            print("update_canvas: height=%d,width=%d" % (height, width))
        bytesPerLine = 3 * width
        qImg = QImage(img, width, height,
                      bytesPerLine, QImage.Format_RGB888)
        pixmap = QPixmap(qImg)
        self.img_view.setPixmap(pixmap)
        self.img_view.show()

    def get_input_file(self):
        self.currentImage = QFileDialog.getOpenFileName(self, 'Open file',
                                                        'c:\\', "Image files (*.jpg *.png)")
        self.load_new_image()
        self.read_filelist()

    def get_output_folder(self):
        self.outputFolder = str(QFileDialog.getExistingDirectory(
            self, "Select root output directory"))
        self.outputPath.setText(self.outputFolder)
        # print(self.outputFolder)

    def load_opencv_to_canvas(self):
        
        if self.debug == True:
            print("self.ds = %d" % self.ds)
        self.cv_img = cv2.imread(self.currentImage)[::self.ds, ::self.ds, :]
        self.cv_img = cv2.cvtColor(
            self.cv_img, cv2.COLOR_BGR2RGB).astype(np.uint8)
        height, width, __ = self.cv_img.shape
        self.has_original_been_created = False
        self.segmentation_mask = np.zeros((height, width))
        self.update_canvas(self.cv_img, height, width)

    def run_slic(self):

        #self.original = self.cv_img.copy()
        #self.segmentation_mask = np.zeros(self.cv_img[:, :, 0].shape)

        self.segments = slic(self.cv_img, n_segments=self.nseg, sigma=self.sigma,
                             enforce_connectivity=self.enforce, compactness=self.compactness)
        self.cv_img = 255. * \
            mark_boundaries(self.cv_img, self.segments, color=(0, 0, 0))
        self.cv_img = self.cv_img.astype(np.uint8)

if __name__ == "__main__":

    parser = argparse.ArgumentParser()
    parser.add_argument('--debug', help="run in debug mode",
                        action="store_true")
    args = parser.parse_args()

    app = QtGui.QApplication(sys.argv)
    window = TruthAndCropApp(args.debug)
    window.show()
    sys.exit(app.exec_())

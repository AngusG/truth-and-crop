import cv2  # Tested with opencv version 3.0.0.
import os.path
import numpy as np
import argparse
from natsort import natsorted
import matplotlib.pyplot as plt
from colorama import Fore, Back, Style
from skimage.segmentation import slic
from skimage.segmentation import mark_boundaries

import sys
from PyQt4 import QtCore, QtGui, uic
from PyQt4.QtGui import *

qtCreatorFile = "truth_and_crop_qt4.ui"

# Constants
APP_NAME = 'Truth and Crop'
IMAGES_OUT_DIR = 'images/'
MASKS_OUT_DIR = 'masks/'
VALID_EXT = '.JPG'  # File extension to consider valid when searching for prv/next image
IMAGE_EXT = '.jpg'  # Output file extension
MASK_EXT = '_mask.jpg'
PX_INTENSITY = 0.4
N_CHANNELS = 2

# Constants - class labels
CLASS_OTHER = 0
CLASS_MUSSEL = 1
CLASS_CIONA = 2
CLASS_S_CLAVA = 3

# Globals
crop_list = []
# class_label = 0
drawing_list = []

Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)


class MyApp(QtGui.QMainWindow, Ui_MainWindow):

    def __init__(self):
        QtGui.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)

        # Init
        self.class_label = CLASS_OTHER
        self.progressBar.setValue(0)
        self.currentImageIndex = 0 # Override later
        self.cropping = False
        self.toggleSuperPx = False
        self.w = self.wndBox.value()

        self.groupBox.setStyleSheet(
            "QGroupBox { background-color: rgb(255, 255, 255); border:1px solid rgb(255, 170, 255); }")

        self.enforceConnectivityBox.setChecked(True)
        self.img_view.mousePressEvent = self.handleClick

        # Connect handlers to signals from QPushButton(s)
        self.doneBtn.clicked.connect(self.handleDoneBtn)
        self.cropBtn.clicked.connect(self.handleCropBtn)
        self.refreshBtn.clicked.connect(self.formatImage)
        self.toggleBtn.clicked.connect(self.handleToggleBtn)
        self.inFile.clicked.connect(self.getInputFile)
        self.outFile.clicked.connect(self.getOutputFolder)
        self.wndBox.valueChanged.connect(self.handleWndBox)
        self.nextBtn.clicked.connect(self.handleNextBtn)
        self.previousBtn.clicked.connect(self.handlePreviousBtn)

        # Connect handlers to QRadioButton(s)
        self.class_other.toggled.connect(
            lambda: self.btnstate(self.class_other))
        self.class_mussel.toggled.connect(
            lambda: self.btnstate(self.class_mussel))
        self.class_ciona.toggled.connect(
            lambda: self.btnstate(self.class_ciona))
        self.class_styela.toggled.connect(
            lambda: self.btnstate(self.class_styela))

    def handleNextBtn(self, event):
        self.currentImageIndex = self.currentImageIndex + 1
        self.currentImage = self.imgList[self.currentImageIndex]
        self.loadNewImage()

    def handlePreviousBtn(self, event):
        self.currentImageIndex = self.currentImageIndex - 1
        self.currentImage = self.imgList[self.currentImageIndex]
        self.loadNewImage()

    def loadNewImage(self):        
        self.imageField.setText(self.currentImage)
        self.formatImage()

    def read_filelist(self):
        img_path, img_name = os.path.split(self.currentImage)
        imgList = [os.path.join(dirpath, f)
                   for dirpath, dirnames, files in os.walk(img_path)
                   for f in files if f.endswith(VALID_EXT)]
        self.imgList = natsorted(imgList)
        print("No of files: %i" % len(self.imgList))

    def handleWndBox(self, event):
        self.w = self.wndBox.value()

    def handleCropBtn(self, event):
        self.cropping = not self.cropping

    # Save the output
    def handleDoneBtn(self, event):

        image_path = os.path.join(self.outputFolder, IMAGES_OUT_DIR)
        mask_path = os.path.join(self.outputFolder, MASKS_OUT_DIR)

        if not os.path.exists(image_path):
            os.makedirs(image_path)

        if not os.path.exists(mask_path):
            os.makedirs(mask_path)

        # Separate currentImage into dir and filename, can discard dir
        _, img_name = os.path.split(self.currentImage)

        ds = self.dsBox.value()
        n_seg = self.segmentsBox.value()
        sig = self.sigmaBox.value()

        for px, py, p_class in drawing_list:

            # Find superpixel that coord belongs to.
            super_px = self.segments[py, px]

            # Set all pixels in super_px to p_class.
            self.segmentation_mask[self.segments == super_px] = p_class

            for i, (x, y) in enumerate(crop_list):

                # Detailed cropped image suffix.
                details = img_name[:-4] \
                    + '_nseg' + str(n_seg) \
                    + '_sig' + str(sig) \
                    + '_ds' + str(ds) \
                    + '_' + str(i) \
                    + "_x" + str(x) \
                    + "_y" + str(y)

                height, width, _ = self.original.shape

                if y - self.w > 0 and y + self.w < height and x - self.w > 0 and x + self.w < width:

                    cropped_image = self.original[
                        y - self.w:y + self.w, x - self.w:x + self.w, :]
                    cropped_mask = self.segmentation_mask[
                        y - self.w:y + self.w, x - self.w:x + self.w]

                    cv2.imwrite(os.path.join(
                        image_path, details + IMAGE_EXT), cropped_image)
                    cv2.imwrite(os.path.join(
                        mask_path, details + IMAGE_EXT), cropped_mask)

                    print('Success: cropped image at x=%d,y=%d with wnd=%d' %
                          (x, y, w))

                else:
                    print(Fore.RED + 'Error: exceeded image dimensions, could not crop at x=%d,y=%d with wnd=%d' % (
                        x, y, w))
                    print(Style.RESET_ALL)

    # Save the output
    def handleToggleBtn(self, event):
        self.toggleSuperPx = not self.toggleSuperPx

        # Show the raw image
        if self.toggleSuperPx == True:
            height, width, _ = self.original.shape
            self.updateCanvas(self.original, height, width)
        # Show the image with superpixels
        else:
            height, width, _ = self.cv_img.shape
            self.updateCanvas(self.cv_img, height, width)

    def handleClick(self, event):

        x = event.pos().x()
        y = event.pos().y()

        print('Pixel position = (' + str(x) +
              ' , ' + str(y) + ')')

        if self.cropping == False:
            drawing_list.append((x, y, self.class_label))
            self.color_superpixel_by_class(x, y)
        else:
            print('Cropping')
            cv2.rectangle(self.cv_img, (x - self.w, y - self.w),
                          (x + self.w, y + self.w), (0, 255, 0), 3)
            crop_list.append((x, y))

        height, width, _ = self.cv_img.shape
        self.updateCanvas(self.cv_img, height, width)

    def color_superpixel_by_class(self, x, y):
        """Color superpixel according to class_label

        Keyword arguments:
        x,y -- pixel coordinates from MouseCallback
        class_label -- determines channel (B,G,R) whose intensity to set
        """
        # global segments
        self.cv_img[:, :, N_CHANNELS - self.class_label][self.segments ==
                                                         self.segments[y, x]] = PX_INTENSITY * 255
        self.progressBar.setValue(self.progressBar.value() + 1)

    def btnstate(self, b):

        if b.text() == "Other":
            self.class_label = CLASS_OTHER
            if b.isChecked() == True:
                print(b.text() + " is selected")
            else:
                print(self.b.text() + " is deselected")

        if b.text() == "Blue Mussel":
            self.class_label = CLASS_MUSSEL
            if b.isChecked() == True:
                print(b.text() + " is selected")
            else:
                print(b.text() + " is deselected")

        if b.text() == "Ciona":
            self.class_label = CLASS_CIONA
            if b.isChecked() == True:
                print(b.text() + " is selected")
            else:
                print(b.text() + " is deselected")

        if b.text() == "S. Clava":
            self.class_label = CLASS_S_CLAVA
            if b.isChecked() == True:
                print(b.text() + " is selected")
            else:
                print(b.text() + " is deselected")

    def updateCanvas(self, img, height, width):
        bytesPerLine = 3 * width
        qImg = QImage(img, width, height,
                      bytesPerLine, QImage.Format_RGB888)
        pixmap = QPixmap(qImg)
        self.img_view.setPixmap(pixmap)
        self.img_view.show()

    def getInputFile(self):
        self.currentImage = QFileDialog.getOpenFileName(self, 'Open file',
                                                        'c:\\', "Image files (*.jpg *.png)")
        self.loadNewImage()
        self.read_filelist()        

    def getOutputFolder(self):
        self.outputFolder = str(QFileDialog.getExistingDirectory(
            self, "Select root output directory"))
        self.outputPath.setText(self.outputFolder)
        # print(self.outputFolder)

    def formatImage(self):
        ds = self.dsBox.value()
        n_seg = self.segmentsBox.value()
        sig = self.sigmaBox.value()
        compactness = self.compactnessBox.value()

        enforce = self.enforceConnectivityBox.isChecked()

        cv_img = cv2.imread(self.currentImage)[::ds, ::ds, :]
        cv_img = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB).astype(np.uint8)
        self.original = cv_img.copy()
        self.segmentation_mask = np.zeros(cv_img[:, :, 0].shape)
        self.segments = slic(cv_img, n_segments=n_seg, sigma=sig,
                             enforce_connectivity=enforce, compactness=compactness)
#        qImg = mark_boundaries(cv_img, segments, color=(0, 0, 0))
        cv_img = 255. * mark_boundaries(cv_img, self.segments, color=(0, 0, 0))
        self.cv_img = cv_img.astype(np.uint8)

        height, width, channel = cv_img.shape
        self.updateCanvas(self.cv_img, height, width)

        self.progressBar.setMinimum = 0
        self.progressBar.setMaximum = n_seg
        self.progressBar.setValue(0)

    '''
    def getDial(self):
        # price = int(self.price_box.toPlainText())
        # tax = (self.tax_rate.value())
        self.lcdNumber.display(self.dial.value())
    '''

if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_())
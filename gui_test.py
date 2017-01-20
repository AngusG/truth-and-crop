# Imports for frontend
from __future__ import division
from PyQt4 import QtCore, QtGui, uic
from PyQt4.QtGui import *

# Imports for backend
import sys
import cv2  # Tested with opencv version 3.0.0.
import os.path
import numpy as np
import argparse
import matplotlib.pyplot as plt
from colorama import Fore, Back, Style
from skimage.segmentation import slic
from skimage.segmentation import mark_boundaries

qtCreatorFile = "gui_test.ui" # Enter file here.

Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)

class MyApp(QtGui.QMainWindow, Ui_MainWindow):
    def __init__(self):
        QtGui.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)
        cv_img = cv2.imread("/home/angus/Documents/1uog/masc/data-acquisition/data/atlantic-aqua-farms-nov-7-2016/aaf-ciona-nov-7-2016/IMG_5351.JPG")[::4, ::4, :]
        cv_img = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB).astype(np.uint8)
        original = cv_img.copy()
        segmentation_mask = np.zeros(cv_img[:, :, 0].shape)
        segments = slic(cv_img, n_segments=200, sigma=3, \
         	enforce_connectivity=True, compactness=20)
#        qImg = mark_boundaries(cv_img, segments, color=(0, 0, 0))
        cv_img = 255. * mark_boundaries(cv_img, segments, color=(0, 0, 0))
        cv_img = cv_img.astype(np.uint8)
        height, width, channel = cv_img.shape
        bytesPerLine = 3 * width
        
        qImg = QImage(cv_img, width, height, bytesPerLine, QImage.Format_RGB888)
        pixmap = QPixmap(qImg)
        self.img_view.setPixmap(pixmap)
        self.img_view.show()

if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_())

/********************************************************************************
** Form generated from reading UI file 'gui_testi18017.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef GUI_TESTI18017_H
#define GUI_TESTI18017_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TruthAndCrop
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout;
    QLabel *img_view;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *dsBox;
    QSpinBox *sigmaBox;
    QSpinBox *segmentsBox;
    QSpinBox *wndBox;
    QSpinBox *compactnessBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *class_other;
    QRadioButton *class_mussel;
    QRadioButton *class_ciona;
    QRadioButton *class_styela;
    QVBoxLayout *verticalLayout_2;
    QPushButton *refreshBtn;
    QPushButton *cropBtn;
    QPushButton *toggleBtn;
    QPushButton *doneBtn;
    QCheckBox *enforceConnectivityBox;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QTextEdit *imageField;
    QLabel *label_4;
    QTextEdit *outputPath;
    QProgressBar *progressBar;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *inFile;
    QPushButton *outFile;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TruthAndCrop)
    {
        if (TruthAndCrop->objectName().isEmpty())
            TruthAndCrop->setObjectName(QStringLiteral("TruthAndCrop"));
        TruthAndCrop->resize(1209, 923);
        centralwidget = new QWidget(TruthAndCrop);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 881, 791));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 879, 789));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        img_view = new QLabel(scrollAreaWidgetContents_2);
        img_view->setObjectName(QStringLiteral("img_view"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(img_view->sizePolicy().hasHeightForWidth());
        img_view->setSizePolicy(sizePolicy);
        img_view->setScaledContents(true);
        img_view->setWordWrap(true);

        horizontalLayout->addWidget(img_view);

        scrollArea->setWidget(scrollAreaWidgetContents_2);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(910, 470, 298, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        dsBox = new QSpinBox(horizontalLayoutWidget);
        dsBox->setObjectName(QStringLiteral("dsBox"));
        dsBox->setValue(3);

        horizontalLayout_2->addWidget(dsBox);

        sigmaBox = new QSpinBox(horizontalLayoutWidget);
        sigmaBox->setObjectName(QStringLiteral("sigmaBox"));
        sigmaBox->setValue(3);

        horizontalLayout_2->addWidget(sigmaBox);

        segmentsBox = new QSpinBox(horizontalLayoutWidget);
        segmentsBox->setObjectName(QStringLiteral("segmentsBox"));
        segmentsBox->setMaximum(9999);
        segmentsBox->setValue(200);

        horizontalLayout_2->addWidget(segmentsBox);

        wndBox = new QSpinBox(horizontalLayoutWidget);
        wndBox->setObjectName(QStringLiteral("wndBox"));
        wndBox->setMinimum(2);
        wndBox->setMaximum(999);
        wndBox->setValue(112);

        horizontalLayout_2->addWidget(wndBox);

        compactnessBox = new QSpinBox(horizontalLayoutWidget);
        compactnessBox->setObjectName(QStringLiteral("compactnessBox"));
        compactnessBox->setValue(3);

        horizontalLayout_2->addWidget(compactnessBox);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(910, 410, 291, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        label_8 = new QLabel(horizontalLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(910, 560, 291, 191));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        class_other = new QRadioButton(horizontalLayoutWidget_3);
        class_other->setObjectName(QStringLiteral("class_other"));

        verticalLayout->addWidget(class_other);

        class_mussel = new QRadioButton(horizontalLayoutWidget_3);
        class_mussel->setObjectName(QStringLiteral("class_mussel"));

        verticalLayout->addWidget(class_mussel);

        class_ciona = new QRadioButton(horizontalLayoutWidget_3);
        class_ciona->setObjectName(QStringLiteral("class_ciona"));

        verticalLayout->addWidget(class_ciona);

        class_styela = new QRadioButton(horizontalLayoutWidget_3);
        class_styela->setObjectName(QStringLiteral("class_styela"));

        verticalLayout->addWidget(class_styela);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        refreshBtn = new QPushButton(horizontalLayoutWidget_3);
        refreshBtn->setObjectName(QStringLiteral("refreshBtn"));

        verticalLayout_2->addWidget(refreshBtn);

        cropBtn = new QPushButton(horizontalLayoutWidget_3);
        cropBtn->setObjectName(QStringLiteral("cropBtn"));

        verticalLayout_2->addWidget(cropBtn);

        toggleBtn = new QPushButton(horizontalLayoutWidget_3);
        toggleBtn->setObjectName(QStringLiteral("toggleBtn"));

        verticalLayout_2->addWidget(toggleBtn);

        doneBtn = new QPushButton(horizontalLayoutWidget_3);
        doneBtn->setObjectName(QStringLiteral("doneBtn"));

        verticalLayout_2->addWidget(doneBtn);

        enforceConnectivityBox = new QCheckBox(horizontalLayoutWidget_3);
        enforceConnectivityBox->setObjectName(QStringLiteral("enforceConnectivityBox"));

        verticalLayout_2->addWidget(enforceConnectivityBox);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(910, 130, 291, 141));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_3->addWidget(label_6);

        imageField = new QTextEdit(verticalLayoutWidget_3);
        imageField->setObjectName(QStringLiteral("imageField"));

        verticalLayout_3->addWidget(imageField);

        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        outputPath = new QTextEdit(verticalLayoutWidget_3);
        outputPath->setObjectName(QStringLiteral("outputPath"));

        verticalLayout_3->addWidget(outputPath);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(910, 760, 291, 23));
        progressBar->setValue(24);
        horizontalLayoutWidget_4 = new QWidget(centralwidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(910, 70, 291, 51));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        inFile = new QPushButton(horizontalLayoutWidget_4);
        inFile->setObjectName(QStringLiteral("inFile"));

        horizontalLayout_5->addWidget(inFile);

        outFile = new QPushButton(horizontalLayoutWidget_4);
        outFile->setObjectName(QStringLiteral("outFile"));

        horizontalLayout_5->addWidget(outFile);

        TruthAndCrop->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TruthAndCrop);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1209, 19));
        TruthAndCrop->setMenuBar(menubar);
        statusbar = new QStatusBar(TruthAndCrop);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TruthAndCrop->setStatusBar(statusbar);

        retranslateUi(TruthAndCrop);

        QMetaObject::connectSlotsByName(TruthAndCrop);
    } // setupUi

    void retranslateUi(QMainWindow *TruthAndCrop)
    {
        TruthAndCrop->setWindowTitle(QApplication::translate("TruthAndCrop", "MainWindow", 0));
        img_view->setText(QString());
        label_7->setText(QApplication::translate("TruthAndCrop", "ds", 0));
        label->setText(QApplication::translate("TruthAndCrop", "sigma", 0));
        label_2->setText(QApplication::translate("TruthAndCrop", "segments", 0));
        label_8->setText(QApplication::translate("TruthAndCrop", "wnd", 0));
        label_3->setText(QApplication::translate("TruthAndCrop", "compactness", 0));
        class_other->setText(QApplication::translate("TruthAndCrop", "Other", 0));
        class_mussel->setText(QApplication::translate("TruthAndCrop", "Blue Mussel", 0));
        class_ciona->setText(QApplication::translate("TruthAndCrop", "Ciona", 0));
        class_styela->setText(QApplication::translate("TruthAndCrop", "S. Clava", 0));
        refreshBtn->setText(QApplication::translate("TruthAndCrop", "Refresh", 0));
        cropBtn->setText(QApplication::translate("TruthAndCrop", "Crop", 0));
        toggleBtn->setText(QApplication::translate("TruthAndCrop", "Toggle", 0));
        doneBtn->setText(QApplication::translate("TruthAndCrop", "Done", 0));
        enforceConnectivityBox->setText(QApplication::translate("TruthAndCrop", "Enforce Connect.", 0));
        label_6->setText(QApplication::translate("TruthAndCrop", " Image", 0));
        imageField->setHtml(QApplication::translate("TruthAndCrop", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:11pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:11pt;\"><br /></p></body></html>", 0));
        label_4->setText(QApplication::translate("TruthAndCrop", " Output Path", 0));
        outputPath->setHtml(QApplication::translate("TruthAndCrop", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:11pt;\"><br /></p></body></html>", 0));
        inFile->setText(QApplication::translate("TruthAndCrop", "Input file", 0));
        outFile->setText(QApplication::translate("TruthAndCrop", "Output file", 0));
    } // retranslateUi

};

namespace Ui {
    class TruthAndCrop: public Ui_TruthAndCrop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // GUI_TESTI18017_H

/********************************************************************************
** Form generated from reading UI file 'truth_and_crop_qt4Sa2743.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef TRUTH_AND_CROP_QT4SA2743_H
#define TRUTH_AND_CROP_QT4SA2743_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
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
    QVBoxLayout *verticalLayout_4;
    QSpinBox *compactnessBox;
    QSpinBox *wndBox;
    QSpinBox *segmentsBox;
    QSpinBox *sigmaBox;
    QSpinBox *dsBox;
    QWidget *horizontalLayoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_7;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *class_other;
    QRadioButton *class_mussel;
    QRadioButton *class_ciona;
    QRadioButton *class_styela;
    QRadioButton *class_void;
    QVBoxLayout *verticalLayout_6;
    QLCDNumber *lcdNumber_0;
    QLCDNumber *lcdNumber_1;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;
    QLCDNumber *lcdNumber_4;
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
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *previousBtn;
    QPushButton *nextBtn;
    QLabel *label_5;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QTextEdit *textEdit;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TruthAndCrop)
    {
        if (TruthAndCrop->objectName().isEmpty())
            TruthAndCrop->setObjectName(QStringLiteral("TruthAndCrop"));
        TruthAndCrop->resize(1212, 923);
        centralwidget = new QWidget(TruthAndCrop);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 871, 801));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 869, 799));
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
        horizontalLayoutWidget->setGeometry(QRect(900, 360, 71, 141));
        verticalLayout_4 = new QVBoxLayout(horizontalLayoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        compactnessBox = new QSpinBox(horizontalLayoutWidget);
        compactnessBox->setObjectName(QStringLiteral("compactnessBox"));
        compactnessBox->setMinimum(1);
        compactnessBox->setMaximum(999);
        compactnessBox->setValue(20);

        verticalLayout_4->addWidget(compactnessBox);

        wndBox = new QSpinBox(horizontalLayoutWidget);
        wndBox->setObjectName(QStringLiteral("wndBox"));
        wndBox->setMinimum(2);
        wndBox->setMaximum(999);
        wndBox->setValue(112);

        verticalLayout_4->addWidget(wndBox);

        segmentsBox = new QSpinBox(horizontalLayoutWidget);
        segmentsBox->setObjectName(QStringLiteral("segmentsBox"));
        segmentsBox->setMaximum(9999);
        segmentsBox->setValue(200);

        verticalLayout_4->addWidget(segmentsBox);

        sigmaBox = new QSpinBox(horizontalLayoutWidget);
        sigmaBox->setObjectName(QStringLiteral("sigmaBox"));
        sigmaBox->setValue(3);

        verticalLayout_4->addWidget(sigmaBox);

        dsBox = new QSpinBox(horizontalLayoutWidget);
        dsBox->setObjectName(QStringLiteral("dsBox"));
        dsBox->setValue(3);

        verticalLayout_4->addWidget(dsBox);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(980, 360, 211, 141));
        verticalLayout_5 = new QVBoxLayout(horizontalLayoutWidget_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_5->addWidget(label_3);

        label_8 = new QLabel(horizontalLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_5->addWidget(label_8);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_5->addWidget(label_2);

        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_5->addWidget(label);

        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_5->addWidget(label_7);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(900, 570, 298, 191));
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

        class_void = new QRadioButton(horizontalLayoutWidget_3);
        class_void->setObjectName(QStringLiteral("class_void"));

        verticalLayout->addWidget(class_void);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        lcdNumber_0 = new QLCDNumber(horizontalLayoutWidget_3);
        lcdNumber_0->setObjectName(QStringLiteral("lcdNumber_0"));
        lcdNumber_0->setDigitCount(3);

        verticalLayout_6->addWidget(lcdNumber_0);

        lcdNumber_1 = new QLCDNumber(horizontalLayoutWidget_3);
        lcdNumber_1->setObjectName(QStringLiteral("lcdNumber_1"));
        lcdNumber_1->setDigitCount(3);

        verticalLayout_6->addWidget(lcdNumber_1);

        lcdNumber_2 = new QLCDNumber(horizontalLayoutWidget_3);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setDigitCount(3);

        verticalLayout_6->addWidget(lcdNumber_2);

        lcdNumber_3 = new QLCDNumber(horizontalLayoutWidget_3);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setDigitCount(3);

        verticalLayout_6->addWidget(lcdNumber_3);

        lcdNumber_4 = new QLCDNumber(horizontalLayoutWidget_3);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));
        lcdNumber_4->setDigitCount(3);

        verticalLayout_6->addWidget(lcdNumber_4);


        horizontalLayout_4->addLayout(verticalLayout_6);

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
        verticalLayoutWidget_3->setGeometry(QRect(900, 80, 291, 188));
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
        progressBar->setGeometry(QRect(900, 770, 301, 31));
        progressBar->setValue(24);
        horizontalLayoutWidget_4 = new QWidget(centralwidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(900, 20, 291, 51));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        inFile = new QPushButton(horizontalLayoutWidget_4);
        inFile->setObjectName(QStringLiteral("inFile"));

        horizontalLayout_5->addWidget(inFile);

        outFile = new QPushButton(horizontalLayoutWidget_4);
        outFile->setObjectName(QStringLiteral("outFile"));

        horizontalLayout_5->addWidget(outFile);

        horizontalLayoutWidget_5 = new QWidget(centralwidget);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(900, 280, 291, 51));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        previousBtn = new QPushButton(horizontalLayoutWidget_5);
        previousBtn->setObjectName(QStringLiteral("previousBtn"));

        horizontalLayout_6->addWidget(previousBtn);

        nextBtn = new QPushButton(horizontalLayoutWidget_5);
        nextBtn->setObjectName(QStringLiteral("nextBtn"));

        horizontalLayout_6->addWidget(nextBtn);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(900, 550, 140, 16));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Mono"));
        font.setPointSize(12);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(890, 330, 311, 181));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(890, -10, 311, 351));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(890, 530, 311, 281));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(1100, 520, 104, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1056, 520, 41, 21));
        TruthAndCrop->setCentralWidget(centralwidget);
        groupBox_3->raise();
        groupBox_2->raise();
        groupBox->raise();
        scrollArea->raise();
        horizontalLayoutWidget->raise();
        horizontalLayoutWidget_2->raise();
        horizontalLayoutWidget_3->raise();
        verticalLayoutWidget_3->raise();
        progressBar->raise();
        horizontalLayoutWidget_4->raise();
        horizontalLayoutWidget_5->raise();
        label_5->raise();
        textEdit->raise();
        label_9->raise();
        menubar = new QMenuBar(TruthAndCrop);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1212, 19));
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
        label_3->setText(QApplication::translate("TruthAndCrop", "Superpixel compactness", 0));
        label_8->setText(QApplication::translate("TruthAndCrop", "Crop window size / 2", 0));
        label_2->setText(QApplication::translate("TruthAndCrop", "Number of SLIC segments", 0));
        label->setText(QApplication::translate("TruthAndCrop", "Gaussian sigma smoothing", 0));
        label_7->setText(QApplication::translate("TruthAndCrop", "Down-sampling factor", 0));
        class_other->setText(QApplication::translate("TruthAndCrop", "Other", 0));
        class_mussel->setText(QApplication::translate("TruthAndCrop", "Mussel", 0));
        class_ciona->setText(QApplication::translate("TruthAndCrop", "Ciona", 0));
        class_styela->setText(QApplication::translate("TruthAndCrop", "Styela", 0));
        class_void->setText(QApplication::translate("TruthAndCrop", "Void", 0));
        refreshBtn->setText(QApplication::translate("TruthAndCrop", "Refresh", 0));
        cropBtn->setText(QApplication::translate("TruthAndCrop", "Crop", 0));
        toggleBtn->setText(QApplication::translate("TruthAndCrop", "Toggle", 0));
        doneBtn->setText(QApplication::translate("TruthAndCrop", "Save", 0));
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
        inFile->setText(QApplication::translate("TruthAndCrop", "Input File", 0));
        outFile->setText(QApplication::translate("TruthAndCrop", "Output Path", 0));
        previousBtn->setText(QApplication::translate("TruthAndCrop", "Previous Image", 0));
        nextBtn->setText(QApplication::translate("TruthAndCrop", "Next Image", 0));
        label_5->setText(QApplication::translate("TruthAndCrop", "Choose class", 0));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        label_9->setText(QApplication::translate("TruthAndCrop", "Mode:", 0));
    } // retranslateUi

};

namespace Ui {
    class TruthAndCrop: public Ui_TruthAndCrop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // TRUTH_AND_CROP_QT4SA2743_H

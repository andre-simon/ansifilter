/********************************************************************************
** Form generated from reading UI file 'ansifilter.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANSIFILTER_H
#define UI_ANSIFILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pbFileOpen;
    QPushButton *pbSaveAs;
    QPushButton *pbClipboard;
    QFrame *line_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblDrop;
    QFrame *line;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QComboBox *comboFormat;
    QCheckBox *cbIgnoreSequences;
    QCheckBox *cbFragment;
    QCheckBox *cbCodepage437;
    QFrame *artSizeFrame;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblWidth;
    QSpinBox *sbWidth;
    QSpacerItem *horizontalSpacer;
    QLabel *lblHeight;
    QSpinBox *sbHeight;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *leTitle;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblEncoding;
    QComboBox *comboEncoding;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpinBox *spinBoxWrap;
    QFontComboBox *comboFont;
    QFrame *line_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leColorMapPath;
    QPushButton *pbSelectMapFile;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pbAbout;
    QPushButton *pbExit;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;
    QLabel *lblInFilePath;
    QCheckBox *cbWatchFile;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->resize(784, 738);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ansifilter.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(Dialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pbFileOpen = new QPushButton(groupBox);
        pbFileOpen->setObjectName(QStringLiteral("pbFileOpen"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pbFileOpen->sizePolicy().hasHeightForWidth());
        pbFileOpen->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(pbFileOpen);

        pbSaveAs = new QPushButton(groupBox);
        pbSaveAs->setObjectName(QStringLiteral("pbSaveAs"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pbSaveAs->sizePolicy().hasHeightForWidth());
        pbSaveAs->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(pbSaveAs);

        pbClipboard = new QPushButton(groupBox);
        pbClipboard->setObjectName(QStringLiteral("pbClipboard"));
        sizePolicy3.setHeightForWidth(pbClipboard->sizePolicy().hasHeightForWidth());
        pbClipboard->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(pbClipboard);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        lblDrop = new QLabel(groupBox);
        lblDrop->setObjectName(QStringLiteral("lblDrop"));
        lblDrop->setEnabled(false);
        lblDrop->setMaximumSize(QSize(48, 48));
        lblDrop->setPixmap(QPixmap(QString::fromUtf8(":/Actions-drop-icon.png")));
        lblDrop->setScaledContents(true);

        gridLayout->addWidget(lblDrop, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        comboFormat = new QComboBox(groupBox);
        comboFormat->setObjectName(QStringLiteral("comboFormat"));
        comboFormat->setEnabled(true);

        horizontalLayout_6->addWidget(comboFormat);


        verticalLayout->addLayout(horizontalLayout_6);

        cbIgnoreSequences = new QCheckBox(groupBox);
        cbIgnoreSequences->setObjectName(QStringLiteral("cbIgnoreSequences"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cbIgnoreSequences->sizePolicy().hasHeightForWidth());
        cbIgnoreSequences->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(cbIgnoreSequences);

        cbFragment = new QCheckBox(groupBox);
        cbFragment->setObjectName(QStringLiteral("cbFragment"));
        sizePolicy4.setHeightForWidth(cbFragment->sizePolicy().hasHeightForWidth());
        cbFragment->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(cbFragment);

        cbCodepage437 = new QCheckBox(groupBox);
        cbCodepage437->setObjectName(QStringLiteral("cbCodepage437"));

        verticalLayout->addWidget(cbCodepage437);

        artSizeFrame = new QFrame(groupBox);
        artSizeFrame->setObjectName(QStringLiteral("artSizeFrame"));
        artSizeFrame->setEnabled(false);
        artSizeFrame->setFrameShape(QFrame::StyledPanel);
        artSizeFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(artSizeFrame);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lblWidth = new QLabel(artSizeFrame);
        lblWidth->setObjectName(QStringLiteral("lblWidth"));

        horizontalLayout_7->addWidget(lblWidth);

        sbWidth = new QSpinBox(artSizeFrame);
        sbWidth->setObjectName(QStringLiteral("sbWidth"));
        sbWidth->setMinimum(60);
        sbWidth->setMaximum(240);
        sbWidth->setSingleStep(5);
        sbWidth->setValue(80);

        horizontalLayout_7->addWidget(sbWidth);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        lblHeight = new QLabel(artSizeFrame);
        lblHeight->setObjectName(QStringLiteral("lblHeight"));

        horizontalLayout_7->addWidget(lblHeight);

        sbHeight = new QSpinBox(artSizeFrame);
        sbHeight->setObjectName(QStringLiteral("sbHeight"));
        sbHeight->setMinimum(80);
        sbHeight->setMaximum(200);
        sbHeight->setSingleStep(5);
        sbHeight->setValue(150);

        horizontalLayout_7->addWidget(sbHeight);


        verticalLayout->addWidget(artSizeFrame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(label_2);

        leTitle = new QLineEdit(groupBox);
        leTitle->setObjectName(QStringLiteral("leTitle"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(leTitle->sizePolicy().hasHeightForWidth());
        leTitle->setSizePolicy(sizePolicy6);

        horizontalLayout_2->addWidget(leTitle);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lblEncoding = new QLabel(groupBox);
        lblEncoding->setObjectName(QStringLiteral("lblEncoding"));
        sizePolicy1.setHeightForWidth(lblEncoding->sizePolicy().hasHeightForWidth());
        lblEncoding->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lblEncoding);

        comboEncoding = new QComboBox(groupBox);
        comboEncoding->setObjectName(QStringLiteral("comboEncoding"));
        sizePolicy6.setHeightForWidth(comboEncoding->sizePolicy().hasHeightForWidth());
        comboEncoding->setSizePolicy(sizePolicy6);
        comboEncoding->setEditable(true);

        horizontalLayout_3->addWidget(comboEncoding);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        spinBoxWrap = new QSpinBox(groupBox);
        spinBoxWrap->setObjectName(QStringLiteral("spinBoxWrap"));

        horizontalLayout_4->addWidget(spinBoxWrap);


        verticalLayout->addLayout(horizontalLayout_4);

        comboFont = new QFontComboBox(groupBox);
        comboFont->setObjectName(QStringLiteral("comboFont"));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        comboFont->setCurrentFont(font);

        verticalLayout->addWidget(comboFont);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leColorMapPath = new QLineEdit(groupBox);
        leColorMapPath->setObjectName(QStringLiteral("leColorMapPath"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(leColorMapPath->sizePolicy().hasHeightForWidth());
        leColorMapPath->setSizePolicy(sizePolicy7);

        horizontalLayout->addWidget(leColorMapPath);

        pbSelectMapFile = new QPushButton(groupBox);
        pbSelectMapFile->setObjectName(QStringLiteral("pbSelectMapFile"));
        QSizePolicy sizePolicy8(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(pbSelectMapFile->sizePolicy().hasHeightForWidth());
        pbSelectMapFile->setSizePolicy(sizePolicy8);
        pbSelectMapFile->setMinimumSize(QSize(20, 0));
        pbSelectMapFile->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(pbSelectMapFile);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pbAbout = new QPushButton(groupBox);
        pbAbout->setObjectName(QStringLiteral("pbAbout"));
        sizePolicy3.setHeightForWidth(pbAbout->sizePolicy().hasHeightForWidth());
        pbAbout->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(pbAbout);

        pbExit = new QPushButton(groupBox);
        pbExit->setObjectName(QStringLiteral("pbExit"));
        sizePolicy3.setHeightForWidth(pbExit->sizePolicy().hasHeightForWidth());
        pbExit->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pbExit->setFont(font1);

        horizontalLayout_5->addWidget(pbExit);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(1);
        sizePolicy9.setVerticalStretch(1);
        sizePolicy9.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy9);
        QFont font2;
        font2.setFamily(QStringLiteral("Courier New"));
        font2.setPointSize(10);
        textEdit->setFont(font2);
        textEdit->setAcceptDrops(false);
        textEdit->setReadOnly(true);

        gridLayout_2->addWidget(textEdit, 1, 0, 1, 1);

        lblInFilePath = new QLabel(Dialog);
        lblInFilePath->setObjectName(QStringLiteral("lblInFilePath"));

        gridLayout_2->addWidget(lblInFilePath, 0, 0, 1, 1);

        cbWatchFile = new QCheckBox(Dialog);
        cbWatchFile->setObjectName(QStringLiteral("cbWatchFile"));
        cbWatchFile->setEnabled(false);

        gridLayout_2->addWidget(cbWatchFile, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(leTitle);
        lblEncoding->setBuddy(comboEncoding);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(cbIgnoreSequences, cbFragment);
        QWidget::setTabOrder(cbFragment, leTitle);
        QWidget::setTabOrder(leTitle, comboEncoding);
        QWidget::setTabOrder(comboEncoding, comboFont);
        QWidget::setTabOrder(comboFont, textEdit);

        retranslateUi(Dialog);
        QObject::connect(pbExit, SIGNAL(clicked()), Dialog, SLOT(close()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "ANSIFilter", 0));
        groupBox->setTitle(QApplication::translate("Dialog", "ANSIFilter", 0));
#ifndef QT_NO_TOOLTIP
        pbFileOpen->setToolTip(QApplication::translate("Dialog", "Open a text file.", 0));
#endif // QT_NO_TOOLTIP
        pbFileOpen->setText(QApplication::translate("Dialog", "Open File", 0));
#ifndef QT_NO_TOOLTIP
        pbSaveAs->setToolTip(QApplication::translate("Dialog", "Save the opened file as text, HTML, LaTeX, Plain TeX, BBCode or RTF.", 0));
#endif // QT_NO_TOOLTIP
        pbSaveAs->setText(QApplication::translate("Dialog", "Save as", 0));
#ifndef QT_NO_TOOLTIP
        pbClipboard->setToolTip(QApplication::translate("Dialog", "Copy opened file as plain text to clipboard", 0));
#endif // QT_NO_TOOLTIP
        pbClipboard->setText(QApplication::translate("Dialog", "Copy to clipboard", 0));
#ifndef QT_NO_TOOLTIP
        lblDrop->setToolTip(QApplication::translate("Dialog", "You may drop a file on this window.", 0));
#endif // QT_NO_TOOLTIP
        lblDrop->setText(QString());
        label_4->setText(QApplication::translate("Dialog", "Output format:", 0));
        comboFormat->clear();
        comboFormat->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Text", 0)
         << QApplication::translate("Dialog", "HTML", 0)
         << QApplication::translate("Dialog", "RTF", 0)
         << QApplication::translate("Dialog", "LaTeX", 0)
         << QApplication::translate("Dialog", "TeX", 0)
         << QApplication::translate("Dialog", "BBCode", 0)
         << QApplication::translate("Dialog", "Pango Markup", 0)
        );
#ifndef QT_NO_TOOLTIP
        cbIgnoreSequences->setToolTip(QApplication::translate("Dialog", "Show and save files ignoring the contained ANSI formatting information.", 0));
#endif // QT_NO_TOOLTIP
        cbIgnoreSequences->setText(QApplication::translate("Dialog", "Omit styling in output", 0));
#ifndef QT_NO_TOOLTIP
        cbFragment->setToolTip(QApplication::translate("Dialog", "Save HTML without header and footer to paste it into existing documents.", 0));
#endif // QT_NO_TOOLTIP
        cbFragment->setText(QApplication::translate("Dialog", "Omit header and footer", 0));
#ifndef QT_NO_TOOLTIP
        cbCodepage437->setToolTip(QApplication::translate("Dialog", "Enable support for codepage 437 symbols and ANSI.SYS commands.", 0));
#endif // QT_NO_TOOLTIP
        cbCodepage437->setText(QApplication::translate("Dialog", "Codepage 437 (ASCII art)", 0));
        lblWidth->setText(QApplication::translate("Dialog", "Width", 0));
        lblHeight->setText(QApplication::translate("Dialog", "Height", 0));
        label_2->setText(QApplication::translate("Dialog", "Tit&le:", 0));
#ifndef QT_NO_TOOLTIP
        leTitle->setToolTip(QApplication::translate("Dialog", "Set the output document title.", 0));
#endif // QT_NO_TOOLTIP
        lblEncoding->setText(QApplication::translate("Dialog", "En&coding:", 0));
        comboEncoding->clear();
        comboEncoding->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "ISO-8859-1", 0)
         << QApplication::translate("Dialog", "ISO-8859-2", 0)
         << QApplication::translate("Dialog", "ISO-8859-3", 0)
         << QApplication::translate("Dialog", "ISO-8859-4", 0)
         << QApplication::translate("Dialog", "ISO-8859-6", 0)
         << QApplication::translate("Dialog", "ISO-8859-7", 0)
         << QApplication::translate("Dialog", "ISO-8859-8", 0)
         << QApplication::translate("Dialog", "ISO-8859-9", 0)
         << QApplication::translate("Dialog", "ISO-8859-10", 0)
         << QApplication::translate("Dialog", "ISO-8859-11", 0)
         << QApplication::translate("Dialog", "ISO-8859-13", 0)
         << QApplication::translate("Dialog", "ISO-8859-14", 0)
         << QApplication::translate("Dialog", "ISO-8859-15", 0)
         << QApplication::translate("Dialog", "UTF-8", 0)
        );
#ifndef QT_NO_TOOLTIP
        comboEncoding->setToolTip(QApplication::translate("Dialog", "Set the encoding (has to match input file encoding).", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("Dialog", "Line wrap:", 0));
#ifndef QT_NO_TOOLTIP
        spinBoxWrap->setToolTip(QApplication::translate("Dialog", "Wrap lines after given char count (0 disables wrapping).", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        comboFont->setToolTip(QApplication::translate("Dialog", "Set the output font.", 0));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("Dialog", "Color map file:", 0));
#ifndef QT_NO_TOOLTIP
        leColorMapPath->setToolTip(QApplication::translate("Dialog", "Color map file (see README for details).", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pbSelectMapFile->setToolTip(QApplication::translate("Dialog", "Select a color map configuration file. ", 0));
#endif // QT_NO_TOOLTIP
        pbSelectMapFile->setText(QApplication::translate("Dialog", "...", 0));
#ifndef QT_NO_TOOLTIP
        pbAbout->setToolTip(QApplication::translate("Dialog", "Show information about this program.", 0));
#endif // QT_NO_TOOLTIP
        pbAbout->setText(QApplication::translate("Dialog", "About", 0));
#ifndef QT_NO_TOOLTIP
        pbExit->setToolTip(QApplication::translate("Dialog", "Quit this program.", 0));
#endif // QT_NO_TOOLTIP
        pbExit->setText(QApplication::translate("Dialog", "Quit", 0));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        textEdit->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Courier New'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">Please open a file.</span></p></body></html>", 0));
        lblInFilePath->setText(QApplication::translate("Dialog", "Input file:", 0));
#ifndef QT_NO_TOOLTIP
        cbWatchFile->setToolTip(QApplication::translate("Dialog", "Update view if input file changes, Do not apply with big or fast growing input files.", 0));
#endif // QT_NO_TOOLTIP
        cbWatchFile->setText(QApplication::translate("Dialog", "Watch this file", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANSIFILTER_H

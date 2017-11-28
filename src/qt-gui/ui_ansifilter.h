/********************************************************************************
** Form generated from reading UI file 'ansifilter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
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
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_4;
    QPushButton *pbFileOpen;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pbSaveAs;
    QPushButton *pbClipboard;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblDrop;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QComboBox *comboFormat;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *gridLayout_2;
    QCheckBox *cbOmitVersion;
    QCheckBox *cbIgnoreSequences;
    QCheckBox *cbFragment;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *gbAsciiArt;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *cbParseAsciiArt;
    QComboBox *comboAnsiFormat;
    QFrame *artSizeFrame;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblWidth;
    QSpinBox *sbWidth;
    QSpacerItem *horizontalSpacer;
    QLabel *lblHeight;
    QSpinBox *sbHeight;
    QSpacerItem *verticalSpacer_5;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLineEdit *leTitle;
    QLabel *lblEncoding;
    QComboBox *comboEncoding;
    QLabel *label_3;
    QSpinBox *spinBoxWrap;
    QFontComboBox *comboFont;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *leColorMapPath;
    QPushButton *pbSelectMapFile;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pbAbout;
    QPushButton *pbExit;
    QVBoxLayout *verticalLayout;
    QLabel *lblInFilePath;
    QTextEdit *textEdit;
    QCheckBox *cbWatchFile;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->resize(784, 791);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ansifilter.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        horizontalLayout_2 = new QHBoxLayout(Dialog);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pbFileOpen = new QPushButton(groupBox);
        pbFileOpen->setObjectName(QStringLiteral("pbFileOpen"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pbFileOpen->sizePolicy().hasHeightForWidth());
        pbFileOpen->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pbFileOpen, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 1, 1, 1);

        pbSaveAs = new QPushButton(groupBox);
        pbSaveAs->setObjectName(QStringLiteral("pbSaveAs"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pbSaveAs->sizePolicy().hasHeightForWidth());
        pbSaveAs->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(pbSaveAs, 1, 0, 1, 1);

        pbClipboard = new QPushButton(groupBox);
        pbClipboard->setObjectName(QStringLiteral("pbClipboard"));
        sizePolicy3.setHeightForWidth(pbClipboard->sizePolicy().hasHeightForWidth());
        pbClipboard->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(pbClipboard, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

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


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        comboFormat = new QComboBox(groupBox);
        comboFormat->setObjectName(QStringLiteral("comboFormat"));
        comboFormat->setEnabled(true);

        horizontalLayout_6->addWidget(comboFormat);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        cbOmitVersion = new QCheckBox(groupBox);
        cbOmitVersion->setObjectName(QStringLiteral("cbOmitVersion"));

        gridLayout_2->addWidget(cbOmitVersion, 1, 0, 1, 1);

        cbIgnoreSequences = new QCheckBox(groupBox);
        cbIgnoreSequences->setObjectName(QStringLiteral("cbIgnoreSequences"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cbIgnoreSequences->sizePolicy().hasHeightForWidth());
        cbIgnoreSequences->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(cbIgnoreSequences, 0, 0, 1, 1);

        cbFragment = new QCheckBox(groupBox);
        cbFragment->setObjectName(QStringLiteral("cbFragment"));
        sizePolicy4.setHeightForWidth(cbFragment->sizePolicy().hasHeightForWidth());
        cbFragment->setSizePolicy(sizePolicy4);

        gridLayout_2->addWidget(cbFragment, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        gbAsciiArt = new QGroupBox(groupBox);
        gbAsciiArt->setObjectName(QStringLiteral("gbAsciiArt"));
        gbAsciiArt->setEnabled(true);
        sizePolicy3.setHeightForWidth(gbAsciiArt->sizePolicy().hasHeightForWidth());
        gbAsciiArt->setSizePolicy(sizePolicy3);
        gbAsciiArt->setFlat(false);
        gridLayout_5 = new QGridLayout(gbAsciiArt);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cbParseAsciiArt = new QCheckBox(gbAsciiArt);
        cbParseAsciiArt->setObjectName(QStringLiteral("cbParseAsciiArt"));

        horizontalLayout_3->addWidget(cbParseAsciiArt);

        comboAnsiFormat = new QComboBox(gbAsciiArt);
        comboAnsiFormat->setObjectName(QStringLiteral("comboAnsiFormat"));
        comboAnsiFormat->setEnabled(false);
        comboAnsiFormat->setEditable(false);
        comboAnsiFormat->setMaxVisibleItems(3);
        comboAnsiFormat->setMaxCount(3);

        horizontalLayout_3->addWidget(comboAnsiFormat);


        gridLayout_5->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        artSizeFrame = new QFrame(gbAsciiArt);
        artSizeFrame->setObjectName(QStringLiteral("artSizeFrame"));
        artSizeFrame->setEnabled(false);
        artSizeFrame->setFrameShape(QFrame::StyledPanel);
        artSizeFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(artSizeFrame);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lblWidth = new QLabel(artSizeFrame);
        lblWidth->setObjectName(QStringLiteral("lblWidth"));
        lblWidth->setEnabled(false);

        horizontalLayout_7->addWidget(lblWidth);

        sbWidth = new QSpinBox(artSizeFrame);
        sbWidth->setObjectName(QStringLiteral("sbWidth"));
        sbWidth->setEnabled(false);
        sbWidth->setMinimum(60);
        sbWidth->setMaximum(320);
        sbWidth->setSingleStep(5);
        sbWidth->setValue(80);

        horizontalLayout_7->addWidget(sbWidth);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        lblHeight = new QLabel(artSizeFrame);
        lblHeight->setObjectName(QStringLiteral("lblHeight"));
        lblHeight->setEnabled(false);

        horizontalLayout_7->addWidget(lblHeight);

        sbHeight = new QSpinBox(artSizeFrame);
        sbHeight->setObjectName(QStringLiteral("sbHeight"));
        sbHeight->setEnabled(false);
        sbHeight->setMinimum(80);
        sbHeight->setMaximum(500);
        sbHeight->setSingleStep(5);
        sbHeight->setValue(150);

        horizontalLayout_7->addWidget(sbHeight);


        gridLayout_5->addWidget(artSizeFrame, 1, 0, 1, 1);


        verticalLayout_2->addWidget(gbAsciiArt);

        verticalSpacer_5 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_5);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        leTitle = new QLineEdit(groupBox);
        leTitle->setObjectName(QStringLiteral("leTitle"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(leTitle->sizePolicy().hasHeightForWidth());
        leTitle->setSizePolicy(sizePolicy6);

        gridLayout_3->addWidget(leTitle, 0, 1, 1, 2);

        lblEncoding = new QLabel(groupBox);
        lblEncoding->setObjectName(QStringLiteral("lblEncoding"));
        sizePolicy1.setHeightForWidth(lblEncoding->sizePolicy().hasHeightForWidth());
        lblEncoding->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(lblEncoding, 1, 0, 1, 2);

        comboEncoding = new QComboBox(groupBox);
        comboEncoding->setObjectName(QStringLiteral("comboEncoding"));
        sizePolicy6.setHeightForWidth(comboEncoding->sizePolicy().hasHeightForWidth());
        comboEncoding->setSizePolicy(sizePolicy6);
        comboEncoding->setEditable(true);

        gridLayout_3->addWidget(comboEncoding, 1, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 2);

        spinBoxWrap = new QSpinBox(groupBox);
        spinBoxWrap->setObjectName(QStringLiteral("spinBoxWrap"));

        gridLayout_3->addWidget(spinBoxWrap, 2, 2, 1, 1);

        comboFont = new QFontComboBox(groupBox);
        comboFont->setObjectName(QStringLiteral("comboFont"));
        QFont font;
        font.setFamily(QStringLiteral("Liberation Mono"));
        comboFont->setCurrentFont(font);

        gridLayout_3->addWidget(comboFont, 3, 0, 1, 3);


        verticalLayout_2->addLayout(gridLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

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

        horizontalLayout->addWidget(pbSelectMapFile);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

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


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_2->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblInFilePath = new QLabel(Dialog);
        lblInFilePath->setObjectName(QStringLiteral("lblInFilePath"));

        verticalLayout->addWidget(lblInFilePath);

        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(1);
        sizePolicy9.setVerticalStretch(1);
        sizePolicy9.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy9);
        QFont font2;
        font2.setFamily(QStringLiteral("Monospace"));
        font2.setPointSize(10);
        textEdit->setFont(font2);
        textEdit->setAcceptDrops(false);
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        cbWatchFile = new QCheckBox(Dialog);
        cbWatchFile->setObjectName(QStringLiteral("cbWatchFile"));
        cbWatchFile->setEnabled(false);

        verticalLayout->addWidget(cbWatchFile);


        horizontalLayout_2->addLayout(verticalLayout);

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
        Dialog->setWindowTitle(QApplication::translate("Dialog", "ANSIFilter", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dialog", "ANSIFilter", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbFileOpen->setToolTip(QApplication::translate("Dialog", "Open a text file.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbFileOpen->setText(QApplication::translate("Dialog", "Open File", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbSaveAs->setToolTip(QApplication::translate("Dialog", "Save the opened file as text, HTML, LaTeX, Plain TeX, BBCode or RTF.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbSaveAs->setText(QApplication::translate("Dialog", "Save as", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbClipboard->setToolTip(QApplication::translate("Dialog", "Copy opened file as plain text to clipboard", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbClipboard->setText(QApplication::translate("Dialog", "Copy to clipboard", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lblDrop->setToolTip(QApplication::translate("Dialog", "You may drop a file on this window.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lblDrop->setText(QString());
        label_4->setText(QApplication::translate("Dialog", "Output format:", Q_NULLPTR));
        comboFormat->clear();
        comboFormat->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Text", Q_NULLPTR)
         << QApplication::translate("Dialog", "HTML", Q_NULLPTR)
         << QApplication::translate("Dialog", "RTF", Q_NULLPTR)
         << QApplication::translate("Dialog", "LaTeX", Q_NULLPTR)
         << QApplication::translate("Dialog", "TeX", Q_NULLPTR)
         << QApplication::translate("Dialog", "BBCode", Q_NULLPTR)
         << QApplication::translate("Dialog", "Pango Markup", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        cbOmitVersion->setToolTip(QApplication::translate("Dialog", "Do not include version info comment", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cbOmitVersion->setText(QApplication::translate("Dialog", "Omit version info", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbIgnoreSequences->setToolTip(QApplication::translate("Dialog", "Show and save files ignoring the contained ANSI formatting information.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cbIgnoreSequences->setText(QApplication::translate("Dialog", "Omit styling in output", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbFragment->setToolTip(QApplication::translate("Dialog", "Save HTML without header and footer to paste it into existing documents.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cbFragment->setText(QApplication::translate("Dialog", "Omit header and footer", Q_NULLPTR));
        gbAsciiArt->setTitle(QApplication::translate("Dialog", "ANSI art options", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbParseAsciiArt->setToolTip(QApplication::translate("Dialog", "Enable parsing of ANSI art files.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cbParseAsciiArt->setText(QApplication::translate("Dialog", "Enable ANSI art", Q_NULLPTR));
        comboAnsiFormat->clear();
        comboAnsiFormat->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Codepage 437", Q_NULLPTR)
         << QApplication::translate("Dialog", "BIN/XBIN", Q_NULLPTR)
         << QApplication::translate("Dialog", "Tundra", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        comboAnsiFormat->setToolTip(QApplication::translate("Dialog", "Select the ANSI art file format", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lblWidth->setText(QApplication::translate("Dialog", "Width", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        sbWidth->setToolTip(QApplication::translate("Dialog", "Set the ASCII art image width (default: 80). This setting is ignored with XBIN input.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lblHeight->setText(QApplication::translate("Dialog", "Height", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        sbHeight->setToolTip(QApplication::translate("Dialog", "Set the ASCII art image height (default: 150). This setting is ignored with XBIN input.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("Dialog", "Tit&le:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        leTitle->setToolTip(QApplication::translate("Dialog", "Set the output document title.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lblEncoding->setText(QApplication::translate("Dialog", "E&ncoding:", Q_NULLPTR));
        comboEncoding->clear();
        comboEncoding->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "ISO-8859-1", Q_NULLPTR)
         << QApplication::translate("Dialog", "ISO-8859-2", Q_NULLPTR)
         << QApplication::translate("Dialog", "ISO-8859-3", Q_NULLPTR)
         << QApplication::translate("Dialog", "ISO-8859-4", Q_NULLPTR)
         << QApplication::translate("Dialog", "ISO-8859-6", Q_NULLPTR)
         << QApplication::translate("Dialog", "ISO-8859-7", Q_NULLPTR)
         << QApplication::translate("Dialog", "ISO-8859-8", Q_NULLPTR)
         << QApplication::translate("Dialog", "ISO-8859-9", Q_NULLPTR)
         << QApplication::translate("Dialog", "ISO-8859-10", Q_NULLPTR)
         << QApplication::translate("Dialog", "ISO-8859-11", Q_NULLPTR)
         << QApplication::translate("Dialog", "ISO-8859-13", Q_NULLPTR)
         << QApplication::translate("Dialog", "ISO-8859-14", Q_NULLPTR)
         << QApplication::translate("Dialog", "ISO-8859-15", Q_NULLPTR)
         << QApplication::translate("Dialog", "UTF-8", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        comboEncoding->setToolTip(QApplication::translate("Dialog", "Set the encoding (has to match input file encoding).", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("Dialog", "Line wrap:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spinBoxWrap->setToolTip(QApplication::translate("Dialog", "Wrap lines after given char count (0 disables wrapping).", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        comboFont->setToolTip(QApplication::translate("Dialog", "Set the output font.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("Dialog", "Color map file:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        leColorMapPath->setToolTip(QApplication::translate("Dialog", "Color map file (see README for details). This setting is ignored with XBIN input.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pbSelectMapFile->setToolTip(QApplication::translate("Dialog", "Select a color map configuration file. ", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbSelectMapFile->setText(QApplication::translate("Dialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbAbout->setToolTip(QApplication::translate("Dialog", "Show information about this program.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbAbout->setText(QApplication::translate("Dialog", "About", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbExit->setToolTip(QApplication::translate("Dialog", "Quit this program.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbExit->setText(QApplication::translate("Dialog", "Quit", Q_NULLPTR));
        lblInFilePath->setText(QApplication::translate("Dialog", "Input file:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("Dialog", "Output preview", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        textEdit->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Monospace'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Noto Sans,Courier New';\">Please open a file.</span></p></body></html>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbWatchFile->setToolTip(QApplication::translate("Dialog", "Update view if input file changes, Do not apply with big or fast growing input files.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cbWatchFile->setText(QApplication::translate("Dialog", "Watch this file", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANSIFILTER_H

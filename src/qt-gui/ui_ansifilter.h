/********************************************************************************
** Form generated from reading UI file 'ansifilter.ui'
**
** Created: Wed Jan 4 19:11:18 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANSIFILTER_H
#define UI_ANSIFILTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFontComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;
    QSpacerItem *spacerItem;
    QFrame *frame;
    QVBoxLayout *vboxLayout;
    QPushButton *pbFileOpen;
    QPushButton *pbSaveAs;
    QPushButton *pbClipboard;
    QFrame *line;
    QPushButton *pbAbout;
    QPushButton *pbExit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *cbIgnoreSequences;
    QCheckBox *cbFragment;
    QLabel *label_2;
    QLineEdit *leTitle;
    QLabel *label;
    QComboBox *comboEncoding;
    QLabel *label_3;
    QSpinBox *spinBoxWrap;
    QFontComboBox *comboFont;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->resize(765, 658);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("ansifilter.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(Dialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textEdit = new QTextEdit(Dialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(10);
        textEdit->setFont(font);
        textEdit->setAcceptDrops(false);
        textEdit->setReadOnly(true);

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 3);

        spacerItem = new QSpacerItem(415, 178, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(spacerItem, 1, 2, 1, 1);

        frame = new QFrame(Dialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        vboxLayout = new QVBoxLayout(frame);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        pbFileOpen = new QPushButton(frame);
        pbFileOpen->setObjectName(QString::fromUtf8("pbFileOpen"));

        vboxLayout->addWidget(pbFileOpen);

        pbSaveAs = new QPushButton(frame);
        pbSaveAs->setObjectName(QString::fromUtf8("pbSaveAs"));

        vboxLayout->addWidget(pbSaveAs);

        pbClipboard = new QPushButton(frame);
        pbClipboard->setObjectName(QString::fromUtf8("pbClipboard"));

        vboxLayout->addWidget(pbClipboard);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        vboxLayout->addWidget(line);

        pbAbout = new QPushButton(frame);
        pbAbout->setObjectName(QString::fromUtf8("pbAbout"));

        vboxLayout->addWidget(pbAbout);

        pbExit = new QPushButton(frame);
        pbExit->setObjectName(QString::fromUtf8("pbExit"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pbExit->setFont(font1);

        vboxLayout->addWidget(pbExit);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);

        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cbIgnoreSequences = new QCheckBox(groupBox);
        cbIgnoreSequences->setObjectName(QString::fromUtf8("cbIgnoreSequences"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cbIgnoreSequences->sizePolicy().hasHeightForWidth());
        cbIgnoreSequences->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(cbIgnoreSequences, 0, 0, 1, 2);

        cbFragment = new QCheckBox(groupBox);
        cbFragment->setObjectName(QString::fromUtf8("cbFragment"));
        sizePolicy3.setHeightForWidth(cbFragment->sizePolicy().hasHeightForWidth());
        cbFragment->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(cbFragment, 1, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        leTitle = new QLineEdit(groupBox);
        leTitle->setObjectName(QString::fromUtf8("leTitle"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(leTitle->sizePolicy().hasHeightForWidth());
        leTitle->setSizePolicy(sizePolicy5);

        gridLayout->addWidget(leTitle, 2, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        comboEncoding = new QComboBox(groupBox);
        comboEncoding->setObjectName(QString::fromUtf8("comboEncoding"));
        sizePolicy5.setHeightForWidth(comboEncoding->sizePolicy().hasHeightForWidth());
        comboEncoding->setSizePolicy(sizePolicy5);
        comboEncoding->setEditable(true);

        gridLayout->addWidget(comboEncoding, 3, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        spinBoxWrap = new QSpinBox(groupBox);
        spinBoxWrap->setObjectName(QString::fromUtf8("spinBoxWrap"));

        gridLayout->addWidget(spinBoxWrap, 4, 1, 1, 1);

        comboFont = new QFontComboBox(groupBox);
        comboFont->setObjectName(QString::fromUtf8("comboFont"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Courier New"));
        comboFont->setCurrentFont(font2);

        gridLayout->addWidget(comboFont, 5, 0, 1, 2);


        gridLayout_2->addWidget(groupBox, 1, 1, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(leTitle);
        label->setBuddy(comboEncoding);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(pbFileOpen, pbSaveAs);
        QWidget::setTabOrder(pbSaveAs, pbAbout);
        QWidget::setTabOrder(pbAbout, pbExit);
        QWidget::setTabOrder(pbExit, cbIgnoreSequences);
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
        Dialog->setWindowTitle(QApplication::translate("Dialog", "ANSIFilter", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        textEdit->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Courier New'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8pt;\">Please open a file.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbFileOpen->setToolTip(QApplication::translate("Dialog", "Open a text file.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbFileOpen->setText(QApplication::translate("Dialog", "Open File", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbSaveAs->setToolTip(QApplication::translate("Dialog", "Save the opened file as text, HTML or RTF.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbSaveAs->setText(QApplication::translate("Dialog", "Save as", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbClipboard->setToolTip(QApplication::translate("Dialog", "Copy opened file as plain text to clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbClipboard->setText(QApplication::translate("Dialog", "Copy to clipboard", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbAbout->setToolTip(QApplication::translate("Dialog", "Show information about this program.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbAbout->setText(QApplication::translate("Dialog", "About", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pbExit->setToolTip(QApplication::translate("Dialog", "Quit the program.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pbExit->setText(QApplication::translate("Dialog", "Quit", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog", "Output options", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cbIgnoreSequences->setToolTip(QApplication::translate("Dialog", "Show and save files without the ANSI formatting information.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cbIgnoreSequences->setText(QApplication::translate("Dialog", "Ignore formatting", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cbFragment->setToolTip(QApplication::translate("Dialog", "Save HTML without header and footer to paste it into existing documents.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cbFragment->setText(QApplication::translate("Dialog", "Omit header and footer", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Title:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        leTitle->setToolTip(QApplication::translate("Dialog", "Set the output document title.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Dialog", "Encoding:", 0, QApplication::UnicodeUTF8));
        comboEncoding->clear();
        comboEncoding->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "ISO-8859-1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO-8859-2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO-8859-3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO-8859-4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO-8859-6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO-8859-7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO-8859-8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO-8859-9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO-8859-10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO-8859-11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO-8859-13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO-8859-14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "ISO-8859-15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "UTF-8", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboEncoding->setToolTip(QApplication::translate("Dialog", "Set the encoding (has to match input file encoding).", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("Dialog", "Line wrap:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        comboFont->setToolTip(QApplication::translate("Dialog", "Set the output font.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANSIFILTER_H

/********************************************************************************
** Form generated from reading UI file 'hoggui.ui'
**
** Created: Fri May 25 15:19:39 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOGGUI_H
#define UI_HOGGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HogGuiClass
{
public:
    QPushButton *pic_pushButton;
    QPushButton *video_pushButton;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *pic_path_lineEdit;
    QLineEdit *video_path_lineEdit;
    QLabel *show_label;
    QPushButton *load_pushButton;
    QLabel *label_4;
    QLineEdit *xml_lineEdit;
    QLabel *label_5;
    QLCDNumber *time_lcdNumber;
    QLabel *label_6;
    QTabWidget *sample_train;
    QWidget *sample;
    QLineEdit *postiveinfo_lineEdit;
    QLineEdit *negetiveinfo_lineEdit;
    QLineEdit *postive_pic_path_lineEdit;
    QLineEdit *negetive_pic_path_lineEdit;
    QLineEdit *target_postive_pic_path_lineEdit;
    QLineEdit *target_negetive_pic_path_lineEdit;
    QLineEdit *total_lineEdit;
    QPushButton *create_pushButton;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *train;
    QLineEdit *postive_infolineEdit;
    QLineEdit *negetive_infolineEdit;
    QLineEdit *postive_pathlineEdit;
    QLineEdit *nengtive_pathlineEdit;
    QLineEdit *save_pathlineEdit;
    QLineEdit *postive_numlineEdit;
    QLineEdit *negetive_numlineEdit;
    QPushButton *trainpushButton;
    QLineEdit *pic_tatallineEdit;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QWidget *tab;

    void setupUi(QDialog *HogGuiClass)
    {
        if (HogGuiClass->objectName().isEmpty())
            HogGuiClass->setObjectName(QString::fromUtf8("HogGuiClass"));
        HogGuiClass->resize(956, 514);
        HogGuiClass->setMinimumSize(QSize(956, 514));
        HogGuiClass->setMaximumSize(QSize(956, 514));
        QIcon icon;
        icon.addFile(QString::fromUtf8("3gf1nk5XvJk9QKP.png"), QSize(), QIcon::Normal, QIcon::Off);
        HogGuiClass->setWindowIcon(icon);
        pic_pushButton = new QPushButton(HogGuiClass);
        pic_pushButton->setObjectName(QString::fromUtf8("pic_pushButton"));
        pic_pushButton->setGeometry(QRect(670, 10, 141, 41));
        video_pushButton = new QPushButton(HogGuiClass);
        video_pushButton->setObjectName(QString::fromUtf8("video_pushButton"));
        video_pushButton->setGeometry(QRect(670, 60, 141, 41));
        label = new QLabel(HogGuiClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(670, 120, 81, 31));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        lcdNumber = new QLCDNumber(HogGuiClass);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(750, 120, 61, 31));
        lcdNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        label_2 = new QLabel(HogGuiClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 420, 54, 12));
        label_3 = new QLabel(HogGuiClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 460, 54, 12));
        pic_path_lineEdit = new QLineEdit(HogGuiClass);
        pic_path_lineEdit->setObjectName(QString::fromUtf8("pic_path_lineEdit"));
        pic_path_lineEdit->setGeometry(QRect(100, 420, 391, 20));
        video_path_lineEdit = new QLineEdit(HogGuiClass);
        video_path_lineEdit->setObjectName(QString::fromUtf8("video_path_lineEdit"));
        video_path_lineEdit->setGeometry(QRect(100, 460, 391, 20));
        show_label = new QLabel(HogGuiClass);
        show_label->setObjectName(QString::fromUtf8("show_label"));
        show_label->setGeometry(QRect(10, 10, 600, 400));
        show_label->setAcceptDrops(false);
        show_label->setStyleSheet(QString::fromUtf8("background-color: rgb(109, 109, 109);"));
        load_pushButton = new QPushButton(HogGuiClass);
        load_pushButton->setObjectName(QString::fromUtf8("load_pushButton"));
        load_pushButton->setGeometry(QRect(500, 420, 121, 61));
        label_4 = new QLabel(HogGuiClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 490, 61, 16));
        xml_lineEdit = new QLineEdit(HogGuiClass);
        xml_lineEdit->setObjectName(QString::fromUtf8("xml_lineEdit"));
        xml_lineEdit->setGeometry(QRect(100, 490, 391, 20));
        label_5 = new QLabel(HogGuiClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(670, 170, 51, 31));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        time_lcdNumber = new QLCDNumber(HogGuiClass);
        time_lcdNumber->setObjectName(QString::fromUtf8("time_lcdNumber"));
        time_lcdNumber->setGeometry(QRect(720, 170, 71, 31));
        time_lcdNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        label_6 = new QLabel(HogGuiClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(790, 170, 20, 31));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        sample_train = new QTabWidget(HogGuiClass);
        sample_train->setObjectName(QString::fromUtf8("sample_train"));
        sample_train->setGeometry(QRect(630, 200, 321, 301));
        sample_train->setStyleSheet(QString::fromUtf8(""));
        sample = new QWidget();
        sample->setObjectName(QString::fromUtf8("sample"));
        postiveinfo_lineEdit = new QLineEdit(sample);
        postiveinfo_lineEdit->setObjectName(QString::fromUtf8("postiveinfo_lineEdit"));
        postiveinfo_lineEdit->setGeometry(QRect(90, 20, 221, 20));
        negetiveinfo_lineEdit = new QLineEdit(sample);
        negetiveinfo_lineEdit->setObjectName(QString::fromUtf8("negetiveinfo_lineEdit"));
        negetiveinfo_lineEdit->setGeometry(QRect(90, 50, 221, 20));
        postive_pic_path_lineEdit = new QLineEdit(sample);
        postive_pic_path_lineEdit->setObjectName(QString::fromUtf8("postive_pic_path_lineEdit"));
        postive_pic_path_lineEdit->setGeometry(QRect(90, 80, 221, 20));
        negetive_pic_path_lineEdit = new QLineEdit(sample);
        negetive_pic_path_lineEdit->setObjectName(QString::fromUtf8("negetive_pic_path_lineEdit"));
        negetive_pic_path_lineEdit->setGeometry(QRect(90, 110, 221, 20));
        target_postive_pic_path_lineEdit = new QLineEdit(sample);
        target_postive_pic_path_lineEdit->setObjectName(QString::fromUtf8("target_postive_pic_path_lineEdit"));
        target_postive_pic_path_lineEdit->setGeometry(QRect(90, 140, 221, 20));
        target_negetive_pic_path_lineEdit = new QLineEdit(sample);
        target_negetive_pic_path_lineEdit->setObjectName(QString::fromUtf8("target_negetive_pic_path_lineEdit"));
        target_negetive_pic_path_lineEdit->setGeometry(QRect(90, 170, 221, 20));
        total_lineEdit = new QLineEdit(sample);
        total_lineEdit->setObjectName(QString::fromUtf8("total_lineEdit"));
        total_lineEdit->setGeometry(QRect(90, 200, 113, 20));
        create_pushButton = new QPushButton(sample);
        create_pushButton->setObjectName(QString::fromUtf8("create_pushButton"));
        create_pushButton->setGeometry(QRect(90, 230, 111, 41));
        label_7 = new QLabel(sample);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 20, 71, 16));
        label_7->setStyleSheet(QString::fromUtf8(""));
        label_8 = new QLabel(sample);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 50, 54, 16));
        label_9 = new QLabel(sample);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 80, 54, 16));
        label_10 = new QLabel(sample);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 112, 54, 20));
        label_11 = new QLabel(sample);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 140, 91, 21));
        label_12 = new QLabel(sample);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(0, 170, 91, 16));
        label_13 = new QLabel(sample);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 200, 54, 16));
        sample_train->addTab(sample, QString());
        train = new QWidget();
        train->setObjectName(QString::fromUtf8("train"));
        postive_infolineEdit = new QLineEdit(train);
        postive_infolineEdit->setObjectName(QString::fromUtf8("postive_infolineEdit"));
        postive_infolineEdit->setGeometry(QRect(100, 10, 211, 20));
        negetive_infolineEdit = new QLineEdit(train);
        negetive_infolineEdit->setObjectName(QString::fromUtf8("negetive_infolineEdit"));
        negetive_infolineEdit->setGeometry(QRect(100, 40, 211, 20));
        postive_pathlineEdit = new QLineEdit(train);
        postive_pathlineEdit->setObjectName(QString::fromUtf8("postive_pathlineEdit"));
        postive_pathlineEdit->setGeometry(QRect(100, 70, 211, 20));
        nengtive_pathlineEdit = new QLineEdit(train);
        nengtive_pathlineEdit->setObjectName(QString::fromUtf8("nengtive_pathlineEdit"));
        nengtive_pathlineEdit->setGeometry(QRect(100, 100, 211, 20));
        save_pathlineEdit = new QLineEdit(train);
        save_pathlineEdit->setObjectName(QString::fromUtf8("save_pathlineEdit"));
        save_pathlineEdit->setGeometry(QRect(100, 130, 211, 20));
        postive_numlineEdit = new QLineEdit(train);
        postive_numlineEdit->setObjectName(QString::fromUtf8("postive_numlineEdit"));
        postive_numlineEdit->setGeometry(QRect(100, 170, 41, 20));
        negetive_numlineEdit = new QLineEdit(train);
        negetive_numlineEdit->setObjectName(QString::fromUtf8("negetive_numlineEdit"));
        negetive_numlineEdit->setGeometry(QRect(100, 190, 41, 20));
        trainpushButton = new QPushButton(train);
        trainpushButton->setObjectName(QString::fromUtf8("trainpushButton"));
        trainpushButton->setGeometry(QRect(100, 220, 161, 51));
        pic_tatallineEdit = new QLineEdit(train);
        pic_tatallineEdit->setObjectName(QString::fromUtf8("pic_tatallineEdit"));
        pic_tatallineEdit->setGeometry(QRect(100, 150, 41, 20));
        label_14 = new QLabel(train);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 10, 81, 16));
        label_15 = new QLabel(train);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 40, 81, 16));
        label_16 = new QLabel(train);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 70, 91, 21));
        label_17 = new QLabel(train);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 100, 81, 16));
        label_18 = new QLabel(train);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 130, 81, 16));
        label_19 = new QLabel(train);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 151, 91, 21));
        label_20 = new QLabel(train);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 171, 71, 21));
        label_21 = new QLabel(train);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 192, 81, 20));
        sample_train->addTab(train, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        sample_train->addTab(tab, QString());

        retranslateUi(HogGuiClass);

        sample_train->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HogGuiClass);
    } // setupUi

    void retranslateUi(QDialog *HogGuiClass)
    {
        HogGuiClass->setWindowTitle(QApplication::translate("HogGuiClass", "HogGui", 0, QApplication::UnicodeUTF8));
        pic_pushButton->setText(QApplication::translate("HogGuiClass", "\345\233\276\347\211\207\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
        video_pushButton->setText(QApplication::translate("HogGuiClass", "\350\247\206\351\242\221\346\243\200\346\265\213", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HogGuiClass", "\346\243\200\346\265\213\345\210\260\347\232\204\344\272\272\346\225\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HogGuiClass", "\345\233\276\347\211\207\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HogGuiClass", "\350\247\206\351\242\221\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
        pic_path_lineEdit->setText(QApplication::translate("HogGuiClass", "D:/C++&&JAVA&&C&&OTHER/opencv/HOG/test.png", 0, QApplication::UnicodeUTF8));
        video_path_lineEdit->setText(QApplication::translate("HogGuiClass", "F:/Program Files/YouKu/Youku Files/download/zyhlc.flv", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        show_label->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        show_label->setText(QString());
        load_pushButton->setText(QApplication::translate("HogGuiClass", "\350\275\275\345\205\245\345\233\276\347\211\207/\350\247\206\351\242\221", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("HogGuiClass", "\345\210\206\347\261\273\345\231\250\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
        xml_lineEdit->setText(QApplication::translate("HogGuiClass", "E:/sample/resultfinnal.xml", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("HogGuiClass", "\346\243\200\346\265\213\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("HogGuiClass", " ms", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        sample->setWhatsThis(QApplication::translate("HogGuiClass", "\345\233\240\344\270\272\345\233\276\347\211\207\350\256\255\347\273\203\347\232\204\346\227\266\345\200\231\351\234\200\350\246\201\344\270\200\347\247\215\345\233\272\345\256\232\347\232\204\346\240\274\345\274\217\357\274\214\350\200\214\345\234\250\347\250\213\345\272\217\344\270\255\345\267\262\347\273\217\350\242\253\350\256\276\347\275\256\344\270\272\345\233\272\345\256\232\347\232\204\345\206\205\345\217\202\346\225\260\357\274\214\346\211\200\344\273\245\351\234\200\350\246\201\345\257\271\345\233\276\347\211\207\345\201\232\347\273\237\344\270\200\347\232\204\350\243\201\345\211\252\345\244\204\347\220\206\357\274\214\351\200\211\345\256\232\345\233\276\345\203\217\345\214\272\345\237\237\357\274\214\347\224\237\346\210\220\346\240\207\345\207\206\347\232\204\350\256\255\347\273\203\345\233\276\345\203\217\346\240\267\346\234\254\357\274\210\345\214\205\346\213\254\346\255\243\346\240\267\346\234\254\345\222\214\350\264\237\346\240\267\346\234\254\357\274\211\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        postiveinfo_lineEdit->setText(QApplication::translate("HogGuiClass", "E:/INRIAPerson/70X134H96/Test/pos/pos.txt", 0, QApplication::UnicodeUTF8));
        negetiveinfo_lineEdit->setText(QApplication::translate("HogGuiClass", "E:/INRIAPerson/Train/neg/neg.txt", 0, QApplication::UnicodeUTF8));
        postive_pic_path_lineEdit->setText(QApplication::translate("HogGuiClass", "E:/INRIAPerson/70X134H96/Test/pos/", 0, QApplication::UnicodeUTF8));
        negetive_pic_path_lineEdit->setText(QApplication::translate("HogGuiClass", "E:/INRIAPerson/Train/neg/", 0, QApplication::UnicodeUTF8));
        target_postive_pic_path_lineEdit->setText(QApplication::translate("HogGuiClass", "E:/sample/pos1/", 0, QApplication::UnicodeUTF8));
        target_negetive_pic_path_lineEdit->setText(QApplication::translate("HogGuiClass", "E:/sample/neg1/", 0, QApplication::UnicodeUTF8));
        total_lineEdit->setText(QApplication::translate("HogGuiClass", "10000", 0, QApplication::UnicodeUTF8));
        create_pushButton->setText(QApplication::translate("HogGuiClass", "\347\224\237\346\210\220", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("HogGuiClass", "pos.txt", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("HogGuiClass", "neg.txt", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("HogGuiClass", "pos.path", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("HogGuiClass", "neg.path", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("HogGuiClass", "target.pos.path", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("HogGuiClass", "target.neg.path", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("HogGuiClass", "total", 0, QApplication::UnicodeUTF8));
        sample_train->setTabText(sample_train->indexOf(sample), QApplication::translate("HogGuiClass", "\346\240\267\346\234\254\347\224\237\346\210\220", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        train->setWhatsThis(QApplication::translate("HogGuiClass", "\347\224\237\346\210\220\345\245\275\345\233\276\347\211\207\346\240\267\346\234\254\344\271\213\345\220\216\357\274\214\345\274\200\345\247\213\345\257\271\345\233\276\347\211\207\350\277\233\350\241\214\350\256\255\347\273\203\357\274\214\345\260\206\344\274\232\347\224\237\346\210\220\344\270\200\344\270\252\350\256\255\347\273\203\350\211\257\345\245\275\347\232\204\345\210\206\347\261\273\345\231\250\357\274\214\350\200\214\350\256\255\347\273\203\345\231\250\347\232\204\345\217\202\346\225\260\345\267\262\347\273\217\350\256\276\347\275\256\345\245\275", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        postive_infolineEdit->setText(QApplication::translate("HogGuiClass", "E:/sample/pos1/pos.txt", 0, QApplication::UnicodeUTF8));
        negetive_infolineEdit->setText(QApplication::translate("HogGuiClass", "E:/sample/neg1/neg.txt", 0, QApplication::UnicodeUTF8));
        postive_pathlineEdit->setText(QApplication::translate("HogGuiClass", "E:/sample/pos1/", 0, QApplication::UnicodeUTF8));
        nengtive_pathlineEdit->setText(QApplication::translate("HogGuiClass", "E:/sample/neg1/", 0, QApplication::UnicodeUTF8));
        save_pathlineEdit->setText(QApplication::translate("HogGuiClass", "E:/sample/", 0, QApplication::UnicodeUTF8));
        postive_numlineEdit->setText(QApplication::translate("HogGuiClass", "1126", 0, QApplication::UnicodeUTF8));
        negetive_numlineEdit->setText(QApplication::translate("HogGuiClass", "2436", 0, QApplication::UnicodeUTF8));
        trainpushButton->setText(QApplication::translate("HogGuiClass", "\345\274\200\345\247\213\350\256\255\347\273\203", 0, QApplication::UnicodeUTF8));
        pic_tatallineEdit->setText(QApplication::translate("HogGuiClass", "3562", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("HogGuiClass", "postive_info", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("HogGuiClass", "negetive_info", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("HogGuiClass", "postive_path", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("HogGuiClass", "nengtive_path", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("HogGuiClass", "save_path", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("HogGuiClass", "pic_tatal", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("HogGuiClass", "postive_num", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("HogGuiClass", "negetive_num", 0, QApplication::UnicodeUTF8));
        sample_train->setTabText(sample_train->indexOf(train), QApplication::translate("HogGuiClass", "\350\256\255\347\273\203", 0, QApplication::UnicodeUTF8));
        sample_train->setTabText(sample_train->indexOf(tab), QApplication::translate("HogGuiClass", "\347\273\237\350\256\241\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HogGuiClass: public Ui_HogGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOGGUI_H

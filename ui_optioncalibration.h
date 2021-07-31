/********************************************************************************
** Form generated from reading UI file 'optioncalibration.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONCALIBRATION_H
#define UI_OPTIONCALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>

QT_BEGIN_NAMESPACE

class Ui_OptionCalibration
{
public:
    QWidget *widget;
    MyLabelAnimated *l_calibration_back;
    MyLabelAnimated *l_calibration_state_button;
    QTextEdit *pt_calibration_state_text;
    QLabel *l_calibration_state_footer_text_1;
    QLabel *l_calibration_state_footer_text_2;
    QLabel *l_calibration_state;
    QLabel *l_calibration_state_progress_text;
    QProgressBar *pbar_calibration_state_progress;
    MyLabelAnimated *l_calibration_state_button_out;
    MyLabelAnimated *l_calibration_state_button_repeat;
    QLabel *l_calibration_state_error_tag;
    QLabel *l_calibration_state_error_text;

    void setupUi(QWidget *OptionCalibration)
    {
        if (OptionCalibration->objectName().isEmpty())
            OptionCalibration->setObjectName(QStringLiteral("OptionCalibration"));
        OptionCalibration->resize(320, 359);
        OptionCalibration->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(OptionCalibration);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 320, 359));
        widget->setStyleSheet(QStringLiteral("background-image: url(:/icons/main_menu/calibration_menu/background_calibration_menu.png);"));
        l_calibration_back = new MyLabelAnimated(widget);
        l_calibration_back->setObjectName(QStringLiteral("l_calibration_back"));
        l_calibration_back->setGeometry(QRect(0, 25, 320, 75));
        l_calibration_back->setStyleSheet(QLatin1String("border-image: url(:/icons/main_menu/calibration_menu/header_calibration_menu.png);\n"
"background-image: url(:/icons/general/fondo_transparente.png);"));
        l_calibration_state_button = new MyLabelAnimated(widget);
        l_calibration_state_button->setObjectName(QStringLiteral("l_calibration_state_button"));
        l_calibration_state_button->setGeometry(QRect(80, 220, 163, 70));
        l_calibration_state_button->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"border-image: url(:/icons/general/next_button.png);"));
        l_calibration_state_button->setScaledContents(true);
        pt_calibration_state_text = new QTextEdit(widget);
        pt_calibration_state_text->setObjectName(QStringLiteral("pt_calibration_state_text"));
        pt_calibration_state_text->setGeometry(QRect(20, 130, 281, 91));
        QFont font;
        font.setFamily(QStringLiteral("Swis721 Lt BT"));
        font.setPointSize(12);
        pt_calibration_state_text->setFont(font);
        pt_calibration_state_text->setStyleSheet(QLatin1String("QTextEdit { \n"
"	background-image: url(:/icons/general/fondo_transparente.png);\n"
"	color: rgb(28, 28, 28);\n"
"	border-radius: 3px;\n"
"	text-align: center;\n"
"}"));
        pt_calibration_state_text->setFrameShadow(QFrame::Plain);
        l_calibration_state_footer_text_1 = new QLabel(widget);
        l_calibration_state_footer_text_1->setObjectName(QStringLiteral("l_calibration_state_footer_text_1"));
        l_calibration_state_footer_text_1->setGeometry(QRect(60, 290, 201, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Swis721 Lt BT"));
        font1.setPointSize(14);
        l_calibration_state_footer_text_1->setFont(font1);
        l_calibration_state_footer_text_1->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"color:rgb(62, 167, 132);"));
        l_calibration_state_footer_text_1->setAlignment(Qt::AlignCenter);
        l_calibration_state_footer_text_2 = new QLabel(widget);
        l_calibration_state_footer_text_2->setObjectName(QStringLiteral("l_calibration_state_footer_text_2"));
        l_calibration_state_footer_text_2->setGeometry(QRect(60, 320, 201, 31));
        l_calibration_state_footer_text_2->setFont(font1);
        l_calibration_state_footer_text_2->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"color:rgb(62, 167, 132);"));
        l_calibration_state_footer_text_2->setAlignment(Qt::AlignCenter);
        l_calibration_state = new QLabel(widget);
        l_calibration_state->setObjectName(QStringLiteral("l_calibration_state"));
        l_calibration_state->setGeometry(QRect(60, 100, 201, 31));
        l_calibration_state->setFont(font1);
        l_calibration_state->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"color:rgb(62, 167, 132);"));
        l_calibration_state->setAlignment(Qt::AlignCenter);
        l_calibration_state_progress_text = new QLabel(widget);
        l_calibration_state_progress_text->setObjectName(QStringLiteral("l_calibration_state_progress_text"));
        l_calibration_state_progress_text->setGeometry(QRect(20, 120, 280, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Swis721 Lt BT"));
        font2.setPointSize(18);
        l_calibration_state_progress_text->setFont(font2);
        l_calibration_state_progress_text->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"color:rgb(62, 167, 132);"));
        l_calibration_state_progress_text->setAlignment(Qt::AlignCenter);
        pbar_calibration_state_progress = new QProgressBar(widget);
        pbar_calibration_state_progress->setObjectName(QStringLiteral("pbar_calibration_state_progress"));
        pbar_calibration_state_progress->setGeometry(QRect(20, 160, 280, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Swis721 BT"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        pbar_calibration_state_progress->setFont(font3);
        pbar_calibration_state_progress->setStyleSheet(QLatin1String(" QProgressBar::chunk {\n"
"	color: rgb(77, 77, 77);\n"
"     border-radius: 4px;\n"
"     background-color: #3ea784;\n"
" }\n"
"QProgressBar {\n"
"	 color: rgb(77, 77, 77);\n"
"     border-radius: 4px;\n"
"     background-color: #E3E3E3;\n"
" }"));
        pbar_calibration_state_progress->setValue(0);
        pbar_calibration_state_progress->setAlignment(Qt::AlignCenter);
        l_calibration_state_button_out = new MyLabelAnimated(widget);
        l_calibration_state_button_out->setObjectName(QStringLiteral("l_calibration_state_button_out"));
        l_calibration_state_button_out->setGeometry(QRect(160, 250, 163, 70));
        l_calibration_state_button_out->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"border-image: url(:/icons/general/exit_button.png);"));
        l_calibration_state_button_out->setScaledContents(true);
        l_calibration_state_button_repeat = new MyLabelAnimated(widget);
        l_calibration_state_button_repeat->setObjectName(QStringLiteral("l_calibration_state_button_repeat"));
        l_calibration_state_button_repeat->setGeometry(QRect(0, 250, 163, 70));
        l_calibration_state_button_repeat->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"border-image: url(:/icons/general/repeat_button.png);"));
        l_calibration_state_button_repeat->setScaledContents(true);
        l_calibration_state_error_tag = new QLabel(widget);
        l_calibration_state_error_tag->setObjectName(QStringLiteral("l_calibration_state_error_tag"));
        l_calibration_state_error_tag->setGeometry(QRect(10, 160, 280, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Swis721 Lt BT"));
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        l_calibration_state_error_tag->setFont(font4);
        l_calibration_state_error_tag->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"color:rgb(255, 50, 50);"));
        l_calibration_state_error_tag->setAlignment(Qt::AlignCenter);
        l_calibration_state_error_text = new QLabel(widget);
        l_calibration_state_error_text->setObjectName(QStringLiteral("l_calibration_state_error_text"));
        l_calibration_state_error_text->setGeometry(QRect(10, 200, 280, 31));
        QFont font5;
        font5.setFamily(QStringLiteral("Swis721 Lt BT"));
        font5.setPointSize(18);
        font5.setBold(false);
        font5.setWeight(50);
        l_calibration_state_error_text->setFont(font5);
        l_calibration_state_error_text->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"color:rgb(255, 50, 50);"));
        l_calibration_state_error_text->setAlignment(Qt::AlignCenter);

        retranslateUi(OptionCalibration);

        QMetaObject::connectSlotsByName(OptionCalibration);
    } // setupUi

    void retranslateUi(QWidget *OptionCalibration)
    {
        OptionCalibration->setWindowTitle(QApplication::translate("OptionCalibration", "Form", nullptr));
        l_calibration_back->setText(QString());
        l_calibration_state_button->setText(QString());
#ifndef QT_NO_TOOLTIP
        pt_calibration_state_text->setToolTip(QApplication::translate("OptionCalibration", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pt_calibration_state_text->setHtml(QApplication::translate("OptionCalibration", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Swis721 Lt BT'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">El dispositivo deber\303\241 realizar una medici\303\263n m\303\241xima y m\303\255nima. Para ello siga las instruciones durante el progreso una vez iniciado</p></body></html>", nullptr));
        l_calibration_state_footer_text_1->setText(QApplication::translate("OptionCalibration", "\303\232ltima calibraci\303\263n", nullptr));
        l_calibration_state_footer_text_2->setText(QApplication::translate("OptionCalibration", "12 dic. 2020 17:52", nullptr));
        l_calibration_state->setText(QApplication::translate("OptionCalibration", "Informaci\303\263n", nullptr));
        l_calibration_state_progress_text->setText(QApplication::translate("OptionCalibration", "Medici\303\263n m\303\255nima", nullptr));
        l_calibration_state_button_out->setText(QString());
        l_calibration_state_button_repeat->setText(QString());
        l_calibration_state_error_tag->setText(QApplication::translate("OptionCalibration", "Incompleta", nullptr));
        l_calibration_state_error_text->setText(QApplication::translate("OptionCalibration", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionCalibration: public Ui_OptionCalibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONCALIBRATION_H

/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>
#include <mywidgetanimated.h>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    MyWidgetAnimated *widget_menu;
    MyLabelAnimated *l_calibration;
    MyLabelAnimated *l_general;
    MyLabelAnimated *l_date_time;
    MyLabelAnimated *l_alarm_limit;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(320, 345);
        MainMenu->setStyleSheet(QStringLiteral(""));
        widget_menu = new MyWidgetAnimated(MainMenu);
        widget_menu->setObjectName(QStringLiteral("widget_menu"));
        widget_menu->setGeometry(QRect(0, 0, 320, 345));
        widget_menu->setStyleSheet(QStringLiteral("background-image: url(:/icons/main_screen/widget_settings_on.png);"));
        l_calibration = new MyLabelAnimated(widget_menu);
        l_calibration->setObjectName(QStringLiteral("l_calibration"));
        l_calibration->setGeometry(QRect(0, 140, 320, 84));
        QPalette palette;
        QBrush brush(QColor(77, 77, 77, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(164, 166, 168, 96));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_calibration->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(20);
        l_calibration->setFont(font);
        l_calibration->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"border-image: url(:/icons/main_menu/calibration_menu/calibration_button.png);"));
        l_calibration->setAlignment(Qt::AlignCenter);
        l_general = new MyLabelAnimated(widget_menu);
        l_general->setObjectName(QStringLiteral("l_general"));
        l_general->setGeometry(QRect(0, 270, 320, 75));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_general->setPalette(palette1);
        l_general->setFont(font);
        l_general->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"border-image: url(:/icons/main_menu/general_menu/general_button.png);"));
        l_general->setAlignment(Qt::AlignCenter);
        l_date_time = new MyLabelAnimated(widget_menu);
        l_date_time->setObjectName(QStringLiteral("l_date_time"));
        l_date_time->setGeometry(QRect(0, 205, 320, 83));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_date_time->setPalette(palette2);
        l_date_time->setFont(font);
        l_date_time->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"border-image: url(:/icons/main_menu/date_time_menu/date_time_button.png);"));
        l_date_time->setAlignment(Qt::AlignCenter);
        l_alarm_limit = new MyLabelAnimated(widget_menu);
        l_alarm_limit->setObjectName(QStringLiteral("l_alarm_limit"));
        l_alarm_limit->setGeometry(QRect(0, 75, 320, 83));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_alarm_limit->setPalette(palette3);
        l_alarm_limit->setFont(font);
        l_alarm_limit->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"border-image: url(:/icons/main_menu/alarm_limit_menu/alarm_limit_button.png);"));
        l_alarm_limit->setAlignment(Qt::AlignCenter);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "Form", nullptr));
        l_calibration->setText(QString());
        l_general->setText(QString());
        l_date_time->setText(QString());
        l_alarm_limit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H

/********************************************************************************
** Form generated from reading UI file 'optiondatetime.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONDATETIME_H
#define UI_OPTIONDATETIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>

QT_BEGIN_NAMESPACE

class Ui_OptionDateTime
{
public:
    MyLabelAnimated *l_date_time_back;
    MyLabelAnimated *l_define_date;
    MyLabelAnimated *l_define_time;
    QLabel *label_2;
    MyLabelAnimated *l_24_hours;
    MyLabelAnimated *l_12_hours;

    void setupUi(QWidget *OptionDateTime)
    {
        if (OptionDateTime->objectName().isEmpty())
            OptionDateTime->setObjectName(QStringLiteral("OptionDateTime"));
        OptionDateTime->resize(320, 320);
        OptionDateTime->setStyleSheet(QStringLiteral(""));
        l_date_time_back = new MyLabelAnimated(OptionDateTime);
        l_date_time_back->setObjectName(QStringLiteral("l_date_time_back"));
        l_date_time_back->setGeometry(QRect(0, 0, 320, 75));
        l_date_time_back->setStyleSheet(QStringLiteral("border-image: url(:/icons/main_menu/date_time_menu/header_date_time_menu.png);"));
        l_define_date = new MyLabelAnimated(OptionDateTime);
        l_define_date->setObjectName(QStringLiteral("l_define_date"));
        l_define_date->setGeometry(QRect(0, 55, 320, 84));
        QPalette palette;
        QBrush brush(QColor(77, 77, 77, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(164, 166, 168, 96));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_define_date->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(20);
        l_define_date->setFont(font);
        l_define_date->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"border-image: url(:/icons/main_menu/date_time_menu/define_date_button.png);"));
        l_define_date->setAlignment(Qt::AlignCenter);
        l_define_time = new MyLabelAnimated(OptionDateTime);
        l_define_time->setObjectName(QStringLiteral("l_define_time"));
        l_define_time->setGeometry(QRect(0, 118, 320, 84));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        l_define_time->setPalette(palette1);
        l_define_time->setFont(font);
        l_define_time->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"border-image: url(:/icons/main_menu/date_time_menu/define_hour_button.png);"));
        l_define_time->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(OptionDateTime);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 172, 320, 148));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/icons/main_menu/date_time_menu/date_format_button.png);"));
        l_24_hours = new MyLabelAnimated(OptionDateTime);
        l_24_hours->setObjectName(QStringLiteral("l_24_hours"));
        l_24_hours->setGeometry(QRect(0, 250, 164, 71));
        l_24_hours->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"border-image: url(:/icons/main_menu/date_time_menu/24_hours_on.png);"));
        l_12_hours = new MyLabelAnimated(OptionDateTime);
        l_12_hours->setObjectName(QStringLiteral("l_12_hours"));
        l_12_hours->setGeometry(QRect(160, 250, 163, 71));
        l_12_hours->setStyleSheet(QLatin1String("border-image: url(:/icons/main_menu/date_time_menu/12_hours_off.png);\n"
"background-image: url(:/icons/general/fondo_transparente.png);"));
        l_date_time_back->raise();
        l_define_date->raise();
        label_2->raise();
        l_24_hours->raise();
        l_12_hours->raise();
        l_define_time->raise();

        retranslateUi(OptionDateTime);

        QMetaObject::connectSlotsByName(OptionDateTime);
    } // setupUi

    void retranslateUi(QWidget *OptionDateTime)
    {
        OptionDateTime->setWindowTitle(QApplication::translate("OptionDateTime", "Form", nullptr));
        l_date_time_back->setText(QString());
        l_define_date->setText(QString());
        l_define_time->setText(QString());
        label_2->setText(QString());
        l_24_hours->setText(QString());
        l_12_hours->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OptionDateTime: public Ui_OptionDateTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDATETIME_H

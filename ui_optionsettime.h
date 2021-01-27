/********************************************************************************
** Form generated from reading UI file 'optionsettime.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSETTIME_H
#define UI_OPTIONSETTIME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>

QT_BEGIN_NAMESPACE

class Ui_OptionSetTime
{
public:
    QWidget *widget;
    QPushButton *pb_minutes_up;
    QLabel *l_hours_value;
    MyLabelAnimated *l_save;
    QPushButton *pb_hours_up;
    MyLabelAnimated *l_define_time_back;
    QPushButton *pb_minutes_down;
    QPushButton *pb_hours_down;
    QLabel *l_minutes_value;
    QLabel *l_max_value_2;

    void setupUi(QWidget *OptionSetTime)
    {
        if (OptionSetTime->objectName().isEmpty())
            OptionSetTime->setObjectName(QStringLiteral("OptionSetTime"));
        OptionSetTime->resize(320, 314);
        widget = new QWidget(OptionSetTime);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 320, 314));
        widget->setStyleSheet(QLatin1String("border-image: url(:/icons/main_menu/alarm_limit_menu/background_alarm_limit_menu.png);\n"
"background-image: url(:/icons/general/fondo_transparente.png);"));
        pb_minutes_up = new QPushButton(widget);
        pb_minutes_up->setObjectName(QStringLiteral("pb_minutes_up"));
        pb_minutes_up->setGeometry(QRect(190, 70, 80, 61));
        pb_minutes_up->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/general/up_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_minutes_up->setIcon(icon);
        pb_minutes_up->setIconSize(QSize(40, 40));
        pb_minutes_up->setFlat(true);
        l_hours_value = new QLabel(widget);
        l_hours_value->setObjectName(QStringLiteral("l_hours_value"));
        l_hours_value->setGeometry(QRect(60, 120, 61, 61));
        QPalette palette;
        QBrush brush(QColor(62, 167, 132, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(164, 166, 168, 96));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_hours_value->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Swis721 Cn BT"));
        font.setPointSize(30);
        font.setBold(false);
        font.setWeight(50);
        l_hours_value->setFont(font);
        l_hours_value->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        l_hours_value->setAlignment(Qt::AlignCenter);
        l_save = new MyLabelAnimated(widget);
        l_save->setObjectName(QStringLiteral("l_save"));
        l_save->setGeometry(QRect(80, 240, 163, 71));
        l_save->setStyleSheet(QLatin1String("border-image: url(:/icons/general/save_button.png);\n"
"background-image: url(:/icons/general/fondo_transparente.png);"));
        pb_hours_up = new QPushButton(widget);
        pb_hours_up->setObjectName(QStringLiteral("pb_hours_up"));
        pb_hours_up->setGeometry(QRect(50, 70, 80, 61));
        pb_hours_up->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        pb_hours_up->setIcon(icon);
        pb_hours_up->setIconSize(QSize(40, 40));
        pb_hours_up->setFlat(true);
        l_define_time_back = new MyLabelAnimated(widget);
        l_define_time_back->setObjectName(QStringLiteral("l_define_time_back"));
        l_define_time_back->setGeometry(QRect(0, 0, 320, 73));
        QPalette palette1;
        l_define_time_back->setPalette(palette1);
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        font1.setPointSize(20);
        l_define_time_back->setFont(font1);
        l_define_time_back->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
""));
        l_define_time_back->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        l_define_time_back->setMargin(6);
        pb_minutes_down = new QPushButton(widget);
        pb_minutes_down->setObjectName(QStringLiteral("pb_minutes_down"));
        pb_minutes_down->setGeometry(QRect(190, 170, 80, 61));
        pb_minutes_down->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/general/down_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_minutes_down->setIcon(icon1);
        pb_minutes_down->setIconSize(QSize(40, 40));
        pb_minutes_down->setFlat(true);
        pb_hours_down = new QPushButton(widget);
        pb_hours_down->setObjectName(QStringLiteral("pb_hours_down"));
        pb_hours_down->setGeometry(QRect(50, 170, 80, 61));
        pb_hours_down->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        pb_hours_down->setIcon(icon1);
        pb_hours_down->setIconSize(QSize(40, 40));
        pb_hours_down->setFlat(true);
        l_minutes_value = new QLabel(widget);
        l_minutes_value->setObjectName(QStringLiteral("l_minutes_value"));
        l_minutes_value->setGeometry(QRect(200, 120, 61, 61));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_minutes_value->setPalette(palette2);
        l_minutes_value->setFont(font);
        l_minutes_value->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        l_minutes_value->setAlignment(Qt::AlignCenter);
        l_max_value_2 = new QLabel(widget);
        l_max_value_2->setObjectName(QStringLiteral("l_max_value_2"));
        l_max_value_2->setGeometry(QRect(140, 120, 41, 61));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_max_value_2->setPalette(palette3);
        l_max_value_2->setFont(font);
        l_max_value_2->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        l_max_value_2->setAlignment(Qt::AlignCenter);

        retranslateUi(OptionSetTime);

        QMetaObject::connectSlotsByName(OptionSetTime);
    } // setupUi

    void retranslateUi(QWidget *OptionSetTime)
    {
        OptionSetTime->setWindowTitle(QApplication::translate("OptionSetTime", "Form", nullptr));
        pb_minutes_up->setText(QString());
        l_hours_value->setText(QApplication::translate("OptionSetTime", "16", nullptr));
        l_save->setText(QString());
        pb_hours_up->setText(QString());
        l_define_time_back->setText(QApplication::translate("OptionSetTime", "Definir Hora", nullptr));
        pb_minutes_down->setText(QString());
        pb_hours_down->setText(QString());
        l_minutes_value->setText(QApplication::translate("OptionSetTime", "28", nullptr));
        l_max_value_2->setText(QApplication::translate("OptionSetTime", ":", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionSetTime: public Ui_OptionSetTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSETTIME_H

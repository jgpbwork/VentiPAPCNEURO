/********************************************************************************
** Form generated from reading UI file 'optionsetdate.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSETDATE_H
#define UI_OPTIONSETDATE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>

QT_BEGIN_NAMESPACE

class Ui_OptionSetDate
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
    QPushButton *pb_minutes_up_2;
    QPushButton *pb_minutes_down_2;
    QLabel *l_minutes_value_2;

    void setupUi(QWidget *OptionSetDate)
    {
        if (OptionSetDate->objectName().isEmpty())
            OptionSetDate->setObjectName(QStringLiteral("OptionSetDate"));
        OptionSetDate->resize(320, 314);
        widget = new QWidget(OptionSetDate);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 320, 314));
        widget->setStyleSheet(QLatin1String("border-image: url(:/icons/main_menu/alarm_limit_menu/background_alarm_limit_menu.png);\n"
"background-image: url(:/icons/general/fondo_transparente.png);"));
        pb_minutes_up = new QPushButton(widget);
        pb_minutes_up->setObjectName(QStringLiteral("pb_minutes_up"));
        pb_minutes_up->setGeometry(QRect(120, 70, 80, 61));
        pb_minutes_up->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/general/up_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_minutes_up->setIcon(icon);
        pb_minutes_up->setIconSize(QSize(40, 40));
        pb_minutes_up->setFlat(true);
        l_hours_value = new QLabel(widget);
        l_hours_value->setObjectName(QStringLiteral("l_hours_value"));
        l_hours_value->setGeometry(QRect(20, 120, 61, 61));
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
        pb_hours_up->setGeometry(QRect(10, 70, 80, 61));
        pb_hours_up->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        pb_hours_up->setIcon(icon);
        pb_hours_up->setIconSize(QSize(40, 40));
        pb_hours_up->setFlat(true);
        l_define_time_back = new MyLabelAnimated(widget);
        l_define_time_back->setObjectName(QStringLiteral("l_define_time_back"));
        l_define_time_back->setGeometry(QRect(0, 0, 320, 73));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
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
        pb_minutes_down->setGeometry(QRect(120, 170, 80, 61));
        pb_minutes_down->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/general/down_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_minutes_down->setIcon(icon1);
        pb_minutes_down->setIconSize(QSize(40, 40));
        pb_minutes_down->setFlat(true);
        pb_hours_down = new QPushButton(widget);
        pb_hours_down->setObjectName(QStringLiteral("pb_hours_down"));
        pb_hours_down->setGeometry(QRect(10, 170, 80, 61));
        pb_hours_down->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        pb_hours_down->setIcon(icon1);
        pb_hours_down->setIconSize(QSize(40, 40));
        pb_hours_down->setFlat(true);
        l_minutes_value = new QLabel(widget);
        l_minutes_value->setObjectName(QStringLiteral("l_minutes_value"));
        l_minutes_value->setGeometry(QRect(100, 120, 121, 61));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_minutes_value->setPalette(palette2);
        l_minutes_value->setFont(font);
        l_minutes_value->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        l_minutes_value->setAlignment(Qt::AlignCenter);
        pb_minutes_up_2 = new QPushButton(widget);
        pb_minutes_up_2->setObjectName(QStringLiteral("pb_minutes_up_2"));
        pb_minutes_up_2->setGeometry(QRect(230, 70, 80, 61));
        pb_minutes_up_2->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        pb_minutes_up_2->setIcon(icon);
        pb_minutes_up_2->setIconSize(QSize(40, 40));
        pb_minutes_up_2->setFlat(true);
        pb_minutes_down_2 = new QPushButton(widget);
        pb_minutes_down_2->setObjectName(QStringLiteral("pb_minutes_down_2"));
        pb_minutes_down_2->setGeometry(QRect(230, 170, 80, 61));
        pb_minutes_down_2->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        pb_minutes_down_2->setIcon(icon1);
        pb_minutes_down_2->setIconSize(QSize(40, 40));
        pb_minutes_down_2->setFlat(true);
        l_minutes_value_2 = new QLabel(widget);
        l_minutes_value_2->setObjectName(QStringLiteral("l_minutes_value_2"));
        l_minutes_value_2->setGeometry(QRect(220, 120, 101, 61));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_minutes_value_2->setPalette(palette3);
        l_minutes_value_2->setFont(font);
        l_minutes_value_2->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        l_minutes_value_2->setAlignment(Qt::AlignCenter);

        retranslateUi(OptionSetDate);

        QMetaObject::connectSlotsByName(OptionSetDate);
    } // setupUi

    void retranslateUi(QWidget *OptionSetDate)
    {
        OptionSetDate->setWindowTitle(QApplication::translate("OptionSetDate", "Form", nullptr));
        pb_minutes_up->setText(QString());
        l_hours_value->setText(QApplication::translate("OptionSetDate", "26", nullptr));
        l_save->setText(QString());
        pb_hours_up->setText(QString());
        l_define_time_back->setText(QApplication::translate("OptionSetDate", "Definir Fecha", nullptr));
        pb_minutes_down->setText(QString());
        pb_hours_down->setText(QString());
        l_minutes_value->setText(QApplication::translate("OptionSetDate", "Enero", nullptr));
        pb_minutes_up_2->setText(QString());
        pb_minutes_down_2->setText(QString());
        l_minutes_value_2->setText(QApplication::translate("OptionSetDate", "2021", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionSetDate: public Ui_OptionSetDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSETDATE_H

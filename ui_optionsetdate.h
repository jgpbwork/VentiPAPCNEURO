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
    QPushButton *pb_month_up;
    QLabel *l_day_value;
    MyLabelAnimated *l_save;
    QPushButton *pb_day_up;
    MyLabelAnimated *l_define_date_back;
    QPushButton *pb_month_down;
    QPushButton *pb_day_down;
    QLabel *l_month_value;
    QPushButton *pb_year_up;
    QPushButton *pb_year_down;
    QLabel *l_year_value;

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
        pb_month_up = new QPushButton(widget);
        pb_month_up->setObjectName(QStringLiteral("pb_month_up"));
        pb_month_up->setGeometry(QRect(120, 70, 80, 61));
        pb_month_up->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/general/up_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_month_up->setIcon(icon);
        pb_month_up->setIconSize(QSize(40, 40));
        pb_month_up->setFlat(true);
        l_day_value = new QLabel(widget);
        l_day_value->setObjectName(QStringLiteral("l_day_value"));
        l_day_value->setGeometry(QRect(20, 120, 61, 61));
        QPalette palette;
        QBrush brush(QColor(62, 167, 132, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(164, 166, 168, 96));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_day_value->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Swis721 Cn BT"));
        font.setPointSize(30);
        font.setBold(false);
        font.setWeight(50);
        l_day_value->setFont(font);
        l_day_value->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        l_day_value->setAlignment(Qt::AlignCenter);
        l_save = new MyLabelAnimated(widget);
        l_save->setObjectName(QStringLiteral("l_save"));
        l_save->setGeometry(QRect(80, 240, 163, 71));
        l_save->setStyleSheet(QLatin1String("border-image: url(:/icons/general/save_button.png);\n"
"background-image: url(:/icons/general/fondo_transparente.png);"));
        pb_day_up = new QPushButton(widget);
        pb_day_up->setObjectName(QStringLiteral("pb_day_up"));
        pb_day_up->setGeometry(QRect(10, 70, 80, 61));
        pb_day_up->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        pb_day_up->setIcon(icon);
        pb_day_up->setIconSize(QSize(40, 40));
        pb_day_up->setFlat(true);
        l_define_date_back = new MyLabelAnimated(widget);
        l_define_date_back->setObjectName(QStringLiteral("l_define_date_back"));
        l_define_date_back->setGeometry(QRect(0, 0, 320, 73));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_define_date_back->setPalette(palette1);
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        font1.setPointSize(20);
        l_define_date_back->setFont(font1);
        l_define_date_back->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
""));
        l_define_date_back->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        l_define_date_back->setMargin(6);
        pb_month_down = new QPushButton(widget);
        pb_month_down->setObjectName(QStringLiteral("pb_month_down"));
        pb_month_down->setGeometry(QRect(120, 170, 80, 61));
        pb_month_down->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/general/down_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_month_down->setIcon(icon1);
        pb_month_down->setIconSize(QSize(40, 40));
        pb_month_down->setFlat(true);
        pb_day_down = new QPushButton(widget);
        pb_day_down->setObjectName(QStringLiteral("pb_day_down"));
        pb_day_down->setGeometry(QRect(10, 170, 80, 61));
        pb_day_down->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        pb_day_down->setIcon(icon1);
        pb_day_down->setIconSize(QSize(40, 40));
        pb_day_down->setFlat(true);
        l_month_value = new QLabel(widget);
        l_month_value->setObjectName(QStringLiteral("l_month_value"));
        l_month_value->setGeometry(QRect(100, 120, 121, 61));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_month_value->setPalette(palette2);
        l_month_value->setFont(font);
        l_month_value->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        l_month_value->setAlignment(Qt::AlignCenter);
        pb_year_up = new QPushButton(widget);
        pb_year_up->setObjectName(QStringLiteral("pb_year_up"));
        pb_year_up->setGeometry(QRect(230, 70, 80, 61));
        pb_year_up->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        pb_year_up->setIcon(icon);
        pb_year_up->setIconSize(QSize(40, 40));
        pb_year_up->setFlat(true);
        pb_year_down = new QPushButton(widget);
        pb_year_down->setObjectName(QStringLiteral("pb_year_down"));
        pb_year_down->setGeometry(QRect(230, 170, 80, 61));
        pb_year_down->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        pb_year_down->setIcon(icon1);
        pb_year_down->setIconSize(QSize(40, 40));
        pb_year_down->setFlat(true);
        l_year_value = new QLabel(widget);
        l_year_value->setObjectName(QStringLiteral("l_year_value"));
        l_year_value->setGeometry(QRect(220, 120, 101, 61));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_year_value->setPalette(palette3);
        l_year_value->setFont(font);
        l_year_value->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        l_year_value->setAlignment(Qt::AlignCenter);

        retranslateUi(OptionSetDate);

        QMetaObject::connectSlotsByName(OptionSetDate);
    } // setupUi

    void retranslateUi(QWidget *OptionSetDate)
    {
        OptionSetDate->setWindowTitle(QApplication::translate("OptionSetDate", "Form", nullptr));
        pb_month_up->setText(QString());
        l_day_value->setText(QApplication::translate("OptionSetDate", "26", nullptr));
        l_save->setText(QString());
        pb_day_up->setText(QString());
        l_define_date_back->setText(QApplication::translate("OptionSetDate", "Definir Fecha", nullptr));
        pb_month_down->setText(QString());
        pb_day_down->setText(QString());
        l_month_value->setText(QApplication::translate("OptionSetDate", "Enero", nullptr));
        pb_year_up->setText(QString());
        pb_year_down->setText(QString());
        l_year_value->setText(QApplication::translate("OptionSetDate", "2021", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionSetDate: public Ui_OptionSetDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSETDATE_H

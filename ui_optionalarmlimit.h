/********************************************************************************
** Form generated from reading UI file 'optionalarmlimit.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONALARMLIMIT_H
#define UI_OPTIONALARMLIMIT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>

QT_BEGIN_NAMESPACE

class Ui_OptionAlarmLimit
{
public:
    QWidget *widget;
    QLabel *l_min_value_4;
    QPushButton *pb_max_limit_up;
    QLabel *l_min_value;
    MyLabelAnimated *l_save;
    QPushButton *pb_min_limit_up;
    QLabel *l_alarm_limit_back;
    QPushButton *pb_max_limit_down;
    QPushButton *pb_min_limit_down;
    QLabel *l_min_value_3;
    QLabel *l_max_value;

    void setupUi(QWidget *OptionAlarmLimit)
    {
        if (OptionAlarmLimit->objectName().isEmpty())
            OptionAlarmLimit->setObjectName(QStringLiteral("OptionAlarmLimit"));
        OptionAlarmLimit->resize(320, 314);
        OptionAlarmLimit->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(OptionAlarmLimit);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 320, 314));
        widget->setStyleSheet(QLatin1String("border-image: url(:/icons/main_menu/alarm_limit_menu/background_alarm_limit_menu.png);\n"
"background-image: url(:/icons/general/fondo_transparente.png);"));
        l_min_value_4 = new QLabel(widget);
        l_min_value_4->setObjectName(QStringLiteral("l_min_value_4"));
        l_min_value_4->setGeometry(QRect(170, 130, 61, 41));
        QPalette palette;
        QBrush brush(QColor(62, 167, 132, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(164, 166, 168, 96));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_min_value_4->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Swis721 Cn BT"));
        font.setPointSize(24);
        font.setBold(false);
        font.setWeight(50);
        l_min_value_4->setFont(font);
        l_min_value_4->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        l_min_value_4->setAlignment(Qt::AlignCenter);
        pb_max_limit_up = new QPushButton(widget);
        pb_max_limit_up->setObjectName(QStringLiteral("pb_max_limit_up"));
        pb_max_limit_up->setGeometry(QRect(220, 70, 80, 61));
        pb_max_limit_up->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/general/up_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_max_limit_up->setIcon(icon);
        pb_max_limit_up->setIconSize(QSize(40, 40));
        pb_max_limit_up->setFlat(true);
        l_min_value = new QLabel(widget);
        l_min_value->setObjectName(QStringLiteral("l_min_value"));
        l_min_value->setGeometry(QRect(70, 120, 61, 61));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_min_value->setPalette(palette1);
        QFont font1;
        font1.setFamily(QStringLiteral("Swis721 Cn BT"));
        font1.setPointSize(30);
        font1.setBold(false);
        font1.setWeight(50);
        l_min_value->setFont(font1);
        l_min_value->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        l_min_value->setAlignment(Qt::AlignCenter);
        l_save = new MyLabelAnimated(widget);
        l_save->setObjectName(QStringLiteral("l_save"));
        l_save->setGeometry(QRect(80, 240, 163, 71));
        l_save->setStyleSheet(QLatin1String("border-image: url(:/icons/general/save_button.png);\n"
"background-image: url(:/icons/general/fondo_transparente.png);"));
        pb_min_limit_up = new QPushButton(widget);
        pb_min_limit_up->setObjectName(QStringLiteral("pb_min_limit_up"));
        pb_min_limit_up->setGeometry(QRect(60, 70, 80, 61));
        pb_min_limit_up->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        pb_min_limit_up->setIcon(icon);
        pb_min_limit_up->setIconSize(QSize(40, 40));
        pb_min_limit_up->setFlat(true);
        l_alarm_limit_back = new QLabel(widget);
        l_alarm_limit_back->setObjectName(QStringLiteral("l_alarm_limit_back"));
        l_alarm_limit_back->setGeometry(QRect(0, 0, 320, 73));
        l_alarm_limit_back->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"border-image: url(:/icons/main_menu/alarm_limit_menu/header_alarm_limit_menu.png);"));
        pb_max_limit_down = new QPushButton(widget);
        pb_max_limit_down->setObjectName(QStringLiteral("pb_max_limit_down"));
        pb_max_limit_down->setGeometry(QRect(220, 170, 80, 61));
        pb_max_limit_down->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/general/down_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_max_limit_down->setIcon(icon1);
        pb_max_limit_down->setIconSize(QSize(40, 40));
        pb_max_limit_down->setFlat(true);
        pb_min_limit_down = new QPushButton(widget);
        pb_min_limit_down->setObjectName(QStringLiteral("pb_min_limit_down"));
        pb_min_limit_down->setGeometry(QRect(60, 170, 80, 61));
        pb_min_limit_down->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        pb_min_limit_down->setIcon(icon1);
        pb_min_limit_down->setIconSize(QSize(40, 40));
        pb_min_limit_down->setFlat(true);
        l_min_value_3 = new QLabel(widget);
        l_min_value_3->setObjectName(QStringLiteral("l_min_value_3"));
        l_min_value_3->setGeometry(QRect(10, 130, 61, 41));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_min_value_3->setPalette(palette2);
        l_min_value_3->setFont(font);
        l_min_value_3->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        l_min_value_3->setAlignment(Qt::AlignCenter);
        l_max_value = new QLabel(widget);
        l_max_value->setObjectName(QStringLiteral("l_max_value"));
        l_max_value->setGeometry(QRect(230, 120, 61, 61));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_max_value->setPalette(palette3);
        l_max_value->setFont(font1);
        l_max_value->setStyleSheet(QStringLiteral("border-image: url(:/icons/general/fondo_transparente.png);"));
        l_max_value->setAlignment(Qt::AlignCenter);

        retranslateUi(OptionAlarmLimit);

        QMetaObject::connectSlotsByName(OptionAlarmLimit);
    } // setupUi

    void retranslateUi(QWidget *OptionAlarmLimit)
    {
        OptionAlarmLimit->setWindowTitle(QApplication::translate("OptionAlarmLimit", "Form", nullptr));
        l_min_value_4->setText(QApplication::translate("OptionAlarmLimit", "m\303\241x", nullptr));
        pb_max_limit_up->setText(QString());
        l_min_value->setText(QApplication::translate("OptionAlarmLimit", "21", nullptr));
        l_save->setText(QString());
        pb_min_limit_up->setText(QString());
        l_alarm_limit_back->setText(QString());
        pb_max_limit_down->setText(QString());
        pb_min_limit_down->setText(QString());
        l_min_value_3->setText(QApplication::translate("OptionAlarmLimit", "m\303\255n", nullptr));
        l_max_value->setText(QApplication::translate("OptionAlarmLimit", "28", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionAlarmLimit: public Ui_OptionAlarmLimit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONALARMLIMIT_H

/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mywidgetanimated.h>

QT_BEGIN_NAMESPACE

class Ui_MainScreen
{
public:
    QWidget *widget_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *l_oxygen_value;
    QWidget *widget_max_value;
    QVBoxLayout *verticalLayout;
    QLabel *l_max_value;
    QLabel *label_11;
    QWidget *widget_min_value;
    QVBoxLayout *verticalLayout_2;
    QLabel *l_min_value;
    QLabel *label_13;
    QWidget *widget_o2_porcentile;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *widget_o2_porcentile_mini;
    QLabel *label_10;
    QLabel *label_12;
    MyWidgetAnimated *widget_menu_off;

    void setupUi(QWidget *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName(QStringLiteral("MainScreen"));
        MainScreen->resize(320, 480);
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(20);
        MainScreen->setFont(font);
        MainScreen->setStyleSheet(QStringLiteral("background-image: url(:/icons/main_screen/background.png);"));
        widget_2 = new QWidget(MainScreen);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 320, 68));
        widget_2->setStyleSheet(QStringLiteral("background-image: url(:/icons/main_screen/header.png);"));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 81, 31));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(164, 166, 168, 96));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label->setPalette(palette);
        QFont font1;
        font1.setFamily(QStringLiteral("Swis721 Cn BT"));
        font1.setPointSize(20);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(5, 35, 151, 21));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_2->setPalette(palette1);
        QFont font2;
        font2.setFamily(QStringLiteral("Swis721 Cn BT"));
        font2.setPointSize(14);
        label_2->setFont(font2);
        label_2->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(225, 35, 90, 21));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_3->setPalette(palette2);
        label_3->setFont(font2);
        label_3->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(245, 5, 70, 26));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_4->setPalette(palette3);
        QFont font3;
        font3.setFamily(QStringLiteral("Segoe UI"));
        font3.setPointSize(14);
        label_4->setFont(font3);
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/general/battery_75.png")));
        label_4->setScaledContents(true);
        label_4->setAlignment(Qt::AlignCenter);
        l_oxygen_value = new QLabel(MainScreen);
        l_oxygen_value->setObjectName(QStringLiteral("l_oxygen_value"));
        l_oxygen_value->setGeometry(QRect(10, 130, 291, 221));
        QPalette palette4;
        QBrush brush2(QColor(62, 167, 132, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_oxygen_value->setPalette(palette4);
        QFont font4;
        font4.setFamily(QStringLiteral("Swis721 Cn BT"));
        font4.setPointSize(150);
        font4.setBold(false);
        font4.setWeight(50);
        l_oxygen_value->setFont(font4);
        l_oxygen_value->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"\n"
""));
        l_oxygen_value->setPixmap(QPixmap(QString::fromUtf8(":/icons/main_menu/calibration_menu/ok.png")));
        l_oxygen_value->setScaledContents(true);
        l_oxygen_value->setAlignment(Qt::AlignCenter);
        widget_max_value = new QWidget(MainScreen);
        widget_max_value->setObjectName(QStringLiteral("widget_max_value"));
        widget_max_value->setGeometry(QRect(20, 70, 50, 71));
        widget_max_value->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        verticalLayout = new QVBoxLayout(widget_max_value);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        l_max_value = new QLabel(widget_max_value);
        l_max_value->setObjectName(QStringLiteral("l_max_value"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_max_value->setPalette(palette5);
        QFont font5;
        font5.setFamily(QStringLiteral("Swis721 Cn BT"));
        font5.setPointSize(24);
        font5.setBold(false);
        font5.setWeight(50);
        l_max_value->setFont(font5);
        l_max_value->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        l_max_value->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(l_max_value);

        label_11 = new QLabel(widget_max_value);
        label_11->setObjectName(QStringLiteral("label_11"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_11->setPalette(palette6);
        QFont font6;
        font6.setFamily(QStringLiteral("Swis721 Cn BT"));
        font6.setPointSize(14);
        font6.setBold(false);
        font6.setWeight(50);
        label_11->setFont(font6);
        label_11->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_11);

        widget_min_value = new QWidget(MainScreen);
        widget_min_value->setObjectName(QStringLiteral("widget_min_value"));
        widget_min_value->setGeometry(QRect(20, 350, 50, 71));
        widget_min_value->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        verticalLayout_2 = new QVBoxLayout(widget_min_value);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        l_min_value = new QLabel(widget_min_value);
        l_min_value->setObjectName(QStringLiteral("l_min_value"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        l_min_value->setPalette(palette7);
        l_min_value->setFont(font5);
        l_min_value->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        l_min_value->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(l_min_value);

        label_13 = new QLabel(widget_min_value);
        label_13->setObjectName(QStringLiteral("label_13"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_13->setPalette(palette8);
        label_13->setFont(font6);
        label_13->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_13);

        widget_o2_porcentile = new QWidget(MainScreen);
        widget_o2_porcentile->setObjectName(QStringLiteral("widget_o2_porcentile"));
        widget_o2_porcentile->setGeometry(QRect(230, 78, 81, 41));
        widget_o2_porcentile->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        label_8 = new QLabel(widget_o2_porcentile);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 0, 81, 30));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_8->setPalette(palette9);
        label_8->setFont(font5);
        label_8->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(widget_o2_porcentile);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 20, 16, 20));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_9->setPalette(palette10);
        label_9->setFont(font6);
        label_9->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        label_9->setAlignment(Qt::AlignCenter);
        widget_o2_porcentile_mini = new QWidget(MainScreen);
        widget_o2_porcentile_mini->setObjectName(QStringLiteral("widget_o2_porcentile_mini"));
        widget_o2_porcentile_mini->setGeometry(QRect(170, 70, 81, 41));
        widget_o2_porcentile_mini->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        label_10 = new QLabel(widget_o2_porcentile_mini);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 0, 81, 30));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_10->setPalette(palette11);
        QFont font7;
        font7.setFamily(QStringLiteral("Swis721 Cn BT"));
        font7.setPointSize(16);
        font7.setBold(false);
        font7.setWeight(50);
        label_10->setFont(font7);
        label_10->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        label_10->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(widget_o2_porcentile_mini);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(37, 16, 16, 20));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_12->setPalette(palette12);
        QFont font8;
        font8.setFamily(QStringLiteral("Swis721 Cn BT"));
        font8.setPointSize(11);
        font8.setBold(false);
        font8.setWeight(50);
        label_12->setFont(font8);
        label_12->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        label_12->setAlignment(Qt::AlignCenter);
        widget_menu_off = new MyWidgetAnimated(MainScreen);
        widget_menu_off->setObjectName(QStringLiteral("widget_menu_off"));
        widget_menu_off->setGeometry(QRect(0, 403, 320, 77));
        widget_menu_off->setStyleSheet(QLatin1String("border-image: url(:/icons/main_screen/widget_settings_off.png);\n"
"background-image: url(:/icons/general/fondo_transparente.png);"));

        retranslateUi(MainScreen);

        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QWidget *MainScreen)
    {
        MainScreen->setWindowTitle(QApplication::translate("MainScreen", "Form", nullptr));
        label->setText(QApplication::translate("MainScreen", "12:00", nullptr));
        label_2->setText(QApplication::translate("MainScreen", "mi\303\251 06/01/2021", nullptr));
        label_3->setText(QApplication::translate("MainScreen", "5h 12m", nullptr));
        label_4->setText(QString());
        l_oxygen_value->setText(QApplication::translate("MainScreen", "...", nullptr));
        l_max_value->setText(QApplication::translate("MainScreen", "28", nullptr));
        label_11->setText(QApplication::translate("MainScreen", "max", nullptr));
        l_min_value->setText(QApplication::translate("MainScreen", "16", nullptr));
        label_13->setText(QApplication::translate("MainScreen", "min", nullptr));
        label_8->setText(QApplication::translate("MainScreen", "FiO  %", nullptr));
        label_9->setText(QApplication::translate("MainScreen", "2", nullptr));
        label_10->setText(QApplication::translate("MainScreen", "FiO  %", nullptr));
        label_12->setText(QApplication::translate("MainScreen", "2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H

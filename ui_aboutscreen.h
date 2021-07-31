/********************************************************************************
** Form generated from reading UI file 'aboutscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTSCREEN_H
#define UI_ABOUTSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <mylabelanimated.h>

QT_BEGIN_NAMESPACE

class Ui_AboutScreen
{
public:
    QWidget *widget;
    MyLabelAnimated *l_about_back;
    QLabel *label;

    void setupUi(QWidget *AboutScreen)
    {
        if (AboutScreen->objectName().isEmpty())
            AboutScreen->setObjectName(QStringLiteral("AboutScreen"));
        AboutScreen->resize(320, 322);
        widget = new QWidget(AboutScreen);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 320, 322));
        widget->setStyleSheet(QStringLiteral("background-image: url(:/icons/general/fondo_transparente.png);"));
        l_about_back = new MyLabelAnimated(widget);
        l_about_back->setObjectName(QStringLiteral("l_about_back"));
        l_about_back->setGeometry(QRect(0, 0, 320, 84));
        l_about_back->setStyleSheet(QLatin1String("background-image: url(:/icons/general/fondo_transparente.png);\n"
"border-image: url(:/icons/main_menu/general_menu/about_button.png);"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 70, 320, 251));
        QFont font;
        font.setFamily(QStringLiteral("Swis721 Lt BT"));
        font.setPointSize(10);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("background-color: rgb(232, 232, 232);\n"
"color: rgb(77, 77, 77);"));
        label->setAlignment(Qt::AlignCenter);
        label->raise();
        l_about_back->raise();

        retranslateUi(AboutScreen);

        QMetaObject::connectSlotsByName(AboutScreen);
    } // setupUi

    void retranslateUi(QWidget *AboutScreen)
    {
        AboutScreen->setWindowTitle(QApplication::translate("AboutScreen", "Form", nullptr));
        l_about_back->setText(QString());
        label->setText(QApplication::translate("AboutScreen", "VENTIPAP\n"
"Analizador de Ox\303\255geno\n"
"Modelo: NV2.0-OXI\n"
"Versi\303\263n del software: 1.0\n"
"\n"
"Centro de Neurociencias de Cuba\n"
"Direcci\303\263n: Calle 190 entre 25 y 27\n"
"Cuabanc\303\241n, Playa. CP 11600\n"
"La Habana, Cuba\n"
"\n"
"Tel\303\251fonos: +53 72637100\n"
"ext.243, 244, 245\n"
"Correo electr\303\263nico:\n"
"soportetecnico@cneuro.cu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutScreen: public Ui_AboutScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTSCREEN_H

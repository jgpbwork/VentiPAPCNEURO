/**
 * Created by Ing. Luis Alejandro Reyes Morales on 8/12/2020.
 *
 * email: inglreyesm@gmail.com
 * github: github.com/lreyesm
 * linkedin: linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
 *
 */

#include "aboutscreen.h"
#include "ui_aboutscreen.h"

AboutScreen::AboutScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutScreen)
{
    ui->setupUi(this);
}

AboutScreen::~AboutScreen()
{
    delete ui;
}

/**
 * AboutScreen :: on_l_about_back_clicked
 *
 * ? Slot of back button on about menu widget 
 *
 * Closes about widget and show the main menu widget
 * LINK forms/mainmenu.ui
 */
void AboutScreen::on_l_about_back_clicked(){
    this->close();
    emit closing();
}

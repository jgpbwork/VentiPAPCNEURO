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

void AboutScreen::on_l_about_back_clicked(){
    this->close();
    emit closing();
}

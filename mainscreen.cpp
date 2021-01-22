#include "mainscreen.h"
#include "ui_mainscreen.h"
#include <QDebug>
#include "globalfunctions.h"
#include "processesclass.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QGraphicsDropShadowEffect>

MainScreen::MainScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint);

    main_menu = new MainMenu(this);
    main_menu->hide();
    shownMenu = false;

    connect(main_menu, &MainMenu::menu_clicked,
            this, &MainScreen::hideWidgetMenu);
    connect(ui->widget_menu_off, &MyWidgetAnimated::clicked,
            this, &MainScreen::showWidgetMenu);

    connect(main_menu, &MainMenu::alarmLimitSetted,
            this, &MainScreen::setAlarmLimits);


    ui->widget_o2_porcentile_mini->hide();

    GlobalFunctions::loadData();

    QString answer = ProcessesClass::executeProcess(this, "sudo i2cdetect -y 1",
                                                    ProcessesClass::LINUX, 1000, true);

    if( ((answer.contains("48")) || (answer.contains("49"))) && answer.contains("64")
            && answer.contains("68")){

        qDebug()<<"answer"<<answer;
    }
    else{
        QWidget *widget = new QWidget(this);
        QWidget *widget_blur = new QWidget(this);
        widget_blur->setFixedSize(320, 480);
        widget_blur->setStyleSheet("background-color: rgba(100, 100, 100, 100);");
        widget->setFixedSize(300, 150);
        widget->move(10, 165);
        widget->setStyleSheet("border-radius: 10px");


        qDebug()<<"answer"<<answer;
        QLabel *icon = new QLabel(widget);
        icon->setPixmap(QPixmap(":icons/main_menu/calibration_menu/error.png"));
        icon->setScaledContents(true);
        icon->setFixedSize(30, 30);
        icon->move(10,10);

        QLabel *message = new QLabel(widget);
        QFont f = this->font();
        message->setText("Error");
        message->setFont(f);
        message->move(120,10);

        QPlainTextEdit *messageText = new QPlainTextEdit(widget);
        messageText->setFixedSize(300, 85);
        f.setPointSize(12);
        messageText->setPlainText("Reinicie el equipo. Si persiste el error, contacte a email@example.com");
        messageText->setFont(f);
        messageText->move(10,55);

        QGraphicsDropShadowEffect *eff = new QGraphicsDropShadowEffect(this);
        eff->setBlurRadius(20);
        eff->setOffset(1);
        eff->setColor(QColor(Qt::red));
        widget->setGraphicsEffect(eff);

        widget_blur->show();
        widget->show();
        widget->raise();
    }
}

MainScreen::~MainScreen()
{
    delete ui;
}

void MainScreen::setAlarmLimits(){
    ui->l_min_value->setText(QString::number(GlobalFunctions::configured_min_limit));
    ui->l_max_value->setText(QString::number(GlobalFunctions::configured_max_limit));
}

void MainScreen::setOxygenValue(double value)
{
    GlobalFunctions::lastSettedValue = value;
    value = GlobalFunctions::getRealValue(value);

    if(value < 0 ){
        ui->l_oxygen_value->setText("--");
        return;
    }

    if(value < GlobalFunctions::configured_min_limit
            || value > GlobalFunctions::configured_max_limit){
        QString style = ui->l_oxygen_value->styleSheet();
        style += "color: rgb(255, 0, 0);";
        ui->l_oxygen_value->setStyleSheet(style);
    }
    else{
        QString style = ui->l_oxygen_value->styleSheet();
        style.remove("color: rgb(255, 0, 0);");
        ui->l_oxygen_value->setStyleSheet(style);
    }
    if(value >= 100){
        QFont f = ui->l_oxygen_value->font();
        if(shownMenu){
            f.setPointSize(24);
        }
        else{
            f.setPointSize(150);
        }
        ui->l_oxygen_value->setFont(f);
    }
    else{
        QFont f = ui->l_oxygen_value->font();
        if(shownMenu){
            f.setPointSize(50);
        }
        else{
            f.setPointSize(200);
        }
        ui->l_oxygen_value->setFont(f);
    }
    if(!blockedDisplayValue){
        ui->l_oxygen_value->setText(QString::number(value, 'f', 0));
    }
    GlobalFunctions::lastSettedValue = value;
}

void MainScreen::setOxygenImage(QString image)
{
    blockedDisplayValue = true;
    qDebug()<<"image"<< image;
    ui->l_oxygen_value->setPixmap(QPixmap(image));
    ui->widget_o2_porcentile_mini->hide();
    ui->l_oxygen_value->raise();
}

void MainScreen::emitMenuClicked()
{
    emit menu_clicked();
}
void MainScreen::showWidgetMenu(){
    if(main_menu != nullptr){

        shownMenu = true;

        main_menu->move(0,135);
        main_menu->showMenu();

        ui->l_oxygen_value->move(125, 70);
        ui->l_oxygen_value->setFixedSize(70, 70);
        QFont f = ui->l_oxygen_value->font();
        f.setPointSize(50);
        ui->l_oxygen_value->setFont(f);
        ui->widget_o2_porcentile_mini->show();
        ui->widget_max_value->hide();
        ui->widget_o2_porcentile->hide();
    }
}
void MainScreen::hideWidgetMenu(){
    if(main_menu != nullptr){
        main_menu->hideMenu();

        shownMenu = false;
        ui->l_oxygen_value->move(10, 130);
        ui->l_oxygen_value->setFixedSize(291, 221);
        QFont f = ui->l_oxygen_value->font();
        f.setPointSize(200);
        ui->l_oxygen_value->setFont(f);
        ui->widget_o2_porcentile_mini->hide();
        ui->widget_max_value->show();
        ui->widget_o2_porcentile->show();
    }
}

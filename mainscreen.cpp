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

    QString answer_shutdown = ProcessesClass::
            executeProcess(this,"sudo python /home/pi/VentiApp/scripts/shutdownbuttons.py &",
                                                    ProcessesClass::LINUX, 1000, true);
    if(!GlobalFunctions::loadData()){
        QString mess = "Error"
                       "Calibracion no encontrada. Reintente calibracion";
        GlobalFunctions::setWarningMessage(this, mess);
    }

    QString answer = ProcessesClass::executeProcess(this, "sudo i2cdetect -y 1",
                                                    ProcessesClass::LINUX, 1000, true);

#ifdef NDEBUG
#warning "Release target.
    if((answer.contains("48")) || (answer.contains("49")))
                               && answer.contains("64")
                               && answer.contains("68")){
        qDebug() << " Release answer" << answer;
    }
#else
    if( ((answer.contains("48")) || (answer.contains("49"))) ///Target debug doesn't have Gause Battery management
                                 && answer.contains("68")) {

        qDebug()<<"Debug answer"<<answer;
    }
#endif
    else{
        qDebug()<<"answer"<<answer;
        QString mess = "Reinicie el equipo. Si persiste "
                       "el error, contacte a email@example.com";
        GlobalFunctions::setErrorMessage(this, mess);
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

void MainScreen::setDate(QDate date){
    if(date.isValid()){
        ///set label_2
        ui->label_2->setText(date.toString());
    }
}

void MainScreen::setTime(QTime time){
    if(time.isValid()){
        ///set label
        ui->label->setText(time.toString("hh:mm"));
    }
}

void MainScreen::setOxygenValue(double value)
{
    GlobalFunctions::lastSettedValue = value;
    value = GlobalFunctions::getRealValue(value);

    if(value < 0 || value > 100){
        if(!blockedDisplayValue){
            ui->l_oxygen_value->setText("--");
        }
        return;
    }

    ///TODO if Value is out or Range, start alarm process
    /// if Value is in Range, stop alarm process
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

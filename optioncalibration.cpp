#include "optioncalibration.h"
#include "ui_optioncalibration.h"
#include "globalfunctions.h"
#include <QDebug>
#include "mainscreen.h"

OptionCalibration::OptionCalibration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionCalibration)
{
    ui->setupUi(this);

    jsonArrayStates.append(getJsonObjectStateInitInformation());
    jsonArrayStates.append(getJsonObjectStateInitMinCalibration());
    jsonArrayStates.append(getJsonObjectStateRunningMinCalibration());
    jsonArrayStates.append(getJsonObjectStateEndedMinCalibration());
    jsonArrayStates.append(getJsonObjectStateInitMaxCalibration());
    jsonArrayStates.append(getJsonObjectStateRunningMaxCalibration());
    jsonArrayStates.append(getJsonObjectStateEndedMaxCalibration());
    jsonArrayStates.append(getJsonObjectStateEndedCalibration());

    setCurrentState(jsonArrayStates.at(0).toObject());
}

OptionCalibration::~OptionCalibration()
{
    delete ui;
}

void OptionCalibration::initMinCalibration(){
    minCalibrationProgress = 0;
    ui->pbar_calibration_state_progress->setValue(minCalibrationProgress);
    QEventLoop loop;
    connect(this, &OptionCalibration::minCalibrationEnded, &loop, &QEventLoop::quit);
    connect(&minCalTimer, &QTimer::timeout, this, &OptionCalibration::incProgressMinCalibration);
    minCalTimer.setInterval(CAL_TIME / (100/CAL_INCREASE_VALUE));
    minCalTimer.start();
    loop.exec();
    navigateNextState();
}
void OptionCalibration::initMaxCalibration(){
    maxCalibrationProgress = 0;
    ui->pbar_calibration_state_progress->setValue(maxCalibrationProgress);
    QEventLoop loop;
    connect(this, &OptionCalibration::maxCalibrationEnded, &loop, &QEventLoop::quit);
    connect(&maxCalTimer, &QTimer::timeout, this, &OptionCalibration::incProgressMaxCalibration);
    maxCalTimer.setInterval(CAL_TIME / (100/CAL_INCREASE_VALUE));
    maxCalTimer.start();
    loop.exec();
    navigateNextState();
}
void OptionCalibration::incProgressMinCalibration(){
    minCalibrationProgress += CAL_INCREASE_VALUE;
    ui->pbar_calibration_state_progress->setValue(minCalibrationProgress);
    if(minCalibrationProgress >= 80){
        if(minCalValue >= 0){
            double sum = minCalValue + GlobalFunctions::lastSettedValue;
            minCalValue = sum/2;
            qDebug()<<"minCalValue"<<minCalValue<<"******************************************";
        }else{
            minCalValue = GlobalFunctions::lastSettedValue;
            qDebug()<<"minCalValue"<<minCalValue<<"******************************************";
        }
    }
    if(minCalibrationProgress >= 100){
        minCalTimer.stop();
        emit minCalibrationEnded();
    }
}
void OptionCalibration::incProgressMaxCalibration(){
    maxCalibrationProgress += CAL_INCREASE_VALUE;
    ui->pbar_calibration_state_progress->setValue(maxCalibrationProgress);
    if(maxCalibrationProgress >= 80){
        if(maxCalValue >= 0){
            double sum = maxCalValue + GlobalFunctions::lastSettedValue;
            maxCalValue = sum/2;
            qDebug()<<"maxCalValue"<<maxCalValue<<"******************************************";
        }else{
            maxCalValue = GlobalFunctions::lastSettedValue;
            qDebug()<<"maxCalValue"<<maxCalValue<<"******************************************";
        }
    }
    if(maxCalibrationProgress >= 100){
        maxCalTimer.stop();
        emit maxCalibrationEnded();
    }
}void OptionCalibration::on_l_calibration_back_clicked(){
    unBlockDisplayValue();
    this->close();
    emit closing();
}

void OptionCalibration::on_l_calibration_state_button_clicked()
{
    if(currentStateJsonObject.value("calibration_state_button").
            toString().contains("cancel_button")){
        currentStateJsonObject = getJsonObjectStateCancelCalibration();
        setCurrentState(currentStateJsonObject);
        return;
    }
    navigateNextState();
}
void OptionCalibration::navigateNextState(){
    currentState++;
    if(currentState >= jsonArrayStates.size()){

        GlobalFunctions::m_slope_value = 79.1/(maxCalValue - minCalValue);
        GlobalFunctions::n_value = 100 - (maxCalValue*(GlobalFunctions::m_slope_value));
        
        if(GlobalFunctions::m_slope_value > 0
                && (GlobalFunctions::n_value < 10
                    && GlobalFunctions::n_value > -10)){
            GlobalFunctions::calibrated = true;
            GlobalFunctions::saveData();
            on_l_calibration_back_clicked();
        }
        else{
            QString mess = "Error de calibracion"
                           ", reintente calibrar";
            GlobalFunctions::setErrorMessage(this, mess + "\n m = " 
            + QString::number(GlobalFunctions::m_slope_value) + "\n n = " + QString::number(GlobalFunctions::n_value));
            QTimer::singleShot(4000, this, &OptionCalibration::
                               on_l_calibration_back_clicked);
        }

        return;
    }
    currentStateJsonObject = jsonArrayStates.at(currentState).toObject();
    setCurrentState(currentStateJsonObject);
    qDebug()<<"calibration state" << currentState;

    if(currentState == INIT_MIN_CAL_STATE){
        initMinCalibration();
    }
    else if(currentState == INIT_MAX_CAL_STATE){
        initMaxCalibration();
    }
}

MainScreen* OptionCalibration::getMainScreenInstance(){
    MainScreen *mainWindow = qobject_cast<MainScreen*>(this->parent()->parent());
    if(mainWindow){
        qDebug()<<"Casteo OK";
        return mainWindow;
    }else{
        qDebug()<<"Casteo ERROR";
        return nullptr;
    }
}
void OptionCalibration::setMainScreenImage(QString image_name){
    MainScreen *mainScreen = getMainScreenInstance();
    if(mainScreen){
        mainScreen->setOxygenImage(image_name);
    }
}
void OptionCalibration::unBlockDisplayValue(){
    MainScreen *mainScreen = getMainScreenInstance();
    if(mainScreen){
        mainScreen->setBlockedDisplayValue(false);
    }
}

void OptionCalibration::setCurrentState(QJsonObject jsonObjectState){

    if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state").toString())){
        ui->l_calibration_state->setText(jsonObjectState.value("calibration_state").toString());
        ui->l_calibration_state->show();
    }
    else{
        ui->l_calibration_state->hide();
    }

    if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state_text").toString())){
        ui->pt_calibration_state_text->setPlainText(jsonObjectState.value("calibration_state_text").toString());
        ui->pt_calibration_state_text->setAlignment(Qt::AlignHCenter);
        ui->pt_calibration_state_text->show();
    }
    else{
        ui->pt_calibration_state_text->hide();
    }

    if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state_progress_text").toString())){
        ui->l_calibration_state_progress_text->setText(jsonObjectState.value("calibration_state_progress_text").toString());
        ui->l_calibration_state_progress_text->show();
    }
    else{
        ui->l_calibration_state_progress_text->hide();
    }

    if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state_progress_value").toString())){
        ui->pbar_calibration_state_progress->setValue(jsonObjectState.value("calibration_state_progress_value").toString().toInt());
        ui->pbar_calibration_state_progress->show();
    }
    else{
        ui->pbar_calibration_state_progress->hide();
    }

    if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state_button").toString())){
        ui->l_calibration_state_button->setPixmap(QPixmap(":/icons/"+jsonObjectState.value("calibration_state_button").toString()));
        ui->l_calibration_state_button->show();
    }
    else{
        ui->l_calibration_state_button->hide();
    }

    if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state_footer_text_1").toString())){
        ui->l_calibration_state_footer_text_1->setText(jsonObjectState.value("calibration_state_footer_text_1").toString());
        ui->l_calibration_state_footer_text_1->show();
    }
    else{
        ui->l_calibration_state_footer_text_1->hide();
    }

    if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state_footer_text_2").toString())){
        ui->l_calibration_state_footer_text_2->setText(jsonObjectState.value("calibration_state_footer_text_2").toString());
        ui->l_calibration_state_footer_text_2->show();
    }
    else{
        ui->l_calibration_state_footer_text_2->hide();
    }

    if(jsonObjectState.contains("calibration_state_error_tag")){
        if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state_error_tag").toString())){
            ui->l_calibration_state_error_tag->setText(jsonObjectState.value("calibration_state_error_tag").toString());
            ui->l_calibration_state_error_tag->show();
        }
        else{
            ui->l_calibration_state_error_tag->hide();
        }
    }else{
        ui->l_calibration_state_error_tag->hide();
    }
    if(jsonObjectState.contains("calibration_state_error_text")){
        if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state_error_text").toString())){
            ui->l_calibration_state_error_text->setText(jsonObjectState.value("calibration_state_error_text").toString());
            ui->l_calibration_state_error_text->show();
        }
        else{
            ui->l_calibration_state_error_text->hide();
        }
    }else{
        ui->l_calibration_state_error_text->hide();
    }
    if(jsonObjectState.contains("calibration_state_button_repeat")){
        if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state_button_repeat").toString())){
            ui->l_calibration_state_button_repeat->setPixmap(QPixmap(":/icons/"+jsonObjectState.value("calibration_state_button_repeat").toString()));
            ui->l_calibration_state_button_repeat->show();
        }
        else{
            ui->l_calibration_state_button_repeat->hide();
        }
    }else{
        ui->l_calibration_state_button_repeat->hide();
    }
    if(jsonObjectState.contains("calibration_state_button_out")){
        if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state_button_out").toString())){
            ui->l_calibration_state_button_out->setPixmap(QPixmap(":/icons/"+jsonObjectState.value("calibration_state_button_out").toString()));
            ui->l_calibration_state_button_out->show();
        }
        else{
            ui->l_calibration_state_button_out->hide();
        }
    }
    else{
        ui->l_calibration_state_button_out->hide();
    }
    if(jsonObjectState.contains("main_screen_image")){
        if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("main_screen_image").toString())){
            setMainScreenImage(jsonObjectState.value("main_screen_image").toString());
        }
    }
    else{
        unBlockDisplayValue();
    }
}

QJsonObject OptionCalibration::getJsonObjectStateInitInformation(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "Información");
    jsonObject.insert("calibration_state_text", "El dispositivo deberá realizar"
                                                " una medición máxima y mínima. "
                                                "Para ello siga las instruciones "
                                                "durante el progreso una vez iniciado");
    jsonObject.insert("calibration_state_progress_text", "");
    jsonObject.insert("calibration_state_progress_value", "");
    jsonObject.insert("calibration_state_button", "general/next_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "Última calibración");
    ///TODO Set Real Calibration Date...
    jsonObject.insert("calibration_state_footer_text_2", "12 dic. 2020 17:52");
    return jsonObject;
}

QJsonObject OptionCalibration::getJsonObjectStateInitMinCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "Medición mínima");
    jsonObject.insert("calibration_state_text", "Para realizar la medición mínima "
                                                "antes desconecte el dispositivo de "
                                                "la válvula para medir el oxígeno"
                                                " ambiente");
    jsonObject.insert("calibration_state_progress_text", "");
    jsonObject.insert("calibration_state_progress_value", "");
    jsonObject.insert("calibration_state_button", "general/start_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    return jsonObject;
}

QJsonObject OptionCalibration::getJsonObjectStateRunningMinCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "");
    jsonObject.insert("calibration_state_text", "");
    jsonObject.insert("calibration_state_progress_text", "Medición mínima");
    jsonObject.insert("calibration_state_progress_value", "0");
    jsonObject.insert("calibration_state_button", "general/cancel_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    return jsonObject;
}

QJsonObject OptionCalibration::getJsonObjectStateEndedMinCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "");
    jsonObject.insert("calibration_state_text", "");
    jsonObject.insert("calibration_state_progress_text", "Completada");
    jsonObject.insert("calibration_state_progress_value", "100");
    jsonObject.insert("calibration_state_button", "general/next_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    jsonObject.insert("main_screen_image", ":/icons/main_menu/calibration_menu/ok.png");
    return jsonObject;
}

QJsonObject OptionCalibration::getJsonObjectStateInitMaxCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "Medición máxima");
    jsonObject.insert("calibration_state_text", "Para realizar la medición máxima "
                                                "antes conecte el dispositivo a la "
                                                "válvula y ábrala a toda capacidad");
    jsonObject.insert("calibration_state_progress_text", "");
    jsonObject.insert("calibration_state_progress_value", "");
    jsonObject.insert("calibration_state_button", "general/start_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    return jsonObject;
}

QJsonObject OptionCalibration::getJsonObjectStateRunningMaxCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "");
    jsonObject.insert("calibration_state_text", "");
    jsonObject.insert("calibration_state_progress_text", "Medición máxima");
    jsonObject.insert("calibration_state_progress_value", "0");
    jsonObject.insert("calibration_state_button", "general/cancel_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    return jsonObject;
}

QJsonObject OptionCalibration::getJsonObjectStateEndedMaxCalibration(){

    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "");
    jsonObject.insert("calibration_state_text", "");
    jsonObject.insert("calibration_state_progress_text", "Completada");
    jsonObject.insert("calibration_state_progress_value", "100");
    jsonObject.insert("calibration_state_button", "general/next_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    jsonObject.insert("main_screen_image", ":/icons/main_menu/calibration_menu/ok.png");
    return jsonObject;
}

QJsonObject OptionCalibration::getJsonObjectStateEndedCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "Calibración Completada");
    jsonObject.insert("calibration_state_text", "Se ha realizado correctamente la "
                                                "calibración del dispositivo. "
                                                "Puede comenzar a usarlo con "
                                                "normalidad");
    jsonObject.insert("calibration_state_progress_text", "");
    jsonObject.insert("calibration_state_progress_value", "");
    jsonObject.insert("calibration_state_button", "general/exit_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    jsonObject.insert("main_screen_image", ":/icons/main_menu/calibration_menu/ok.png");
    return jsonObject;
}

QJsonObject OptionCalibration::getJsonObjectStateErrorCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "");
    jsonObject.insert("calibration_state_text", "");
    jsonObject.insert("calibration_state_progress_text", "Medición");
    jsonObject.insert("calibration_state_progress_value", "");
    jsonObject.insert("calibration_state_button", "");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");

    jsonObject.insert("calibration_state_error_tag", "Incompleta");
    jsonObject.insert("calibration_state_error_text", "Error en la medición");
    jsonObject.insert("calibration_state_button_out", "general/out_button.png");
    jsonObject.insert("calibration_state_button_repeat", "general/repeat_button.png");
    jsonObject.insert("main_screen_image", ":/icons/main_menu/calibration_menu/error.png");
    return jsonObject;
}
QJsonObject OptionCalibration::getJsonObjectStateCancelCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "");
    jsonObject.insert("calibration_state_text", "");
    jsonObject.insert("calibration_state_progress_text", "Medición");
    jsonObject.insert("calibration_state_progress_value", "");
    jsonObject.insert("calibration_state_button", "");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");

    jsonObject.insert("calibration_state_error_tag", "Incompleta");
    jsonObject.insert("calibration_state_error_text", "Cancelado por el usuario");
    jsonObject.insert("calibration_state_button_out", "general/out_button.png");
    jsonObject.insert("calibration_state_button_repeat", "general/repeat_button.png");
    jsonObject.insert("main_screen_image", ":/icons/main_menu/calibration_menu/error.png");
    return jsonObject;
}

void OptionCalibration::on_l_calibration_state_button_out_clicked()
{
    on_l_calibration_back_clicked();
}

void OptionCalibration::on_l_calibration_state_button_repeat_clicked()
{
    if(currentState <= 2){
        currentState = 0;
        on_l_calibration_state_button_clicked();
    }
    else if(currentState >= 5){
        currentState = 3;
        on_l_calibration_state_button_clicked();
    }
}

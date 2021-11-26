/**
* Created by Ing. Luis Alejandro Reyes Morales on 9/12/2020.
*
* email: inglreyesm@gmail.com
* github: https://github.com/lreyesm
* linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
*
*/

#include "optioncalibration.h"
#include "ui_optioncalibration.h"
#include "globalfunctions.h"
#include <QDebug>
#include <QDateTime>
#include "mainscreen.h"

/**
 * OptionCalibration :: OptionCalibration 
 * 
 * @param  {QWidget*} parent : Parent of this widget
 */
OptionCalibration::OptionCalibration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OptionCalibration)
{
    ui->setupUi(this);

    // * This variable has the current state of the UI 
    currentState = 0;

    // * This are the state of the UI, each state sets the corresponding text
    // * to the text labels and sets the text of the buttons 
    // * Each state is a JSON object with the key value pairs containing the
    // * texts of labels and buttons 
    // * All the states are inside the jsonArrayStates JsonArray variable type
    jsonArrayStates.append(getJsonObjectStateInitInformation());
    jsonArrayStates.append(getJsonObjectStateInitMinCalibration());
    jsonArrayStates.append(getJsonObjectStateRunningMinCalibration());
    jsonArrayStates.append(getJsonObjectStateEndedMinCalibration());
    jsonArrayStates.append(getJsonObjectStateInitMaxCalibration());
    jsonArrayStates.append(getJsonObjectStateRunningMaxCalibration());
    jsonArrayStates.append(getJsonObjectStateEndedMaxCalibration());
    jsonArrayStates.append(getJsonObjectStateEndedCalibration());

    // * Sets the initial state in the JSON array of states 
    setCurrentState(jsonArrayStates.at(0).toObject());
}


OptionCalibration::~OptionCalibration()
{
    delete ui;
}

/**
 * OptionCalibration :: initMinCalibration
 * 
 * Start the minimun calibration proccess, turn off the alarm if 
 * it is active, inits the calibration progress bar and timer
 * with a timeout of CAL_TIME / (100/CAL_INCREASE_VALUE),
 * calling the initMinCalibration 
 * function. Finally navigates to next state
 * after the loop of increasing progress bar ended.
 */
void OptionCalibration::initMinCalibration(){
    turnOffAlarm();
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


/**
 * OptionCalibration :: initMaxCalibration
 * 
 * Start the maximun calibration proccess, 
 * inits the calibration progress bar and timer
 * with a timeout of CAL_TIME / (100/CAL_INCREASE_VALUE),
 * calling the initMaxCalibration 
 * function. Finally navigates to next state
 * after the loop of increasing progress bar ended.
 */
void OptionCalibration::initMaxCalibration(){
    maxCalibrationProgress = 0;
    setMainScreenValueText("...");
    ui->pbar_calibration_state_progress->setValue(maxCalibrationProgress);
    QEventLoop loop;
    connect(this, &OptionCalibration::maxCalibrationEnded, &loop, &QEventLoop::quit);
    connect(&maxCalTimer, &QTimer::timeout, this, &OptionCalibration::incProgressMaxCalibration);
    maxCalTimer.setInterval(CAL_TIME / (100/CAL_INCREASE_VALUE));
    maxCalTimer.start();
    loop.exec();
    navigateNextState();
}

/**
 * OptionCalibration :: incProgressMinCalibration
 * 
 * Increments the progress bar on minimun calibration on going
  * when get to the 80% start averaging the oxygen value unprocessed
 * received from oxygen sensor thread 
 * If progress bar goes to 100% stop the increment timer
 */
void OptionCalibration::incProgressMinCalibration(){
    minCalibrationProgress += CAL_INCREASE_VALUE;
    setMainScreenValueText("...");
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
        // setMainScreenBatteryText(QString::number(minCalValue, 'f', 6));
    }
    if(minCalibrationProgress >= 100){
        minCalTimer.stop();
        emit minCalibrationEnded();
    }
}

/**
 * OptionCalibration :: incProgressMaxCalibration
 * 
 * Increments the progress bar on maximun calibration on going
 * when get to the 80% start averaging the oxygen value unprocessed
 * received from oxygen sensor thread 
 * If progress bar goes to 100% stop the increment timer
 */
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
        //setMainScreenBatteryText(QString::number(maxCalValue, 'f', 6));
    }
    if(maxCalibrationProgress >= 100){
        maxCalTimer.stop();
        emit maxCalibrationEnded();
    }
}

/**
 * OptionCalibration :: on_l_calibration_back_clicked
 * 
 * Closes this calibration widget and shows general widget
 * Unblocks the display and pass the control of it 
 * to main screen widget
 */
void OptionCalibration::on_l_calibration_back_clicked(){
    setMainScreenValueText("--");
    unBlockDisplayValue();
    this->close();
    emit closing();
}

/**
 * OptionCalibration :: on_l_calibration_state_button_clicked
 * 
 * Slot for the next state button, executes the right action 
 * by navigating the next state depending on the current state value
 */
void OptionCalibration::on_l_calibration_state_button_clicked()
{
    if(currentStateJsonObject.value("calibration_state_button").
            toString().contains("cancel_button")){
        if(currentStateJsonObject.value("calibration_state_min_or_max").toString().contains("min"))
        {
            currentStateJsonObject = getJsonObjectStateCancelCalibration();
            currentStateJsonObject.insert("calibration_state_progress_text", "Medición mínima");
            currentStateJsonObject.insert("calibration_state_error_text", "Cancelado por el usuario");
            setCurrentState(currentStateJsonObject);
        }
        if(currentStateJsonObject.value("calibration_state_min_or_max").toString().contains("max"))
        {
            currentStateJsonObject = getJsonObjectStateCancelCalibration();
            currentStateJsonObject.insert("calibration_state_progress_text", "Medición máxima");
            currentStateJsonObject.insert("calibration_state_error_text", "Cancelado por el usuario");
            setCurrentState(currentStateJsonObject);
        }
//        currentStateJsonObject = getJsonObjectStateCancelCalibration();
//        setCurrentState(currentStateJsonObject);

        return;
    }
    navigateNextState();
}

/**
 * OptionCalibration :: navigateNextState
 * 
 * Navigate next state function, sets the current state 
 * depending on the current state variable value
 * If current state is INIT_MIN_CAL_STATE inits the minimun calibration
 * If current state is INIT_MAX_CAL_STATE inits the minimun calibration
 * * If is the last state checks if the minimun and maximun calibration value 
 * * average is between the correct range.
 * * If it's in the right range save the values and calculates the m slope
 * * and n offset value, saves them to a file and go out of calibration
 * * else shows a warning and retries the calibration
 * ! The calibration retries process has an error needs test and fix 
 */
void OptionCalibration::navigateNextState(){
    currentState++;

    if(currentState == jsonArrayStates.size() - 1){
        double m = 79.1/(maxCalValue - minCalValue);
        double n = 100 - (maxCalValue*(GlobalFunctions::m_slope_value));

        qDebug()<<"calibration m_slope_value" << m;
        qDebug()<<"calibration n_value" << n;
        if(!(m > 0
             && (n < 100
                 && n > -100))){
//            QString mess = "Error configurando calibracion"
//                           ", reintente calibrar";
//            GlobalFunctions::setWarningMessage(this->parentWidget()->parentWidget(), mess + "\n m = "
//                                               + QString::number(m) + "\n n = " + QString::number(n));
//            currentStateJsonObject = getJsonObjectStateCancelCalibration();

            if(currentStateJsonObject.value("calibration_state_min_or_max").toString().contains("ended_max_calibration"))
            {
                currentStateJsonObject = getJsonObjectStateCancelCalibration();
                currentStateJsonObject.insert("calibration_state_progress_text", "");
                currentStateJsonObject.insert("calibration_state_error_tag", "Calibración Incompleta");
                currentStateJsonObject.insert("calibration_state_error_text", "Error en la medición");
                setCurrentState(currentStateJsonObject);
            }

            setCurrentState(currentStateJsonObject);
            return;
        }

    }
    if(currentState >= jsonArrayStates.size()){

        GlobalFunctions::m_slope_value = 79.1/(maxCalValue - minCalValue);
        GlobalFunctions::n_value = 100 - (maxCalValue*(GlobalFunctions::m_slope_value));
        
        qDebug()<<"calibration m_slope_value" << GlobalFunctions::m_slope_value;
        qDebug()<<"calibration n_value" << GlobalFunctions::n_value;
        if(GlobalFunctions::m_slope_value > 0
                && (GlobalFunctions::n_value < 100
                    && GlobalFunctions::n_value > -100)){
            GlobalFunctions::calibrated = true;
            GlobalFunctions::lastCalibrationDateTime = QDateTime::currentDateTime();
            GlobalFunctions::saveData();
            on_l_calibration_back_clicked();
        }

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

/**
 * OptionCalibration :: getMainScreenInstance
 * 
 * Get the main screen instance to access it public functions
 *
 * @return {MainScreen*}  : Returns the instance of main screen widget if it was found
 */
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

/**
 * OptionCalibration :: turnOffAlarm
 * 
 * Sets the alarm off by accessing the main screen instance
 */
void OptionCalibration::turnOffAlarm(){
    MainScreen *mainScreen = getMainScreenInstance();
    if(mainScreen){
        mainScreen->emitAlarm(false);
    }
}

/**
 * OptionCalibration :: setMainScreenBatteryText
 * 
 * Sets the text in battery label (remaining time) 
 * by accessing the main screen instance
 * This is for debugging purposes
 *
 * @param  {QString} text : Text to display in battery label
 */
void OptionCalibration::setMainScreenBatteryText(QString text){
    MainScreen *mainScreen = getMainScreenInstance();
    if(mainScreen){
        mainScreen->setLBatteryText(text);
    }
}

/**
 * OptionCalibration :: setMainScreenValueText
 * 
 * Sets the text in oxygen label by accessing the main screen instance 
 *
 * @param  {QString} text : Text to display in oxygen label
 */
void OptionCalibration::setMainScreenValueText(QString text){
    MainScreen *mainScreen = getMainScreenInstance();
    if(mainScreen){
        mainScreen->setValueText(text);
    }
}

/**
 * OptionCalibration :: setMainScreenImage
 * 
 * Sets an image in oxygen label by accessing the main screen instance 
 *
 * @param  {QString} image_name : Image to display in oxygen label 
 */
void OptionCalibration::setMainScreenImage(QString image_name){
    MainScreen *mainScreen = getMainScreenInstance();
    if(mainScreen){
        mainScreen->setOxygenImage(image_name);
    }
}

/**
 * OptionCalibration :: unBlockDisplayValue
 * 
 * Pass the control of the oxygen label to the main screen widget
 */
void OptionCalibration::unBlockDisplayValue(){
    MainScreen *mainScreen = getMainScreenInstance();
    if(mainScreen){
        mainScreen->setBlockedDisplayValue(false);
    }
}

/**
 * OptionCalibration :: blockDisplayValue
 * 
 * Pass the control of the oxygen label to this calibration widget
 */
void OptionCalibration::blockDisplayValue(){
    MainScreen *mainScreen = getMainScreenInstance();
    if(mainScreen){
        mainScreen->setBlockedDisplayValue(true);
    }
}

/**
 * OptionCalibration :: setCurrentState
 * 
 * Sets the corresponding state, corresponding text labels and buttons
 * on the UI, if is the last state pass the control the main screen widget
 *
 * @param  {QJsonObject} jsonObjectState : JSON object containing the state keys values pairs to set
 */
void OptionCalibration::setCurrentState(QJsonObject jsonObjectState){

//    if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state").toString())){
//        ui->l_calibration_state->setText(jsonObjectState.value("calibration_state").toString());
//        ui->l_calibration_state->show();
//    }
//    else{
//        ui->l_calibration_state->hide();
//    }

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

    if(GlobalFunctions::checkIfFieldValid(jsonObjectState.value("calibration_state_footer_text_2").toString())){  //some times setted datetime here
        ui->l_last_calibration_time->setText(jsonObjectState.value("calibration_state_footer_text_2").toString());
        ui->l_last_calibration_time->show();
    }
    else{
        ui->l_last_calibration_time->hide();
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

/**
 * OptionCalibration :: getJsonObjectStateInitInformation
 * 
 * @return {QJsonObject}  : Return the init information json object state
 */
QJsonObject OptionCalibration::getJsonObjectStateInitInformation(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "Información");
    jsonObject.insert("calibration_state_text", "El dispositivo deberá realizar"
                                                " una medición máxima y mínima. "
                                                "Para ello siga las instruciones "
                                                "durante el proceso, una vez iniciado.");
    jsonObject.insert("calibration_state_progress_text", "");
    jsonObject.insert("calibration_state_progress_value", "");
    jsonObject.insert("calibration_state_button", "general/next_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "Última calibración");
    ///TODO Set Real Calibration Date...
    if(GlobalFunctions::lastCalibrationDateTime.isValid()){
        QString dateString = GlobalFunctions::lastCalibrationDateTime.toString("dd MMM yyyy HH:mm");
        ui->l_last_calibration_time->text();
        jsonObject.insert("calibration_state_footer_text_2", dateString);
    }
    else{
        jsonObject.insert("calibration_state_footer_text_2", "--");

    }

    return jsonObject;
}

/**
 * OptionCalibration :: getJsonObjectStateInitMinCalibration
 * 
 * @return {QJsonObject}  : Return the init minimun calibration json object state
 */
QJsonObject OptionCalibration::getJsonObjectStateInitMinCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "Medición mínima");
    jsonObject.insert("calibration_state_text", "Retire el sensor de oxígeno "
                                                "del Circuito de Paciente, "
                                                "garantizando que esté conectado al "
                                                "Analizador de Oxígeno."
                      );
    jsonObject.insert("calibration_state_progress_text", "Medición mínima");
    jsonObject.insert("calibration_state_progress_value", "");
    jsonObject.insert("calibration_state_button", "general/start_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    return jsonObject;
}

/**
 * OptionCalibration :: getJsonObjectStateRunningMinCalibration
 * 
 * @return {QJsonObject}  : Return the running minimun calibration json object state
 */
QJsonObject OptionCalibration::getJsonObjectStateRunningMinCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "");
    jsonObject.insert("calibration_state_text", "");
    jsonObject.insert("calibration_state_progress_text", "Medición mínima");
    jsonObject.insert("calibration_state_progress_value", "0");
    jsonObject.insert("calibration_state_button", "general/cancel_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    jsonObject.insert("calibration_state_min_or_max", "min");
    return jsonObject;
}

/**
 * OptionCalibration :: getJsonObjectStateEndedMinCalibration
 * 
 * @return {QJsonObject}  : Return the ended minimun calibration json object state
 */
QJsonObject OptionCalibration::getJsonObjectStateEndedMinCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "");
    jsonObject.insert("calibration_state_text", "");
    jsonObject.insert("calibration_state_progress_text", "Medición mínima");
    jsonObject.insert("calibration_state_progress_value", "100");
    jsonObject.insert("calibration_state_button", "general/next_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    jsonObject.insert("main_screen_image", ":/icons/main_menu/calibration_menu/ok.png");
    return jsonObject;
}

/**
 * OptionCalibration :: getJsonObjectStateInitMaxCalibration
 * 
 * @return {QJsonObject}  : Return the init maximun calibration json object state
 */
QJsonObject OptionCalibration::getJsonObjectStateInitMaxCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "Medición máxima");
    jsonObject.insert("calibration_state_text", "Coloque el sensor de oxígeno "
                                                "en su posición correspondiente "
                                                "en el Circuito de Paciente "
                                                "y abra las tres válvulas del "
                                                "Generador de Flujo a toda capacidad.");
    jsonObject.insert("calibration_state_progress_text", "Medición máxima");
    jsonObject.insert("calibration_state_progress_value", "");
    jsonObject.insert("calibration_state_button", "general/start_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    return jsonObject;
}

/**
 * OptionCalibration :: getJsonObjectStateRunningMaxCalibration
 * 
 * @return {QJsonObject}  : Return the running maximun calibration json object state
 */
QJsonObject OptionCalibration::getJsonObjectStateRunningMaxCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "");
    jsonObject.insert("calibration_state_text", "");
    jsonObject.insert("calibration_state_progress_text", "Medición máxima");
    jsonObject.insert("calibration_state_progress_value", "0");
    jsonObject.insert("calibration_state_button", "general/cancel_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    jsonObject.insert("calibration_state_min_or_max", "max");
    return jsonObject;
}


/**
 * OptionCalibration :: getJsonObjectStateEndedMaxCalibration
 * 
 * @return {QJsonObject}  : Return the ended maximun calibration json object state
 */
QJsonObject OptionCalibration::getJsonObjectStateEndedMaxCalibration(){

    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "");
    jsonObject.insert("calibration_state_text", "");
    jsonObject.insert("calibration_state_progress_text", "Medición máxima");
    jsonObject.insert("calibration_state_progress_value", "100");
    jsonObject.insert("calibration_state_button", "general/next_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    jsonObject.insert("main_screen_image", ":/icons/main_menu/calibration_menu/ok.png");
    jsonObject.insert("calibration_state_min_or_max", "ended_max_calibration");
    return jsonObject;
}


/**
 * OptionCalibration :: getJsonObjectStateEndedCalibration
 * 
 * @return {QJsonObject}  : Return the ended calibration json object state
 */
QJsonObject OptionCalibration::getJsonObjectStateEndedCalibration(){
    QJsonObject jsonObject;
    jsonObject.insert("calibration_state", "Calibración Completada");
    jsonObject.insert("calibration_state_text", "Se ha realizado correctamente la "
                                                "calibración del dispositivo.");
    jsonObject.insert("calibration_state_progress_text", "");
    jsonObject.insert("calibration_state_progress_value", "");
    jsonObject.insert("calibration_state_button", "general/exit_button.png");
    jsonObject.insert("calibration_state_footer_text_1", "");
    jsonObject.insert("calibration_state_footer_text_2", "");
    jsonObject.insert("main_screen_image", ":/icons/main_menu/calibration_menu/ok.png");
    return jsonObject;
}


/**
 * OptionCalibration :: getJsonObjectStateErrorCalibration
 * 
 * @return {QJsonObject}  : Return the error calibration json object state
 */
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


/**
 * OptionCalibration :: getJsonObjectStateCancelCalibration
 * 
 * @return {QJsonObject}  : Return the cancel calibration json object state
 */
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

/**
 * OptionCalibration :: on_l_calibration_state_button_out_clicked
 * 
 * Slot of out button of the UI
 * Calls the on_l_calibration_back_clicked to close
 * this calibration widget
 */
void OptionCalibration::on_l_calibration_state_button_out_clicked()
{
    on_l_calibration_back_clicked();
}

/**
 * OptionCalibration :: on_l_calibration_state_button_repeat_clicked
 * .
 * Slot of repeat button of the UI
 * Repeats the maximun or minimun calibration proccess
 */
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

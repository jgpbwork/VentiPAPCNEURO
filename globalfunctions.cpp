#include "globalfunctions.h"
#include <QFile>
#include <QJsonObject>
#include <QDataStream>
#include <QJsonDocument>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QDebug>
#include <QPlainTextEdit>
#include <QGraphicsDropShadowEffect>
#include <QProcess>
#include <QDir>
#include <QException>

// Enables global animation of the application or not
// (animation of buttons and widgets)
bool GlobalFunctions::myanimationEnabled = true; 

// Default  minimun value of FiO2 setted on MainScreen
int GlobalFunctions::configured_min_limit = 21;

// Default  maximun value of FiO2 setted on MainScreen
int GlobalFunctions::configured_max_limit = 28;

// Global last battery level received from sensor's thread
// Value between 65535 and MIN_BATTERY_LEVEL -> 
// (current battery configuration setted) 
int GlobalFunctions::lastBatteryLevel = -1;

// Global last received sensor's oxygen thread value
// It can be the unproccess value when calibrating or 
// proccess value after the calibration occurs
double GlobalFunctions::lastSettedValue = 0;

// Global (m) slope value setted on calibration or loading last
// calibration slope value inside the save_config.dat file 
double GlobalFunctions::m_slope_value = 100;

// Global (n) offset value setted on calibration or loading last
// calibration offset value inside the save_config.dat file
double GlobalFunctions::n_value = 0;

// Last calibration date time value, setted on calibration 
// or loading last calibration inside the save_config.dat file 
QDateTime GlobalFunctions::lastCalibrationDateTime;

// Global calibration state value, setted on calibration 
// or loading last calibration inside the save_config.dat file 
bool GlobalFunctions::calibrated = false;

// Global current date time of environment, at start of application
QDateTime GlobalFunctions::dateTime = QDateTime::currentDateTime();

/**
 * GlobalFunctions :: GlobalFunctions

 * Constructor of the class, not using it right now
 * this is like a static class in Java, with only 
 * static functions, an utils class
 * 
 * @param  {parent} undefined                                  : 
 * @return {GlobalFunctions::GlobalFunctions(QWidgetparent)*}  : 
 */
GlobalFunctions::GlobalFunctions(QWidget *parent) : QWidget(parent)
{
}

/**
 * GlobalFunctions :: setDateTimeInRaspi
 * 
 * This function sets the date and time of the computer 
 *  
 * @param  {QWidget*} parent : Widget for parenting the QProcess
 * @param  {QDateTime} dt    : Date and time to set
 * @return {QString}         : Response of the Terminal of setting the date and time
 */
QString GlobalFunctions::setDateTimeInRaspi(QWidget *parent, QDateTime dt)
{
    dateTime = dt;
    //sudo date -s "21 APR 2020 19:45:00"
    QMap<QString, int> mapMonthEnglish;
    mapMonthEnglish.insert("JANUARY", 1);
    mapMonthEnglish.insert("FEBRUARY", 2);
    mapMonthEnglish.insert("MARCH", 3);
    mapMonthEnglish.insert("APRIL", 4);
    mapMonthEnglish.insert("MAY", 5);
    mapMonthEnglish.insert("JUNE", 6);
    mapMonthEnglish.insert("JULY", 7);
    mapMonthEnglish.insert("AUGUST", 8);
    mapMonthEnglish.insert("SEPTEMBER", 9);
    mapMonthEnglish.insert("OCTOBER", 10);
    mapMonthEnglish.insert("NOVEMBER", 11);
    mapMonthEnglish.insert("DECEMBER", 12);

    QString day = " \"" + QString::number(dt.date().day());
    QString month = " " + mapMonthEnglish.key(dt.date().month()).left(3);
    QString year = " " + QString::number(dt.date().year());

    QString date_string = "sudo date -s" + day + month + year;
    QString time_string = " " + dt.time().toString("HH:mm:ss") + "\"";
    QProcess *proc_ovpn = new QProcess(parent);
    proc_ovpn->setProcessChannelMode(QProcess::MergedChannels);

    proc_ovpn->start("sh", QStringList() << "-c" << date_string + time_string);

    if (!proc_ovpn->waitForStarted()) //default wait time 30 sec
        qDebug() << " cannot start process ";

    int waitTime = 500; //60 sec
    if (!proc_ovpn->waitForFinished(waitTime))
        qDebug() << "timeout .. ";

    QString str(proc_ovpn->readAllStandardOutput());
    return str;
}

/**
 * GlobalFunctions :: setErrorMessage
 * 
 * Sets an error message widget over the parent widget, it annot be closed
 * 
 * @param  {QWidget*} parent : Parent widget of the error message
 * @param  {QString} mess    : Error message to display
 * @return {bool}            : Not using the return value, it was going to be use for a try catch
 */
bool GlobalFunctions::setErrorMessage(QWidget *parent, QString mess)
{
    QWidget *widget = new QWidget(parent);
    QWidget *widget_blur = new QWidget(parent);
    widget_blur->setFixedSize(320, 480);
    widget_blur->setStyleSheet("background-color: rgba(100, 100, 100, 100);");
    widget->setFixedSize(300, 150);
    widget->move(10, 165);
    widget->setStyleSheet("border-radius: 10px");

    QLabel *icon = new QLabel(widget);
    icon->setPixmap(QPixmap(":icons/main_menu/calibration_menu/error.png"));
    icon->setScaledContents(true);
    icon->setFixedSize(30, 30);
    icon->move(10, 10);

    QLabel *message = new QLabel(widget);
    QFont f = parent->font();
    message->setText("Error");
    message->setFont(f);
    message->move(120, 10);

    QPlainTextEdit *messageText = new QPlainTextEdit(widget);
    messageText->setFixedSize(300, 85);
    f.setPointSize(12);
    messageText->setPlainText(mess);
    messageText->setFont(f);
    messageText->move(10, 55);
    messageText->setReadOnly(true);

    QGraphicsDropShadowEffect *eff = new QGraphicsDropShadowEffect(parent);
    eff->setBlurRadius(20);
    eff->setOffset(1);
    eff->setColor(QColor(Qt::red));
    widget->setGraphicsEffect(eff);

    widget_blur->show();
    widget->show();
    widget->raise();

    return true;
}

/**
 * GlobalFunctions :: setWarningMessage
 * 
 * Sets an warning message widget over the parent widget
 * 
 * @param  {QWidget*} parent : Parent widget of the warning message
 * @param  {QString} mess    : Warning message to display
 * @return {QWidget *}            : Pointer to the widget that show the warning, for further proccessing
 */
QWidget * GlobalFunctions::setWarningMessage(QWidget *parent, QString mess)
{
    QWidget *widget = new QWidget(parent);
    QWidget *widget_blur = new QWidget(parent);
    widget->setAttribute(Qt::WA_DeleteOnClose);
    widget_blur->setAttribute(Qt::WA_DeleteOnClose);
    widget_blur->setFixedSize(320, 480);
    widget_blur->setStyleSheet("background-color: rgba(100, 100, 100, 100);");
    widget->setFixedSize(300, 150);
    widget->move(10, 165);
    widget->setStyleSheet("border-radius: 10px");

    QLabel *icon = new QLabel(widget);
    icon->setPixmap(QPixmap(":icons/main_menu/calibration_menu/information.png"));
    icon->setScaledContents(true);
    icon->setFixedSize(30, 30);
    icon->move(10, 10);

    QLabel *message = new QLabel(widget);
    QFont f = parent->font();    
    message->setText("Advertencia");
    f.setPointSize(14);
    message->setFont(f);
    message->move(85, 10);

    QPlainTextEdit *messageText = new QPlainTextEdit(widget);
    messageText->setFixedSize(300, 85);
    f.setPointSize(12);
    messageText->setPlainText(mess);
    messageText->setFont(f);
    messageText->move(10, 55);

    QGraphicsDropShadowEffect *eff = new QGraphicsDropShadowEffect(parent);
    eff->setBlurRadius(20);
    eff->setOffset(1);
    eff->setColor(QColor(Qt::red));
    widget->setGraphicsEffect(eff);

    QPushButton *accept_button = new QPushButton(widget);
    QIcon icon_accept(":icons/main_menu/calibration_menu/ok.png");
    accept_button->setIcon(icon_accept);
    accept_button->setIconSize(QSize(25, 25));

    accept_button->setText("ACEPTAR");
    accept_button->setFixedSize(100, 30);
    accept_button->move(190, 110);
    accept_button->raise();

    connect(accept_button, &QPushButton::clicked, widget, &QWidget::close);
    connect(accept_button, &QPushButton::clicked, widget_blur, &QWidget::close);

    connect(widget, &QWidget::destroyed, widget_blur, &QWidget::close);

    widget_blur->show();
    widget->show();
    widget->raise();

    return widget;
}

/**
 * GlobalFunctions :: saveData
 * 
 * Saves the calibration data on a JsonObject format:
 * (m, n, calibration state boolean,
 * date and time of calibration) on a file (save_config.dat)
 * 
 * @return {bool}  : True if was correctly saved false if not
 */
bool GlobalFunctions::saveData()
{
    QDir dir("/home/pi/VentiApp/");
    if (!dir.exists())
    {
        dir.mkpath("/home/pi/VentiApp/");
    }
    QFile file("/home/pi/VentiApp/save_config.dat");
    if (file.open(QIODevice::WriteOnly))
    {
        QJsonObject jsonObject;
        try {
            jsonObject.insert("lastCalibrationDateTime", lastCalibrationDateTime.toString("yyyy-MM-dd HH:mm:ss"));
        } catch (QException e) {

        }
        jsonObject.insert("m_slope_value", m_slope_value);
        jsonObject.insert("n_value", n_value);
        jsonObject.insert("calibrated", calibrated);
        QJsonDocument d;
        d.setObject(jsonObject);
        QDataStream out(&file);
        out << d.toJson(QJsonDocument::Compact);
        file.close();
        return true;
    }
    return false;
}

/**
 * GlobalFunctions :: loadData
 * 
 * Loads the calibration data saved on save_config.dat file
 * and returns the valid state of reading the file
 *  
 * @return {bool}  : True if data was read correctly, false if not
 */
bool GlobalFunctions::loadData()
{
    QDir dir("/home/pi/VentiApp/");
    if (!dir.exists())
    {
        dir.mkpath("/home/pi/VentiApp/");
        return false;
    }
    QFile file("/home/pi/VentiApp/save_config.dat");
    if (file.open(QIODevice::ReadOnly))
    {
        QJsonObject jsonObject;
        QJsonDocument d;
        QByteArray bytes;
        QDataStream in(&file);
        in >> bytes;
        d = QJsonDocument::fromJson(bytes);
        if (d.isObject())
        {
            jsonObject = d.object();
        }
        file.close();

        return readValues(jsonObject);
    }
    return false;
}

/**
 * GlobalFunctions :: readValues
 * 
 * This function is called on loadData(). 
 * It reads the calibration values on JsonObject
 * and validates the read values return boolean
 * state of validation
 * 
 * @param  {QJsonObject} jsonObject : JsonObjec that contains the calibration values
 * @return {bool}                   : True if read values are valid, false if not
 */
bool GlobalFunctions::readValues(QJsonObject jsonObject)
{
    double m = jsonObject.value("m_slope_value").toDouble();
    double n = jsonObject.value("n_value").toDouble();
    bool cal = jsonObject.value("calibrated").toBool();
    if (cal)
    {
        if (m > 0)
        {
            if ((n > -100) && (n < 100))
            {
                try {
                    QString date = jsonObject.value("lastCalibrationDateTime").toString();
                    if(!date.trimmed().isEmpty()){
                        lastCalibrationDateTime = QDateTime::fromString(date, "yyyy-MM-dd HH:mm:ss");
                    }
                } catch (QException e) {

                }
                n_value = n;
                m_slope_value = m;
                calibrated = cal;
                return true;
            }
        }
    }
    return false;
}

/**
 * GlobalFunctions :: checkIfFieldValid
 * 
 * Check whether a string is valid or not, it checks nullity,
 * emptyness and "null" string equality
 *   
 * @param  {QString} value : String value to check
 * @return {bool}          : True if string is valid, false if not
 */
bool GlobalFunctions::checkIfFieldValid(QString value)
{
    if (value != nullptr && !value.trimmed().isEmpty() && value.toLower() != "null")
    {
        return true;
    }
    return false;
}

/**
 * GlobalFunctions :: getRealValue
 * 
 * Processes the received sensor's thread value 
 * and applies the last calibration function
 * to correct the value
 *  
 * @param  {double} value : Unproccess value received sensor's thread
 * @return {double}       : Corrected value applying the calibration function (-1 if not calibrated)
 */
double GlobalFunctions::getRealValue(double value) 
{
    if (calibrated)
    {
        value = (m_slope_value * value) + n_value; //y = mx + n
        return value;
    }
    else
    {
        return -1;
    }
}

/**
 * GlobalFunctions :: loadBatteryConfiguration
 * 
 * This functions is worthless right now, not using it
 * 
 * @return {int}  : Maximun battery value setted on config file
 */
int GlobalFunctions::loadBatteryConfiguration()
{
    QDir dir("/home/pi/VentiApp/");
    if (!dir.exists())
    {
        dir.mkpath("/home/pi/VentiApp/");
        return 1900;
    }
    QFile file("/home/pi/VentiApp/battery_config.dat");
    if (file.open(QIODevice::ReadOnly))
    {
        QJsonObject jsonObject;
        QByteArray bytes;
        QDataStream in(&file);
        in >> bytes;
        file.close();
        bool ok = false;
        int number = bytes.toInt(&ok);
        if (ok)
        {
            return number;
        }
    }
    return 1900;
}

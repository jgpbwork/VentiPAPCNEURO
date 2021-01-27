#include "globalfunctions.h"
#include <QFile>
#include <QJsonObject>
#include <QDataStream>
#include <QJsonDocument>
#include <QLabel>
#include <QDebug>
#include <QPlainTextEdit>
#include <QGraphicsDropShadowEffect>
#include <QProcess>

bool GlobalFunctions::myanimationEnabled = true;
int GlobalFunctions::configured_min_limit = 16;
int GlobalFunctions::configured_max_limit = 28;
double GlobalFunctions::lastSettedValue = -1;
double GlobalFunctions::m_slope_value = -1;
double GlobalFunctions::n_value = -1;
bool GlobalFunctions::calibrated = false;
QDateTime GlobalFunctions::dateTime = QDateTime::currentDateTime();

GlobalFunctions::GlobalFunctions(QWidget *parent) : QWidget(parent)
{

}


QString GlobalFunctions::setDateTimeInRaspi(QWidget *parent, QDateTime dt){
    dateTime = dt;
    //sudo date -s "21 APR 2020 19:45:00"
    QMap<QString, int> mapMonthEnglish;
    mapMonthEnglish.insert("JANUARY", 1);
    mapMonthEnglish.insert("FEBRUARY" , 2);
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

    QString day =  " \"" + QString::number(dt.date().day());
    QString month = " " + mapMonthEnglish.key(dt.date().month()).left(3);
    QString year = " " + QString::number(dt.date().year());

    QString date_string = "sudo date -s" + day + month + year;
    QString time_string = " " + dt.time().toString("HH:mm:ss") + "\"";
    QProcess *proc_ovpn = new QProcess(parent);
    proc_ovpn->setProcessChannelMode(QProcess::MergedChannels);

    proc_ovpn->start("sh",QStringList() << "-c" << date_string + time_string);

    if(!proc_ovpn->waitForStarted()) //default wait time 30 sec
        qDebug() << " cannot start process ";

    int waitTime = 500 ; //60 sec
    if (!proc_ovpn->waitForFinished(waitTime))
        qDebug() << "timeout .. ";

    QString str(proc_ovpn->readAllStandardOutput());
    return str;
}

bool GlobalFunctions::setErrorMessage(QWidget *parent, QString mess){
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
    icon->move(10,10);

    QLabel *message = new QLabel(widget);
    QFont f = parent->font();
    message->setText("Error");
    message->setFont(f);
    message->move(120,10);

    QPlainTextEdit *messageText = new QPlainTextEdit(widget);
    messageText->setFixedSize(300, 85);
    f.setPointSize(12);
    messageText->setPlainText(mess);
    messageText->setFont(f);
    messageText->move(10,55);

    QGraphicsDropShadowEffect *eff = new QGraphicsDropShadowEffect(parent);
    eff->setBlurRadius(20);
    eff->setOffset(1);
    eff->setColor(QColor(Qt::red));
    widget->setGraphicsEffect(eff);

    widget_blur->show();
    widget->show();
    widget->raise();
}
bool GlobalFunctions::saveData(){
    QFile file("save_config.dat");
    if(file.open(QIODevice::WriteOnly)){
        QJsonObject jsonObject;
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

bool GlobalFunctions::loadData(){
    QFile file("save_config.dat");
    if(file.open(QIODevice::ReadOnly)){
        QJsonObject jsonObject;
        QJsonDocument d;
        QByteArray bytes;
        QDataStream in(&file);
        in >> bytes;
        d = QJsonDocument::fromJson(bytes);
        if(d.isObject()){
            jsonObject = d.object();
        }
        readValues(jsonObject);
        file.close();
        return true;
    }
    return false;
}

bool GlobalFunctions::readValues(QJsonObject jsonObject)
{
    double m = jsonObject.value("m_slope_value").toDouble();
    double n = jsonObject.value("n_value").toDouble();
    bool cal = jsonObject.value("calibrated").toBool();
    if(cal){
        if(m > 0){
            if((n > -10) && (n < 10)){
                n_value = n;
                m_slope_value = m;
                calibrated = cal;
                return true;
            }
        }
    }
    return false;
}

bool GlobalFunctions::checkIfFieldValid(QString value)
{
    if(value != nullptr && !value.trimmed().isEmpty() && value.toLower() != "null"){
        return true;
    }
    return false;
}

double GlobalFunctions::getRealValue(double value) //aplica la correcion de la calibracion
{
    if(calibrated){
        value = (m_slope_value*value) + n_value; //y = mx + n
        return value;
    }else{
        return -1;
    }
}

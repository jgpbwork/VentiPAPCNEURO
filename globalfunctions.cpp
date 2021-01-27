#include "globalfunctions.h"
#include <QFile>
#include <QJsonObject>
#include <QDataStream>
#include <QJsonDocument>
#include <QLabel>
#include <QDebug>
#include <QPlainTextEdit>
#include <QGraphicsDropShadowEffect>


bool GlobalFunctions::myanimationEnabled = true;
int GlobalFunctions::configured_min_limit = 16;
int GlobalFunctions::configured_max_limit = 28;
double GlobalFunctions::lastSettedValue = -1;
double GlobalFunctions::m_slope_value = -1;
double GlobalFunctions::n_value = -1;
bool GlobalFunctions::calibrated = false;

GlobalFunctions::GlobalFunctions(QWidget *parent) : QWidget(parent)
{

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

#include "globalfunctions.h"
#include <QFile>
#include <QJsonObject>
#include <QDataStream>
#include <QJsonDocument>

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
        out << d.toJson();
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
        d.fromJson(bytes);
        jsonObject = d.object();
        readValues(jsonObject);
        file.close();
        return true;
    }
    return false;
}

bool GlobalFunctions::readValues(QJsonObject jsonObject)
{
    m_slope_value = jsonObject.value("m_slope_value").toDouble();
    n_value = jsonObject.value("n_value").toDouble();
    calibrated = jsonObject.value("calibrated").toBool();
    return true;
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
        value = (value - n_value)/m_slope_value; //y = mx + n
        return value;
    }else{
        return -1;
    }
}

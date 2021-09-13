/**
 * Created by Ing. Luis Alejandro Reyes Morales on 8/12/2020.
 *
 * email: inglreyesm@gmail.com
 * github: https://github.com/lreyesm
 * linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
 *
 */

#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

#include <QWidget>
#include <QDateTime>
#define MIN_BATTERY_LEVEL 21772

class GlobalFunctions : public QWidget
{
    Q_OBJECT
public:
    explicit GlobalFunctions(QWidget *parent = nullptr);
    static bool myanimationEnabled;
    static bool checkIfFieldValid(QString);
    static double getRealValue(double value);

    static int configured_max_limit;
    static int configured_min_limit;
    static double lastSettedValue;

    static QDateTime lastCalibrationDateTime;
    static double m_slope_value;
    static double n_value;
    static bool calibrated;

    static QDateTime dateTime;

    static bool saveData();
    static bool loadData();
    static bool readValues(QJsonObject);
    static QWidget * setWarningMessage(QWidget *parent, QString mess);
    static bool setErrorMessage(QWidget *parent, QString mess);
    static QString setDateTimeInRaspi(QWidget *parent, QDateTime dt);

    static int loadBatteryConfiguration();

    static int lastBatteryLevel;
signals:

public slots:
};

#endif // GLOBALFUNCTIONS_H

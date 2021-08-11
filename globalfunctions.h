#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

#include <QWidget>
#include <QDateTime>

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

    static double m_slope_value;
    static double n_value;
    static bool calibrated;

    static QDateTime dateTime;

    static bool saveData();
    static bool loadData();
    static bool readValues(QJsonObject);
    static bool setWarningMessage(QWidget *parent, QString mess);
    static bool setErrorMessage(QWidget *parent, QString mess);
    static QString setDateTimeInRaspi(QWidget *parent, QDateTime dt);

    static int loadBatteryConfiguration();
signals:

public slots:
};

#endif // GLOBALFUNCTIONS_H

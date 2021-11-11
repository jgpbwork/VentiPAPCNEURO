#ifndef ThrButtonQuery_H
#define ThrButtonQuery_H

#include <QtCore>
#include <QObject>
#include <QThread>

#include "Singleton.h"
#include "Time.h"
#include "DrvGpio.h"

class ThrButtonQuery : public QObject,
                 public Singleton<ThrButtonQuery>,
                 public Time
{
    Q_OBJECT
public:
    explicit ThrButtonQuery(QObject *parent = nullptr);

    ~ThrButtonQuery();

    bool configureSignal();

signals:
    void ButtonPressed();

public slots:
    void shutdown();

private slots:

private:
    QThread* qThrButtonQuery_;
    QTimer *timer;

    DrvGpio gpioButton;

    [[noreturn]] static void ThrButtonQueryRun();

};

#endif // ThrButtonQuery_H

#include "ThrButtonQuery.h"
#include "mainwindow.h"

#include <wiringPi.h>
#include <QMath.h>
#include <QDebug>

#define BUTTON_PIN 4

ThrButtonQuery::ThrButtonQuery(QObject *parent) : QObject (),
                                      Singleton(this),
                                      Time() 
{
    Q_UNUSED(parent)

}

ThrButtonQuery::~ThrButtonQuery()
{    
    this->qThrButtonQuery_->exit();
//    this->qThrAlarm_->wait();
    qDebug() << "At Destructor: ThrButtonQuery isFinished: " << this->qThrButtonQuery_->isFinished();
    if(this->qThrButtonQuery_->isRunning()) {
        this->qThrButtonQuery_->terminate();
    }
//    this->gpioBuzzer.write(BUZZER_PIN, DrvGpio::GPIO_LOW);
    //emit this->finished();
}

void ThrButtonQuery::ThrButtonQueryRun() 
{

}

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

    this->gpioButton.setup(BUTTON_PIN, DrvGpio::GPIO_IN);

    qThrButtonQuery_ = QThread::create(&ThrButtonQuery::ThrButtonQueryRun);
    if(qThrButtonQuery_ != nullptr) {
        qThrButtonQuery_->setParent(this);
        qThrButtonQuery_->setObjectName("ThrButtonQuery");
        qThrButtonQuery_->setPriority(QThread::TimeCriticalPriority);
        this->moveToThread(qThrButtonQuery_);

        connect(this, SIGNAL(ButtonPressed()), this, SLOT(shutdown()));
        connect(qThrButtonQuery_, &QThread::finished, this, &QObject::deleteLater);
        connect(this, SIGNAL(finished()), qThrButtonQuery_, SLOT(quit()));
        connect(this, SIGNAL(finished()), qThrButtonQuery_, SLOT(deleteLater()));
        qThrButtonQuery_->start();
    }

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
     int status;
     while (true)
     {
        status = ThrButtonQuery::instance().gpioButton.read(BUTTON_PIN);
        if(status)
        {
            ThrButtonQuery::instance().qThrButtonQuery_->msleep(10);
        }
     }
}

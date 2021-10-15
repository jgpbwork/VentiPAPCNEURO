#include "ThrButtonQuery.h"
#include "mainwindow.h"

#include <wiringPi.h>
#include <QMath.h>
#include <QDebug>

#define BUTTON_PIN 4

bool ThrButtonQuery::alarm_;
std::uint8_t ThrButtonQuery::alarmPriority_;

ThrButtonQuery::ThrButtonQuery(QObject *parent) : QObject (),
                                      Singleton(this),
                                      Time() 
{
    Q_UNUSED(parent)

}

ThrButtonQuery::~ThrButtonQuery()
{    

}

void ThrButtonQuery::ThrButtonQueryRun() 
{

}

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

}

void ThrButtonQuery::ThrButtonQueryRun() 
{

}

/**
* Created by Ing. Luis Alejandro Reyes Morales on 11/11/2019.
*
* email: inglreyesm@gmail.com
* github: https://github.com/lreyesm
* linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
*
*/
 
#ifndef PROCESSESCLASS_H
#define PROCESSESCLASS_H

#include <QtCore>

class ProcessesClass
{

public:
    enum{WINDOWS, LINUX}typedef OPtype;

    ProcessesClass();

    static QString executeProcess(QObject *parent = nullptr, QString process = "",
                                  OPtype so = LINUX, int waitTime = 500,
                                  bool close_on_finished = true);


};

#endif // PROCESSESCLASS_H

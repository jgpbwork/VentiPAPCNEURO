/**
* Created by Ing. Luis Alejandro Reyes Morales on 11/11/2019.
*
* email: inglreyesm@gmail.com
* github: https://github.com/lreyesm
* linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
*
*/

#include "processesclass.h"

/**
 * ProcessesClass::ProcessesClass 
 * 
 * Constructor of the static class
 */
ProcessesClass::ProcessesClass()
{

}

/**
 * ProcessesClass 
 * 
 * Executes a cmd proccess on Windows or Linux,
 * waits the execution for a defined timeout and
 * returns the response of the console
 *
 * @param  {QObject*} parent        : Parent of the process
 * @param  {QString} process        : String containing the commands to execute
 * @param  {OPtype} so              : Type of Operating system WINDOWS or LINUX
 * @param  {int} waitTime           : Wait time for the proccess to ended and function´s return
 * @param  {bool} close_on_finished : Close the console on process finished or not
 * @return {QString}                : String response of the console
 */

QString ProcessesClass::executeProcess(QObject *parent, QString process, OPtype so,
                                       int waitTime, bool close_on_finished)
{
    QString response="";

    if(so == LINUX){
        QProcess *proc_ovpn = new QProcess(parent);
        proc_ovpn->setProcessChannelMode(QProcess::MergedChannels);

        proc_ovpn->start("sh",QStringList() << "-c" << process);

        if(!proc_ovpn->waitForStarted()) //default wait time 30 sec
            qDebug() << " cannot start process ";

        if (!proc_ovpn->waitForFinished(waitTime))
            qDebug() << "timeout .. ";

        response = proc_ovpn->readAllStandardOutput();

        if(close_on_finished){
            proc_ovpn->close();
        }

    }else if(so == WINDOWS){

        QProcess *proc_ovpn = new QProcess(parent);
        proc_ovpn->setProcessChannelMode(QProcess::MergedChannels);
        proc_ovpn->start("C:/windows/system32/cmd.exe",QStringList()<<"/C"<<process);
        if(!proc_ovpn->waitForStarted()) //default wait time 30 sec
            qDebug() << " cannot start process ";

        if (!proc_ovpn->waitForFinished(waitTime))
            qDebug() << "timeout .. ";

        response = proc_ovpn->readAllStandardOutput();
        if(close_on_finished){
            proc_ovpn->close();
        }
    }
    return response;
}

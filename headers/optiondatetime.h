/**
* Created by Ing. Luis Alejandro Reyes Morales on 9/12/2020.
*
* email: inglreyesm@gmail.com
* github: https://github.com/lreyesm
* linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
*
*/

#ifndef OPTIONDATETIME_H
#define OPTIONDATETIME_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class OptionDateTime;
}

class OptionDateTime : public QWidget
{
    Q_OBJECT

public:
    explicit OptionDateTime(QWidget *parent = nullptr);
    ~OptionDateTime();

public slots:
    void setDate(QDateTime currentDateTime);
signals:
    void closing();


private slots:
    void on_l_date_time_back_clicked();
    void on_l_define_date_clicked();

    void on_l_define_time_clicked();

    void on_l_12_hours_clicked();
    void on_l_24_hours_clicked();
    void showBackMenu();
    void hideBackMenu();
private:
    Ui::OptionDateTime *ui;
};

#endif // OPTIONDATETIME_H


<<<<<<< HEAD
#ifndef OPTIONSETTIME_H
#define OPTIONSETTIME_H

#include <QWidget>

namespace Ui {
class OptionSetTime;
}

class OptionSetTime : public QWidget
{
    Q_OBJECT

public:
    explicit OptionSetTime(QWidget *parent = nullptr);
    ~OptionSetTime();

private slots:
    void on_l_save_clicked();

    void on_l_define_time_back_clicked();

    void on_pb_minutes_down_clicked();

    void on_pb_minutes_up_clicked();

    void on_pb_hours_down_clicked();

    void on_pb_hours_up_clicked();

private:
    Ui::OptionSetTime *ui;
};

#endif // OPTIONSETTIME_H
=======
#ifndef OPTIONSETTIME_H
#define OPTIONSETTIME_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class OptionSetTime;
}

class OptionSetTime : public QWidget
{
    Q_OBJECT

public:
    explicit OptionSetTime(QWidget *parent = nullptr);
    ~OptionSetTime();

signals:
    void closing();

private slots:
    void on_l_save_clicked();

    void on_l_define_time_back_clicked();

    void on_pb_minutes_down_clicked();

    void on_pb_minutes_up_clicked();

    void on_pb_hours_down_clicked();

    void on_pb_hours_up_clicked();

private:
    Ui::OptionSetTime *ui;
    QDateTime currentDateTime;
    QString dateTimeProcessInRaspi(QDateTime dt);
};

#endif // OPTIONSETTIME_H
>>>>>>> 9090ceb909ef3c3f4473bedbfa53a0fa127bc4ed

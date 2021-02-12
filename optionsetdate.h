#ifndef OPTIONSETDATE_H
#define OPTIONSETDATE_H

#include <QWidget>
#include <QMap>
#include <QDateTime>

namespace Ui {
class OptionSetDate;
}

class OptionSetDate : public QWidget
{
    Q_OBJECT

public:
    explicit OptionSetDate(QWidget *parent = nullptr);
    ~OptionSetDate();

signals:
    void closing();
    void dateSetted(QDateTime);
private slots:
    void on_pb_day_down_clicked();
    void on_pb_day_up_clicked();
    void on_pb_month_down_clicked();
    void on_pb_month_up_clicked();
    void on_pb_year_down_clicked();
    void on_pb_year_up_clicked();

    void on_l_save_clicked();

    void on_l_define_date_back_clicked();

    void updateDateInfo();
private:
    Ui::OptionSetDate *ui;
    QMap<QString, int> mapMonth;
    void fillJsonDate();
    QDateTime currentDateTime;
};

#endif // OPTIONSETDATE_H


#ifndef OPTIONDATETIME_H
#define OPTIONDATETIME_H

#include <QWidget>

namespace Ui {
class OptionDateTime;
}

class OptionDateTime : public QWidget
{
    Q_OBJECT

public:
    explicit OptionDateTime(QWidget *parent = nullptr);
    ~OptionDateTime();

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


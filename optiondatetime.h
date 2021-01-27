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
private:
    Ui::OptionDateTime *ui;
};

#endif // OPTIONDATETIME_H

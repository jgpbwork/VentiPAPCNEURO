#ifndef OPTIONGENERAL_H
#define OPTIONGENERAL_H

#include <QWidget>

namespace Ui {
class OptionGeneral;
}

class OptionGeneral : public QWidget
{
    Q_OBJECT

public:
    explicit OptionGeneral(QWidget *parent = nullptr);
    ~OptionGeneral();
signals:
    void closing();
private slots:
    void on_l_general_back_clicked();
    void on_l_about_clicked();
private:
    Ui::OptionGeneral *ui;
};

#endif // OPTIONGENERAL_H

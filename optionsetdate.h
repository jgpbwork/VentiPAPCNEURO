#ifndef OPTIONSETDATE_H
#define OPTIONSETDATE_H

#include <QWidget>

namespace Ui {
class OptionSetDate;
}

class OptionSetDate : public QWidget
{
    Q_OBJECT

public:
    explicit OptionSetDate(QWidget *parent = nullptr);
    ~OptionSetDate();

private:
    Ui::OptionSetDate *ui;
};

#endif // OPTIONSETDATE_H

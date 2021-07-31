#ifndef ABOUTSCREEN_H
#define ABOUTSCREEN_H

#include <QWidget>

namespace Ui {
class AboutScreen;
}

class AboutScreen : public QWidget
{
    Q_OBJECT

public:
    explicit AboutScreen(QWidget *parent = nullptr);
    ~AboutScreen();

signals:
    void closing();

private slots:
    void on_l_about_back_clicked();

private:
    Ui::AboutScreen *ui;
};

#endif // ABOUTSCREEN_H

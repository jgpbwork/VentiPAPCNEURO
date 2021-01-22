#ifndef MYLABELANIMATED_H
#define MYLABELANIMATED_H

#include <QLabel>
#include <QMouseEvent>
#include <QPropertyAnimation>

#define ANIM_TIME_L 150
#define ANIM_SCALE_L 10

class MyLabelAnimated : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabelAnimated(QWidget *parent = nullptr);
     ~MyLabelAnimated();
    void setEditable(bool);
    void setTextInfo(QString information);
    bool isActivatedState(){
        return activated_state;
    }
    void setActivadeState(bool state){
        activated_state = state;
    }
    void setAnimationInit();
    void setAnimation(QPropertyAnimation *);
    void startAnimation(int delay = 0, int scale =ANIM_SCALE_L, int anim_time =ANIM_TIME_L);

    void setChecked(bool checked);
    bool isChecked();


    void setBackgroundImage(const QString image_filename);
signals:
    void doubleClickedLabel();
    void mouseLeftClicked(QString);
    void pressed();
    void clicked();
    void send_text(QString);
    void mouseEntered(QPoint);

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

public slots:
    void hideChilds();

private slots:
    void setAnimationEnd();
    void finalizadaAnimacion();
    void setFotoInit(const QString&);
    void emitirClicked();
private:
    QString info ="";
    bool activated_state=false;
    bool animationOnGoing =false;
    QPropertyAnimation *animation=nullptr;
    QRect startValue;
    QRect endValue;
    QSize maxSize, minSize;
    int anim_scale = ANIM_SCALE_L;
    int anim_time = ANIM_TIME_L;
    bool emit_enabled = true;

};

#endif // MYLABELANIMATED_H

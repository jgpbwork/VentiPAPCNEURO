/**
* Created by Ing. Luis Alejandro Reyes Morales on 12/11/2019.
*
* email: inglreyesm@gmail.com
* github: https://github.com/lreyesm
* linkedin: https://linkedin.com/in/luis-alejandro-reyes-morales-9b672012a
*
*/

#include "mylabelstateanimated.h"
#include <QTimer>


MyLabelStateAnimated::MyLabelStateAnimated(QWidget *parent)
    :QLabel(parent)
{
    this->setMouseTracking(true);

    QPoint p = this->pos();
    connect(this, SIGNAL(objectNameChanged(const QString&)), this, SLOT(setFotoInit(const QString&)));
}

MyLabelStateAnimated::~MyLabelStateAnimated()
{
    //    delete animation;
}

void MyLabelStateAnimated::setFotoInit(const QString& n)
{
    disconnect(this, SIGNAL(objectNameChanged(const QString&)), this, SLOT(setFotoInit(const QString&)));
    info = n;
    if(!info.isEmpty()){
        if(info.contains("_")){
            QStringList name = info.split("_");
            if(name.size() >= 2){
                name.removeAt(0);
                info = name.join("_").trimmed();
            }
        }
        if(QFile::exists(":/icons/" + info + "_off.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_off.png"));
        }
    }
}
void MyLabelStateAnimated::setAnimationInit()
{
    int anim_scale_width = this->width() * static_cast<float>(anim_scale)/100;
    int anim_scale_height = this->height() * static_cast<float>(anim_scale)/100;

    startValue = this->geometry();
    endValue = QRect(startValue.x()+anim_scale_width,startValue.y() +anim_scale_height
                     ,startValue.width() - anim_scale_width*2,startValue.height() - anim_scale_height*2);
    minSize= this->minimumSize();
    if(((minSize.width() -  anim_scale_width*2) > 0) && ((minSize.height() - anim_scale_height*2) > 0)){
        this->setMinimumSize(minSize.width() -  anim_scale_width*2, minSize.height() - anim_scale_height*2);
    }
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
}
void MyLabelStateAnimated::setAnimationEnd()
{
    //    disconnect(animation, &QPropertyAnimation::finished, this, &MyLabelStateAnimated::setAnimationEnd);
    //    disconnect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    delete animation;
    animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(anim_time);
    animation->setStartValue(endValue);
    animation->setEndValue(startValue);
    connect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    animation->start();
}
void MyLabelStateAnimated::finalizadaAnimacion()
{
    disconnect(animation, SIGNAL(finished()), this, SLOT(finalizadaAnimacion()));
    this->setMinimumSize(minSize);
    delete animation;
    animationOnGoing = false;
    QTimer::singleShot(50, this, SLOT(emitirClicked()));

    startValue = this->geometry();
}

void MyLabelStateAnimated::startAnimationFromChild()
{
    if(!animationOnGoing){
        if(!isChecked()){
            setChecked(true);
        }
        startAnimation(true);
    }
}

void MyLabelStateAnimated::emitirClicked()
{
    if(emit_enabled){
        emit clicked();
        emit send_text(this->text());
    }
}

void MyLabelStateAnimated::startAnimation(bool emit_clicked, int scale, int anim_tim)
{
    //hacer un single shot con delay
    animationOnGoing = true;
    emit_enabled = emit_clicked;
    anim_time = anim_tim;
    anim_scale = scale;
    setAnimationInit();
    connect(animation, SIGNAL(finished()), this, SLOT(setAnimationEnd()));
    animation->start();
}

void MyLabelStateAnimated::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    label_size = this->size();
    if(!this->is_Enabled()){
        return;
    }
    if(!animationOnGoing){
        if(!isChecked()){
            setChecked(true);
        }else {
            setChecked(false);
        }
        if(!startValue.isEmpty()){
            if(startValue.size() != this->geometry().size()){
                this->setGeometry(startValue);
            }
        }
        startValue = this->geometry();
        if(GlobalFunctions::myanimationEnabled){
            startAnimation(true);
        }else{
            emitirClicked();
        }
    }
}

void MyLabelStateAnimated::moveEvent(QMoveEvent *event)
{
    QWidget::moveEvent(event);
}
void MyLabelStateAnimated::setChecked(bool checked){
    if(checked){
        activated_state = true;
        if(QFile::exists(":/icons/" + info + "_on.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_on.png"));
        }
    }else{
        activated_state = false;
        if(QFile::exists(":/icons/" + info + "_off.png")){
            this->setPixmap(QPixmap(":/icons/" + info + "_off.png"));
        }
    }
}
bool MyLabelStateAnimated::isChecked(){
    return activated_state;
}

#include "mypushbutton.h"
#include<QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
//{
//}
MyPushButton::MyPushButton(QString normalImg,QString pressImg )
{
    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;
    QPixmap pix;
    bool ret=pix.load(normalImg);
    if(!ret)
    {
            return;
    }
    //设置图片大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("border:none;");
    //this->setMask(pix.mask());
    //设置图标及大小
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

}
void MyPushButton::zoom1()
{
    QPropertyAnimation *animation =new QPropertyAnimation(this,"geometry");
    //设置动画间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}
void MyPushButton::zoom2()
{
    QPropertyAnimation *animation =new QPropertyAnimation(this,"geometry");
    //设置动画间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

#include "victory.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QDebug>
victory::victory(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1282, 800);
    this->setWindowTitle("win");
    this->setWindowIcon(QIcon(":/UNO2D/star.png"));
    MyPushButton *winquit = new MyPushButton(":/UNO2D/winquit.png");
    winquit->setParent(this);
    winquit->move(550, 500);
    connect(winquit, &MyPushButton::clicked, [=]() {
        //弹起特效
        winquit->zoom1();
        winquit->zoom2();
        QTimer::singleShot(400, this, [=]() {
            this->close();
        });
    });
}
 void victory::paintEvent(QPaintEvent *)
 {
     QPainter painter(this);
     QPixmap pix,pix2;
     pix.load(":/UNO2D/back3.png");
     painter.drawPixmap(this->rect(), pix);
     pix2.load(":/UNO2D/win.png");
     painter.drawPixmap(500,150,pix2.width(),pix2.height(),pix2);
 }

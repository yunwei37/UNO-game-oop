#include "mygamewindow.h"
#include <QMainWindow>
#include <QDebug>
#include "qevent.h"
#include "qtimer.h"
#include "qpainter.h"
#include "qpixmap.h"
#include "QEventLoop"
#include "qpropertyanimation.h"

myGameWindow::myGameWindow(QWidget *parent) : QMainWindow(parent)
{
    setStyleSheet("QWidget{font-family:方正粗圆简体;}");
    setFixedSize(1299, 731);
    this->setWindowIcon(QIcon(":/UNO2D/star.png"));
    //cardStack = CardWidget(0,0,false,this);
    turnDirection = true;

    MyPushButton *setBtn=new MyPushButton(":/UNO2D/set.png");
    setBtn->setParent(this);
    setBtn->move(0,0);
    connect(setBtn,&MyPushButton::clicked,[=]()
    {
        qDebug()<<"点击了退出";
        //弹起特效
        setBtn->zoom1();
        setBtn->zoom2();
        QTimer::singleShot(400,this,[=](){
            //关闭场景
            this->close();
        });
    });

}

void myGameWindow::showCards()
{
    //获取牌的张数
    int n = MyCards.size();
    if (n == 0)
        return;
    //自己的牌左边(X)位置计算
    int left = (width() - (n - 1) * 40 - MyCards[0]->width()) / 2;
    //自己的牌上面(Y)位置
    int top = height() - MyCards[0]->height() - 70;


    for (int i = 0; i < n; i++)
    {
        //自己的牌 只需更新X位置从左到右
        MyCards[i]->setGeometry(580,300,90,140);
        MyCards[i]->move(left + i * 40, top);
        MyCards[i]->show();
        MyCards[i]->raise();
        //如果牌是选中状态，保持选中状态
        if (MyCards[i]->getIsClick())
        {
            MyCards[i]->setClick(true);
        }
    }
}

void myGameWindow::showPlayers()
{
    int n = Players.size();
    if (n == 0)
        return;

    Players[0]->setGeometry(500,300,213,270);
    Players[0]->move(width()*0.75, height()*0.50);
    Players[0]->show();
    Players[0]->raise();

    Players[1]->setGeometry(500,300,213,270);
    Players[1]->move(width()*0.1, height()*0.33);
    Players[1]->show();
    Players[1]->raise();
}

void myGameWindow::changeDirection()
{
    turnDirection = ~turnDirection;
    update();
}

void myGameWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    if(turnDirection){
        pix.load(":/UNO2D/back1.png");
    }else{
        pix.load(":/UNO2D/back2.png");
    }
        painter.drawPixmap(this->rect(), pix);
    showCards();
    showPlayers();
}

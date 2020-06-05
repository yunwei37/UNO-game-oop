#include "mygamewindow.h"
#include <QMainWindow>
#include "qevent.h"
#include "qtimer.h"
#include "qpainter.h"
#include "qpixmap.h"
#include "QEventLoop"
#include "qpropertyanimation.h"

myGameWindow::myGameWindow(QWidget *parent) : QMainWindow(parent)
{
    setStyleSheet("QWidget{font-family:方正粗圆简体;}");
    setFixedSize(1282,800);
    //cardStack = CardWidget(0,0,false,this);
}

void myGameWindow::showCards()
{
    //获取牌的张数
    int n= MyCards.size();
    if(n==0)
        return;
    //自己的牌左边(X)位置计算
    int left=(width()-(n-1)*40-MyCards[0]->width())/2;
    //自己的牌上面(Y)位置
    int top=height()-MyCards[0]->height()-70;
    //下家Y起始位置
    int topSpace1=height()-(height()-(n-1)*11-MyCards[0]->height())/2-60;
    //上家Y起始位置
    int topSpace2=(height()-(n-1)*11-MyCards[0]->height())/2+20;

    for(int i=0;i<n;i++)
    {
        //自己的牌 只需更新X位置从左到右
        MyCards[i]->move(left+i*40,top);
        MyCards[i]->raise();
        //如果牌是选中状态，保持选中状态
        if(MyCards[i]->getIsClick())
        {
            MyCards[i]->setClick(true);
        }
    }
}


void myGameWindow::paintEvent(QPaintEvent *event)
{
    //定义画板为本背景
    QPainter painter(this);

     //导入图像
    QPixmap pix(":/UNO2D/bg.png");

    //绘到窗口中，rect()是窗口大小，位置是 0，0，width(),height()
    painter.drawPixmap(rect(),pix);
}






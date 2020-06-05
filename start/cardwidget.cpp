#include "cardwidget.h"
#include "qpainter.h"
#include "QMouseEvent"

bool CardWidget::getIsClick() const
{
    return isClick;
}

CardWidget::CardWidget(QWidget *parent) : QWidget(parent)
{

}

CardWidget::CardWidget(int id,int color, bool isShow, QWidget *parent) : QWidget(parent)
{
    this->id = id;
    this->color = color;
    this->isShow = isShow;
    QString colorMap[] = {"Blue", "Green", "Red", "Yellow"};
    QString resName = ":/UNO2D/";
    if(id < 10){
        char buffer[20];
        resName += colorMap[color]+QString(itoa(id,buffer,10))+".jpg";
    }else if(id==10){
        resName += colorMap[color]+"Drawtwo"+".jpg";
    }
    else if(id==11){
        resName += colorMap[color]+"Reverse"+".jpg";
    }
    else if(id==12){
        resName += colorMap[color]+"Skip"+".jpg";
    }
    this->pix = QPixmap(resName);
    this->backpix = QPixmap(":/UNO2D/Cardback.jpg");
}

void CardWidget::setClick(bool b)
{
    isClick=b;
    if(isClick)
    {
        move(this->x(),this->y()-30);
    }
    else
    {
        move(this->x(),this->y()+30);
    }
    //更新重绘
    update();
}

void CardWidget::setSelected(bool b)
{
    isSelected=b;
     //更新重绘
    update();
}

void CardWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);//定义画板为自己背景，相当于VS中DC pDC
    //设置去毛边 高质量模式
    painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
    //透明覆盖
    painter.fillRect(this->rect(), QBrush(Qt::transparent));
    //定义一个图像用来绘到背景
    QPixmap thisPix(width(),height());
    if(isShow)
    {
        thisPix=this->pix;

        QPainter painter2;//重新定义一个画板为 thisPix
        painter2.begin(&thisPix);//画板开始
            //设置去毛边 高质量模式
        painter2.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);

        if(isSelected)//如果选中了，上面添加一层透明度为100的颜色
        {
            painter2.setBrush(QColor(44,44,44,100));
            painter2.drawRect(rect());
        }
        painter2.end();//画板结束

    }
    else//不显示直接绘牌的背面
    {
        thisPix=this->backpix;
    }

     //绘制到背景上去
    painter.drawPixmap(this->rect(),thisPix);
}


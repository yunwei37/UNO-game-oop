#include "cardwidget.h"
#include "qpainter.h"
#include "QMouseEvent"
#include <QDebug>

bool CardWidget::getIsClick() const
{
    return isClick;
}

CardWidget::CardWidget(QWidget *parent) : QWidget(parent)
{
    this->isShow = false;
    this->pix = QPixmap(":/UNO2D/Cardback.jpg");
}

CardWidget::CardWidget(int id, int color, QWidget *parent) : QWidget(parent)
{
    this->id = id;
    this->color = color;
    this->isClick = false;
    this->isShow = true;
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(this, SIGNAL(clicked()), this, SLOT(mouseClicked()));

    QString colorMap[] = {"Blue", "Green", "Red", "Yellow"};
    QString rresName = ":/UNO2D/";
    char buffer[] = "0";

    if (id < 10)
    {
        buffer[0]+=id;
        rresName += colorMap[color];
        rresName += buffer;
        rresName += ".jpg";
    }
    else if (id == 10)
    {
        rresName += colorMap[color] + "Drawtwo" + ".jpg";
    }
    else if (id == 11)
    {
        rresName += colorMap[color] + "Reverse" + ".jpg";
    }
    else if (id == 12)
    {
        rresName += colorMap[color]+"Skip" + ".jpg";
    }
    else if(id==13)
    {
        rresName =rresName + "Wild" + ".jpg";
    }
    else if(id==14)
    {
        rresName =rresName + "DrawFour" + ".jpg";
    }
    this->resName=rresName;

    this->pix = QPixmap(this->resName);
}

void CardWidget::setClick(bool b)
{
    if(isShow == false)
        return;
    isClick = b;
    if (isClick)
    {
        move(this->x(), this->y() - 30);
    }
    else
    {
        move(this->x(), this->y() + 30);
    }
    //更新重绘
    update();
}

void CardWidget::setSelected(bool b)
{
    isSelected = b;
    //更新重绘
    update();
}

void CardWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this); //定义画板为自己背景，相当于VS中DC pDC
    //设置去毛边 高质量模式
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    //透明覆盖
    painter.fillRect(this->rect(), QBrush(Qt::transparent));
    //定义一个图像用来绘到背景
    QPixmap thisPix(width(), height());
    thisPix = this->pix;
    //绘制到背景上去
    painter.drawPixmap(this->rect(), thisPix);
}

void CardWidget::mousePressEvent(QMouseEvent *event)
{
    setClick(!isClick);
    qDebug()<<"clicked";
}

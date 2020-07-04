#include "transformation.h"
#include <QPainter>
transformation::transformation(QWidget *parent) : QWidget(parent)
{
    id = trans[trans.length() - 1]->id;
    color = trans[trans.length() - 1]->color;
    QString colorMap[] = {"Blue", "Green", "Red", "Yellow"};
    QString resName = ":/UNO2D/";
    if (id == 10)
    {
        resName += colorMap[color] + "Drawtwo2" + ".jpg";
    }
    else if (id == 11)
    {
        resName += colorMap[color] + "Reverse2" + ".jpg";
    }
    else if (id == 12)
    {
        resName += colorMap[color] + "Skip2" + ".jpg";
    }
    else if (id == 13)
    {
        resName = resName + "Wild2" + ".jpg";
    }
    else if (id == 14)
    {
        resName = resName + "DrawFour2" + ".jpg";
    }
    this->pix = QPixmap(resName);
}
void transformation::paintEvent(QPaintEvent *event)
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

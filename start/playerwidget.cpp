#include "playerwidget.h"

int PlayerWidget::getCurrentCardCount() const
{
    return currentCardCount;
}

void PlayerWidget::setCurrentCardCount(int value)
{
    currentCardCount = value;
}

void PlayerWidget::setIsTurned(bool value)
{
    isTurned = value;
    update();
}

PlayerWidget::PlayerWidget(QWidget *parent) : QWidget(parent)
{

}

PlayerWidget::PlayerWidget(QString id, QPixmap playerImg, QWidget *parent)
{
    this->isTurned = false;
    this->currentCardCount = 0;
    this->playerID = id;
    this->playerImg = playerImg;
}

void PlayerWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);//定义画板为自己背景，相当于VS中DC pDC
    //设置去毛边 高质量模式
    painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
    //透明覆盖
    painter.fillRect(this->rect(), QBrush(Qt::transparent));
    //定义一个图像用来绘到背景
    QPixmap thisPix(width(),height());

    thisPix=this->bgpix;
     //绘制到背景上去
    painter.drawPixmap(this->rect(),thisPix);
}

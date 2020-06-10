#include "playerwidget.h"
#include "cardwidget.h"

void PlayerWidget::setCurrentCardCount(int value)
{
    currentCardCount = value;
    Cards.clear();
    for(int i=0;i<currentCardCount;++i){
        Cards.append(new CardWidget(this));
    }
    update();
}

void PlayerWidget::setIsTurned(bool value)
{
    isTurned = value;
    update();
}

PlayerWidget::PlayerWidget(QWidget *parent) : QWidget(parent)
{
}

PlayerWidget::PlayerWidget(QString id, QPixmap playerImg, QWidget *parent) : QWidget(parent)
{
    this->isTurned = false;
    this->currentCardCount = 0;
    this->playerID = id;
    this->playerImg = playerImg;
    this->setWindowFlags(Qt::FramelessWindowHint);
}

void PlayerWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this); //定义画板为自己背景，相当于VS中DC pDC
    //设置去毛边 高质量模式
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    //透明覆盖
    painter.fillRect(this->rect(), QBrush(Qt::transparent));

    //绘制到背景上去
    painter.drawPixmap(QRect(this->rect().left(),this->rect().top(),this->rect().height()*0.8,this->rect().width())
                           , playerImg);

    QFont font;
    font.setPixelSize(24);
    QFontMetrics metrics(font);
    int w=metrics.width(playerID); //获取显示文本的宽度
    int h=metrics.height();
    painter.setFont(font);
    painter.setPen(Qt::black);
    painter.drawText(QRect(width()*0.2,height()*0.77-h,w,h),playerID);

    int left = 0, i = 0;
    //自己的牌上面(Y)位置
    int top = height()*0.82;

    for(auto card:Cards){
        card->setGeometry(580,300,width()*0.10,height()*0.15);
        card->move(left + i * width()/(Cards.size()*2), top);
        card->show();
        card->raise();
        i++;
    }

}

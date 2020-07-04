#include "mygamewindow.h"
#include <QMainWindow>
#include <QDebug>
#include "qevent.h"
#include "qtimer.h"
#include "qpainter.h"
#include "qpixmap.h"
#include "QEventLoop"
#include "qpropertyanimation.h"
#include <QLabel>
#include <QTimer>
#include <QElapsedTimer>
#include <QTime>

void myGameWindow::updateStatus()
{
    qDebug() <<"statue"<< statue;
    qDebug() << "turn: " << backend->getCurrnetTurnID();
    QVector<Card*> mycards;
    this->backend->getPlayerCards(0,mycards);
    for(auto c:MyCards){
        delete c;
    }
    MyCards.clear();
    for (auto c : mycards) {
        int id =  c->getCardId();
        int color = Card::getColorById(id);
        int num = Card::getCardNumById(id);
        int type = Card::getCardTypeById(id);
        if(type == Card::NUMBERIC){
             MyCards.append(new CardWidget(num,color,this));
        }else if (type == Card::SKIP){
             MyCards.append(new CardWidget(12,color,this));
        }else if (type == Card::RESERVE){
             MyCards.append(new CardWidget(11,color,this));
        }else if (type == Card::DRAW_TWO){
             MyCards.append(new CardWidget(10,color,this));
        }else if (type == Card::WILD_DRAW_FOUR){
            MyCards.append(new CardWidget(14,color,this));
        }else if (type == Card::WILD){
            MyCards.append(new CardWidget(13,color,this));
        }
    }
    for (int i = 0; i < Players.length(); ++i) {
        Players[i]->setCurrentCardCount(backend->getPlayerCardCount(i));
    }
}

myGameWindow::myGameWindow(QWidget *parent) : QMainWindow(parent)
{
    isUno = false;
    effortNum = 0;
    v = false;
    vic = new victory();
    setStyleSheet("QWidget{font-family:方正粗圆简体;}");
    setFixedSize(1299, 731);
    this->setWindowIcon(QIcon(":/UNO2D/star.png"));
    //cardStack = CardWidget(0,0,false,this);
    turnDirection = true;

    MyPushButton *setBtn = new MyPushButton(":/UNO2D/quit.png");
    setBtn->setParent(this);
    setBtn->move(0, 0);

    MyPushButton *redBtn = new MyPushButton(":/UNO2D/red.png");
    redBtn->setParent(this);
    redBtn->hide();

    MyPushButton *yellowBtn = new MyPushButton(":/UNO2D/yellow.png");
    yellowBtn->setParent(this);
    yellowBtn->hide();

    MyPushButton *blueBtn = new MyPushButton(":/UNO2D/blue.png");
    blueBtn->setParent(this);
    blueBtn->hide();

    MyPushButton *greenBtn = new MyPushButton(":/UNO2D/green.png");
    greenBtn->setParent(this);
    greenBtn->hide();

    MyPushButton *goBtn = new MyPushButton(":/UNO2D/go.png");
    goBtn->setParent(this);
    goBtn->move(400, 500);
    // 出牌
    connect(goBtn, &MyPushButton::clicked, [=]() {
        //弹起特效
        goBtn->zoom1();
        goBtn->zoom2();
        QTimer::singleShot(400,  this, [=]() {
            if (backend->getCurrnetTurnID() != 0 ||  ( statue != 1 && statue != 3)){
                return;
            }
            QVector<Card*> mycards;
            this->backend->getPlayerCards(0,mycards);
            QVector<int> validids;
            backend->getPlayerValidCards(0,validids);
            if(validids.length()==0){
                emit draw();
                return;
            }
            for (int i = 0; i < MyCards.length(); i++)
            {
                if (validids.count( mycards[i]->getCardId())!=0 && MyCards[i]->getIsClick())
                {

                    MyCards[i]->hide();
                    int a = MyCards[i]->id;
                    int b = MyCards[i]->color;
                    MyCards.erase(MyCards.begin() + i);

                    if (a >= 10 && a <= 14)
                    {
                        PickCards.append(new CardWidget(a, b, this));
                        qDebug() << PickCards.length();
                        if (a == 13 || a == 14)
                        {
                            redBtn->move(this->width() * 0.415, this->height() * 0.52);
                            redBtn->show();
                            connect(redBtn, &MyPushButton::clicked, [=]() {
                                //弹起特效
                                if (!isChange)
                                {
                                    redBtn->zoom1();
                                    redBtn->zoom2();
                                    QTimer::singleShot(400, this, [=]() {
                                        color = 2;
                                        isChange = true;
                                    });
                                }
                                redBtn->hide();
                                blueBtn->hide();
                                yellowBtn->hide();
                                greenBtn->hide();
                            });
                            blueBtn->move(this->width() * 0.35, this->height() * 0.37);
                            blueBtn->show();
                            connect(blueBtn, &MyPushButton::clicked, [=]() {
                                //弹起特效
                                if (!isChange)
                                {
                                    blueBtn->zoom1();
                                    blueBtn->zoom2();
                                    QTimer::singleShot(400, this, [=]() {
                                        color = 0;
                                        isChange = true;
                                    });
                                }
                                redBtn->hide();
                                blueBtn->hide();
                                yellowBtn->hide();
                                greenBtn->hide();
                            });
                            yellowBtn->move(this->width() * 0.5, this->height() * 0.4);
                            yellowBtn->show();
                            connect(yellowBtn, &MyPushButton::clicked, [=]() {
                                //弹起特效
                                if (!isChange)
                                {
                                    yellowBtn->zoom1();
                                    yellowBtn->zoom2();
                                    QTimer::singleShot(400, this, [=]() {
                                        color = 3;
                                        isChange = true;
                                    });
                                }
                                redBtn->hide();
                                blueBtn->hide();
                                yellowBtn->hide();
                                greenBtn->hide();
                            });
                            greenBtn->move(this->width() * 0.43, this->height() * 0.25);
                            greenBtn->show();
                            connect(greenBtn, &MyPushButton::clicked, [=]() {
                                //弹起特效
                                if (!isChange)
                                {
                                    greenBtn->zoom1();
                                    greenBtn->zoom2();
                                    QTimer::singleShot(400, this, [=]() {
                                        color = 1;
                                        isChange = true;
                                    });
                                }
                                redBtn->hide();
                                blueBtn->hide();
                                yellowBtn->hide();
                                greenBtn->hide();
                            });
                            emit play(mycards[i]->getCardId(),(Card::COLOR)this->color);
                        }else{
                            emit play(mycards[i]->getCardId(),mycards[i]->getColor());

                        }
                        isChange = false;
                    } else {
                        emit play(mycards[i]->getCardId(),mycards[i]->getColor());

                    }
                    break;
                }
            }
            statue = this->backend->getCurrentStatue();
            updateStatus();
        });
    });

    MyPushButton *unoBtn = new MyPushButton(":/UNO2D/UNO.png");
    unoBtn->setParent(this);
    unoBtn->move(700, 500);
    connect(unoBtn, &MyPushButton::clicked, [=]() {
        //弹起特效
        if (isUno)
        {
            unoBtn->zoom1();
            unoBtn->zoom2();
            QTimer::singleShot(400, this, [=]() {
                isPress = true;
                emit uno();
                update();
            });
        }
    });
    if (!isUno)
        isPress = false;
    time = new QTimer(this);
    rat = 0;

    connect(time, &QTimer::timeout, [=]() {
        if (rat++ == 360)
            rat = 0;
        update();
    });

    time->start(10);
    connect(setBtn, &MyPushButton::clicked, [=]() {
        //弹起特效
        setBtn->zoom1();
        setBtn->zoom2();
        QTimer::singleShot(400, this, [=]() {
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
    {
        qDebug() << "n=0";
        this->close();
        vic->show();
        return;
    }
    //自己的牌左边(X)位置计算
    int left = (width() - (n - 1) * 40 - MyCards[0]->width()) / 2;
    //自己的牌上面(Y)位置
    int top = height() - MyCards[0]->height() - 70;

    for (int i = 0; i < n; i++)
    {
        //自己的牌 只需更新X位置从左到右
        MyCards[i]->setGeometry(580, 300, 90, 140);
        MyCards[i]->move(left + i * 60, top + 60);
        MyCards[i]->show();
        MyCards[i]->raise();
        //如果牌是选中状态，保持选中状态
        if (MyCards[i]->getIsClick())
        {
            MyCards[i]->setClick(true);
        }
    }
    if (n == 2)
        isUno = true;
    else
        isUno = false;
}

void myGameWindow::showPlayers()
{
    int n = Players.size();
    if (n == 0)
        return;
    Players[0]->setGeometry(500, 300, 180, 240);
    Players[0]->move(width() * 0.8, height() * 0.7);
    Players[0]->show();
    Players[0]->raise();
    if (n >= 2)
    {
        Players[1]->setGeometry(500, 300, 180, 240);
        Players[1]->move(width() * 0.05, height() * 0.33);
        Players[1]->show();
        Players[1]->raise();
    }
    if (n >= 3)
    {
        Players[2]->setGeometry(500, 300, 180, 240);
        Players[2]->move(width() * 0.8, height() * 0.33);
        Players[2]->show();
        Players[2]->raise();
    }
    if (n >= 4)
    {
        Players[3]->setGeometry(500, 300, 180, 240);
        Players[3]->move(width() * 0.4, height() * 0.01);
        Players[3]->show();
        Players[3]->raise();
    }
    if (n >= 5)
    {
        Players[4]->setGeometry(500, 300, 180, 240);
        Players[4]->move(width() * 0.6, height() * 0.01);
        Players[4]->show();
        Players[4]->raise();
    }
    if (n >= 6)
    {
        Players[5]->setGeometry(500, 300, 180, 240);
        Players[5]->move(width() * 0.8, height() * 0.01);
        Players[5]->show();
        Players[5]->raise();
    }
    if (n >= 7)
    {
        Players[6]->setGeometry(500, 300, 180, 240);
        Players[6]->move(width() * 0.2, height() * 0.01);
        Players[6]->show();
        Players[6]->raise();
    }
    if (n >= 8)
    {
        Players[7]->setGeometry(500, 300, 180, 240);
        Players[7]->move(width() * 0.05, height() * 0.7);
        Players[7]->show();
        Players[7]->raise();
    }
}

void myGameWindow::showEffort()
{
    int a = PickCards.length() - 1;
    int iid = PickCards[a]->id;
    PickCards[a]->isNomal = false;
    int icolor = PickCards[a]->color;
    if (iid == 10)
    {
        //
    }
    else if (iid == 11)
    {
        changeDirection();
    }
    else if (iid == 12)
    {
        //
    }
    else if (iid == 13)
    {
        //
    }
    else if (iid == 14)
    {
    }
    //PickCards[a]->pix
    qDebug() << PickCards[a]->resName;
    QString s = ".jpg";
    PickCards[a]->resName.remove(s, Qt::CaseInsensitive);
    PickCards[a]->resName = PickCards[a]->resName + "2.png";
    PickCards[a]->pix = QPixmap(PickCards[a]->resName);
    PickCards[a]->setGeometry(400, 350, 150, 140);
    PickCards[a]->move(width() * 0.43, height() * 0.42);
    PickCards[a]->show();
    PickCards[a]->raise();
}

void myGameWindow::changeDirection()
{
    turnDirection = ~turnDirection;
    rat = 0;
    update();
}

void myGameWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    QPixmap p1, p2, p3;
    int ratt;
    pix.load(":/UNO2D/back3.png");
    painter.drawPixmap(this->rect(), pix);
    if (turnDirection)
    {
        p1.load(":/UNO2D/11.png");
        ratt = qAbs(rat);
    }
    else
    {
        p1.load(":/UNO2D/12.png");
        ratt = -qAbs(rat);
    }
    painter.translate(this->width() * 0.5, this->height() * 0.5);   //让图片的中心作为旋转的中心
    painter.rotate(ratt);                                           //旋转
    painter.translate(-this->width() * 0.5, -this->height() * 0.5); //使原点复原
    painter.drawPixmap(this->width() * 0.5 - p1.width() * 0.35, this->height() * 0.5 - p1.height() * 0.35, p1.width() * 0.7, 0.7 * p1.height(), p1);
    p2.load(":/UNO2D/UNO2.png");
    if (isPress && isUno)
    {
        painter.drawPixmap(555, 500, p2.width(), p2.height(), p2);
    }

    showCards();
    showPlayers();
    if ((PickCards.length() - effortNum) == 1)
    {
        if (PickCards.length() >= 2)
            PickCards[PickCards.length() - 2]->hide();
        showEffort();
        QTime n = QTime::currentTime();
        QTime now;
        do
        {
            now = QTime::currentTime();
        } while (n.msecsTo(now) <= 500);
        effortNum++;
    }
}

void myGameWindow::TimerTimeOut()
{
    int cardid;
    int colorid;
    QVector<int> validids;
    QVector<Card*> mycards;
    backend->getPlayerCards(backend->getCurrnetTurnID(), mycards);
    backend->getPlayerValidCards(backend->getCurrnetTurnID(),validids);
    if (backend->getCurrnetTurnID() == 0 && ( statue == 1 || statue == 3) ) {			// if opera
                    if (validids.size() > 0) {
                        //std::cin >> cardid;
                        cardid = validids[rand() % validids.size()];
                        if (Card::getCardTypeById(cardid) == Card::WILD || Card::getCardTypeById(cardid) == Card::WILD_DRAW_FOUR)
                            colorid = rand() % 4;
                        else {
                            if (mycards.size() == 2) {
                                emit uno();
                            }
                            emit play(cardid, (Card::COLOR)colorid);
                            statue = this->backend->getCurrentStatue();
                            updateStatus();   // for put
                        }
                    }
                    else {
                        emit draw();
                    }
                }

                statue = this->backend->getCurrentStatue();
                updateStatus();   // for put		// get next statue
                if (statue == 5) {
                    statue = this->backend->getCurrentStatue();
                    updateStatus();   // for put
                }
                if (statue == 8 || statue == 9) {
                    exit(0);
                }
    if (backend->getCurrnetTurnID() != 0 ||  ( statue != 1 && statue != 3)){
        statue = this->backend->getCurrentStatue();
        updateStatus();
    }
}

void myGameWindow::setGameProperties(int gameType, int playerNum)
{
    this->gameType = gameType;
    this->playerNum = playerNum;
}

void myGameWindow::initBackend(int playerNum, QString myName, bool isAI)
{
    this->backend = new Backend(playerNum,myName,isAI);
    connect(this, &myGameWindow::operate, this->backend, &Backend::startGame);
    connect(this, &myGameWindow::draw, this->backend, &Backend::drawCard);
    connect(this, &myGameWindow::play, this->backend, &Backend::playCard);
    connect(this, &myGameWindow::uno, this->backend, &Backend::sayUNO);


    m_timer = new QTimer(this);
    //设置定时器是否为单次触发。默认为 false 多次触发
    m_timer->setSingleShot(false);
    //启动或重启定时器, 并设置定时器时间：毫秒
    connect(m_timer, &QTimer::timeout, this, &myGameWindow::TimerTimeOut);
    m_timer->start(2000);
    //定时器触发信号槽
    emit operate();
    statue = this->backend->getCurrentStatue();
    updateStatus();
    statue = this->backend->getCurrentStatue();
    updateStatus();
}

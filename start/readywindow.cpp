#include "readywindow.h"
#include <QPainter>
#include <mypushbutton.h>
#include <QTimer>
#include <QDebug>
#include "mysetwindow.h"
readywindow::readywindow(QWidget *parent) : QMainWindow(parent)
{
    isConnecting = false;
    timeStart = 0;
    nowNum = 0;
    int a = qnum.toInt();
    int b = 1;
    myGameWindow *mgw = new myGameWindow();
    mgw->setGameProperties(b, a);

    //test
    personName.push_back("Mike");
    personName.push_back("Tony");
    personName.push_back("Kobe");
    personName.push_back("Curry");
    personName.push_back("Lebron");
    personName.push_back("Westbrook");
    personName.push_back("Durant");

    this->setFixedSize(1282, 800);
    this->setWindowTitle("房间等待");
    this->setWindowIcon(QIcon(":/UNO2D/star.png"));
    MyPushButton *yesBtn = new MyPushButton(":/UNO2D/start2.png");
    yesBtn->setParent(this);
    yesBtn->move(this->width() * 0.4, this->height() * 0.87);
    MyPushButton *startgame = new MyPushButton(":/UNO2D/connecting.png");
    startgame->setParent(this);
    startgame->hide();
    MyPushButton *gobackBtn = new MyPushButton(":/UNO2D/goback.png");
    gobackBtn->setParent(this);
    gobackBtn->move(this->width() * 0.05, this->height() * 0.05);

    connect(gobackBtn, &MyPushButton::clicked, [=]() {
        //弹起特效
        gobackBtn->zoom1();
        gobackBtn->zoom2();
        QTimer::singleShot(400, this, [=]() {
            //告诉场景返回 主场景监听返回按钮
            emit this->mysetBack();
        });
    });

    connect(yesBtn, &MyPushButton::clicked, [=]() {
        //弹起特效
        yesBtn->zoom1();
        yesBtn->zoom2();
        QTimer::singleShot(400, this, [=]() {
            yesBtn->hide();
            gobackBtn->hide();
            isConnecting = true;
            startgame->move(this->width() * 0.4, this->height() * 0.87);
            startgame->show();
            timeStart = 1;
            update();
            connecting();

            QTimer::singleShot(1200, this, [=]() {
                // test code
                //此处应加入随机生成每个玩家牌的部分
                mgw->Players.append(new PlayerWidget(QString(qname), QString(":/UNO2D/" + QString::number(1) + ".png"), mgw));

                for (int i = 0; i < qnum.toInt() - 1; i++)
                {
                    mgw->Players.append(new PlayerWidget(QString(personName[i]), QString(":/UNO2D/" + QString::number(i + 1) + ".png"), mgw));
                    mgw->Players[i + 1]->setCurrentCardCount(7);
                }
                this->hide();
                mgw->show();

            });
        });
    });
}
void readywindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix, pix1, pix2, pix3;
    QString number;
    QString address;
    if (!isConnecting)
    {
        pix.load(":/UNO2D/ready.png");
        painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    }
    else
    {
        pix.load(":/UNO2D/ready2.png");
        painter.drawPixmap(0, 0, this->width(), this->height(), pix);
        pix2.load(":/UNO2D/cao.PNG");
        painter.drawPixmap(800, 47, pix2.width(), pix2.height(), pix2);
    }
    if (timeStart == 1)
    {
        pix3.load(":/UNO2D/power.PNG");
        painter.drawPixmap(900, 70, pix3.width(), pix3.height(), pix3);
    }
    for (int i = 1; i < nowNum; i++)
    {
        if (i <= 6)
        {
            number = QString::number(i);
        }
        else
        {
            number = QString::number(i - 4);
        }
        address = ":/UNO2D/" + number + ".png";
        pix1.load(address);
        if (i <= 3)
        {
            painter.drawPixmap(this->width() * 0.08 + i * 295, this->height() * 0.18, pix1.width(), pix1.height(), pix1);
        }
        else
        {
            painter.drawPixmap(this->width() * 0.075 + (i - 4) * 295, this->height() * 0.35 + 150, pix1.width(), pix1.height(), pix1);
        }
    }
}
void readywindow::connecting()
{
    num = qnum.toInt();
    QString number;
    QString address;
    for (int i = 0; i < num; i++)
    {
        QLineEdit *person = new QLineEdit(this);
        person->setFont(QFont("微软雅黑", 10, QFont::Bold));
        QPalette palette;
        palette.setColor(QPalette::Text, Qt::white);
        person->setPalette(palette);
        if (i == 0)
        {
            person->setText(qname);
        }
        else
        {
            person->setText(personName[i - 1]);
        }
        person->setParent(this);
        person->resize(150, 40);
        person->setStyleSheet("background-color:rgba(0,0,0,0);");
        if (i <= 3)
        {
            person->move(this->width() * 0.08 + i * 305, this->height() * 0.453);
        }
        else
        {
            person->move(this->width() * 0.08 + (i - 4) * 305, this->height() * 0.453 + 285);
        }
        person->show();
        nowNum++;
        update();
    }
}
void readywindow::setNumName(QString num, QString name)
{
    qnum = num;
    qname = name;
}

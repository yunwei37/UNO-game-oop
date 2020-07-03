#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<mypushbutton.h>
#include<QDebug>
#include<QTimer>
#include<mysetwindow.h>
#include<victory.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //配置主场景
    setFixedSize(1282,800);
    //设置图标
    setWindowIcon(QIcon(":/UNO2D/star.png"));
    //设置标题
    setWindowTitle("UNO");
    //model1按钮
    MyPushButton *model1Btn=new MyPushButton(":/UNO2D/model1.png");
    model1Btn->setParent(this);
    model1Btn->move(this->width()*0.5-model1Btn->width()*0.5,this->height()*0.25);
     msw =new  mysetwindow();

     connect(msw,&mysetwindow::mysetBack,this,[=]()
     {
         msw->hide();
         this->show();
     });

    connect(model1Btn,&MyPushButton::clicked,[=]()
    {
        qDebug()<<"点击了模式1";
        //弹起特效
        model1Btn->zoom1();
        model1Btn->zoom2();
        QTimer::singleShot(400,this,[=](){
            //进入设置场景
            this->hide();
            msw->show();
            //监听设置界面的返回按钮

        });
    });

    //model2按钮
    MyPushButton *model2Btn=new MyPushButton(":/UNO2D/model2.png");
    model2Btn->setParent(this);
    model2Btn->move(this->width()*0.5-model2Btn->width()*0.5,this->height()*0.35);
    connect(model2Btn,&MyPushButton::clicked,[=]()
    {
        qDebug()<<"点击了模式2";
        //弹起特效
        model2Btn->zoom1();
        model2Btn->zoom2();
    });

    MyPushButton *linkBtn=new MyPushButton(":/UNO2D/link.png");
    linkBtn->setParent(this);
    linkBtn->move(this->width()*0.5-linkBtn->width()*0.5,this->height()*0.45);
    connect(linkBtn,&MyPushButton::clicked,[=]()
    {
        qDebug()<<"点击了模式2";
        //弹起特效
        linkBtn->zoom1();
       linkBtn->zoom2();
    });
    
    //退出按钮
    MyPushButton *quitBtn=new MyPushButton(":/UNO2D/quit.png");
    quitBtn->setParent(this);
    quitBtn->move(this->width()*0.5-quitBtn->width()*0.5,this->height()*0.55);
    connect(quitBtn,&MyPushButton::clicked,[=]()
    {
        qDebug()<<"点击了退出";
        //弹起特效
        quitBtn->zoom1();
        quitBtn->zoom2();
        QTimer::singleShot(400,this,[=](){
            //关闭场景
            this->close();
        });
    });
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/UNO2D/back.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}

MainWindow::~MainWindow()
{
    delete ui;
}


#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H


#include<QPushButton>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    //构造函数 参数1 正常显示的路径 参数2 按下后显示的路径
    MyPushButton(QString normalImg,QString pressImg ="");
    //成员属性 保存默认路径 按下后显示的路径
    QString normalImgPath;
    QString pressImgPath;

    //弹起特效
    void zoom1();
    void zoom2();
signals:

};

#endif // MYPUSHBUTTON_H

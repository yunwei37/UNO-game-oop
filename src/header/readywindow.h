#ifndef READYWINDOW_H
#define READYWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QLineEdit>
#include "mygamewindow.h"
class readywindow : public QMainWindow
{
    Q_OBJECT
public:
    int nowNum;
    int timeStart;
    long int num;
    bool isConnecting;
    QVector<QString> personName;
    QString qnum;
    QString qname;

public:
    explicit readywindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void connecting();
    void setNumName(QString num, QString name);
signals:
    void mysetBack();
};

#endif // READYWINDOW_H

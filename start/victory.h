#ifndef VICTORY_H
#define VICTORY_H

#include <QWidget>
#include"mysetwindow.h"
#include<QMainWindow>
class victory : public QMainWindow
{
    Q_OBJECT
public:
    explicit victory(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) ;
signals:
};

#endif // VICTORY_H

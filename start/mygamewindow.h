#ifndef MYGAMEWINDOW_H
#define MYGAMEWINDOW_H

#include <QMainWindow>
#include <qvector.h>
#include "cardwidget.h"
#include "playerwidget.h"
#include "mypushbutton.h"
#include<QTimer>
#include"transformation.h"
#include"victory.h"
class victory;
class myGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    int gameType;
    int playerNum;
    bool turnDirection;
    int nowNum;
    QTimer* time;
    int effortNum;
    bool isUno;
    bool isPress;
    int color;
    bool isEffort;
    int rat;
    bool v;
    bool isChange;
    CardWidget *c;
    victory *vic;
public:
    explicit myGameWindow(QWidget *parent = nullptr);
    void showCards();
    void showPlayers();
    void changeDirection();
    void showEffort();
    void get(int gameType,int playerNum);
    void showV();
    QVector<CardWidget *> MyCards;
    QVector<PlayerWidget *> Players;
    QVector<CardWidget *> PickCards;
protected:
    virtual void paintEvent(QPaintEvent *event);
public slots:
};

#endif // MYGAMEWINDOW_H

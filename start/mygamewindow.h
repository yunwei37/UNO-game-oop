#ifndef MYGAMEWINDOW_H
#define MYGAMEWINDOW_H

#include <QMainWindow>
#include <qvector.h>
#include "cardwidget.h"
#include "playerwidget.h"
#include "mypushbutton.h"

class myGameWindow : public QMainWindow
{
    Q_OBJECT

private:
    int gameType;
    int playerNum;
    QVector<PlayerWidget *> players;

public:
    explicit myGameWindow(QWidget *parent = nullptr);
    explicit myGameWindow(int gameType, int playerNum, QWidget *parent = nullptr);
    void showCards();

    QVector<CardWidget *> MyCards;

protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // MYGAMEWINDOW_H

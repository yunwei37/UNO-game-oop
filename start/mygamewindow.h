#ifndef MYGAMEWINDOW_H
#define MYGAMEWINDOW_H

#include <QMainWindow>
#include <qvector.h>
#include "cardwidget.h"
#include "playerwidget.h"
#include "mypushbutton.h"
#include <QTimer>
#include "transformation.h"
#include "victory.h"
#include "backend.h"
class victory;
class myGameWindow : public QMainWindow
{
    Q_OBJECT

private:
    int gameType;
    int playerNum;
    bool turnDirection;
    int nowNum;
    QTimer *time;
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
    void setGameProperties(int gameType, int playerNum);
    void showV();

    void initBackend(int playerNum, QString myName, bool isAI);

    QVector<CardWidget *> MyCards;
    QVector<PlayerWidget *> Players;
    QVector<CardWidget *> PickCards;
    Backend* backend;


protected:
    virtual void paintEvent(QPaintEvent *event);
public slots:
    void handleResults(const QString& r) {
        std::cout << r.toStdString();
    }
    void AIEnds() {
        std::cout << "AI finish" << std::endl;
    }
signals:
    void operate();
    void draw();
    void play(int cardID, Card::COLOR color);
    void uno();
};

#endif // MYGAMEWINDOW_H

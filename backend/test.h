#pragma once

#include <QCoreApplication>
#include "aithread.h"
#include "netthread.h"
#include <qtcpsocket.h>
#include<backend.h>

class Controller : public QObject
{
    Q_OBJECT;
public:
    int playerCount;
    Controller(int i) {
        playerCount = i;
    }
    ~Controller() {

    }
    void test() {
        auto b = createBack();
        connect(this, &Controller::operate, b, &Backend::startGame);
        connect(this, &Controller::draw, b, &Backend::drawCard);
        connect(this, &Controller::play, b, &Backend::playCard);
        connect(this, &Controller::uno, b, &Backend::sayUNO);
        for (int i = 0; i < playerCount; ++i) {
            std::cout << b->getPlayerName(i).toStdString() << std::endl;
        }
        printData(b);
        emit operate();
        printData(b);
        printData(b);
        while (true) {
            int cardid;
            int colorid;
            QVector<int> validids;
            b->getMyValidCards(validids);
            if (validids.size() > 0) {
                std::cin >> cardid;
                if (Card::getCardTypeById(cardid) == Card::WILD || Card::getCardTypeById(cardid) == Card::WILD_DRAW_FOUR)
                    std::cin >> colorid;
                
                chooseplay(cardid, (Card::COLOR)colorid);
            }
            else {
                chooseDraw();
            }
            QThread::sleep(1);
            printData(b);
        }
        destroyBack(b);
    }
    void printData(Backend* b) {
        std::cout << "------------------------------------------" << std::endl;
        std::cout <<"statue: "<< b->getCurrentStatue() << std::endl;
        std::cout << "turn: " << b->getCurrnetTurnID() << std::endl;

        QVector<Card*> mycards;
        QVector<int> validids;
        b->getMyCards(mycards);
        std::cout << "my cards: ";
        for (auto c : mycards) {
            std::cout << c->getCardId() << " ";
        }
        std::cout << std::endl;
        b->getMyValidCards(validids);
        for (auto i : validids) {
            std::cout <<i << " ";
        }
        std::cout << std::endl;

        std::cout << "player card count: ";
        for (int i = 0; i < playerCount; ++i) {
            std::cout << b->getPlayerCardCount(i) << " ";
        }
        std::cout << std::endl;

        mycards.clear();
        b->getTopFiveCards(mycards);
        std::cout << "top 5: ";
        for (auto c : mycards) {
            std::cout << c->getCardId() << " ";
        }
        std::cout << std::endl;

    }
    Backend* createBack() {
        return new Backend(playerCount, "me");
    }
    void destroyBack(Backend* b) {
        delete b;
    }
    void chooseDraw() {
        emit draw();
    }
    void chooseplay(int cardID, Card::COLOR color) {
        emit play(cardID, color);
    }
    void chooseuno() {
        emit uno();
    }
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

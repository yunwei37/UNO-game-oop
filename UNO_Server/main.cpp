#include <iostream>
#include <map>
#include "string.h"
#include "message.h"
#include <assert.h>
#include "cards.h"

void test() {


    ResultGameStart t1 = ResultGameStart();
    ExtractResult t2 = (ResultGameStart) t1;
    assert(t1.getType() == t2.getType());
    assert(MessageExtractor::handleMessage("GAMESTART")->getType() == t2.getType());


    std::map<int, std::string> player_map{
            {0, "tom"},
            {2, "toom"},
            {3, "tooom"}
    };

    ExtractResult *res;
    std::string msg;

    msg = MessageFactory::join_ack_factory(player_map.size(), 4, player_map);
    std::cout << msg << std::endl;
    res = MessageExtractor::handleMessage(msg.c_str());
    ResultJoinACK *resultJoinAck = (ResultJoinACK *) res;
    assert(resultJoinAck->getAssignedPlayerId() == 4);
    assert(resultJoinAck->getPlayerCount() == player_map.size());
    assert(resultJoinAck->getPlayerMap().find(3)->second == "tooom");


    msg = MessageFactory::newplayer_factory(5, "tooooom");
    std::cout << msg << std::endl;
    res = MessageExtractor::handleMessage(msg.c_str());
    ResultNewPlayer *resultNewPlayer = (ResultNewPlayer *) res;
    assert(resultNewPlayer->getNewPlayerId() == 5);
    assert(resultNewPlayer->getNewPlayerName() == "tooooom");

    msg = MessageFactory::client_keepalive_factory(5);
    std::cout << msg << std::endl;
    res = MessageExtractor::handleMessage(msg.c_str());
    ResultClientKeepAlive *resultClientKeepAlive = (ResultClientKeepAlive *) res;
    assert(resultClientKeepAlive->getPlayerId() == 5);


    msg = MessageFactory::playerleave_factory(5);
    std::cout << msg << std::endl;
    res = MessageExtractor::handleMessage(msg.c_str());
    ResultPlayerLeave *resultPlayerLeave = (ResultPlayerLeave *) res;
    assert(resultPlayerLeave->getPlayerId() == 5);

    msg = MessageFactory::player_action_factory(1, 1, 1);
    std::cout << msg << std::endl;
    res = MessageExtractor::handleMessage(msg.c_str());
    ResultPlayerAction *resultPlayerAction = (ResultPlayerAction *) res;
    assert(resultPlayerAction->getDrawCardId() == 1);


    Card handcard[3]={
            Card::getCardById(0),
            Card::getCardById(5),
            Card::getCardById(26)
    };
    assert(Card::getCardById(1) == Card(Card::COLOR::RED, Card::CARD_TYPE::NUMBERIC, 1));

    assert(handcard[0] == Card::getCardById(0));


}

int main() {

    test();

    return 0;
}

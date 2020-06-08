#include <iostream>
#include <map>
#include "string.h"
#include "message.h"
#include <map>
#include <assert.h>

void test(){

    int a1 = ExtractResult(true).getTypeId();
    ResultGameStart ann;
    ExtractResult bnn;
    std::cout<<bnn.getTypeId();
    bnn = (ExtractResult)ann;
    std::cout<<bnn.getTypeId();

    std::map<int, std::string> player_map{
            {0, "tom"},
            {2, "toom"},
            {3, "tooom"}
    };

    std::string msg;

    msg = MessageFactory::join_ack_factory(player_map.size(), 4, player_map);
    puts(msg.c_str());
    ResultJoinACK resultJoinAck = MessageExtractor::join_ack_extractor(msg.c_str());
    assert(resultJoinAck.isSuccess());
    assert(resultJoinAck.getAssignedPlayerId()==4);
    assert(resultJoinAck.getPlayerCount()==player_map.size());
    assert(resultJoinAck.getPlayerMap().find(3)->second=="tooom");


    msg = MessageFactory::newplayer_factory(5, "tooooom");
    puts(msg.c_str());
    ResultNewPlayer resultNewPlayer = MessageExtractor::newplayer_extractor(msg.c_str());
    assert(resultNewPlayer.isSuccess());
    assert(resultNewPlayer.getNewPlayerId()==5);
    assert(resultNewPlayer.getNewPlayerName()=="tooooom");

    msg = MessageFactory::client_keepalive_factory(5);
    puts(msg.c_str());
    ResultClientKeepAlive resultClientKeepAlive = MessageExtractor::client_keepalive_extractor(msg.c_str());
    assert(resultClientKeepAlive.isSuccess());
    assert(resultClientKeepAlive.getPlayerId()==5);


    msg = MessageFactory::playerleave_factory(5);
    puts(msg.c_str());
    ResultPlayerLeave resultPlayerLeave = MessageExtractor::playerleave_extractor(msg.c_str());
    assert(resultPlayerLeave.isSuccess());
    assert(resultPlayerLeave.getPlayerId()==5);

}
int main() {

    test();

    return 0;
}

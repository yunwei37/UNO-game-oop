//
// Created by ubuntu on 2020/6/8.
//
#include "message.h"
#include "extractresults.h"

#include "string.h"
#include <map>
#include <string>

std::string MessageFactory::join_room_factory(std::string player_name) {
    char message[128];
    sscanf(message, MESSAGEFORMAT_JOINROOM, player_name.c_str());
    return std::string(message);
}

ExtractResult* MessageExtractor::join_room_extractor(const char *message) {
    char player_name_buf[128];
    sscanf(message, MESSAGEFORMAT_JOINROOM, player_name_buf);
    return new ResultJoinRoom(std::string(player_name_buf));
}

std::string MessageFactory::join_ack_factory(int player_count, int player_id, std::map<int, std::string> & player_map){
    if(player_count<=0 or player_id<0 or player_map.empty()
       or player_map.size()!=(unsigned)player_count)
        return std::string(MESSAGE_ERROR);

    char message[1024], buf[128];

    sprintf(message, MESSAGEFORMAT_JOINACK_HEADER, player_count, player_id);
    for(auto &i : player_map){
        sprintf(buf, MESSAGEFORMAT_PLAYERLIST_ITEM, i.first, i.second.c_str());
        strcat(message, buf);
    }

    std::string message_std_str =  std::string(message);
    return message_std_str;

}

ExtractResult* MessageExtractor::join_ack_extractor(const char* message) {
    int player_count, assigned_player_id;
    sscanf(message, MESSAGEFORMAT_JOINACK_HEADER, &player_count, &assigned_player_id);

    const char* player_list_item = strchr(message, '\n') + 1;
    //fisrt item

    std::map<int, std::string> player_map;

    int player_id;
    char player_name_buf[128];
    std::string player_name;

    for(int i=1; i<=player_count; ++i){
        sscanf(player_list_item, MESSAGEFORMAT_PLAYERLIST_ITEM, &player_id, player_name_buf);
        player_map[player_id] = std::string(player_name_buf);
        //get next item in the list
        player_list_item = strchr(player_list_item, '\n') + 1;
    }

    return new ResultJoinACK(player_count, assigned_player_id, player_map);
}

ExtractResult* MessageExtractor::newplayer_extractor(const char * message) {
    int player_id;
    char player_name_buf[128];
    sscanf(message, MESSAGEFORMAT_NEWPLAYER, &player_id, &player_name_buf);
    return new ResultNewPlayer(player_id, std::string(player_name_buf));
}


std::string MessageFactory::newplayer_factory(int new_player_id, std::string player_name) {
    char message[128];
    sprintf(message, MESSAGEFORMAT_NEWPLAYER, new_player_id, player_name.c_str());
    return std::string(message);
}

ExtractResult* MessageExtractor::playerleave_extractor(const char *message) {
    int player_id;
    sscanf(message, MESSAGEFORMAT_PLAYERLEAVE, &player_id);
    return new ResultPlayerLeave(player_id);
}

std::string MessageFactory::playerleave_factory(int player_id) {
    char message[128];
    sprintf(message, MESSAGEFORMAT_PLAYERLEAVE, player_id);
    return std::string(message);
}

std::string MessageFactory::gamestart_factory() {
    return std::string(MESSAGEFORMAT_GAMESTART);
}

std::string MessageFactory::server_keepalive_factory() {
    return std::string(MESSAGEFORMAT_KEEPALIVE_SERVER);
}

ExtractResult* MessageExtractor::gamestart_extractor() {
    return new ResultGameStart();
}

std::string MessageFactory::client_keepalive_factory(int player_id) {
    char message[128];
    sprintf(message, MESSAGEFORMAT_KEEPALIVE_CLIENT, player_id);
    return std::string(message);
}

ExtractResult* MessageExtractor::client_keepalive_extractor(const char *message) {
    int player_id;
    sscanf(message, MESSAGEFORMAT_KEEPALIVE_CLIENT, &player_id);
    return new ResultClientKeepAlive(player_id);
}

ExtractResult* MessageExtractor::server_keepalive_extractor() {
    return new ResultServerKeepAlive();
}

std::string MessageFactory::player_action_factory(int player_id, int draw_card_id, int put_card_id) {
    char message[512];
    sprintf(message, MESSAGEFORMAT_PLAYERACTION, player_id, draw_card_id, put_card_id);
    return std::string(message);
}

ExtractResult* MessageExtractor::player_action_extractor(const char * message) {
    int player_id, draw_card_id, put_card_id;
    sscanf(message, MESSAGEFORMAT_PLAYERACTION, &player_id, &draw_card_id, &put_card_id);
    return new ResultPlayerAction(player_id, draw_card_id, put_card_id);
}


ExtractResult* MessageExtractor::handleMessage(const char *message) {
    char identifier[32];
    sscanf(message,"%s", identifier);

//    puts(identifier);
    auto identify = [identifier](const char* IDENTIFIER) -> bool {return 0==strcmp(identifier, IDENTIFIER);};

    if(identify(IDENTIFIER_GAMESTART))
       return MessageExtractor::gamestart_extractor();
    else if(identify(IDENTIFIER_KEEPALIVE_SERVER))
        return MessageExtractor::server_keepalive_extractor();
    else if(identify(IDENTIFIER_KEEPALIVE_CLIENT))
        return MessageExtractor::client_keepalive_extractor(message);
    else if(identify(IDENTIFIER_JOINACK))
        return MessageExtractor::join_ack_extractor(message);
    else if(identify(IDENTIFIER_JOINROOM))
        return MessageExtractor::join_room_extractor(message);
    else if(identify(IDENTIFIER_NEWPLAYER))
        return MessageExtractor::newplayer_extractor(message);
    else if(identify(IDENTIFIER_PLAYERLEAVE))
        return MessageExtractor::join_ack_extractor(message);
    else if(identify(IDENTIFIER_PLAYERACTION))
        return MessageExtractor::player_action_extractor(message);
    else
        return new ResultError("Unkown Identifier: " + std::string(identifier));


}



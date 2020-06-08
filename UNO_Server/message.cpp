//
// Created by ubuntu on 2020/6/8.
//
#include "message.h"
#include "extractresults.h"

#include "string.h"
#include <map>
#include <string>
const char* JOINACK_HEADER_FORMAT = "JOIN_ACK %d %d\n";
const char* PLAYERLIST_ITEM_FORMAT = "%d %s\n";
const char* NEWPLAYER_MESSAGE_FORMAT = "NEWPLAYER %d %s";
const char* PLAYERLEAVE_MESSAGE_FORMAT = "PLAYERLEAVE %d";
const char* GAMESTART_MESSAGE_FORMAT = "GAMESTART";
const char* KEEPALIVE_CLIENT_MESSAGE_FORMAT = "CLIENTKEEPALIVE %d";
const char* KEEPALIVE_SERVER_MESSAGE_FORMAT = "SERVERKEEPALIVE";

const char* MESSAGE_ERROR = "ERROR";


std::string MessageFactory::join_ack_factory(const int player_count, const int player_id, std::map<int, std::string> & player_map){
    if(player_count<=0 or player_id<0 or player_map.empty()
       or player_map.size()!=player_count)
        return std::string(MESSAGE_ERROR);

    char message[1024], buf[128];

    sprintf(message, JOINACK_HEADER_FORMAT, player_count, player_id);
    for(auto &i : player_map){
        sprintf(buf, PLAYERLIST_ITEM_FORMAT, i.first, i.second.c_str());
        strcat(message, buf);
    }

    std::string message_std_str =  std::string(message);
    return message_std_str;

}

ResultJoinACK MessageExtractor::join_ack_extractor(const char* message) {
    int player_count, assigned_player_id;

    if(sscanf(message, JOINACK_HEADER_FORMAT, &player_count, &assigned_player_id)!=2)
        return ResultJoinACK(false);


    const char* player_list_item = strchr(message, '\n') + 1;
    //fisrt item

    std::map<int, std::string> player_map;

    int player_id;
    char player_name_buf[128];
    std::string player_name;

    for(int i=1; i<=player_count; ++i){
        if(sscanf(player_list_item, PLAYERLIST_ITEM_FORMAT, &player_id, player_name_buf)!=2)
            return ResultJoinACK(false);

        player_map[player_id] = std::string(player_name_buf);
        //get next item in the list
        player_list_item = strchr(player_list_item, '\n') + 1;
    }

    return ResultJoinACK(player_count, assigned_player_id, player_map);
}

ResultNewPlayer MessageExtractor::newplayer_extractor(const char * message) {
    int player_id;
    char player_name_buf[128];
    sscanf(message, NEWPLAYER_MESSAGE_FORMAT, &player_id, &player_name_buf);
    return ResultNewPlayer(player_id, std::string(player_name_buf));
}


std::string MessageFactory::newplayer_factory(int new_player_id, std::string player_name) {
    char message[128];
    sprintf(message, NEWPLAYER_MESSAGE_FORMAT, new_player_id, player_name.c_str());
    return std::string(message);
}

ResultPlayerLeave MessageExtractor::playerleave_extractor(const char *message) {
    int player_id;
    sscanf(message, PLAYERLEAVE_MESSAGE_FORMAT, &player_id);
    return ResultPlayerLeave(player_id);
}

std::string MessageFactory::playerleave_factory(int player_id) {
    char message[128];
    sprintf(message, PLAYERLEAVE_MESSAGE_FORMAT, player_id);
    return std::string(message);
}

std::string MessageFactory::gamestart_factory() {
    return std::string(GAMESTART_MESSAGE_FORMAT);
}

std::string MessageFactory::server_keepalive_factory() {
    return std::string(KEEPALIVE_SERVER_MESSAGE_FORMAT);
}

ResultGameStart MessageExtractor::gamestart_extractor() {
    return ResultGameStart();
}

std::string MessageFactory::client_keepalive_factory(int player_id) {
    char message[128];
    sprintf(message, KEEPALIVE_CLIENT_MESSAGE_FORMAT, player_id);
    return std::string(message);
}

ResultClientKeepAlive MessageExtractor::client_keepalive_extractor(const char *message) {
    int player_id;
    sscanf(message, KEEPALIVE_CLIENT_MESSAGE_FORMAT, &player_id);
    return ResultClientKeepAlive(player_id);
}


ResultServerKeepAlive MessageExtractor::server_keepalive_extractor() {
    return ResultServerKeepAlive();
}


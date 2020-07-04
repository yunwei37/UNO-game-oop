//
// Created by ubuntu on 2020/6/8.
//

#ifndef UNO_MESSAGE_H
#define UNO_MESSAGE_H

#include <string>
#include <map>
#include <utility>
#include "extractresults.h"

static const char* IDENTIFIER_JOINROOM = "JOIN_ROOM";
static const char* IDENTIFIER_JOINACK = "JOIN_ACK";
static const char* IDENTIFIER_NEWPLAYER = "NEWPLAYER";
static const char* IDENTIFIER_PLAYERLEAVE = "PLAYERLEAVE";
static const char* IDENTIFIER_GAMESTART = "GAMESTART";
static const char* IDENTIFIER_KEEPALIVE_CLIENT = "CLIENTKEEPALIVE";
static const char* IDENTIFIER_KEEPALIVE_SERVER = "SERVERKEEPALIVE";
static const char* IDENTIFIER_PLAYERACTION = "PLAYER_ACTION";


static const char* MESSAGEFORMAT_JOINROOM = "JOIN_ROOM %s";
static const char* MESSAGEFORMAT_JOINACK_HEADER = "JOIN_ACK %d %d\n";
static const char* MESSAGEFORMAT_PLAYERLIST_ITEM = "%d %s\n";
static const char* MESSAGEFORMAT_NEWPLAYER = "NEWPLAYER %d %s";
static const char* MESSAGEFORMAT_PLAYERLEAVE = "PLAYERLEAVE %d";
static const char* MESSAGEFORMAT_GAMESTART = "GAMESTART";
static const char* MESSAGEFORMAT_KEEPALIVE_CLIENT = "CLIENTKEEPALIVE %d";
static const char* MESSAGEFORMAT_KEEPALIVE_SERVER = "SERVERKEEPALIVE";
static const char* MESSAGEFORMAT_PLAYERACTION= "PLAYER_ACTION %d\nDRAWCARD %d\nPUTCARD %d\n";

static const char* MESSAGE_ERROR = "ERROR";


class MessageFactory {
public:
    static std::string join_room_factory(std::string player_name);
    static std::string join_ack_factory(int player_count, int player_id, std::map<int, std::string> &player_map);
    static std::string newplayer_factory(int new_player_id, std::string player_name);
    static std::string playerleave_factory(int player_id);
    static std::string gamestart_factory();
    static std::string client_keepalive_factory(int player_id);
    static std::string server_keepalive_factory();
    static std::string player_action_factory(int player_id, int draw_card_id, int put_card_id);

};

class MessageExtractor{
private:
    static ExtractResult* join_room_extractor(const char *);
    static ExtractResult* join_ack_extractor(const char *);
    static ExtractResult* newplayer_extractor(const char *);
    static ExtractResult* playerleave_extractor(const char *);
    static ExtractResult* gamestart_extractor();
    static ExtractResult* client_keepalive_extractor(const char *);
    static ExtractResult* server_keepalive_extractor();
    static ExtractResult* player_action_extractor(const char *);
public:
    static ExtractResult* handleMessage(const char *);
};

#endif //UNO_MESSAGE_H

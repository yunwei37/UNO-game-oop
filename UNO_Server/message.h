//
// Created by ubuntu on 2020/6/8.
//

#ifndef UNO_MESSAGE_H
#define UNO_MESSAGE_H

#include <string>
#include <map>
#include <utility>
#include "extractresults.h"
//
//extern const char* JOINACK_HEADER_FORMAT;
//extern const char* PLAYERLIST_ITEM_FORMAT;
//extern const char* ILLEGAL_ARGUMENT;

class MessageFactory {
public:
    static std::string join_ack_factory(int, int, std::map<int, std::string> &);
    static std::string newplayer_factory(int, std::string);
    static std::string playerleave_factory(int);
    static std::string gamestart_factory();
    static std::string client_keepalive_factory(int);
    static std::string server_keepalive_factory();

};
class MessageExtractor{
public:
    static ResultJoinACK join_ack_extractor(const char *);
    static ResultNewPlayer newplayer_extractor(const char *);
    static ResultPlayerLeave playerleave_extractor(const char *);
    static ResultGameStart gamestart_extractor();
    static ResultClientKeepAlive client_keepalive_extractor(const char *);
    static ResultServerKeepAlive server_keepalive_extractor();
    static ExtractResult handleMessage(){
        return ResultGameStart();
    }
};

#endif //UNO_MESSAGE_H
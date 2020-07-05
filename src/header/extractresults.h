//
// Created by ubuntu on 2020/6/8.
//

#ifndef UNO_EXTRACTRESULTS
#define UNO_EXTRACTRESULTS

#include <map>
#include <string>
#include <utility>


class ExtractResult{
public:
    enum TYPE{ERROR, JOINROOM, JOINACK, NEWPLAYER, PLAYERLEAVE, GAMESTART, KEEPALIVE_CLIENT, KEEPALIVE_SERVER, PLAYERACTION};
    explicit ExtractResult(TYPE type) : type(type) {

    }
    int getType() const{
        return type;
    }
protected:
    const TYPE type;
};


class ResultError : public ExtractResult{
protected:
    std::string message;

public:
    explicit ResultError(std::string message) : ExtractResult(TYPE::ERROR), message(std::move(message)) {}
    const std::string &getMessage() const {
        return message;
    }

};

class ResultJoinRoom : public ExtractResult{
protected:
    std::string player_name;
    
public:
    explicit ResultJoinRoom(std::string playerName) : ExtractResult(TYPE::JOINROOM), player_name(std::move(playerName)) {}
    const std::string &getPlayerName() const {
        return player_name;
    }

};

class ResultJoinACK : public ExtractResult{
protected:
    std::map<int, std::string> player_map;
    int player_count, assigned_player_id;

public:
    int getPlayerCount() const {
        return player_count;
    }

    int getAssignedPlayerId() const {
        return assigned_player_id;
    }

    const std::map<int, std::string> &getPlayerMap() const {
        return player_map;
    }
    ResultJoinACK(int player_count, int assigned_player_id, std::map<int, std::string> player_map) :
    ExtractResult(TYPE::JOINACK), player_count(player_count), assigned_player_id(assigned_player_id){
        this->player_map = std::move(player_map);
    }

};

class ResultNewPlayer: public ExtractResult{
protected:
    int new_player_id;
    std::string new_player_name;
public:
    int getNewPlayerId() const {
        return new_player_id;
    }
    const std::string &getNewPlayerName() const {
        return new_player_name;
    }

    ResultNewPlayer(int newPlayerId, std::string newPlayerName) :
        ExtractResult(TYPE::NEWPLAYER), new_player_id(newPlayerId), new_player_name(std::move(newPlayerName)) {}

};
class ResultPlayerLeave: public ExtractResult{
protected:
    int player_id;

public:
    explicit ResultPlayerLeave(int playerId) : ExtractResult(TYPE::PLAYERLEAVE), player_id(playerId) {}
    int getPlayerId() const {
        return player_id;
    }
};

class ResultServerKeepAlive: public ExtractResult{
public:
    ResultServerKeepAlive() : ExtractResult(TYPE::KEEPALIVE_SERVER) {};

};

class ResultClientKeepAlive: public ExtractResult{
protected:
    int player_id;

public:
    explicit ResultClientKeepAlive(int playerId=-1) : ExtractResult(TYPE::KEEPALIVE_CLIENT), player_id(playerId) {}
    int getPlayerId() const {
        return player_id;
    }
};

class ResultGameStart: public ExtractResult{
public:
    ResultGameStart() : ExtractResult(TYPE::GAMESTART) {};
};

class ResultPlayerAction: public ExtractResult{
protected:
    int player_id;
    int draw_card_id;
    int put_card_id;

public:
    explicit ResultPlayerAction(int player_id, int draw_card_id=-1,int put_card_id=-1) :
      ExtractResult(TYPE::PLAYERACTION), player_id(player_id), draw_card_id(draw_card_id), put_card_id(put_card_id){};

    int getPlayerId() const {
        return player_id;
    }

    int getDrawCardId() const {
        return draw_card_id;
    }

    int getPutCardId() const {
        return put_card_id;
    }
};

#endif // UNO_EXTRACTRESULTS

//
// Created by ubuntu on 2020/6/8.
//

#ifndef UNO_EXTRACTRESULTS
#define UNO_EXTRACTRESULTS

#include <map>
#include <string>
#include <utility>

class ExtractResult{
protected:
    int typeId;
    bool success;
public:
    explicit ExtractResult(bool success=true) : success(success), typeId(-1) {};
    bool isSuccess() const{
        return success;
    }
    int getTypeId() const{
        return typeId;
    }

};
class ResultJoinACK : public ExtractResult{
protected:
    int player_count, assigned_player_id;
    const static int typeId = 0;
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

protected:
    std::map<int, std::string> player_map;
public:
    ResultJoinACK(int player_count, int assigned_player_id, std::map<int, std::string> player_map) : player_count(player_count), assigned_player_id(assigned_player_id){
        this->player_map = std::move(player_map);
    };
    explicit ResultJoinACK(bool success) : ExtractResult(success), player_count(-1), assigned_player_id(-1) {};
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
        new_player_id(newPlayerId), new_player_name(std::move(newPlayerName)) {}

    explicit ResultNewPlayer(bool success) : ExtractResult(success), new_player_id(-1) {};
};
class ResultPlayerLeave: public ExtractResult{
protected:
    int player_id;

public:
    explicit ResultPlayerLeave(int playerId) : player_id(playerId) {}
    explicit ResultPlayerLeave(bool success) : ExtractResult(success), player_id(-1) {};
    int getPlayerId() const {
        return player_id;
    }
};

class ResultServerKeepAlive: public ExtractResult{
public:
    explicit ResultServerKeepAlive(bool success=true) : ExtractResult(success) {};

};

class ResultClientKeepAlive: public ExtractResult{
protected:
    int player_id;

public:
    explicit ResultClientKeepAlive(int playerId) : player_id(playerId) {}
    explicit ResultClientKeepAlive(bool success) : ExtractResult(success), player_id(-1) {};
    int getPlayerId() const {
        return player_id;
    }
};

class ResultGameStart: public ExtractResult{
public:
    explicit ResultGameStart(bool success=true) : ExtractResult(success){
        typeId = 1;
    };
};


#endif // UNO_EXTRACTRESULTS
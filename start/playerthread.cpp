#include "playerthread.h"
#include "backend.h"

playerThread::playerThread(Backend* b, QObject* parent): QObject(parent)
{
	type = -1;
	playerID = 0;
	back = b;
}

playerThread::playerThread(int id, Backend* b, QObject* parent)
{
	type = -1;
	playerID = id;
	back = b;
}

playerThread::playerThread(int id, Backend* b, QString name, QObject* parent)
{
	playerID = id;
	playerName = name;
	back = b;
}

QString playerThread::getPlayerName() const
{
    return playerName;
}

void playerThread::setPlayerName(QString playerName)
{
    this->playerName = playerName;
}

int playerThread::getPlayerID() const
{
    return playerID;
}


int playerThread::getType() const
{
    return type;
}



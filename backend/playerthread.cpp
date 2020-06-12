#include "playerthread.h"

playerThread::playerThread(QObject* parent): QObject(parent)
{
	type = -1;
}

playerThread::playerThread(int id, QObject* parent)
{
	playerID = id;
}

playerThread::playerThread(int id, QString name, QObject* parent)
{
	playerID = id;
	playerName = name;
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



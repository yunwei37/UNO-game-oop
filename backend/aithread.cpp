#include "aithread.h"
#include <random>

AIthread::AIthread(int id):playerThread()
{
	type = 0;
	//playerName = names[rand() % 8];
	char buff[2] = "0";
	buff[0] += id;
	playerName = QString("AI No. ") + QString(buff);

}

void AIthread::start() {

}

const QString AIthread::names[]  = { "AI No.1","AI No.2","AI No.3", "AI No.4","AI No.5","AI No.6","AI No.7", "AI No.8" };
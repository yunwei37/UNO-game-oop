#include "netthread.h"

netThread::netThread(int id) :playerThread()
{
	type = 1;
	playerID = id;
}

void netThread::start() {
	/*
	while (true) {
		emit actionReady("hello 1");
		QThread::sleep(2);
	}
	*/
}
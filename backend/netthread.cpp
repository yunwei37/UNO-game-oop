#include "netthread.h"
#include "backend.h"

netThread::netThread(int id, Backend* b) :playerThread(b)
{
	type = 1;
	playerID = id;
}

void netThread::start(int id) {
	if (id != playerID)
		return;
	/*
	while (true) {
		emit actionReady("hello 1");
		QThread::sleep(2);
	}
	*/
}
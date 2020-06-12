#include <QCoreApplication>
#include <QApplication>
#include "aithread.h"
#include "netthread.h"
#include "backend.h"
#include <qtcpsocket.h>
#include "test.h"

int main(int argc, char *argv[])
{	
	QApplication a(argc, argv);
    Backend b(4,1,2,"");
	Controller c;
	return a.exec();
}

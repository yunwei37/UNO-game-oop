#include "netserver.h"

netServer::netServer()
{

}


void netServer::readPendingDatagrams()
{
    while (receiver->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(receiver->pendingDatagramSize());
        receiver->readDatagram(datagram.data(), datagram.size());
        //数据接收在datagram里
            /* readDatagram 函数原型
            qint64 readDatagram(char *data,qint64 maxSize,QHostAddress *address=0,quint16 *port=0)
        */
    }
}
#include "netthread.h"

netThread::netThread():playerThread()
{

}

void netThread::run()
{
    while(true){
        std::cout<<"hello 2"<<std::endl;
        sleep(2);
    }
}

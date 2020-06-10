#include "aithread.h"

AIthread::AIthread():playerThread()
{

}

void AIthread::run()
{
    while(true){
        std::cout<<"hello 1"<<std::endl;
        sleep(2);
    }
}

#include "interfacemanager.h"


InterFaceManager* InterFaceManager::mInstance = NULL;

InterFaceManager::InterFaceManager(QObject *parent): QObject(parent){
    mInstance = this;
    m_sendUdp = new sendUdp();
}

InterFaceManager *InterFaceManager::getInstance()
{
    std::cout << " getinstance "<<mInstance <<std::endl;
    return mInstance;
}

void InterFaceManager::writeDataToSocket(){
    qDebug() <<"write!";
    m_sendUdp->initSocket();
    m_sendUdp->writeData();

}




#include "common.h"
#include "QTime"

Common* Common::m_instance = NULL;
TcpClientSocket* Common::m_tcpClient = NULL;
UserClient* Common::m_userClient = NULL;

Common::Common()
{
}

Common *Common::getInstance()
{
    if(NULL == m_instance){
        m_instance = new Common;
    }
    return m_instance;
}

TcpClientSocket *Common::getTcpClient()
{
    if(NULL == m_tcpClient){
        m_tcpClient = new TcpClientSocket;
    }
    return m_tcpClient;
}

UserClient *Common::getUserClientInstance()
{
    if(NULL == m_userClient){
        m_userClient = new UserClient;
    }
    return m_userClient;
}

void Common::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )   {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

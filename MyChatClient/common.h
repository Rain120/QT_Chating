#ifndef COMMON_H
#define COMMON_H

#include "tcpclientsocket.h"
#include "userclient.h"

class Common
{
public:
    static Common *getInstance();
    static TcpClientSocket *getTcpClient();
    static UserClient *getUserClientInstance();
    static void sleep(unsigned int msec);
private:
    Common();
    static Common* m_instance;
    static TcpClientSocket* m_tcpClient;
    static UserClient* m_userClient;
};

#endif // COMMON_H

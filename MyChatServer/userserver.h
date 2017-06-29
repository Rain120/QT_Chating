#ifndef USERSERVER_H
#define USERSERVER_H

#include <QObject>
#include "userclient.h"
#include "tcpserver.h"

class UserServer : public QObject
{
    Q_OBJECT
public:
    explicit UserServer(QObject *parent = 0);
    void start(int port);
    void stop();
    void addClient(UserClient* c);
    QMap<int, UserClient*>getClients();
    void online(UserClient* user);
    
private:
    TCPServer* m_tcpServer;
    QMap<int, UserClient*> m_userClients;
    
};

#endif // USERSERVER_H

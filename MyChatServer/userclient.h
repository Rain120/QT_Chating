#ifndef USERCLIENT_H
#define USERCLIENT_H

#include <QObject>
#include "tcpclientsocket.h"
#include "database.h"

class UserClient : public QObject
{
    Q_OBJECT
public:
    explicit UserClient(TcpClientSocket* clientSocket, QObject *parent = 0);
    TcpClientSocket* m_clientSocket;

    DBUser *getSelfuser() {
        return m_selfuser;
    }
    void online(UserClient* c);

public slots:
    void receiveMessage(QMap<QString, QString> message);
    
private:
    DBUser *m_selfuser;  // 用户信息数据

    void doRegister(QMap<QString, QString> message);
    void doLogin(QMap<QString, QString> message);
    void doSearch(QMap<QString, QString> message);
};

#endif // USERCLIENT_H

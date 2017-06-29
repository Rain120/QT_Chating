#ifndef USERCLIENT_H
#define USERCLIENT_H

#include <QObject>
#include "QMap"
#include "tcpclientsocket.h"
#include "Database.h"

class UserClient : public QObject
{
    Q_OBJECT
public:
    explicit UserClient(QObject *parent = 0);
    ~UserClient();

    bool login();
    bool regist();

    void doRegisterSuccess(QMap<QString, QString> message);
    void doLoginSuccess(QMap<QString, QString> message);
    void doLoginNoAccount(QMap<QString, QString> message);
    void doLoginExist(QMap<QString, QString> message);

    User* getSelfUser();

signals:
    void registerSuccess();
    void loginSuccess();
    void loginNoAccount();
    void loginExist();

public slots:
    void receiveMessage(QMap<QString, QString> message);

private:
    TcpClientSocket* m_clientSocket;
    User* m_selfuser;
    static UserClient* m_self;

};

#endif // USERCLIENT_H

#include "userserver.h"
#include <QMessageBox>

UserServer::UserServer(QObject *parent) :
    QObject(parent),
    m_tcpServer(new TCPServer)
{
}

void UserServer::start(int port)
{
    if (false == m_tcpServer->listen(QHostAddress::Any, port)) {
        QMessageBox::warning(NULL, "Error", "Can't start listen!");
        qDebug() << m_tcpServer->errorString();
    }
}

void UserServer::stop()
{
    m_userClients.clear();
    m_tcpServer->close();
}

void UserServer::addClient(UserClient *c)
{
    m_userClients[c->getSelfuser()->userid] = c;
}

QMap<int, UserClient *> UserServer::getClients()
{
    return m_userClients;
}

void UserServer::online(UserClient *user)
{
    foreach (UserClient* c, m_userClients)
    {
        if (c->getSelfuser()->userid == user->getSelfuser()->userid)
        {
            continue;
        }
        c->online(user);
    }
}

#include "tcpserver.h"
#include "tcpclientsocket.h"
#include "userclient.h"

TCPServer::TCPServer(QObject *parent) :
    QTcpServer(parent)
{
}

void TCPServer::incomingConnection(int socketDescriptor)
{
    TcpClientSocket* tcpCS = new TcpClientSocket(this);
    tcpCS->setSocketDescriptor(socketDescriptor);

    UserClient* uClient = new UserClient(tcpCS);
    Q_UNUSED(uClient);
}

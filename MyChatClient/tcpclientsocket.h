#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>
#include "QtNetwork"

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QObject *parent = 0);

    void setServerIP(QString serverIP);
    void setServerTcpPort(QString serverTcpPort);

    QString getServerIP();
    QString getServerTcpPort();

    bool testConnect();
    bool connectToServer();

    void sendMessage(QMap<QString, QString> message);

signals:
    void dealMessage(QMap<QString, QString> message);

public slots:
    void receiveMessage();

private:
    QString m_serverIP;  // 服务器IP地址
    int m_serverTcpPort;  // 服务器的监听端口号
    quint16 m_blocksize;  // 包数据大小。

};

#endif // TCPCLIENTSOCKET_H

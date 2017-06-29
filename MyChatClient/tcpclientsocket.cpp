#include "tcpclientsocket.h"
#include "QDebug"

TcpClientSocket::TcpClientSocket(QObject *parent) :
    QTcpSocket(parent),m_blocksize(0)
{
    // 有可读信息后，需要调用receiveMessage进行处理
    connect(this, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
}

void TcpClientSocket::setServerIP(QString serverIP)
{
    m_serverIP = serverIP;
}

void TcpClientSocket::setServerTcpPort(QString serverTcpPort)
{
    m_serverTcpPort = serverTcpPort.toInt();
}

QString TcpClientSocket::getServerIP()
{
    return m_serverIP;
}

QString TcpClientSocket::getServerTcpPort()
{
    return QString::number(m_serverTcpPort);
}

bool TcpClientSocket::testConnect()
{
    disconnectFromHost();    //断开当前socket与主机的连接
    connectToHost(QHostAddress(this->m_serverIP), this->m_serverTcpPort);   //连接服务器
    bool ret = waitForConnected();

    disconnectFromHost();     //断开连接
    qDebug() << "Client TcpClientSocket::testConnect() ret:" << ret;
    return ret;
}

bool TcpClientSocket::connectToServer()
{
    bool ret = true;
    abort();
    if ((ret = testConnect()) == false) {
        return ret;
    }
    connectToHost(QHostAddress(this->m_serverIP), this->m_serverTcpPort);
    return ret;
}

void TcpClientSocket::sendMessage(QMap<QString, QString> message)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);

    // 预存2个字节，消息存储结束后，设置实际大小
    out << (quint16)0;

    // 把消息按照[消息名称：消息内容]的格式进行存储
    foreach (QString key, message.keys()) {
        QString tempmsg = key + ":" + message[key];
        out << tempmsg;
        qDebug() << "Client TcpClientSocket::sendMessage tempmsg:" << tempmsg;
    }

    // 存储消息的大小到预留位置
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    // 发送消息
    write(block);
}

void TcpClientSocket::receiveMessage()
{
    QDataStream in(this);

    // 取得消息的size
    if (m_blocksize == 0) {
        if (bytesAvailable() <(quint16)sizeof(quint16)) {
            return;
        }
        in >> m_blocksize;
    }

    // 取得剩余消息的带下，若不满足size则返回等待下次一起读取
    int initBytes = bytesAvailable();
    if (initBytes < m_blocksize) {
        return;
    }

    // 读取消息并按照[消息名称：消息内容]格式进行解析
    QMap<QString, QString> message;
    int msgSize = 0;
    while(m_blocksize > msgSize) {
        QString tempmsg;
        in >> tempmsg;
        qDebug() <<"Client TcpClientSocket::receiveMessage tempmsg:" << tempmsg;
        int idxSplitor = tempmsg.indexOf(":");
        message[tempmsg.mid(0, idxSplitor)] = \
                tempmsg.mid(idxSplitor+1, tempmsg.length()-idxSplitor-1);
        msgSize = initBytes - bytesAvailable();  // 已读取的数据大小。
    }
    // 读取完毕后，通知
    emit dealMessage(message);

    // 有可能一次发送多个信息，初始化size，判断是否还有数据需要继续读取
    m_blocksize = 0;
    if (bytesAvailable() > 0) {
        this->receiveMessage();
    }
}

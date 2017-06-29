#include "userclient.h"
#include "Constant.h"
#include "Database.h"
#include "common.h"
#include "QDebug"

UserClient::UserClient(QObject *parent) :
    QObject(parent),m_clientSocket(Common::getTcpClient())
{
    m_selfuser = new User;

    connect(m_clientSocket, SIGNAL(dealMessage(QMap<QString,QString>)),
            this, SLOT(receiveMessage(QMap<QString,QString>)));
}

UserClient::~UserClient()
{
    delete m_selfuser;
}

bool UserClient::
login()
{
    bool ret = m_clientSocket->connectToServer();
    if(ret == false){
        return ret;
    }

    QMap<QString, QString> message;
    message["requestKind"] = QString::number(RequestLogin);
    message["userid"] = QString::number(m_selfuser->userid);
    //    message["name"] = m_selfuser->name;
    message["pwd"] = m_selfuser->pwd;

    m_clientSocket->sendMessage(message);
    ret = m_clientSocket->waitForReadyRead();
    qDebug() << "Client UserClient::login() ret:" << ret;
    return ret;
}

bool UserClient::regist()
{
    bool ret = m_clientSocket->connectToServer();
    if(ret == false){
        return ret;
    }

    QMap<QString, QString> message;
    message["requestKind"] = QString::number(RequestRegister);
    message["name"] = m_selfuser->name;
    message["pwd"] = m_selfuser->pwd;

    m_clientSocket->sendMessage(message);

    ret = m_clientSocket->waitForReadyRead();
    qDebug() << "Client UserClient::regist() ret:" << ret;
    m_clientSocket->disconnectFromHost();
    return ret;
}

void UserClient::doRegisterSuccess(QMap<QString, QString> message)
{
    m_selfuser->userid = message["userid"].toInt();
    emit registerSuccess();
}

void UserClient::doLoginSuccess(QMap<QString, QString> message)
{
    m_selfuser->name = message["name"];
    m_selfuser->userid = message["userid"].toInt();

    QMap<QString, QString>msg;
    TcpClientSocket* tcpCS = Common::getTcpClient();

    msg["userid"] = message["userid"];
    msg["username"] = message["name"];
    msg["requestKind"] = QString::number(RequestOnline);

    tcpCS->sendMessage(msg);
    emit loginSuccess();
}

void UserClient::doLoginNoAccount(QMap<QString, QString> message)
{
    Q_UNUSED(message);
    emit loginNoAccount();
}

void UserClient::doLoginExist(QMap<QString, QString> message)
{
    int tempUserid = 0;
    m_selfuser->userid = message["userid"].toInt();
    if(++tempUserid != m_selfuser->userid){
        qDebug() << "UserClient::doLoginExist tempUserid:" << tempUserid;
        emit loginExist();
    }
}

User *UserClient::getSelfUser()
{
    return m_selfuser;
}

void UserClient::receiveMessage(QMap<QString, QString> message)
{
    int responseKind = message["responseKind"].toInt();
    if(ResponseRegisterSuccess == responseKind){
        doRegisterSuccess(message);
    }
    else if(ResponseLoginSuccess == responseKind){
        doLoginSuccess(message);
    }
    else if(ResponseLoginNoAccount == responseKind){
        doLoginNoAccount(message);
    }
    else if(ResponseHaveLogined == responseKind){
        doLoginExist(message);
    }
}

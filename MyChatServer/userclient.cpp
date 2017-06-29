#include "userclient.h"
#include "constant.h"
#include "common.h"
#include"tcpclientsocket.h"
#include<QDebug>
#include"database.h"
#include "QMessageBox"

UserClient::UserClient(TcpClientSocket *clientSocket, QObject *parent) :
    QObject(parent), m_clientSocket(clientSocket), m_selfuser(new DBUser)
{

    connect(m_clientSocket, SIGNAL(dealMessage(QMap<QString,QString>)),\
            this, SLOT(receiveMessage(QMap<QString,QString>)));
}

void UserClient::receiveMessage(QMap<QString, QString> message)
{
    int requestKind = message["requestKind"].toInt();
    if(RequestRegister == requestKind){
        doRegister(message);
    }
    else if(RequestLogin == requestKind){
        doLogin(message);
    }
}

void UserClient::doRegister(QMap<QString, QString> message)
{
    DBUser userinfo;
    Database* db = Database::getInstance();
    userinfo.name = message["name"];
    userinfo.pwd = message["pwd"];

    // 插入到数据库
    db->insertUser(userinfo);

    // 取得插入后的最大userid（即，刚刚注册得用id）
    QString userid = db->getMaxUserid();

    // 反馈注册成功消息
    QMap<QString, QString> msg;
    msg["responseKind"] = QString::number(ResponseRegisterSuccess);
    msg["userid"] = userid;

    m_clientSocket->sendMessage(msg);
}

void UserClient::doLogin(QMap<QString, QString> message)
{
    // 验证用户名密码， 并取得这个用户的个人信息
    Database* db = Database::getInstance();
    DBUser userinfo = db->getUserInfo(message["userid"].toInt(), message["pwd"]);
    QMap<QString, QString> msg;

    // 验证失败，返回失败信息
    if (userinfo.userid == -1) {
        msg["responseKind"] = QString::number(ResponseLoginNoAccount);
        m_clientSocket->sendMessage(msg);
        return;
    }


    // 取得Server实例
    UserServer* s = Common::getServerInstance();
    // 设置个人信息，并添加给server保管
    getSelfuser()->userid = userinfo.userid;
    getSelfuser()->name = userinfo.name;
    getSelfuser()->pwd = userinfo.pwd;

    s->addClient(this);

    // 将取得的个人信息发送给登入者
    msg["responseKind"] = QString::number(ResponseLoginSuccess);
    msg["name"] = userinfo.name;
    msg["userid"] = QString::number(userinfo.userid);
    msg["pwd"] = userinfo.pwd;

    m_clientSocket->sendMessage(msg);

    // 通知其他客户端，有新用户上线
    s->online(this);
}

void UserClient::doSearch(QMap<QString, QString> message)
{
    Database* db = Database::getInstance();

    QMap<QString, QString> msg;
    // 验证失败，返回失败信息
    if (message["userid"].toInt() == -1) {
        msg["responseKind"] = QString::number(ResponseLoginNoAccount);
        m_clientSocket->sendMessage(msg);
        return;
    }
}

void UserClient::online(UserClient *c)
{
    // 发送上线者的个人信息
    QMap<QString, QString> msg;
    msg["responseKind"] = QString::number(ResponseUserOnline);
    msg["userid"] = QString::number(c->getSelfuser()->userid);
    msg["name"] = c->getSelfuser()->name;

    // 发送s
    m_clientSocket->sendMessage(msg);
}

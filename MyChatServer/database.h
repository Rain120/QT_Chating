#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

struct DBUser {
public:
    int userid;     //用户ID
    QString name;   // 用户昵称
    QString pwd;    // 密码
};

class Database
{
public:
    static Database* getInstance();
    void insertUser(struct DBUser user);
    void insertFriendsRelative(int userid, struct DBUser user);
    bool getUserFriendsInfoByID(int userid);
    QString getMaxUserid();
    struct DBUser getUserInfo(int userid, QString pwd);
    struct DBUser getUserInfoByID(int userid);
private:
    Database();
    QSqlDatabase _m_sqldb;
    static Database* _m_db;
};

#endif // DATABASE_H

#include "database.h"
#include <QMessageBox>
#include <QSqlError>
#include "QDebug"
#include "constant.h"

Database* Database::_m_db = NULL;

Database::Database()
{
    _m_sqldb = QSqlDatabase::addDatabase("QSQLITE");
    _m_sqldb.setDatabaseName("E:/QT/ProgramCode/MyChatClient/res/test.db");
    
    if (!_m_sqldb.open()) {
        QMessageBox::warning(NULL, "Error", _m_sqldb.lastError().text());
        qDebug() << "数据库打开失败！！！";
        return;
    }
    
    QSqlQuery query;
    QString sqlTb1 = "create table if not exists test_user(userid integer primary key not null, "
            "name varchar(100) not null, pwd varchar(100) not null)";
    
    if(!query.exec(sqlTb1)){
        qDebug() << "sqlTb1:" << _m_sqldb.lastError().text();
        return;
    }
    //好友表（好友A，好友B，关系，备注）
    QString sqlTb2 = "create table if not exists friends(first integer not null, second integer not null)";

            if(!query.exec(sqlTb2)){
            qDebug() << "sqlTb2:" << _m_sqldb.lastError().text();
            return;
}
}

void Database::insertUser(DBUser user)
{
    qDebug() << "数据库插入ing！！！";
    QSqlQuery query(_m_sqldb);
    //    QString sql = QString("insert into test_user values(null, '%1', '%2')")
    //            .arg(user.name)
    //            .arg(user.pwd);
    //    qDebug() << "Name:" << user.name << "pwd:" << user.pwd;
    //    if(!query.exec(sql)){
    //        qDebug() << "数据库执行错误！！！" << query.lastError().text();
    //        return;
    //    }
    query.prepare("insert into test_user values(NULL, :name, :pwd)");
    query.bindValue(":name", QVariant(user.name));
    query.bindValue(":pwd", QVariant(user.pwd));
    qDebug() << "Userid:" << user.userid << "Name:" << user.name << "pwd:" << user.pwd;
    if(!query.exec()){
        qDebug() << "数据库执行错误！！！" << query.lastError().text();
        return;
    }
    qDebug() << "数据库插入成功！！！";
}

void Database::insertFriendsRelative(int userid, DBUser user)
{
    QSqlQuery query(_m_sqldb);
    query.prepare("insert into friends values(:first, :second)");
    query.bindValue(":first", QVariant(user.userid));
    query.bindValue(":second", QVariant(userid));
    if(!query.exec()){
        qDebug() << "数据库执行错误！！！" << query.lastError().text();
        return;
    }
}

bool Database::getUserFriendsInfoByID(int userid)
{
    QSqlQuery query;
    query.prepare("select userid from friends where userid = :userid;");
    query.bindValue(":userid", QVariant(userid));

    query.exec();
    if (query.isActive())
    {
        qDebug() << query.lastError().text();
    }
    if (query.isValid())
    {
        qDebug () << "bool Database::getUserFriendsInfoByID(int userid):" << query.lastError().text();
    }
    DBUser ret;
    QSqlRecord record = query.record();
    ret.userid = record.value("userid").toInt();
    if(ret.userid == NULL){
        return false;
    }
    else{
        return true;
    }
}

QString Database::getMaxUserid()
{
    
    QSqlQuery query;
    query.exec("select Max(userid) from test_user");
    if (!query.next()) {
        return "";
    }
    return query.value(0).toString();
}

DBUser Database::getUserInfo(int userid, QString pwd)
{
    QSqlQuery query;
    query.prepare("select userid, name from test_user where userid = :userid and pwd = :pwd;");
    query.bindValue(":userid", QVariant(QString::number(userid)));
    query.bindValue(":pwd", QVariant(pwd));
    query.exec();
    DBUser ret;
    if (!query.next()) {
        ret.userid = -1;
        return ret;
    }

    QSqlRecord record = query.record();
    ret.userid = record.value("userid").toInt();
    ret.name = record.value("name").toString();

    return ret;
}

DBUser Database::getUserInfoByID(int userid)
{
    QSqlQuery query;
    query.prepare("select userid, name from test_user where userid = :userid;");
    query.bindValue(":userid", QVariant(userid));

    query.exec();
    if (query.isActive())
    {
        qDebug() << query.lastError().text();
    }
    DBUser ret;
    if (!query.next()) {
        ret.userid = -1;
        return ret;
    }
    if (query.isValid())
    {
        qDebug ()<< query.lastError().text();
    }

    QSqlRecord record = query.record();
    ret.userid = record.value("userid").toInt();
    ret.name = record.value("name").toString();

    return ret;
}

Database *Database::getInstance()
{
    if(_m_db == NULL){
        _m_db = new Database;
    }
    return _m_db;
}

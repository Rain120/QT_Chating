#include "clientwidget.h"
#include "ui_clientwidget.h"
#include "QtNetwork"
#include "QMessageBox"
#include "QFile"
#include "QString"
#include "QFileDialog"
#include "QTimer"
#include "QHostInfo"
#include "QProcess"
#include "QNetworkInterface"
#include "QDateTime"
#include "Database.h"
#include "common.h"
#include "QGroupBox"
#include "QToolButton"
#include "QListWidgetItem"

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("MyChat");
    this->setWindowOpacity(1);

    m_userName = new User;
    m_client = Common::getUserClientInstance();

    _clientBindPort = 8888;
    _clientSender = new QUdpSocket(this);

    _clientReciever = new QUdpSocket(this);
    _clientReciever->bind(_clientBindPort,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    connect(_clientReciever, SIGNAL(readyRead()), this,SLOT(clientProcessPendingDatagram()));

    //    getIP();
    //    getUserName();
    //    getMessage();
    //    showUserInfo();
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(showCurrentTime())); //show recieve time
    _timer->start(1000);
}

void ClientWidget::showUserInfo()
{
    QGroupBox *myFriendsGroup = new QGroupBox(this);
    QHBoxLayout *myFriendsLayout = new QHBoxLayout(myFriendsGroup);
    QListWidget* friendsList = new QListWidget;
    friendsList->setWindowTitle("HelloWorld");

    QListWidgetItem* list1 = new QListWidgetItem(m_client->getSelfUser()->name, friendsList);
    friendsList->addItem(list1);
    //    friendsList->show();
    myFriendsLayout->addWidget(friendsList);
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_send_pbt_clicked()
{
    QString sendMessage = ui->sendMessage_tedt->toPlainText();
    if(sendMessage != NULL){
        _clientSender->writeDatagram(sendMessage.toUtf8().data(),
                                     sendMessage.toUtf8().size(),
                                     QHostAddress::Broadcast, 8888);
        //ui->displayMessage_tbro->setText(sendMessage);
        _oldMessage.append(_newMessage);
        _newMessage = "";
        ui->sendMessage_tedt->clear();
    }
    else{
        QMessageBox::warning(this, "Error", "不能发送空白消息", QMessageBox::Ok);
    }
}

void ClientWidget::clientProcessPendingDatagram()
{
    while(_clientReciever->hasPendingDatagrams()){

        QByteArray datagram;
        datagram.resize(_clientReciever->pendingDatagramSize());
        _clientReciever->readDatagram(datagram.data(), datagram.size());

        ui->displayMessage_tbro->append(m_client->getSelfUser()->name);
        ui->displayMessage_tbro->append(_currentTime);
        ui->displayMessage_tbro->append(datagram);

        _newMessage.append(m_client->getSelfUser()->name + "\t");
        _newMessage.append(_currentTime + "\n");
        _newMessage.append(datagram);

    }
}

void ClientWidget::showCurrentTime()
{
    _currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
}

bool ClientWidget::saveFile(const QString &filename)
{
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "保存文件", (tr("无法保存文件%1:\n%2").arg(filename).arg(file.errorString())));
        return false;
    }
    QTextStream out(&file);
    out << ui->displayMessage_tbro->toPlainText();
    return true;
}

void ClientWidget::clearChatRecord()
{
    ui->displayMessage_tbro->clear();
}

void ClientWidget::on_sendFile_tbt_clicked()
{

}

void ClientWidget::on_chatRecord_comb_activated(const QString &arg1)
{
    if(arg1 == "保存聊天记录"){
        if(ui->displayMessage_tbro->document()->isEmpty()){
            QMessageBox::warning(0, "警告", "聊天记录为空", QMessageBox::Ok);
        }
        else{
            QString filename = QFileDialog::getSaveFileName(this, "保存聊天记录", "聊天记录", "文本(*.txt);;All File(*.*)");
            if(!filename.isEmpty()){
                saveFile(filename);
            }
        }
    }
    else if(arg1 == "删除聊天记录"){
        if(ui->displayMessage_tbro->toPlainText().isEmpty()){
            QMessageBox::warning(0, "警告", "聊天记录为空", QMessageBox::Ok);
        }
        else{
            clearChatRecord();
        }
    }
}


void ClientWidget::on_searchUser_tbt_clicked()
{

}

QString ClientWidget::getIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list) {
        if(address.protocol() == QAbstractSocket::IPv4Protocol){
            qDebug() << address.toString();
            return address.toString();
        }
    }
    return 0;
}

QString ClientWidget::getUserName()
{
    QStringList envVariables;
    envVariables << "USERNAME.*" << "USR.*" << "USERDOMAIN.*" << "HOSTNAME.*" << "DOMAINNAME.*";
    QStringList environment = QProcess::systemEnvironment();
    foreach (QString str, envVariables) {
        int index = environment.indexOf(QRegExp(str));
        if(index != 1){
            QStringList strList = environment.at(index).split('=');
            qDebug() << "strList:"<< strList;
            if(strList.size() == 2){
                return strList.at(1);
                break;
            }
        }
    }
    return "unknow";
}

QString ClientWidget::getMessage()
{
    QString msg = ui->sendMessage_tedt->toPlainText();
    ui->sendMessage_tedt->clear();
    ui->sendMessage_tedt->setFocus();
    qDebug() << "Message:" << msg;
    return msg;
}


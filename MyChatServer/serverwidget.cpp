#include "serverwidget.h"
#include "ui_serverwidget.h"
#include "QDateTime"
#include "QTimer"
#include "QMap"
#include "userserver.h"
#include "common.h"

ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("服务器");
    this->setWindowOpacity(1);

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
        ipAddressesList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    ui->ip_port_ptd->setPlainText(tr("IP:%1\nPort:%2").arg(ipAddress).arg(_serverBindPort));
/*****
*    _serverBindPort = 6667;
*    _serverReciever = new QUdpSocket(this);
*    _serverReciever->bind(_serverBindPort,QUdpSocket::ShareAddress);
*    connect(_serverReciever, SIGNAL(readyRead()), this,SLOT(serverProcessPendingDatagram()));
*
*   _timer = new QTimer(this);
*    connect(_timer, SIGNAL(timeout()), this, SLOT(showCurrentTime())); //show recieve time
*    _timer->start(1000);
*
*    _serverSender = new QUdpSocket(this);
******/
}

ServerWidget::~ServerWidget()
{
    delete ui;
}
void ServerWidget::serverProcessPendingDatagram()
{
    while(_serverReciever->hasPendingDatagrams()){

        QByteArray datagram;
        datagram.resize(_serverReciever->pendingDatagramSize());
        _serverReciever->readDatagram(datagram.data(), datagram.size());

        ui->ip_port_ptd->setPlainText(_currentTime);
        ui->ip_port_ptd->setPlainText(datagram);
        _newMessage.append(_currentTime + "\n");
        _newMessage.append(datagram);

    }
}

void ServerWidget::showCurrentTime()
{
    _currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
}

void ServerWidget::on_serverSend_pbt_clicked()
{
    this->close();
//    _serverSender->writeDatagram(_newMessage.toUtf8().data(),
//                                 _newMessage.toUtf8().size(),
//                                 QHostAddress::Broadcast, _serverBindPort);
//    _oldMessage.append(_newMessage);
//    _newMessage = "";
}

void ServerWidget::on_openServer_pbt_clicked()
{
    UserServer* server = Common::getServerInstance();
    int tcpPort = 11120;
    server->start(tcpPort);
    ui->openServer_pbt->setEnabled(false);
    ui->closeServer_pbt->setEnabled(true);
    qDebug() << "Server Opening!!!";
}

void ServerWidget::on_closeServer_pbt_clicked()
{
    UserServer* server = Common::getServerInstance();
    server->stop();
    ui->openServer_pbt->setEnabled(true);
    ui->closeServer_pbt->setEnabled(false);
}

#include "tcpclient.h"
#include "ui_tcpclient.h"
#include "QTime"
#include "QTimer"
#include "QFile"
#include "QDebug"
#include "QDataStream"
#include "QHostAddress"
#include "QMessageBox"
#include <QLabel>

TcpClient::TcpClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);

    _TotalBytes = 0;
    _bytesReceived = 0;
    _fileNameSize = 0;
    _tcpClient = new QTcpSocket(this);
    _tcpPort = 6666;

    connect(_tcpClient, SIGNAL(readyRead()), this, SLOT(readMessage()));

    connect(_tcpClient, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::setHostAddress(QHostAddress address)
{
    _hostAddress = address;
    newConnect();
}

void TcpClient::setFileName(QString fileName)
{
    _localFile = new QFile(fileName);
}

void TcpClient::changeEvent(QEvent *e)
{
    on_close_pbt_clicked();
}

void TcpClient::on_cancel_pbt_clicked()
{
    _tcpClient->abort();
    if(_localFile->isOpen()){
        _localFile->close();
    }
}

void TcpClient::on_close_pbt_clicked()
{
    _tcpClient->abort();
    if(_localFile->isOpen()){
        _localFile->close();
    }
    this->close();
}

void TcpClient::readMessage()
{
    QDataStream in(_tcpClient);
    in.setVersion(QDataStream::Qt_5_2);

    float useTime = _time.elapsed();
    if(_bytesReceived <= sizeof(qint64)*2){
        if((_tcpClient->bytesAvailable() >= sizeof(qint64)*2) && (_fileNameSize == 0)){
            in>>_TotalBytes>>_fileNameSize;
            _bytesReceived += sizeof(qint64)*2;
        }
        if((_tcpClient->bytesAvailable() >= _fileNameSize) && (_fileNameSize != 0)){
            in>>_fileName;
            _bytesReceived += _fileNameSize;

            if(!_localFile->open(QFile::WriteOnly)){
                QMessageBox::warning(this, "应用程序", (tr("无法读取文件 %1 : \n %2").arg(_fileName).arg(_localFile->errorString())));
                return;
            }
        }
        else{
            return;
        }
    }
    if(_bytesReceived < _TotalBytes){
        _bytesReceived += _tcpClient->bytesAvailable();
        _inBlock = _tcpClient->readAll();
        _localFile->write(_inBlock);
        _inBlock.resize(0);
    }
    ui->recieveFile_proBar->setMaximum(_TotalBytes);
    ui->recieveFile_proBar->setValue(_bytesReceived);
    qDebug()<<_bytesReceived<<"received"<<_TotalBytes;

    double speed = _bytesReceived / useTime;
    ui->hintRecieveFile_label->setText(tr("已接收 %1MB (%2MB/s) \n共%3MB 已用时:%4秒\n估计剩余时间：%5秒")
            .arg( _bytesReceived / (1024 * 1024) )
            .arg( speed * 1000 / (1024*1024), 0, 'f', 2 )
            .arg( _TotalBytes / (1024 * 1024))
            .arg( useTime / 1000,0,'f',0)
            .arg( _TotalBytes/speed/1000 - useTime / 1000,0,'f',0));

    if(_bytesReceived == _TotalBytes)
    {
        _localFile->close();
        _tcpClient->close();
        ui->hintRecieveFile_label->setText((tr("接收文件 %1 完毕")).arg(_fileName));
    }
}

void TcpClient::displayError(QAbstractSocket::SocketError socketError)
{
    switch(socketError)
    {
    case QAbstractSocket::RemoteHostClosedError : break;
    default : qDebug() << _tcpClient->errorString();
    }
}

void TcpClient::newConnect()
{
    _blockSize = 0;
    _tcpClient->abort();
    _tcpClient->connectToHost(_hostAddress, _tcpPort);
    _time.start();
}

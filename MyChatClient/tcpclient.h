#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDialog>
#include "QTcpSocket"
#include "QTime"
#include "QTimer"
#include "QFile"
#include "QHostAddress"

namespace Ui {
class TcpClient;
}

class TcpClient : public QDialog
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = 0);
    ~TcpClient();

    void setHostAddress(QHostAddress address);
    void setFileName(QString fileName);
protected:
    void changeEvent(QEvent *e);
private slots:
    void on_cancel_pbt_clicked();

    void on_close_pbt_clicked();

    void readMessage();

    void displayError(QAbstractSocket::SocketError);

    void newConnect();

private:
    Ui::TcpClient *ui;
    QTcpSocket* _tcpClient;
    quint16 _blockSize;
    QHostAddress _hostAddress;

    qint16 _tcpPort;
    qint64 _TotalBytes;
    qint64 _bytesReceived;
    qint64 _bytesToReceive;
    qint64 _fileNameSize;
    QString _fileName;
    QFile* _localFile;
    QByteArray _inBlock;

    QTime _time;
};

#endif // TCPCLIENT_H

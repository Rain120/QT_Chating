#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include "QtNetwork"
#include "QTime"
#include "QTimer"

namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWidget(QWidget *parent = 0);
    ~ServerWidget();

private slots:

    void serverProcessPendingDatagram(void);

    void showCurrentTime(void);

    void on_serverSend_pbt_clicked();

    void on_openServer_pbt_clicked();

    void on_closeServer_pbt_clicked();

private:
    Ui::ServerWidget *ui;
    QUdpSocket* _serverReciever;
    QUdpSocket* _serverSender;
    QString _currentTime;
    QTimer* _timer;
    QString _oldMessage;
    QString _newMessage;
    qint16 _serverBindPort;
};

#endif // SERVERWIDGET_H

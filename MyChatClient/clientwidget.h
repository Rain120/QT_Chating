#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include "QtNetwork"
#include "QTime"
#include "QTimer"
#include "Database.h"
#include "userclient.h"
#include "QToolButton"

namespace Ui {
class ClientWidget;
}
enum MessageType{
    Message,
    NewParticipate,
    ParticipateLeave,
    FileName,
    Refuse
};
class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWidget(QWidget *parent = 0);
    ~ClientWidget();
protected:
    bool saveFile(const QString& filename);

    void clearChatRecord(void);

    void sendMessage(MessageType type, QString serverAddress = "");

    void showUserInfo();

    QString getIP();
    QString getUserName();
    QString getMessage();

private slots: 

    void showCurrentTime(void);

    void on_send_pbt_clicked();

    void on_sendFile_tbt_clicked();

    void on_chatRecord_comb_activated(const QString &arg1);

    void clientProcessPendingDatagram(void);

    void on_searchUser_tbt_clicked();

private:
    Ui::ClientWidget *ui;

    UserClient* m_client;
    User* m_userName;

    QUdpSocket* _clientSender;
    QUdpSocket* _clientReciever;
    QString _currentTime;
    QTimer* _timer;
    QString _oldMessage;
    QString _newMessage;
    qint16 _clientBindPort;

    QToolButton* toolbt1;
};

#endif // CLIENTWIDGET_H

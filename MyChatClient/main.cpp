#include "clientwidget.h"
#include "logindialog.h"
#include <QApplication>
#include "common.h"
#include "myfriendswidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    ClientWidget w;
    //    w.show();
//    LogInDialog *dlg = new LogInDialog;
//    dlg->setAttribute(Qt::WA_DeleteOnClose);
//    dlg->show();
    //    if (dlg->exec() == QDialog::Accepted)
    //    {
    //       w.show();
    //       return a.exec();
    //    }
    //    else return 0;
    TcpClientSocket* c = Common::getTcpClient();
    c->setServerIP("127.0.0.1");
    c->setServerTcpPort("11120");
    LogInDialog dlg;
    dlg.show();
    return a.exec();
}

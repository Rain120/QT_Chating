#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "userclient.h"

namespace Ui {
class LogInDialog;
}

class LogInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogInDialog(QWidget *parent = 0);
    ~LogInDialog();

private slots:
    void on_exit_pbt_clicked();

    void on_login_pbt_clicked();

    void on_signup_pbt_clicked();

    void loginNoAccountSlots();
    void loginSuccessSlots();
    void loginExistSlots();

private:
    Ui::LogInDialog *ui;
    UserClient* m_client;
};

#endif // LOGINDIALOG_H

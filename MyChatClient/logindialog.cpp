#include "logindialog.h"
#include "ui_logindialog.h"
#include "clientwidget.h"
#include "signupdialog.h"
#include "QMessageBox"
#include "common.h"
#include "QGroupBox"
#include "QToolButton"
#include "QListWidgetItem"

LogInDialog::LogInDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
    this->setWindowOpacity(1);

    UserClient* c = Common::getUserClientInstance();

    connect(c, SIGNAL(loginNoAccount()), this, SLOT(loginNoAccountSlots()));
    connect(c, SIGNAL(loginSuccess()), this, SLOT(loginSuccessSlots()));
    connect(c, SIGNAL(loginExist()), this, SLOT(loginExistSlots()));
}

LogInDialog::~LogInDialog()
{
    delete ui;
}

void LogInDialog::on_exit_pbt_clicked()
{
    this->close();
}

void LogInDialog::on_login_pbt_clicked()
{
    UserClient* c = Common::getUserClientInstance();
    c->getSelfUser()->userid = ui->username_ledt->text().toInt();
    c->getSelfUser()->pwd = ui->passwd_ledt->text();

    if(c->getSelfUser()->userid == NULL && c->getSelfUser()->pwd == NULL){
        QMessageBox::warning(this, "Error", "用户名、密码都为空！", QMessageBox::Ok);
    }
    else if(c->getSelfUser()->userid == NULL && c->getSelfUser()->pwd != NULL)
    {
        QMessageBox::warning(this, "Error", "用户名为空！", QMessageBox::Ok);
    }
    else if(c->getSelfUser()->userid != NULL && c->getSelfUser()->pwd == NULL)
    {
        QMessageBox::warning(this, "Error", "密码为空！", QMessageBox::Ok);
    }
    else{
        if(!c->login()){
            ui->hint_Login_Info_lb->setVisible(true);
            ui->hint_Login_Info_lb->setAlignment(Qt::AlignCenter);
            ui->hint_Login_Info_lb->setText("连接服务器失败！！！");
            ui->hint_Login_Info_lb->setProperty("Error",true);
            qApp->setStyleSheet(qApp->styleSheet());
            Common::sleep(3000);
            ui->hint_Login_Info_lb->setVisible(false);
        }
    }
}

void LogInDialog::on_signup_pbt_clicked()
{
    this->hide();
    SignUpDialog *signupDlg = new SignUpDialog;
    signupDlg->setModal(true);
    int ret = signupDlg->exec();
    this->setHidden(false);

    if(ret == 1){
        UserClient* c = Common::getUserClientInstance();
        int userid = c->getSelfUser()->userid;
        ui->username_ledt->setText(QString::number(userid));
        ui->passwd_ledt->setText(c->getSelfUser()->pwd);
    }

}

void LogInDialog::loginNoAccountSlots()
{
    QMessageBox::information(this, "Error", "用户不存在或账号、密码错误！！！", QMessageBox::Yes);
    return;
}

void LogInDialog::loginSuccessSlots()
{
    this->close();
    ClientWidget *client = new ClientWidget;
    //    client->showNormal();
    client->setAttribute(Qt::WA_DeleteOnClose);
    client->show();
}

void LogInDialog::loginExistSlots()
{
    QMessageBox::information(this, "Error", "用户已登录", QMessageBox::Yes);
    return;
}

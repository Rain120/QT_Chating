#include "signupdialog.h"
#include "ui_signupdialog.h"
#include "logindialog.h"
#include "QDebug"
#include "common.h"
#include "QTimer"

SignUpDialog::SignUpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("注册");
    this->setWindowOpacity(1);

    UserClient* c = Common::getUserClientInstance();
    connect(c, SIGNAL(registerSuccess()), this, SLOT(close()));

}

SignUpDialog::~SignUpDialog()
{
    delete ui;
}

void SignUpDialog::on_cancel_pbt_clicked()
{
    this->close();
}

void SignUpDialog::on_signUp_pbt_clicked()
{
    UserClient* c = Common::getUserClientInstance();
    c->getSelfUser()->name = ui->username_ledt->text();
    c->getSelfUser()->pwd = ui->password_ledt->text();
    if(c->getSelfUser()->pwd == ui->comfirmPwd_ledt->text())
    {
        QEventLoop* loop = new QEventLoop;
        ui->signUp_pbt->setVisible(false);
        ui->cancel_pbt->setVisible(false);
        ui->hintSignup_Info_lb->setVisible(true);
        ui->hintSignup_Info_lb->setAlignment(Qt::AlignCenter);
        ui->hintSignup_Info_lb->setText("正在联网注册用户。。。");
        QTimer::singleShot(1, loop, SLOT(quit()));
        loop->exec();
    }

    bool registRet = c->regist();

    if(!registRet){
        ui->hintSignup_Info_lb->setVisible(true);
        ui->hintSignup_Info_lb->setAlignment(Qt::AlignCenter);
        ui->hintSignup_Info_lb->setText("用户注册失败！！！");
        ui->hintSignup_Info_lb->setProperty("Error",true);
        qApp->setStyleSheet(qApp->styleSheet());
        Common::sleep(3000);
        ui->hintSignup_Info_lb->setVisible(false);
        ui->signUp_pbt->setVisible(true);
        ui->cancel_pbt->setVisible(true);
        return;
    }
    else{
        ui->hintSignup_Info_lb->setProperty("Error",false);
        qApp->setStyleSheet(qApp->styleSheet());
        this->done(1);
    }
}

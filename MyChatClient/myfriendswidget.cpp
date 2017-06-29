#include "myfriendswidget.h"
#include "ui_myfriendswidget.h"
#include <QPainter>

MyFriendsWidget::MyFriendsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyFriendsWidget)
{
    ui->setupUi(this);
    initUI();
}

MyFriendsWidget::~MyFriendsWidget()
{
    delete ui;
}

void MyFriendsWidget::initUI()
{
    //初始化
//    head = new QWidget(this);
    userName = new QLabel(this);
//    sign = new QLabel(this);
    //设置头像大小
//    head->setFixedSize(40,40);
    //设置个性签名字体为灰色
//    QPalette color;
//    color.setColor(QPalette::Text,Qt::gray);
//    sign->setPalette(color);
    //布局
//    head->move(20,20);
//    userName->move(54,10);
//    sign->move(54,27);
    //装载事件过滤器
//    head->installEventFilter(this);
}
//事件过滤器，主要是为了让图片能够全部填充在head里面
bool MyFriendsWidget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == head)
    {
        if(event->type() == QEvent::Paint)
        {
            QPainter painter(head);
            painter.drawPixmap(head->rect(), QPixmap(":/img/res/woman-hair.png"));
        }
    }
    return QWidget::eventFilter(obj, event);
}

void MyFriendsWidget::on_search_tbt_clicked()
{

}

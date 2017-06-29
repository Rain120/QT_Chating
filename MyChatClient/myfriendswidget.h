#ifndef MYFRIENDSWIDGET_H
#define MYFRIENDSWIDGET_H

#include <QWidget>
#include <QEvent>
#include <QLabel>

namespace Ui {
class MyFriendsWidget;
}

class MyFriendsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyFriendsWidget(QWidget *parent = 0);
    ~MyFriendsWidget();
    void initUI();
    QWidget* head;        //头像
    QLabel* userName;
    QLabel* sign;         //签名
    bool eventFilter(QObject *obj, QEvent *event);
private slots:
    void on_search_tbt_clicked();

private:
    Ui::MyFriendsWidget *ui;
};

#endif // MYFRIENDSWIDGET_H

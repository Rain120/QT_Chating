/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogInDialog
{
public:
    QLabel *title_lb;
    QLabel *username_lb;
    QLabel *password_lb;
    QLineEdit *username_ledt;
    QLineEdit *passwd_ledt;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *login_pbt;
    QPushButton *signup_pbt;
    QPushButton *exit_pbt;
    QLabel *hint_Login_Info_lb;

    void setupUi(QDialog *LogInDialog)
    {
        if (LogInDialog->objectName().isEmpty())
            LogInDialog->setObjectName(QStringLiteral("LogInDialog"));
        LogInDialog->resize(379, 257);
        title_lb = new QLabel(LogInDialog);
        title_lb->setObjectName(QStringLiteral("title_lb"));
        title_lb->setGeometry(QRect(120, 10, 120, 23));
        QFont font;
        font.setPointSize(14);
        title_lb->setFont(font);
        username_lb = new QLabel(LogInDialog);
        username_lb->setObjectName(QStringLiteral("username_lb"));
        username_lb->setGeometry(QRect(50, 70, 45, 16));
        password_lb = new QLabel(LogInDialog);
        password_lb->setObjectName(QStringLiteral("password_lb"));
        password_lb->setGeometry(QRect(50, 130, 30, 16));
        username_ledt = new QLineEdit(LogInDialog);
        username_ledt->setObjectName(QStringLiteral("username_ledt"));
        username_ledt->setGeometry(QRect(110, 60, 210, 30));
        passwd_ledt = new QLineEdit(LogInDialog);
        passwd_ledt->setObjectName(QStringLiteral("passwd_ledt"));
        passwd_ledt->setGeometry(QRect(110, 120, 210, 30));
        passwd_ledt->setEchoMode(QLineEdit::Password);
        layoutWidget = new QWidget(LogInDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 210, 311, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        login_pbt = new QPushButton(layoutWidget);
        login_pbt->setObjectName(QStringLiteral("login_pbt"));

        horizontalLayout->addWidget(login_pbt);

        signup_pbt = new QPushButton(layoutWidget);
        signup_pbt->setObjectName(QStringLiteral("signup_pbt"));

        horizontalLayout->addWidget(signup_pbt);

        exit_pbt = new QPushButton(layoutWidget);
        exit_pbt->setObjectName(QStringLiteral("exit_pbt"));

        horizontalLayout->addWidget(exit_pbt);

        hint_Login_Info_lb = new QLabel(LogInDialog);
        hint_Login_Info_lb->setObjectName(QStringLiteral("hint_Login_Info_lb"));
        hint_Login_Info_lb->setGeometry(QRect(30, 170, 311, 21));
        QFont font1;
        font1.setPointSize(12);
        hint_Login_Info_lb->setFont(font1);

        retranslateUi(LogInDialog);

        QMetaObject::connectSlotsByName(LogInDialog);
    } // setupUi

    void retranslateUi(QDialog *LogInDialog)
    {
        LogInDialog->setWindowTitle(QApplication::translate("LogInDialog", "Dialog", 0));
        title_lb->setText(QApplication::translate("LogInDialog", "Super Chat", 0));
        username_lb->setText(QApplication::translate("LogInDialog", "\350\264\246\345\217\267", 0));
        password_lb->setText(QApplication::translate("LogInDialog", "\345\257\206\347\240\201", 0));
        username_ledt->setPlaceholderText(QApplication::translate("LogInDialog", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\350\264\246\345\217\267", 0));
        passwd_ledt->setPlaceholderText(QApplication::translate("LogInDialog", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\345\257\206\347\240\201\357\274\214\350\207\263\345\260\2216\344\275\215", 0));
        login_pbt->setText(QApplication::translate("LogInDialog", "\347\231\273\345\275\225", 0));
        signup_pbt->setText(QApplication::translate("LogInDialog", "\346\263\250\345\206\214", 0));
        exit_pbt->setText(QApplication::translate("LogInDialog", "\351\200\200\345\207\272", 0));
        hint_Login_Info_lb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LogInDialog: public Ui_LogInDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H

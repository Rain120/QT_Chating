/********************************************************************************
** Form generated from reading UI file 'signupdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPDIALOG_H
#define UI_SIGNUPDIALOG_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpDialog
{
public:
    QLabel *title_lb;
    QLabel *username_lb;
    QLabel *password_lb;
    QLabel *comfirmPwd_lb;
    QLineEdit *username_ledt;
    QLineEdit *password_ledt;
    QLineEdit *comfirmPwd_ledt;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *signUp_pbt;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_pbt;
    QLabel *hintSignup_Info_lb;

    void setupUi(QDialog *SignUpDialog)
    {
        if (SignUpDialog->objectName().isEmpty())
            SignUpDialog->setObjectName(QStringLiteral("SignUpDialog"));
        SignUpDialog->resize(557, 335);
        title_lb = new QLabel(SignUpDialog);
        title_lb->setObjectName(QStringLiteral("title_lb"));
        title_lb->setGeometry(QRect(230, 20, 91, 31));
        QFont font;
        font.setPointSize(14);
        title_lb->setFont(font);
        username_lb = new QLabel(SignUpDialog);
        username_lb->setObjectName(QStringLiteral("username_lb"));
        username_lb->setGeometry(QRect(90, 80, 51, 16));
        password_lb = new QLabel(SignUpDialog);
        password_lb->setObjectName(QStringLiteral("password_lb"));
        password_lb->setGeometry(QRect(90, 140, 51, 16));
        comfirmPwd_lb = new QLabel(SignUpDialog);
        comfirmPwd_lb->setObjectName(QStringLiteral("comfirmPwd_lb"));
        comfirmPwd_lb->setGeometry(QRect(90, 200, 71, 16));
        username_ledt = new QLineEdit(SignUpDialog);
        username_ledt->setObjectName(QStringLiteral("username_ledt"));
        username_ledt->setGeometry(QRect(180, 70, 261, 31));
        QFont font1;
        font1.setPointSize(8);
        username_ledt->setFont(font1);
        password_ledt = new QLineEdit(SignUpDialog);
        password_ledt->setObjectName(QStringLiteral("password_ledt"));
        password_ledt->setGeometry(QRect(180, 130, 261, 31));
        password_ledt->setFont(font1);
        password_ledt->setEchoMode(QLineEdit::Password);
        comfirmPwd_ledt = new QLineEdit(SignUpDialog);
        comfirmPwd_ledt->setObjectName(QStringLiteral("comfirmPwd_ledt"));
        comfirmPwd_ledt->setGeometry(QRect(180, 190, 261, 31));
        comfirmPwd_ledt->setFont(font1);
        comfirmPwd_ledt->setEchoMode(QLineEdit::Password);
        layoutWidget = new QWidget(SignUpDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 280, 351, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        signUp_pbt = new QPushButton(layoutWidget);
        signUp_pbt->setObjectName(QStringLiteral("signUp_pbt"));

        horizontalLayout->addWidget(signUp_pbt);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel_pbt = new QPushButton(layoutWidget);
        cancel_pbt->setObjectName(QStringLiteral("cancel_pbt"));

        horizontalLayout->addWidget(cancel_pbt);

        hintSignup_Info_lb = new QLabel(SignUpDialog);
        hintSignup_Info_lb->setObjectName(QStringLiteral("hintSignup_Info_lb"));
        hintSignup_Info_lb->setGeometry(QRect(90, 250, 351, 31));
        QFont font2;
        font2.setPointSize(11);
        hintSignup_Info_lb->setFont(font2);
        layoutWidget->raise();
        title_lb->raise();
        username_lb->raise();
        password_lb->raise();
        comfirmPwd_lb->raise();
        username_ledt->raise();
        password_ledt->raise();
        comfirmPwd_ledt->raise();
        hintSignup_Info_lb->raise();

        retranslateUi(SignUpDialog);

        QMetaObject::connectSlotsByName(SignUpDialog);
    } // setupUi

    void retranslateUi(QDialog *SignUpDialog)
    {
        SignUpDialog->setWindowTitle(QApplication::translate("SignUpDialog", "Dialog", 0));
        title_lb->setText(QApplication::translate("SignUpDialog", "Sign Up", 0));
        username_lb->setText(QApplication::translate("SignUpDialog", "\347\224\250\346\210\267\345\220\215", 0));
        password_lb->setText(QApplication::translate("SignUpDialog", "\345\257\206\347\240\201", 0));
        comfirmPwd_lb->setText(QApplication::translate("SignUpDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", 0));
        username_ledt->setPlaceholderText(QApplication::translate("SignUpDialog", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\347\224\250\346\210\267\345\220\215\357\274\214\344\270\215\350\266\205\350\277\20720\344\275\215", 0));
        password_ledt->setPlaceholderText(QApplication::translate("SignUpDialog", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\345\257\206\347\240\201\357\274\214\350\207\263\345\260\2216\344\275\215", 0));
        comfirmPwd_ledt->setPlaceholderText(QApplication::translate("SignUpDialog", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\344\275\240\347\232\204\345\257\206\347\240\201\357\274\214\344\270\244\346\254\241\345\257\206\347\240\201\345\277\205\351\241\273\344\270\200\350\207\264", 0));
        signUp_pbt->setText(QApplication::translate("SignUpDialog", "\346\263\250\345\206\214", 0));
        cancel_pbt->setText(QApplication::translate("SignUpDialog", "\345\217\226\346\266\210", 0));
        hintSignup_Info_lb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignUpDialog: public Ui_SignUpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPDIALOG_H

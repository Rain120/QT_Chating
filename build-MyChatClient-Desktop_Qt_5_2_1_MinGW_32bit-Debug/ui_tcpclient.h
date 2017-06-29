/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QLabel *hintRecieveFile_label;
    QProgressBar *recieveFile_proBar;
    QPushButton *cancel_pbt;
    QPushButton *close_pbt;

    void setupUi(QDialog *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QStringLiteral("TcpClient"));
        TcpClient->resize(444, 305);
        hintRecieveFile_label = new QLabel(TcpClient);
        hintRecieveFile_label->setObjectName(QStringLiteral("hintRecieveFile_label"));
        hintRecieveFile_label->setGeometry(QRect(80, 10, 261, 151));
        QFont font;
        font.setPointSize(13);
        hintRecieveFile_label->setFont(font);
        recieveFile_proBar = new QProgressBar(TcpClient);
        recieveFile_proBar->setObjectName(QStringLiteral("recieveFile_proBar"));
        recieveFile_proBar->setGeometry(QRect(20, 170, 411, 31));
        QFont font1;
        font1.setPointSize(10);
        recieveFile_proBar->setFont(font1);
        recieveFile_proBar->setValue(0);
        cancel_pbt = new QPushButton(TcpClient);
        cancel_pbt->setObjectName(QStringLiteral("cancel_pbt"));
        cancel_pbt->setGeometry(QRect(60, 230, 93, 28));
        QFont font2;
        font2.setPointSize(12);
        cancel_pbt->setFont(font2);
        close_pbt = new QPushButton(TcpClient);
        close_pbt->setObjectName(QStringLiteral("close_pbt"));
        close_pbt->setGeometry(QRect(230, 230, 93, 28));
        close_pbt->setFont(font2);

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QDialog *TcpClient)
    {
        TcpClient->setWindowTitle(QApplication::translate("TcpClient", "Dialog", 0));
        hintRecieveFile_label->setText(QApplication::translate("TcpClient", "\347\255\211\345\276\205\346\216\245\345\217\227\346\226\207\344\273\266...  ...", 0));
        cancel_pbt->setText(QApplication::translate("TcpClient", "\345\217\226\346\266\210", 0));
        close_pbt->setText(QApplication::translate("TcpClient", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H

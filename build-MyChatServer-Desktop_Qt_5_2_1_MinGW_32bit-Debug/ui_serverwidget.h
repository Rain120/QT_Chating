/********************************************************************************
** Form generated from reading UI file 'serverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWIDGET_H
#define UI_SERVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWidget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *ip_port_ptd;
    QHBoxLayout *horizontalLayout;
    QPushButton *openServer_pbt;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeServer_pbt;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *serverSend_pbt;

    void setupUi(QWidget *ServerWidget)
    {
        if (ServerWidget->objectName().isEmpty())
            ServerWidget->setObjectName(QStringLiteral("ServerWidget"));
        ServerWidget->resize(372, 210);
        widget = new QWidget(ServerWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 371, 211));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ip_port_ptd = new QPlainTextEdit(widget);
        ip_port_ptd->setObjectName(QStringLiteral("ip_port_ptd"));
        ip_port_ptd->setReadOnly(true);

        verticalLayout->addWidget(ip_port_ptd);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        openServer_pbt = new QPushButton(widget);
        openServer_pbt->setObjectName(QStringLiteral("openServer_pbt"));

        horizontalLayout->addWidget(openServer_pbt);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeServer_pbt = new QPushButton(widget);
        closeServer_pbt->setObjectName(QStringLiteral("closeServer_pbt"));

        horizontalLayout->addWidget(closeServer_pbt);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        serverSend_pbt = new QPushButton(widget);
        serverSend_pbt->setObjectName(QStringLiteral("serverSend_pbt"));

        horizontalLayout->addWidget(serverSend_pbt);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 4);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 4);
        horizontalLayout->setStretch(4, 2);

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ServerWidget);

        QMetaObject::connectSlotsByName(ServerWidget);
    } // setupUi

    void retranslateUi(QWidget *ServerWidget)
    {
        ServerWidget->setWindowTitle(QApplication::translate("ServerWidget", "ServerWidget", 0));
        openServer_pbt->setText(QApplication::translate("ServerWidget", "\345\220\257\345\212\250", 0));
        closeServer_pbt->setText(QApplication::translate("ServerWidget", "\345\217\226\346\266\210", 0));
        serverSend_pbt->setText(QApplication::translate("ServerWidget", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class ServerWidget: public Ui_ServerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H

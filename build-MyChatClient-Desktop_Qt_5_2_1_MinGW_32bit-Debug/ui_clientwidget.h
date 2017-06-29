/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *hintChatorsName;
    QTextBrowser *displayMessage_tbro;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *expression_tbt;
    QToolButton *sendFile_tbt;
    QComboBox *chatRecord_comb;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *sendMessage_tedt;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *send_pbt;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QStringLiteral("ClientWidget"));
        ClientWidget->resize(523, 602);
        layoutWidget = new QWidget(ClientWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 521, 601));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        hintChatorsName = new QLabel(layoutWidget);
        hintChatorsName->setObjectName(QStringLiteral("hintChatorsName"));
        QFont font;
        font.setPointSize(12);
        hintChatorsName->setFont(font);

        verticalLayout->addWidget(hintChatorsName);

        displayMessage_tbro = new QTextBrowser(layoutWidget);
        displayMessage_tbro->setObjectName(QStringLiteral("displayMessage_tbro"));

        verticalLayout->addWidget(displayMessage_tbro);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(0, 0, -1, 0);
        expression_tbt = new QToolButton(layoutWidget);
        expression_tbt->setObjectName(QStringLiteral("expression_tbt"));
        expression_tbt->setCursor(QCursor(Qt::PointingHandCursor));
        expression_tbt->setStyleSheet(QStringLiteral("border-color: qlineargradient(spread:pad, x1:0.871, y1:1, x2:1, y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/res/happy.png"), QSize(), QIcon::Normal, QIcon::Off);
        expression_tbt->setIcon(icon);
        expression_tbt->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(expression_tbt);

        sendFile_tbt = new QToolButton(layoutWidget);
        sendFile_tbt->setObjectName(QStringLiteral("sendFile_tbt"));
        sendFile_tbt->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/res/open-archive.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendFile_tbt->setIcon(icon1);
        sendFile_tbt->setIconSize(QSize(40, 40));

        horizontalLayout_2->addWidget(sendFile_tbt);

        chatRecord_comb = new QComboBox(layoutWidget);
        chatRecord_comb->setObjectName(QStringLiteral("chatRecord_comb"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chatRecord_comb->sizePolicy().hasHeightForWidth());
        chatRecord_comb->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(14);
        chatRecord_comb->setFont(font1);
        chatRecord_comb->setCursor(QCursor(Qt::PointingHandCursor));
        chatRecord_comb->setMaxVisibleItems(10);

        horizontalLayout_2->addWidget(chatRecord_comb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 3);
        horizontalLayout_2->setStretch(3, 5);

        verticalLayout->addLayout(horizontalLayout_2);

        sendMessage_tedt = new QTextEdit(layoutWidget);
        sendMessage_tedt->setObjectName(QStringLiteral("sendMessage_tedt"));

        verticalLayout->addWidget(sendMessage_tedt);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(378, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        send_pbt = new QPushButton(layoutWidget);
        send_pbt->setObjectName(QStringLiteral("send_pbt"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(send_pbt->sizePolicy().hasHeightForWidth());
        send_pbt->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(send_pbt);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 5);
        verticalLayout->setStretch(4, 1);

        retranslateUi(ClientWidget);

        chatRecord_comb->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QApplication::translate("ClientWidget", "ClientWidget", 0));
        hintChatorsName->setText(QString());
        expression_tbt->setText(QApplication::translate("ClientWidget", "...", 0));
        sendFile_tbt->setText(QApplication::translate("ClientWidget", "...", 0));
        chatRecord_comb->clear();
        chatRecord_comb->insertItems(0, QStringList()
         << QApplication::translate("ClientWidget", "\350\201\212\345\244\251\350\256\260\345\275\225", 0)
         << QApplication::translate("ClientWidget", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", 0)
         << QApplication::translate("ClientWidget", "\345\210\240\351\231\244\350\201\212\345\244\251\350\256\260\345\275\225", 0)
        );
        send_pbt->setText(QApplication::translate("ClientWidget", "\345\217\221\351\200\201(S)", 0));
        send_pbt->setShortcut(QApplication::translate("ClientWidget", "Return, Ctrl+S", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H

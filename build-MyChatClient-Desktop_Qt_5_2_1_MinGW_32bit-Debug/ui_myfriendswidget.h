/********************************************************************************
** Form generated from reading UI file 'myfriendswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFRIENDSWIDGET_H
#define UI_MYFRIENDSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyFriendsWidget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *headerIcon_tbt;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchUserid_ledt;
    QToolButton *search_tbt;

    void setupUi(QWidget *MyFriendsWidget)
    {
        if (MyFriendsWidget->objectName().isEmpty())
            MyFriendsWidget->setObjectName(QStringLiteral("MyFriendsWidget"));
        MyFriendsWidget->resize(312, 510);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MyFriendsWidget->sizePolicy().hasHeightForWidth());
        MyFriendsWidget->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(MyFriendsWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 311, 138));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(10);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(15, -1, 15, -1);
        headerIcon_tbt = new QToolButton(layoutWidget);
        headerIcon_tbt->setObjectName(QStringLiteral("headerIcon_tbt"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(headerIcon_tbt->sizePolicy().hasHeightForWidth());
        headerIcon_tbt->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/res/woman-hair.png"), QSize(), QIcon::Normal, QIcon::Off);
        headerIcon_tbt->setIcon(icon);
        headerIcon_tbt->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(headerIcon_tbt);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy3);
        comboBox->setBaseSize(QSize(0, 0));

        horizontalLayout_2->addWidget(comboBox);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 1);

        horizontalLayout_3->addLayout(verticalLayout);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 7);

        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(15, -1, 15, -1);
        searchUserid_ledt = new QLineEdit(layoutWidget);
        searchUserid_ledt->setObjectName(QStringLiteral("searchUserid_ledt"));
        searchUserid_ledt->setFont(font);

        horizontalLayout->addWidget(searchUserid_ledt);

        search_tbt = new QToolButton(layoutWidget);
        search_tbt->setObjectName(QStringLiteral("search_tbt"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/res/search-magnifier-interface-symbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        search_tbt->setIcon(icon1);

        horizontalLayout->addWidget(search_tbt);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);

        retranslateUi(MyFriendsWidget);

        QMetaObject::connectSlotsByName(MyFriendsWidget);
    } // setupUi

    void retranslateUi(QWidget *MyFriendsWidget)
    {
        MyFriendsWidget->setWindowTitle(QApplication::translate("MyFriendsWidget", "Form", 0));
        headerIcon_tbt->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        search_tbt->setText(QApplication::translate("MyFriendsWidget", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class MyFriendsWidget: public Ui_MyFriendsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFRIENDSWIDGET_H

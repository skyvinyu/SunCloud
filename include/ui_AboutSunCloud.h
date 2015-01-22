/********************************************************************************
** Form generated from reading UI file 'AboutSunCloud.ui'
**
** Created: Thu 22. Jan 15:12:07 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ABOUTSUNCLOUD_H
#define ABOUTSUNCLOUD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutSunCloud
{
public:

    void setupUi(QWidget *AboutSunCloud)
    {
        if (AboutSunCloud->objectName().isEmpty())
            AboutSunCloud->setObjectName(QString::fromUtf8("AboutSunCloud"));
        AboutSunCloud->resize(400, 300);

        retranslateUi(AboutSunCloud);

        QMetaObject::connectSlotsByName(AboutSunCloud);
    } // setupUi

    void retranslateUi(QWidget *AboutSunCloud)
    {
        AboutSunCloud->setWindowTitle(QApplication::translate("AboutSunCloud", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutSunCloud: public Ui_AboutSunCloud {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ABOUTSUNCLOUD_H

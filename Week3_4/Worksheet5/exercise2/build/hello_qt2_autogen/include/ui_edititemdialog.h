/********************************************************************************
** Form generated from reading UI file 'edititemdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITITEMDIALOG_H
#define UI_EDITITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_EditItemDialog
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *reorder;
    QDoubleSpinBox *unitCost;
    QSpinBox *stockLevel;
    QLineEdit *name;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *EditItemDialog)
    {
        if (EditItemDialog->objectName().isEmpty())
            EditItemDialog->setObjectName(QString::fromUtf8("EditItemDialog"));
        EditItemDialog->resize(302, 222);
        buttonBox = new QDialogButtonBox(EditItemDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-170, 175, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        reorder = new QCheckBox(EditItemDialog);
        reorder->setObjectName(QString::fromUtf8("reorder"));
        reorder->setGeometry(QRect(30, 135, 70, 17));
        unitCost = new QDoubleSpinBox(EditItemDialog);
        unitCost->setObjectName(QString::fromUtf8("unitCost"));
        unitCost->setGeometry(QRect(30, 75, 81, 22));
        stockLevel = new QSpinBox(EditItemDialog);
        stockLevel->setObjectName(QString::fromUtf8("stockLevel"));
        stockLevel->setGeometry(QRect(30, 105, 81, 22));
        name = new QLineEdit(EditItemDialog);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(30, 45, 131, 20));
        label_3 = new QLabel(EditItemDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 100, 61, 31));
        label_2 = new QLabel(EditItemDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 70, 51, 31));
        label = new QLabel(EditItemDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 40, 61, 31));

        retranslateUi(EditItemDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditItemDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditItemDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditItemDialog);
    } // setupUi

    void retranslateUi(QDialog *EditItemDialog)
    {
        EditItemDialog->setWindowTitle(QCoreApplication::translate("EditItemDialog", "Dialog", nullptr));
        reorder->setText(QCoreApplication::translate("EditItemDialog", "CheckBox", nullptr));
        label_3->setText(QCoreApplication::translate("EditItemDialog", "Stock Level", nullptr));
        label_2->setText(QCoreApplication::translate("EditItemDialog", "Item Cost", nullptr));
        label->setText(QCoreApplication::translate("EditItemDialog", "Item Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditItemDialog: public Ui_EditItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITITEMDIALOG_H

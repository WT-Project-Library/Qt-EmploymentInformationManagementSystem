#ifndef USERSELECTIONDIALOG_H
#define USERSELECTIONDIALOG_H

#include <QDialog>
#include <QDebug>
#include <iostream>
#include "StudentLoginDialog.h"
#include "TeacherLoginDialog.h"
#include "EnterpriseLoginDialog.h"
#include "AdminLoginDialog.h"
namespace Ui {
class UserSelectionDialog;
}

class UserSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserSelectionDialog(QWidget *parent = 0);
    ~UserSelectionDialog();


signals:


private slots:
    void on_student_pushButton_clicked();

    void on_teacher_pushButton_2_clicked();

    void on_enterprise_pushButton_3_clicked();

    void on_admin_pushButton_clicked();

private:
    Ui::UserSelectionDialog *ui;
private:
   StudentLoginDialog *stu_login=new StudentLoginDialog;
   TeacherLoginDialog *tea_login=new TeacherLoginDialog;
   EnterpriseLoginDialog *ent_login=new EnterpriseLoginDialog;
   AdminLoginDialog *admin_login=new AdminLoginDialog;
};

#endif // USERSELECTIONDIALOG_H

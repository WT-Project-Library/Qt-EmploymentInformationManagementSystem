#include "UserSelectionDialog.h"
#include "ui_UserSelectionDialog.h"

UserSelectionDialog::UserSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSelectionDialog)
{
    ui->setupUi(this);
}

UserSelectionDialog::~UserSelectionDialog()
{
    delete stu_login;
    delete tea_login;
    delete ent_login;
    delete admin_login;
    delete ui;
}

void UserSelectionDialog::on_student_pushButton_clicked()
{
    this->hide();      //用户选择窗口隐藏
    stu_login->show();  //学生登录窗口显示
}

void UserSelectionDialog::on_teacher_pushButton_2_clicked()
{
    this->hide();      //用户选择窗口隐藏
    tea_login->show();  //教师登录窗口显示
}

void UserSelectionDialog::on_enterprise_pushButton_3_clicked()
{
    this->hide();      //用户选择窗口隐藏
    ent_login->show();  //企业登录窗口显示
}

void UserSelectionDialog::on_admin_pushButton_clicked()
{
    this->hide();      //用户选择窗口隐藏
    admin_login->show();  //管理员登录窗口显示
}

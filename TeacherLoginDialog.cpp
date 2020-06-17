#include "TeacherLoginDialog.h"
#include "ui_TeacherLoginDialog.h"
#include "UserSelectionDialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QtSql>
TeacherLoginDialog::TeacherLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherLoginDialog)
{
    ui->setupUi(this);
}

TeacherLoginDialog::~TeacherLoginDialog()
{
    delete tea_main;
    delete ui;
}

void TeacherLoginDialog::on_login_pushButton_2_clicked()
{
    QString accounttext=ui->account_lineEdit->text();
    QString passwordtext=ui->password_lineEdit_2->text();

    if(accounttext==NULL|passwordtext==NULL)
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("账户或密码为空"),QStringLiteral("确定"));
    }
    else
    {
        qDebug()<<accounttext<<" "<<passwordtext;
        QString S =QString("select * from user_tea where tea_id='%1' and tea_psd='%2' ").arg(accounttext).arg(passwordtext);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {
            qDebug()<<QStringLiteral("教师登录成功");
            this->hide();
            tea_main->show();
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("账户或密码错误"),QStringLiteral("确定"));
        }
    }

}

void TeacherLoginDialog::closeEvent(QCloseEvent *)
{
    UserSelectionDialog *userSel=new UserSelectionDialog;
    userSel->show();
}

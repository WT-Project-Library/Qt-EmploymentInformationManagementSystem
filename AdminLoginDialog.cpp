#include "AdminLoginDialog.h"
#include "ui_AdminLoginDialog.h"
#include "UserSelectionDialog.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QtSql>
AdminLoginDialog::AdminLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLoginDialog)
{
    ui->setupUi(this);
}

AdminLoginDialog::~AdminLoginDialog()
{
    delete admin_main;
    delete ui;
}

void AdminLoginDialog::on_login_pushButton_2_clicked()
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
        QString S =QString("select * from user_admin where admin_id='%1' and admin_psd='%2' ").arg(accounttext).arg(passwordtext);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {
            qDebug()<<QStringLiteral("管理员登录成功");
            this->hide();
            admin_main->show();
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("账户或密码错误"),QStringLiteral("确定"));
        }
    }
}
void AdminLoginDialog::closeEvent(QCloseEvent *)
{
    UserSelectionDialog *userSel=new UserSelectionDialog;
    userSel->show();
}

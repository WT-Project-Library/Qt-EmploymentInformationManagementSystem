#include "EnterpriseLoginDialog.h"
#include "ui_EnterpriseLoginDialog.h"
#include "UserSelectionDialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QtSql>
#include <QString>
EnterpriseLoginDialog::EnterpriseLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterpriseLoginDialog)
{
    ui->setupUi(this);
}

EnterpriseLoginDialog::~EnterpriseLoginDialog()
{
    delete ent_main;
    delete ui;
}
QString EnterpriseLoginDialog::ent_id=" ";
QString EnterpriseLoginDialog::on_login_pushButton_2_clicked()
{
    QString accounttext=ui->account_lineEdit->text();
    ent_id=accounttext;
    QString passwordtext=ui->password_lineEdit_2->text();

    if(accounttext==NULL|passwordtext==NULL)
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("账户或密码为空"),QStringLiteral("确定"));
    }
    else
    {
        qDebug()<<accounttext<<" "<<passwordtext;
        QString S =QString("select * from user_ent where ent_id='%1' and ent_psd='%2' ").arg(accounttext).arg(passwordtext);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {
            qDebug()<<QStringLiteral("企业登录成功");
            this->hide();
            ent_main->show();
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("账户或密码错误"),QStringLiteral("确定"));
        }
    }
    return ent_id;
}

void EnterpriseLoginDialog::closeEvent(QCloseEvent *)
{
    UserSelectionDialog *userSel=new UserSelectionDialog;
    userSel->show();
}

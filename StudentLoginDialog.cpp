#include "StudentLoginDialog.h"
#include "ui_StudentLoginDialog.h"
#include "UserSelectionDialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QtSql>
StudentLoginDialog::StudentLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentLoginDialog)
{
    ui->setupUi(this);

}

StudentLoginDialog::~StudentLoginDialog()
{
    delete stu_main;
    delete ui;
}
QString StudentLoginDialog::st_id=" ";
QString StudentLoginDialog::on_login_pushButton_2_clicked()
{
    QString accounttext=ui->account_lineEdit->text();
    st_id=accounttext;
    QString passwordtext=ui->password_lineEdit_2->text();

    if(accounttext==NULL|passwordtext==NULL)
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("账户或密码为空"),QStringLiteral("确定"));
    }
    else
    {
        qDebug()<<accounttext<<" "<<passwordtext;
        QString S =QString("select * from user_stu where stu_id='%1' and stu_psd='%2' ").arg(accounttext).arg(passwordtext);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {

            qDebug()<<QStringLiteral("学生登录成功");
            this->hide();
            stu_main->show();
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("账户或密码错误"),QStringLiteral("确定"));
        }
    }
    return st_id;
}

void StudentLoginDialog::closeEvent(QCloseEvent *)
{
    UserSelectionDialog *userSel=new UserSelectionDialog;
    userSel->show();
}

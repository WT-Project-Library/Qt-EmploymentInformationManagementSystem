#include "DeleteDialog.h"
#include "ui_DeleteDialog.h"
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QDebug>
DeleteDialog::DeleteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}

void DeleteDialog::on_sure_pushButton_clicked()
{
    QString stu_id=ui->stuId_lineEdit->text();
    QString stu_psd=ui->stuPsd_lineEdit_2->text();

    if(stu_id==NULL|stu_psd==NULL)
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("学号或密码为空"),QStringLiteral("确定"));
    }
    else
    {
        qDebug()<<stu_id<<" "<<stu_psd;
        QString S =QString("select * from user_stu where stu_id='%1' and stu_psd='%2' ").arg(stu_id).arg(stu_psd);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {

            qDebug()<<QStringLiteral("输入正确");
            QMessageBox messageBox(QMessageBox::NoIcon,QStringLiteral("提示"),QStringLiteral("确定要删除吗？"),QMessageBox::Yes|QMessageBox::No);
            int result=messageBox.exec();
            switch (result)
            {
                case QMessageBox::Yes:
                {
                    qDebug()<<"Yes";
                    QString S =QString("delete from stu_resume where stu_id='%1'").arg(stu_id);
                    QSqlQuery query;
                    if(query.exec(S))
                    {
                        QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("删除成功！"),QStringLiteral("确定"));
                        this->close();
                    }
                    break;
                }
                case QMessageBox::No:
                    qDebug()<<"NO";
                    break;
                default:
                    break;
            }
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("学号或密码错误"),QStringLiteral("确定"));
        }
    }

}

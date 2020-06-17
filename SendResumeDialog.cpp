#include "SendResumeDialog.h"
#include "ui_SendResumeDialog.h"
#include "StudentMainWindow.h"
#include "StudentLoginDialog.h"
#include "SpeakDialog.h"
#include <QDebug>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
SendResumeDialog::SendResumeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendResumeDialog)
{
    ui->setupUi(this);
}

SendResumeDialog::~SendResumeDialog()
{
    delete ui;
}

void SendResumeDialog::on_send_pushButton_clicked()
{
    QString ent_click=StudentMainWindow::a;
    QString student_id=StudentLoginDialog::st_id;
    qDebug()<<ent_click<<" "<<student_id;
    QString S1=QString("select * from stu_resume where stu_id='%1'").arg(student_id);
    QSqlQuery query1;
    if(query1.exec(S1)&&query1.next())
    {
        QString S=QString("INSERT INTO ent_sender (ent_id, ent_sender)" "VALUES ('%1', '%2')").arg(ent_click).arg(student_id);
        QSqlQuery query;
        if(query.exec(S))
        {
            QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("投递成功！祝你好运！"),QStringLiteral("确定"));
        }
    }
    else
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("请先填写简历！"),QStringLiteral("确定"));
    }


}

void SendResumeDialog::on_speak_pushButton_2_clicked()
{
    SpeakDialog *speak=new SpeakDialog;
    speak->exec();
}

#include "SpeakDialog.h"
#include "ui_SpeakDialog.h"
#include "StudentMainWindow.h"
#include "StudentLoginDialog.h"
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
SpeakDialog::SpeakDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpeakDialog)
{
    ui->setupUi(this);
}

SpeakDialog::~SpeakDialog()
{
    delete ui;
}

void SpeakDialog::on_sendword_pushButton_clicked()
{
    QString ent_click=StudentMainWindow::a;
    QString student_id=StudentLoginDialog::st_id;
    QString word=ui->word_textEdit->toPlainText();
    qDebug()<<ent_click<<" "<<student_id;

    QString S=QString("INSERT INTO ent_speak (ent_id, ent_speaker, ent_speakword)" "VALUES ('%1', '%2','%3')").arg(ent_click).arg(student_id).arg(word);
    QSqlQuery query;
    if(query.exec(S))
    {
        QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("留言成功！"),QStringLiteral("确定"));
    }
}

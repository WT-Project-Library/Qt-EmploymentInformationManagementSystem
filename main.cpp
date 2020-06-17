#include "UserSelectionDialog.h"
#include "StudentLoginDialog.h"
#include "TeacherLoginDialog.h"
#include "EnterpriseLoginDialog.h"
#include "SendResumeDialog.h"
#include "StudentMainWindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("employinfosystem");
    db.setUserName("root");
    db.setPassword("152355");
    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("Database Error"),db.lastError().text());
    }
    else
    {
        qDebug()<<"Database open succes";
    }

    UserSelectionDialog w;
     w.show();

    return a.exec();
}

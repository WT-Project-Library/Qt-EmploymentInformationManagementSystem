#ifndef STUDENTLOGINDIALOG_H
#define STUDENTLOGINDIALOG_H

#include <QDialog>
#include <QDebug>
#include <iostream>
#include <QCloseEvent>
#include <QString>
#include "StudentMainWindow.h"
namespace Ui {
class StudentLoginDialog;
}

class StudentLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudentLoginDialog(QWidget *parent = 0);
    ~StudentLoginDialog();  

    static QString st_id;

public slots:
    QString on_login_pushButton_2_clicked();

private:
    Ui::StudentLoginDialog *ui;
    StudentMainWindow *stu_main=new StudentMainWindow;
protected:
    virtual void closeEvent(QCloseEvent *);

};

#endif // STUDENTLOGINDIALOG_H

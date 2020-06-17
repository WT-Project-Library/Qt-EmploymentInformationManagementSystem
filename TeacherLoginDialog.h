#ifndef TEACHERLOGINDIALOG_H
#define TEACHERLOGINDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include "TeacherMainWindow.h"
namespace Ui {
class TeacherLoginDialog;
}

class TeacherLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherLoginDialog(QWidget *parent = 0);
    ~TeacherLoginDialog();

private slots:
    void on_login_pushButton_2_clicked();
protected:
    virtual void closeEvent(QCloseEvent *);
private:
    Ui::TeacherLoginDialog *ui;
    TeacherMainWindow *tea_main=new TeacherMainWindow;
};

#endif // TEACHERLOGINDIALOG_H

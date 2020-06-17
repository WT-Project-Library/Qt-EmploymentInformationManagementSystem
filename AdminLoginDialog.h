#ifndef ADMINLOGINDIALOG_H
#define ADMINLOGINDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include "AdminMainWindow.h"
namespace Ui {
class AdminLoginDialog;
}

class AdminLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLoginDialog(QWidget *parent = 0);
    ~AdminLoginDialog();

private slots:
    void on_login_pushButton_2_clicked();

protected:
    virtual void closeEvent(QCloseEvent *);

private:
    Ui::AdminLoginDialog *ui;
    AdminMainWindow *admin_main=new AdminMainWindow;
};

#endif // ADMINLOGINDIALOG_H

#ifndef ENTERPRISELOGINDIALOG_H
#define ENTERPRISELOGINDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include "EnterpriseMainWindow.h"
namespace Ui {
class EnterpriseLoginDialog;
}

class EnterpriseLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EnterpriseLoginDialog(QWidget *parent = 0);
    ~EnterpriseLoginDialog();

    static QString ent_id;

private slots:
    QString on_login_pushButton_2_clicked();
protected:
    virtual void closeEvent(QCloseEvent *);
private:
    Ui::EnterpriseLoginDialog *ui;
    EnterpriseMainWindow *ent_main=new EnterpriseMainWindow;
};

#endif // ENTERPRISELOGINDIALOG_H

#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>

namespace Ui {
class DeleteDialog;
}

class DeleteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteDialog(QWidget *parent = 0);
    ~DeleteDialog();

private slots:
    void on_sure_pushButton_clicked();

private:
    Ui::DeleteDialog *ui;
};

#endif // DELETEDIALOG_H

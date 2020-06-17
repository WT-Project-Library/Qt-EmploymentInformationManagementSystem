#ifndef SENDRESUMEDIALOG_H
#define SENDRESUMEDIALOG_H

#include <QDialog>

namespace Ui {
class SendResumeDialog;
}

class SendResumeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SendResumeDialog(QWidget *parent = 0);
    ~SendResumeDialog();

    Ui::SendResumeDialog *ui;

private slots:
   void on_send_pushButton_clicked();

   void on_speak_pushButton_2_clicked();

private:

};

#endif // SENDRESUMEDIALOG_H

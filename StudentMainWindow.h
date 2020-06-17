#ifndef STUDENTMAINWINDOW_H
#define STUDENTMAINWINDOW_H

#include <QMainWindow>
namespace Ui {
class StudentMainWindow;
}

class StudentMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentMainWindow(QWidget *parent = 0);
    ~StudentMainWindow();

    static QString a;


public slots:
    QString on_pushButton_19_clicked();

    QString on_pushButton_20_clicked();

    QString on_pushButton_21_clicked();

    QString on_pushButton_22_clicked();

    QString on_pushButton_23_clicked();

    QString on_pushButton_3_clicked();

    QString on_pushButton_10_clicked();

    QString on_pushButton_11_clicked();

    QString on_pushButton_12_clicked();

    QString on_pushButton_13_clicked();

    QString on_pushButton_24_clicked();

    QString on_pushButton_25_clicked();

    QString on_pushButton_26_clicked();

    QString on_pushButton_27_clicked();

    QString on_pushButton_28_clicked();

    QString on_pushButton_4_clicked();

    QString on_pushButton_29_clicked();

    QString on_pushButton_30_clicked();

    QString on_pushButton_31_clicked();

    QString on_pushButton_32_clicked();

private slots:
    void on_next_pushButton_10_clicked();

    void on_next1_pushButton_4_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_9_clicked();

    void on_save_pushButton_clicked();

    void on_delete_pushButton_3_clicked();

    void on_submit_pushButton_5_clicked();


    void on_disres_pushButton_clicked();

private:
    Ui::StudentMainWindow *ui;

    //简历数据
    QString stu_id;
    QString stu_name;
    QString stu_date;
    QString stu_phone;
    QString stu_email;
    QString stu_sex;
    QString stu_idnum;
    QString stu_state;
    QString stu_startdate;
    QString stu_place;
    QString stu_school;
    QString stu_professional;
    QString stu_wantjob;
    QString stu_honour;
    QString stu_education;
    QString stu_experience;
    QString stu_ability;
    QString stu_introduction;
    QString stu_break;

    //就业数据
    QString job_id;
    QString job_class;
    QString job_name;
    QString job_depart;
    QString job_graduation;
    QString job_unitName;
    QString job_code;
    QString job_unitNature;
    QString job_unitIndustry;
    QString job_unitPlace;
    QString job_position;
    QString job_linkman;
    QString job_linkPhone;
    QString job_unitPost;
    QString job_unitLocation;
};

#endif // STUDENTMAINWINDOW_H

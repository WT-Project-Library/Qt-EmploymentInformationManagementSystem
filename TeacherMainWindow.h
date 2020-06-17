#ifndef TEACHERMAINWINDOW_H
#define TEACHERMAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
namespace Ui {
class TeacherMainWindow;
}

class TeacherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherMainWindow(QWidget *parent = 0);
    ~TeacherMainWindow();

private slots:
    void on_speakDis_pushButton_clicked();

    void SLot_Measure_Table_Click_Ritht_Menu(QPoint pos);               //菜单 点击   获取当前位置
    void Slot_Menu_Choice_Action(QAction *act);                         //得知菜单当前的位置

    void on_stuDis_pushButton_clicked();

    void on_delStu_pushButton_2_clicked();

    void on_submitStu_pushButton_clicked();

    void on_go_pushButton_clicked();

    void on_nature_pushButton_2_clicked();

    void on_indus_pushButton_3_clicked();

    void on_breakDis_pushButton_2_clicked();

private:
    Ui::TeacherMainWindow *ui;

    QMenu *RightClickMenu;                          //右键点击菜单
    QAction *deleteAction;                          //删除事件（如需要其它事件，可新定义）
    int Selected_Current_Row;
    QSqlTableModel *model1;
    QSqlTableModel *model2;
    float Sum=0.00;
};

#endif // TEACHERMAINWINDOW_H

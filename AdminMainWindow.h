#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget *parent = 0);
    ~AdminMainWindow();

private slots:

    void SLot_Measure_Table_Click_Ritht_Menu(QPoint pos);               //菜单 点击   获取当前位置
    void Slot_Menu_Choice_Action(QAction *act);                         //得知菜单当前的位置

    void SLot_Measure_Table_Click_Ritht_Menu1(QPoint pos);               //菜单 点击   获取当前位置
    void Slot_Menu_Choice_Action1(QAction *act);                         //得知菜单当前的位置


    void on_speakDis_pushButton_clicked();

    void on_breakDis_pushButton_2_clicked();

    void on_save_pushButton_3_clicked();

    void on_go_pushButton_clicked();

    void on_nature_pushButton_2_clicked();

    void on_indus_pushButton_3_clicked();

    void on_dis_pushButton_2_clicked();

    void on_add_pushButton_clicked();

    void on_del_pushButton_2_clicked();

    void on_stuAdd_pushButton_clicked();

    void on_stuDel_pushButton_2_clicked();

    void on_stuMod_pushButton_3_clicked();

    void on_teaDel_pushButton_3_clicked();

    void on_teaAdd_pushButton_2_clicked();

    void on_teaMod_pushButton_4_clicked();

    void on_entAdd_pushButton_3_clicked();

    void on_entDel_pushButton_4_clicked();

    void on_entMod_pushButton_5_clicked();

private:
    Ui::AdminMainWindow *ui;

    QMenu *RightClickMenu;                          //右键点击菜单
    QAction *deleteAction;                          //删除事件（如需要其它事件，可新定义）
    int Selected_Current_Row;

    QMenu *RightClickMenu1;                          //右键点击菜单
    QAction *deleteAction1;                          //删除事件（如需要其它事件，可新定义）
    int Selected_Current_Row1;

    QSqlTableModel *model=new QSqlTableModel(this);
    QSqlTableModel *model1;

    float Sum=0.00;
};

#endif // ADMINMAINWINDOW_H

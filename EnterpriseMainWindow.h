#ifndef ENTERPRISEMAINWINDOW_H
#define ENTERPRISEMAINWINDOW_H

#include <QMainWindow>
#include <QSqlRelationalTableModel>
namespace Ui {
class EnterpriseMainWindow;
}

class EnterpriseMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EnterpriseMainWindow(QWidget *parent = 0);
    ~EnterpriseMainWindow();

private slots:
    void SLot_Measure_Table_Click_Ritht_Menu(QPoint pos);               //菜单 点击   获取当前位置
    void Slot_Menu_Choice_Action(QAction *act);                         //得知菜单当前的位置

    void SLot_Measure_Table_Click_Ritht_Menu1(QPoint pos);               //菜单 点击   获取当前位置
    void Slot_Menu_Choice_Action1(QAction *act);                         //得知菜单当前的位置

    void on_submit_pushButton_clicked();

    void on_disResume_pushButton_2_clicked();

    void on_disSpeak_pushButton_clicked();

    void on_entDis_pushButton_clicked();

    void on_submitEnt_pushButton_clicked();

private:
    Ui::EnterpriseMainWindow *ui;

    QMenu *RightClickMenu;                          //右键点击菜单
    QAction *breakAction;                          //违约事件（如需要其它事件，可新定义）

    QMenu *RightClickMenu1;                          //右键点击菜单
    QAction *deleteAction;                          //删除事件（如需要其它事件，可新定义）
    int Selected_Current_Row1;

    int Selected_Current_Row;

    QSqlRelationalTableModel *model=new QSqlRelationalTableModel(this);
    QSqlTableModel *model1;

};

#endif // ENTERPRISEMAINWINDOW_H

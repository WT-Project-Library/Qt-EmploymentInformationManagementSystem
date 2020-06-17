#include "AdminMainWindow.h"
#include "ui_AdminMainWindow.h"
#include <QMessageBox>
#include <QSqlQuery>
AdminMainWindow::AdminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);

    RightClickMenu = new QMenu();               //右键点击菜单
    deleteAction = new QAction(QString::fromLocal8Bit("删除"),this);  //删除事件
    RightClickMenu->addAction(deleteAction);    //将action添加到菜单内

    connect(ui->notice_tableView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(SLot_Measure_Table_Click_Ritht_Menu(QPoint)));
    connect(RightClickMenu,SIGNAL(triggered(QAction*)),this,SLOT(Slot_Menu_Choice_Action(QAction*)));


    RightClickMenu1 = new QMenu();               //右键点击菜单
    deleteAction1 = new QAction(QString::fromLocal8Bit("删除"),this);  //删除事件
    RightClickMenu1->addAction(deleteAction1);    //将action添加到菜单内

    connect(ui->speakDis_tableView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(SLot_Measure_Table_Click_Ritht_Menu1(QPoint)));
    connect(RightClickMenu1,SIGNAL(triggered(QAction*)),this,SLOT(Slot_Menu_Choice_Action1(QAction*)));


    //公告显示
    enum
    {
        id=0,
        notice=1
    };
    model->setTable("notice");
    model->setSort(id,Qt::AscendingOrder);
    model->setHeaderData(notice,Qt::Horizontal,QStringLiteral("公告"));
    model->select();

    ui->notice_tableView->setModel(model);
    ui->notice_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->notice_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->notice_tableView->setColumnHidden(id,true);
    ui->notice_tableView->resizeRowsToContents();
    ui->notice_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->notice_tableView->setFont(QFont(tr("Consolas"), 14));
    ui->notice_tableView->setContextMenuPolicy(Qt::CustomContextMenu); //可弹出右键菜单
    //ui->notice_tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(40,143,218);font:13pt '宋体';color: white;};");

    QHeaderView *header=ui->notice_tableView->horizontalHeader();
    header->setFont(QFont(tr("Consolas"), 20,75));
    header->setStretchLastSection(true);


    //就业总人数
    QString S=QString("select * from stu_employmentinformation");
    QSqlQuery query;
    if(query.exec(S))
    {
        while(query.next())
        {
            Sum++;
        }
    }
    ui->sum_lineEdit->setText(QString::number(Sum));
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}

//表格菜单  数据 更新
void AdminMainWindow::SLot_Measure_Table_Click_Ritht_Menu(QPoint pos)
{
    QModelIndex index = ui->notice_tableView->indexAt(pos);    //找到tableview当前位置信息
    Selected_Current_Row = index.row();    //获取到了当前右键所选的行数

    if(index.isValid())        //如果行数有效，则显示菜单
    {
        RightClickMenu->exec(QCursor::pos());
    }
}

//表格 按键删除
void AdminMainWindow::Slot_Menu_Choice_Action(QAction *act)
{
    //弹出提示框，看是否删除数据
    QMessageBox message(QMessageBox::NoIcon, QString::fromLocal8Bit("提示"),
                                QString::fromLocal8Bit("是否删除此公告？"),
                        QMessageBox::Yes | QMessageBox::No, NULL);

    //如确认删除
    if(message.exec() == QMessageBox::Yes)
    {
        if(act->text() == QString::fromLocal8Bit("删除"))   //看选中了删除这个菜单
        {
            model->removeRow(Selected_Current_Row);  //删除掉了表格信息
        }
    }
}

//表格菜单  数据 更新
void AdminMainWindow::SLot_Measure_Table_Click_Ritht_Menu1(QPoint pos)
{
    QModelIndex index = ui->speakDis_tableView->indexAt(pos);    //找到tableview当前位置信息
    Selected_Current_Row1 = index.row();    //获取到了当前右键所选的行数

    if(index.isValid())        //如果行数有效，则显示菜单
    {
        RightClickMenu1->exec(QCursor::pos());
    }
}

//表格 按键删除
void AdminMainWindow::Slot_Menu_Choice_Action1(QAction *act)
{
    //弹出提示框，看是否删除数据
    QMessageBox message(QMessageBox::NoIcon, QString::fromLocal8Bit("提示"),
                                QString::fromLocal8Bit("是否删除此留言？"),
                        QMessageBox::Yes | QMessageBox::No, NULL);

    //如确认删除
    if(message.exec() == QMessageBox::Yes)
    {
        if(act->text() == QString::fromLocal8Bit("删除"))   //看选中了删除这个菜单
        {
            model1->removeRow(Selected_Current_Row1);  //删除掉了表格信息
        }
    }
}

void AdminMainWindow::on_speakDis_pushButton_clicked()
{
    //留言显示
    enum
    {
        ent_id=0,
        ent_speaker=1,
        ent_speakword=2
    };
    QString entId=ui->entID_lineEdit->text();
    model1=new QSqlTableModel(this);
    model1->setTable("ent_speak");
    model1->setSort(ent_id,Qt::AscendingOrder);
    model1->setHeaderData(ent_id,Qt::Horizontal,QStringLiteral("公司编号"));
    model1->setHeaderData(ent_speaker,Qt::Horizontal,QStringLiteral("留言者"));
    model1->setHeaderData(ent_speakword,Qt::Horizontal,QStringLiteral("内容"));
    model1->setFilter(QObject::tr(" ent_id = '%1'").arg(entId));
    model1->select();


    ui->speakDis_tableView->setModel(model1);
    ui->speakDis_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->speakDis_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->speakDis_tableView->resizeRowsToContents();
    ui->speakDis_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->speakDis_tableView->setFont(QFont(tr("Consolas"), 14));
    ui->speakDis_tableView->setContextMenuPolicy(Qt::CustomContextMenu); //可弹出右键菜单
    //ui->notice_tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(40,143,218);font:13pt '宋体';color: white;};");

    QHeaderView *header=ui->speakDis_tableView->horizontalHeader();
    header->setFont(QFont(tr("Consolas"), 18,75));
    header->setStretchLastSection(true);
}

void AdminMainWindow::on_breakDis_pushButton_2_clicked()
{
    QString stu_id=ui->StuId_lineEdit_2->text();
    QString S=QString("select stu_break from stu_resume where stu_id='%1'").arg(stu_id);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
      QString breakSum=query.value(0).toString();
      ui->SumBreak_lineEdit->setText(breakSum);
    }
    else
    {
        ui->SumBreak_lineEdit->setText(QStringLiteral("0"));
    }
}

void AdminMainWindow::on_save_pushButton_3_clicked()
{
    QString stu_id=ui->StuId_lineEdit_2->text();
    QString breakSum=ui->SumBreak_lineEdit->text();
    QString S =QString("UPDATE stu_resume SET  stu_break='%1' WHERE (stu_id='%2')").arg(breakSum).arg(stu_id);

    QSqlQuery query;
    if(breakSum==NULL)
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("输入为空！"),QStringLiteral("确定"));
    }
    else if(query.exec(S))
    {
       QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("保存成功！"));
    }
}

void AdminMainWindow::on_go_pushButton_clicked()
{
    QString gotext=ui->graduation_comboBox_3->currentText();
    QString S=QString("select * from stu_employmentinformation where stu_graduation='%1'").arg(gotext);
    QSqlQuery query;
    float gosum=0.00;
    if(query.exec(S))
    {
        while(query.next())
        {
           gosum++;
        }
    }

    ui->gosum_lineEdit_2->setText(QString::number(gosum));
    float goper=gosum/Sum*100;
    ui->goper_lineEdit_3->setText(QString::number(goper)+"%");
}

void AdminMainWindow::on_nature_pushButton_2_clicked()
{
    QString naturetext=ui->unitnature_comboBox_4->currentText();
    QString S=QString("select * from stu_employmentinformation where stu_unitNature='%1'").arg(naturetext);
    QSqlQuery query;
    float naturesum=0.00;
    if(query.exec(S))
    {
        while(query.next())
        {
           naturesum++;
        }
    }

    ui->natureSum_lineEdit_5->setText(QString::number(naturesum));
    float natureper=naturesum/Sum*100;
    ui->naturePer_lineEdit_4->setText(QString::number(natureper)+"%");
}

void AdminMainWindow::on_indus_pushButton_3_clicked()
{
    QString industrytext=ui->unitindustry_comboBox_5->currentText();
    QString S=QString("select * from stu_employmentinformation where stu_unitIndustry='%1'").arg(industrytext);
    QSqlQuery query;
    float industrysum=0.00;
    if(query.exec(S))
    {
        while(query.next())
        {
           industrysum++;
        }
    }

    ui->indusSum_lineEdit_6->setText(QString::number(industrysum));
    float industryper=industrysum/Sum*100;
    ui->indusPer_lineEdit_7->setText(QString::number(industryper)+"%");
}

void AdminMainWindow::on_dis_pushButton_2_clicked()
{
    QString depart=ui->department_comboBox->currentText();
    QString graduate=ui->graduation_comboBox_4->currentText();

    QString S=QString("select * from stu_employmentinformation where stu_department='%1'").arg(depart);
    QSqlQuery query;
    float departSum=0.00;
    if(query.exec(S))
    {
        while(query.next())
        {
           departSum++;
        }
    }

    QString S1=QString("select * from stu_employmentinformation where stu_department='%1' and stu_graduation='%2' ").arg(depart).arg(graduate);
    QSqlQuery query1;
    float graduateSum=0.00;
    if(query1.exec(S1))
    {
        while(query1.next())
        {
           graduateSum++;
        }
    }
    if(departSum==0.00)
    {
        ui->dePer_lineEdit->setText(QString::number(0)+"%");
    }
    else
    {
        float industryper=graduateSum/departSum*100;
        ui->dePer_lineEdit->setText(QString::number(industryper)+"%");
    }

}

void AdminMainWindow::on_add_pushButton_clicked()
{
    QString depart=ui->depart_lineEdit->text();
    QString major=ui->major_lineEdit->text();
    QString S=QString("INSERT INTO depart_profession (department, profession) VALUES ('%1', '%2')").arg(depart).arg(major);
    QSqlQuery query;
    if(depart==NULL|major==NULL)
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("输入为空"),QStringLiteral("确定"));
    }
    else if(query.exec(S))
    {

        QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("添加成功！"),QStringLiteral("确定"));
    }

}

void AdminMainWindow::on_del_pushButton_2_clicked()
{
    QString depart=ui->depart_lineEdit->text();
    QString major=ui->major_lineEdit->text();
    QString S=QString("select * from depart_profession where department='%1' and profession='%2' ").arg(depart).arg(major);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
        QString S1=QString("DELETE FROM depart_profession WHERE department='%1' and profession='%2' ").arg(depart).arg(major);
        QSqlQuery query1;
        if(query1.exec(S1))
        {
            QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("删除成功！"),QStringLiteral("确定"));
        }
    }
    else
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("该专业不存在！"),QStringLiteral("确定"));

    }

}

void AdminMainWindow::on_stuAdd_pushButton_clicked()
{
    QString ID=ui->stuID_lineEdit->text();
    QString PSD=ui->stuPsd_lineEdit_2->text();
    if(ID!=NULL)
    {
        QString S=QString("select * from user_stu where stu_id='%1' ").arg(ID);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("该学生已存在！"),QStringLiteral("确定"));
        }
        else if(PSD!=NULL)
        {

            QString S1=QString("INSERT INTO user_stu (stu_id, stu_psd) VALUES ('%1', '%2')").arg(ID).arg(PSD);
            QSqlQuery query1;
            if(query1.exec(S1))
            {
                QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("添加成功！"),QStringLiteral("确定"));
            }

        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("密码为空！"),QStringLiteral("确定"));
        }
    }
    else
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("学号为空！"),QStringLiteral("确定"));
    }
}

void AdminMainWindow::on_stuDel_pushButton_2_clicked()
{
    QString ID=ui->stuID_lineEdit->text();
    //QString PSD=ui->stuPsd_lineEdit_2->text();

    if(ID!=NULL)
    {
        QString S=QString("select * from user_stu where stu_id='%1' ").arg(ID);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {
            QString S1=QString(" DELETE FROM user_stu WHERE stu_id='%1' ").arg(ID);
            QSqlQuery query1;
            if(query1.exec(S1))
            {
                QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("删除成功！"),QStringLiteral("确定"));
            }
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("该学生不存在！"),QStringLiteral("确定"));
        }
    }
    else
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("学号为空！"),QStringLiteral("确定"));
    }
}

void AdminMainWindow::on_stuMod_pushButton_3_clicked()
{
    QString ID=ui->stuID_lineEdit->text();
    QString PSD=ui->stuPsd_lineEdit_2->text();

    if(ID!=NULL&&PSD!=NULL)
    {
        QString S=QString("select * from user_stu where stu_id='%1' ").arg(ID);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {
            QString S1=QString(" UPDATE user_stu SET stu_psd='%1' WHERE stu_id='%2'  ").arg(PSD).arg(ID);
            QSqlQuery query1;
            if(query1.exec(S1))
            {
                QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("修改成功！"),QStringLiteral("确定"));
            }
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("该学生不存在！"),QStringLiteral("确定"));
        }
    }
    else
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("输入为空！"),QStringLiteral("确定"));
    }

}



void AdminMainWindow::on_teaAdd_pushButton_2_clicked()
{
    QString ID=ui->teaID_lineEdit_2->text();
    QString PSD=ui->teaPsd_lineEdit_3->text();
    if(ID!=NULL)
    {
        QString S=QString("select * from user_tea where tea_id='%1' ").arg(ID);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("该教师已存在！"),QStringLiteral("确定"));
        }
        else if(PSD!=NULL)
        {

            QString S1=QString("INSERT INTO user_tea (tea_id, tea_psd) VALUES ('%1', '%2')").arg(ID).arg(PSD);
            QSqlQuery query1;
            if(query1.exec(S1))
            {
                QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("添加成功！"),QStringLiteral("确定"));
            }
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("密码为空！"),QStringLiteral("确定"));
        }
    }
    else
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("教师工号为空！"),QStringLiteral("确定"));
    }
}

void AdminMainWindow::on_teaDel_pushButton_3_clicked()
{
    QString ID=ui->teaID_lineEdit_2->text();
    //QString PSD=ui->stuPsd_lineEdit_2->text();

    if(ID!=NULL)
    {
        QString S=QString("select * from user_tea where tea_id='%1' ").arg(ID);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {
            QString S1=QString(" DELETE FROM user_tea WHERE tea_id='%1' ").arg(ID);
            QSqlQuery query1;
            if(query1.exec(S1))
            {
                QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("删除成功！"),QStringLiteral("确定"));
            }
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("该教师不存在！"),QStringLiteral("确定"));
        }
    }
    else
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("教师工号为空！"),QStringLiteral("确定"));
    }
}

void AdminMainWindow::on_teaMod_pushButton_4_clicked()
{
    QString ID=ui->teaID_lineEdit_2->text();
    QString PSD=ui->teaPsd_lineEdit_3->text();

    if(ID!=NULL&&PSD!=NULL)
    {
        QString S=QString("select * from user_tea where tea_id='%1' ").arg(ID);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {
            QString S1=QString(" UPDATE user_tea SET tea_psd='%1' WHERE tea_id='%2'  ").arg(PSD).arg(ID);
            QSqlQuery query1;
            if(query1.exec(S1))
            {
                QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("修改成功！"),QStringLiteral("确定"));
            }
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("该教师不存在！"),QStringLiteral("确定"));
        }
    }
    else
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("输入为空！"),QStringLiteral("确定"));
    }
}

void AdminMainWindow::on_entAdd_pushButton_3_clicked()
{
    QString ID=ui->entID_lineEdit_3->text();
    QString PSD=ui->entPsd_lineEdit_4->text();
    if(ID!=NULL)
    {
        QString S=QString("select * from user_ent where ent_id='%1' ").arg(ID);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("该企业已存在！"),QStringLiteral("确定"));
        }
        else if(PSD!=NULL)
        {

            QString S1=QString("INSERT INTO user_ent (ent_id, ent_psd) VALUES ('%1', '%2')").arg(ID).arg(PSD);
            QSqlQuery query1;
            if(query1.exec(S1))
            {
                QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("添加成功！"),QStringLiteral("确定"));
            }
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("密码为空！"),QStringLiteral("确定"));
        }
    }
    else
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("账号为空！"),QStringLiteral("确定"));
    }
}

void AdminMainWindow::on_entDel_pushButton_4_clicked()
{
    QString ID=ui->entID_lineEdit_3->text();
    //QString PSD=ui->stuPsd_lineEdit_2->text();

    if(ID!=NULL)
    {
        QString S=QString("select * from user_ent where ent_id='%1' ").arg(ID);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {
            QString S1=QString(" DELETE FROM user_ent WHERE ent_id='%1' ").arg(ID);
            QSqlQuery query1;
            if(query1.exec(S1))
            {
                QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("删除成功！"),QStringLiteral("确定"));
            }
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("该企业不存在！"),QStringLiteral("确定"));
        }
    }
    else
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("账号为空！"),QStringLiteral("确定"));
    }
}

void AdminMainWindow::on_entMod_pushButton_5_clicked()
{
    QString ID=ui->entID_lineEdit_3->text();
    QString PSD=ui->entPsd_lineEdit_4->text();

    if(ID!=NULL&&PSD!=NULL)
    {
        QString S=QString("select * from user_ent where ent_id='%1' ").arg(ID);
        QSqlQuery query;
        if(query.exec(S)&&query.next())
        {
            QString S1=QString(" UPDATE user_ent SET ent_psd='%1' WHERE ent_id='%2'  ").arg(PSD).arg(ID);
            QSqlQuery query1;
            if(query1.exec(S1))
            {
                QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("修改成功！"),QStringLiteral("确定"));
            }
        }
        else
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("该企业不存在！"),QStringLiteral("确定"));
        }
    }
    else
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("输入为空！"),QStringLiteral("确定"));
    }
}

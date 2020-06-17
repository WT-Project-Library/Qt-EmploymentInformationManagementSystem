#include "EnterpriseMainWindow.h"
#include "ui_EnterpriseMainWindow.h"
#include "EnterpriseLoginDialog.h"
#include <QSqlTableModel>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
EnterpriseMainWindow::EnterpriseMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EnterpriseMainWindow)
{
    ui->setupUi(this);

    RightClickMenu = new QMenu();               //右键点击菜单
    breakAction = new QAction(QString::fromLocal8Bit("违约"),this);  //违约事件
    RightClickMenu->addAction(breakAction);    //将action添加到菜单内

    connect(ui->resume_tableView_2,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(SLot_Measure_Table_Click_Ritht_Menu(QPoint)));
    connect(RightClickMenu,SIGNAL(triggered(QAction*)),this,SLOT(Slot_Menu_Choice_Action(QAction*)));


    RightClickMenu1 = new QMenu();               //右键点击菜单
    deleteAction = new QAction(QString::fromLocal8Bit("删除"),this);  //删除事件
    RightClickMenu1->addAction(deleteAction);    //将action添加到菜单内

    connect(ui->speak_tableView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(SLot_Measure_Table_Click_Ritht_Menu1(QPoint)));
    connect(RightClickMenu1,SIGNAL(triggered(QAction*)),this,SLOT(Slot_Menu_Choice_Action1(QAction*)));


}

EnterpriseMainWindow::~EnterpriseMainWindow()
{
    delete ui;
}

//表格菜单  数据 更新
void EnterpriseMainWindow::SLot_Measure_Table_Click_Ritht_Menu(QPoint pos)
{
    QModelIndex index = ui->resume_tableView_2->indexAt(pos);    //找到tableview当前位置信息
    Selected_Current_Row = index.row();    //获取到了当前右键所选的行数

    if(index.isValid())        //如果行数有效，则显示菜单
    {
        RightClickMenu->exec(QCursor::pos());
    }
}

//表格 按键违约
void EnterpriseMainWindow::Slot_Menu_Choice_Action(QAction *act)
{

    //弹出提示框，看是否违约
    QMessageBox message(QMessageBox::NoIcon, QString::fromLocal8Bit("提示"),
                                QString::fromLocal8Bit("确认违约？"),
                        QMessageBox::Yes | QMessageBox::No, NULL);

    //如确认违约
    if(message.exec() == QMessageBox::Yes)
    {
        if(act->text() == QString::fromLocal8Bit("违约"))   //看选中了删除这个菜单
        {
            QSqlRecord record = model->record(Selected_Current_Row);
            int breakSum=record.value("stu_break").toInt();  //获取当前违约次数
            model->setData(model->index(Selected_Current_Row,18), ++breakSum);
            model->submitAll();
        }
    }
}

void EnterpriseMainWindow::SLot_Measure_Table_Click_Ritht_Menu1(QPoint pos)
{
    QModelIndex index = ui->speak_tableView->indexAt(pos);    //找到tableview当前位置信息
    Selected_Current_Row1 = index.row();    //获取到了当前右键所选的行数

    if(index.isValid())        //如果行数有效，则显示菜单
    {
        RightClickMenu1->exec(QCursor::pos());
    }
}

void EnterpriseMainWindow::Slot_Menu_Choice_Action1(QAction *act)
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

void EnterpriseMainWindow::on_submit_pushButton_clicked()
{
    QString unit=ui->unit_textEdit->toPlainText();
    QString time=ui->time_textEdit_2->toPlainText();
    QString school=ui->school_lineEdit->text();
    QString notice=QStringLiteral("宣讲单位：")+unit+"\n"+QStringLiteral("宣讲时间：")+time+"\n\n"+QStringLiteral("所在学校：")+school;
    qDebug()<<notice;
    QString S=QString("INSERT INTO notice (notice) VALUES ('%1')").arg(notice);
    QSqlQuery query;
    if(unit==NULL|time==NULL|school==NULL)
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("输入为空！"),QStringLiteral("确定"));
    }
    else if(query.exec(S))
    {
        QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("提交成功"));
    }
}

void EnterpriseMainWindow::on_disResume_pushButton_2_clicked()
{
    QString entId=EnterpriseLoginDialog::ent_id;
    enum
    {
        stu_id1=0,
        stu_name1=1,
        stu_dat1=2,
        stu_phone1=3,
        stu_email1=4,
        stu_sex1=5,
        stu_idnum1=6,
        stu_state1=7,
        stu_startdate1=8,
        stu_place1=9,
        stu_school1=10,
        stu_professional1=11,
        stu_wantjob1=12,
        stu_honour1=13,
        stu_education1=14,
        stu_experience1=15,
        stu_ability1=16,
        stu_introduction1=17,
        stu_break=18
    };


    model->setTable("ent_sender");
    model->setFilter(QObject::tr(" ent_id = '%1'").arg(entId));
    model->setRelation(1,QSqlRelation("stu_resume","stu_id","stu_resume"));
    model->setTable("stu_resume");
    model->setHeaderData(stu_name1,Qt::Horizontal,QStringLiteral("姓名"));
    model->setHeaderData(stu_dat1,Qt::Horizontal,QStringLiteral("出生日期"));
    model->setHeaderData(stu_phone1,Qt::Horizontal,QStringLiteral("电话"));
    model->setHeaderData(stu_email1,Qt::Horizontal,QStringLiteral("邮箱"));
    model->setHeaderData(stu_sex1,Qt::Horizontal,QStringLiteral("性别"));
    model->setHeaderData(stu_idnum1,Qt::Horizontal,QStringLiteral("身份证号"));
    model->setHeaderData(stu_state1,Qt::Horizontal,QStringLiteral("目前状态"));
    model->setHeaderData(stu_startdate1,Qt::Horizontal,QStringLiteral("开始工作年份"));
    model->setHeaderData(stu_place1,Qt::Horizontal,QStringLiteral("居住地"));
    model->setHeaderData(stu_school1,Qt::Horizontal,QStringLiteral("学校"));
    model->setHeaderData(stu_professional1,Qt::Horizontal,QStringLiteral("专业"));
    model->setHeaderData(stu_wantjob1,Qt::Horizontal,QStringLiteral("求职意向"));
    model->setHeaderData(stu_honour1,Qt::Horizontal,QStringLiteral("在校荣誉"));
    model->setHeaderData(stu_education1,Qt::Horizontal,QStringLiteral("教育经历"));
    model->setHeaderData(stu_experience1,Qt::Horizontal,QStringLiteral("工作经验"));
    model->setHeaderData(stu_ability1,Qt::Horizontal,QStringLiteral("能力介绍"));
    model->setHeaderData(stu_introduction1,Qt::Horizontal,QStringLiteral("自我介绍"));
    model->setHeaderData(stu_break,Qt::Horizontal,QStringLiteral("违约次数"));
    model->select();

    ui->resume_tableView_2->setModel(model);
    ui->resume_tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->resume_tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->resume_tableView_2->setColumnHidden(stu_id1,true);
    ui->resume_tableView_2->resizeRowsToContents();
    ui->resume_tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->resume_tableView_2->setFont(QFont(tr("Consolas"), 10));
    ui->resume_tableView_2->setContextMenuPolicy(Qt::CustomContextMenu); //可弹出右键菜单
    //ui->resume_tableView->verticalHeader();
    //ui->resume_tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(40,143,218);font:13pt '宋体';color: black;};");

    QHeaderView *header=ui->resume_tableView_2->verticalHeader();
    header->setFont(QFont(tr("Consolas"), 20,75));
    //header->setStretchLastSection(true);

}

void EnterpriseMainWindow::on_disSpeak_pushButton_clicked()
{
    //留言显示
    enum
    {
        ent_id=0,
        ent_speaker=1,
        ent_speakword=2
    };
    QString entId=EnterpriseLoginDialog::ent_id;
    model1=new QSqlTableModel(this);
    model1->setTable("ent_speak");
    model1->setSort(ent_id,Qt::AscendingOrder);
    model1->setHeaderData(ent_id,Qt::Horizontal,QStringLiteral("公司编号"));
    model1->setHeaderData(ent_speaker,Qt::Horizontal,QStringLiteral("留言者"));
    model1->setHeaderData(ent_speakword,Qt::Horizontal,QStringLiteral("内容"));
    model1->setFilter(QObject::tr(" ent_id = '%1'").arg(entId));
    model1->select();


    ui->speak_tableView->setModel(model1);
    ui->speak_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->speak_tableView->setColumnHidden(ent_id,true);
    ui->speak_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->speak_tableView->resizeRowsToContents();
    ui->speak_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->speak_tableView->setFont(QFont(tr("Consolas"), 14));
    ui->speak_tableView->setContextMenuPolicy(Qt::CustomContextMenu); //可弹出右键菜单
    //ui->notice_tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(40,143,218);font:13pt '宋体';color: white;};");

    QHeaderView *header=ui->speak_tableView->horizontalHeader();
    header->setFont(QFont(tr("Consolas"), 18,75));
    header->setStretchLastSection(true);
}

void EnterpriseMainWindow::on_entDis_pushButton_clicked()
{
    QString EntId=EnterpriseLoginDialog::ent_id;
    QString S =QString("select * from ent_info where ent_id='%1' ").arg(EntId);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
       QString entname=query.value(1).toString();
       QString entsort=query.value(2).toString();
       QString jobinfo=query.value(3).toString();
       ui->entName_textEdit->setText(entname);
       ui->entSort_textEdit_2->setText(entsort);
       ui->job_textEdit_3->setText(jobinfo);
    }
}

void EnterpriseMainWindow::on_submitEnt_pushButton_clicked()
{
    QString EntId=EnterpriseLoginDialog::ent_id;
    QString entname=ui->entName_textEdit->toPlainText();
    QString entsort=ui->entSort_textEdit_2->toPlainText();
    QString jobinfo=ui->job_textEdit_3->toPlainText();
    QString S =QString("UPDATE ent_info SET  ent_name='%1', ent_sort='%2', ent_info='%3' WHERE (ent_id='%4')")
               .arg(entname).arg(entsort).arg(jobinfo).arg(EntId);

    QSqlQuery query;
    if(entname==NULL|entsort==NULL|jobinfo==NULL)
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("输入为空！"),QStringLiteral("确定"));
    }
    else if(query.exec(S))
    {
       QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("修改成功！"));
    }
}

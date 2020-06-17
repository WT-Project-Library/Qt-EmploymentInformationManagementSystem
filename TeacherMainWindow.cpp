#include "TeacherMainWindow.h"
#include "ui_TeacherMainWindow.h"
#include <QMenu>
#include <QAction>
#include <QPoint>
#include <QMessageBox>
#include <QString>
#include <QHeaderView>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
TeacherMainWindow::TeacherMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherMainWindow)
{
    ui->setupUi(this);

    RightClickMenu = new QMenu();               //右键点击菜单
    deleteAction = new QAction(QString::fromLocal8Bit("删除"),this);  //删除事件
    RightClickMenu->addAction(deleteAction);    //将action添加到菜单内

    connect(ui->speakDis_tableView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(SLot_Measure_Table_Click_Ritht_Menu(QPoint)));
    connect(RightClickMenu,SIGNAL(triggered(QAction*)),this,SLOT(Slot_Menu_Choice_Action(QAction*)));

    //公告显示
    enum
    {
        id=0,
        notice=1
    };
    QSqlTableModel *model=new QSqlTableModel(this);
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
    //ui->notice_tableView->setContextMenuPolicy(Qt::CustomContextMenu); //可弹出右键菜单
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

TeacherMainWindow::~TeacherMainWindow()
{
    delete ui;
}

//表格菜单  数据 更新
void TeacherMainWindow::SLot_Measure_Table_Click_Ritht_Menu(QPoint pos)
{
    QModelIndex index = ui->speakDis_tableView->indexAt(pos);    //找到tableview当前位置信息
    Selected_Current_Row = index.row();    //获取到了当前右键所选的行数

    if(index.isValid())        //如果行数有效，则显示菜单
    {
        RightClickMenu->exec(QCursor::pos());
    }
}

//表格 按键删除
void TeacherMainWindow::Slot_Menu_Choice_Action(QAction *act)
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
            model1->removeRow(Selected_Current_Row);  //删除掉了表格信息
        }
    }
}

void TeacherMainWindow::on_speakDis_pushButton_clicked()
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

void TeacherMainWindow::on_stuDis_pushButton_clicked()
{
    //学生就业信息展示
    enum
    {
        stu_id=0,
        stu_class=1,
        stu_name=2,
        stu_department=3,
        stu_graduation=4,
        stu_unitName=5,
        stu_code=6,
        stu_unitNature=7,
        stu_unitIndustry=8,
        stu_unitPlace=9,
        stu_position=10,
        stu_unitLinkman=11,
        stu_linkPhone=12,
        stu_unitPostcode=13,
        stu_unitLocation=14
    };
    QString stuId=ui->stuId_lineEdit->text();
    model2=new QSqlTableModel(this);
    model2->setTable("stu_employmentinformation");
    model2->setSort(stu_id,Qt::AscendingOrder);
    model2->setHeaderData(stu_id,Qt::Horizontal,QStringLiteral("学号"));
    model2->setHeaderData(stu_class,Qt::Horizontal,QStringLiteral("班级"));
    model2->setHeaderData(stu_name,Qt::Horizontal,QStringLiteral("姓名"));
    model2->setHeaderData(stu_department,Qt::Horizontal,QStringLiteral("系别"));
    model2->setHeaderData(stu_graduation,Qt::Horizontal,QStringLiteral("毕业去向"));
    model2->setHeaderData(stu_unitName,Qt::Horizontal,QStringLiteral("单位名称"));
    model2->setHeaderData(stu_code,Qt::Horizontal,QStringLiteral("组织机构代码"));
    model2->setHeaderData(stu_unitNature,Qt::Horizontal,QStringLiteral("单位性质"));
    model2->setHeaderData(stu_unitIndustry,Qt::Horizontal,QStringLiteral("单位行业"));
    model2->setHeaderData(stu_unitPlace,Qt::Horizontal,QStringLiteral("单位所在地"));
    model2->setHeaderData(stu_position,Qt::Horizontal,QStringLiteral("工作职位类别"));
    model2->setHeaderData(stu_unitLinkman,Qt::Horizontal,QStringLiteral("单位联系人"));
    model2->setHeaderData(stu_linkPhone,Qt::Horizontal,QStringLiteral("联系人电话"));
    model2->setHeaderData(stu_unitPostcode,Qt::Horizontal,QStringLiteral("单位邮编"));
    model2->setHeaderData(stu_unitLocation,Qt::Horizontal,QStringLiteral("单位地址"));
    model2->setFilter(QObject::tr(" stu_id = '%1'").arg(stuId));
    model2->select();


    ui->stuDis_tableView->setModel(model2);
    ui->stuDis_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->stuDis_tableView->setSelectionBehavior(QAbstractItemView::SelectColumns);
    ui->stuDis_tableView->resizeRowsToContents();
    //ui->stuDis_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->stuDis_tableView->setFont(QFont(tr("Consolas"), 14));
    //ui->stuDis_tableView->setContextMenuPolicy(Qt::CustomContextMenu); //可弹出右键菜单
    //ui->notice_tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(40,143,218);font:13pt '宋体';color: white;};");

    QHeaderView *header=ui->speakDis_tableView->horizontalHeader();
    header->setFont(QFont(tr("Consolas"), 18,75));
    header->setStretchLastSection(true);
}

void TeacherMainWindow::on_submitStu_pushButton_clicked()
{
    model2->database().transaction(); //开始事务操作
        if (model2->submitAll())
        {
            model2->database().commit(); //提交

            QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("修改成功"));
        }
        else
        {
            model2->database().rollback(); //回滚
            QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("数据库错误 '%1'").arg(model2->lastError().text()));
        }
}
void TeacherMainWindow::on_delStu_pushButton_2_clicked()
{
    QMessageBox message(QMessageBox::NoIcon, QString::fromLocal8Bit("提示"),
                                QString::fromLocal8Bit("是否删除该生就业信息？"),
                        QMessageBox::Yes | QMessageBox::No, NULL);

    //如确认删除
    if(message.exec() == QMessageBox::Yes)
    {
        model2->removeRow(0);
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("删除成功"));
    }
}



void TeacherMainWindow::on_go_pushButton_clicked()
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
//单位性质
void TeacherMainWindow::on_nature_pushButton_2_clicked()
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
//单位行业
void TeacherMainWindow::on_indus_pushButton_3_clicked()
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

void TeacherMainWindow::on_breakDis_pushButton_2_clicked()
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

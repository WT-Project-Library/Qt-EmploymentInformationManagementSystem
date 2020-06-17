#include "StudentMainWindow.h"
#include "ui_StudentMainWindow.h"
#include "DeleteDialog.h"
#include "SendResumeDialog.h"
#include "ui_SendResumeDialog.h"
#include "StudentLoginDialog.h"
#include <QMovie>
#include <QPixmap>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QHeaderView>
#include <QTextCursor>
StudentMainWindow::StudentMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentMainWindow)
{
    ui->setupUi(this);

    //首页
    //lable gif 动图
    QMovie *infoMove=new QMovie(":/gif/gif/1585556615460.gif");
    ui->info_label->setMovie(infoMove);
    ui->info_label->setFixedSize(420,290);
    ui->info_label->setScaledContents(true);
    infoMove->start();
    //lable 图片
    QPixmap mImage = QPixmap(":/img/img/u=2383283406,95267633&fm=26&gp=0.jpg");
    ui->image_label_17->setPixmap(mImage);
    ui->image_label_17->setScaledContents(true);//容许缩放
    ui->image_label_17->resize(420,290);

    //求职
    //图片
    QPixmap mImage1 = QPixmap(":/img/img/51jobA05.jpg");
    ui->img1_label_19->setPixmap(mImage1);
    ui->img1_label_19->setScaledContents(true);//容许缩放
    ui->img1_label_19->resize(300,100);

    QPixmap mImage2 = QPixmap(":/img/img/51web_banner_315x70.jpg");
    ui->img2_label_20->setPixmap(mImage2);
    ui->img2_label_20->setScaledContents(true);//容许缩放
    ui->img2_label_20->resize(300,100);

    QPixmap mImage3 = QPixmap(":/img/img/pic_cg_miduoduo.jpg");
    ui->img3_label_21->setPixmap(mImage3);
    ui->img3_label_21->setScaledContents(true);//容许缩放
    ui->img3_label_21->resize(300,100);

    QPixmap mImage4 = QPixmap(":/img/img/hubeizph.jpg");
    ui->img4_label_19 ->setPixmap(mImage4);
    ui->img4_label_19->setScaledContents(true);//容许缩放
    ui->img4_label_19->resize(1000,100);


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
    //ui->notice_tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(40,143,218);font:13pt '宋体';color: white;};");

    QHeaderView *header=ui->notice_tableView->horizontalHeader();
    header->setFont(QFont(tr("Consolas"), 20,75));
    header->setStretchLastSection(true);




    //求职界面 首页 button 数据库赋值 首页换页功能赋值
    QString ent_id;
    QSqlQuery query;
    ent_id=QStringLiteral("001");
    QString S1=QString("select ent_name,ent_info from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S1)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_19->setText(buttontext);
        ui->pushButton_15->setText(buttontext);
        QString dis_text=query.value(1).toString();
        ui->dis1_textEdit_11->setText(dis_text);
    }

    ent_id=QStringLiteral("002");
    QString S2=QString("select ent_name,ent_info from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S2)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_20->setText(buttontext);
        ui->pushButton_2->setText(buttontext);
        QString dis_text=query.value(1).toString();
        ui->dis2_textEdit_12->setText(dis_text);

    }

    ent_id=QStringLiteral("003");
    QString S3=QString("select ent_name,ent_info from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S3)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_21->setText(buttontext);
        ui->pushButton_18->setText(buttontext);
        QString dis_text=query.value(1).toString();
        ui->dis3_textEdit_9->setText(dis_text);
    }

    ent_id=QStringLiteral("004");
    QString S4=QString("select ent_name,ent_info from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S4)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_22->setText(buttontext);
        ui->pushButton_6->setText(buttontext);
        QString dis_text=query.value(1).toString();
        ui->dis4_textEdit_10->setText(dis_text);
    }

    ent_id=QStringLiteral("005");
    QString S5=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S5)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_23->setText(buttontext);
        ui->pushButton_17->setText(buttontext);
    }

    ent_id=QStringLiteral("006");
    QString S6=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S6)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_3->setText(buttontext);
        ui->pushButton_7->setText(buttontext);
    }

    ent_id=QStringLiteral("007");
    QString S7=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S7)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_10->setText(buttontext);
        ui->pushButton_16->setText(buttontext);
    }

    ent_id=QStringLiteral("008");
    QString S8=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S8)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_11->setText(buttontext);
        ui->pushButton_8->setText(buttontext);
    }

    ent_id=QStringLiteral("009");
    QString S9=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S9)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_12->setText(buttontext);
        ui->pushButton_14->setText(buttontext);
    }

    ent_id=QStringLiteral("010");
    QString S10=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S10)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_13->setText(buttontext);
        ui->pushButton_9->setText(buttontext);
    }

    ent_id=QStringLiteral("011");
    QString S11=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S11)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_24->setText(buttontext);
    }

    ent_id=QStringLiteral("012");
    QString S12=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S12)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_25->setText(buttontext);
    }

    ent_id=QStringLiteral("013");
    QString S13=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S13)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_26->setText(buttontext);
    }

    ent_id=QStringLiteral("014");
    QString S14=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S14)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_27->setText(buttontext);
    }

    ent_id=QStringLiteral("015");
    QString S15=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S15)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_28->setText(buttontext);
    }

    ent_id=QStringLiteral("016");
    QString S16=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S16)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_4->setText(buttontext);
    }

    ent_id=QStringLiteral("017");
    QString S17=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S17)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_29->setText(buttontext);
    }

    ent_id=QStringLiteral("018");
    QString S18=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S18)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_30->setText(buttontext);
    }

    ent_id=QStringLiteral("019");
    QString S19=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S19)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_31->setText(buttontext);
    }

    ent_id=QStringLiteral("020");
    QString S20=QString("select ent_name from ent_info where ent_id='%1'").arg(ent_id);
    if( query.exec(S20)&&query.next())
    {
        QString buttontext = query.value(0).toString();
        ui->pushButton_32->setText(buttontext);
    }

}

StudentMainWindow::~StudentMainWindow()
{
    delete ui;
}

void StudentMainWindow::on_next_pushButton_10_clicked()
{
    int nCount = ui->stackedWidget_2->count();
    int nIndex =ui->stackedWidget_2->currentIndex();

       // 获取下一个需要显示的页面索引
       ++nIndex;

       // 当需要显示的页面索引大于等于总页面时，切换至首页
       if (nIndex >= nCount)
           nIndex = 0;

       ui->stackedWidget_2->setCurrentIndex(nIndex);
}

void StudentMainWindow::on_next1_pushButton_4_clicked()
{
    int nCount = ui->stackedWidget->count();
    int nIndex =ui->stackedWidget->currentIndex();

       // 获取下一个需要显示的页面索引
       ++nIndex;

       // 当需要显示的页面索引大于等于总页面时，切换至首页
       if (nIndex >= nCount)
           nIndex = 0;

       ui->stackedWidget->setCurrentIndex(nIndex);
}

void StudentMainWindow::on_pushButton_15_clicked()
{
    QString ent_id="001";
    QString S=QString("select ent_info,ent_name from ent_info where ent_id='%1'").arg(ent_id);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
         QString ent_detail=query.value(0).toString();
         QString ent_name=query.value(1).toString();
         QDialog *w=new QDialog;
         QTextEdit *text=new QTextEdit(w);
         text->append(ent_detail);
         text->setReadOnly(true);
         text->resize(1000,500);
         text->setFont(QFont(tr("Consolas"), 14));
         QTextCursor cursor = text->textCursor();
         cursor.movePosition(QTextCursor::Start);
         text->setTextCursor(cursor);
         w->setWindowTitle(ent_name);
         w->setWindowIcon(QIcon(":/img/img/b5498846b199e90948a50e196277c716.jpg"));
         w->setStyleSheet("background-image:url(:/img/img/c78b9ec7f088f2801b655badc550c2a3.jpg)");
         w->exec();
    }

}

void StudentMainWindow::on_pushButton_2_clicked()
{
    QString ent_id="002";
    QString S=QString("select ent_info,ent_name from ent_info where ent_id='%1'").arg(ent_id);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
         QString ent_detail=query.value(0).toString();
         QString ent_name=query.value(1).toString();
         QDialog *w=new QDialog;
         QTextEdit *text=new QTextEdit(w);
         text->append(ent_detail);
         text->setReadOnly(true);
         text->resize(1000,500);
         text->setFont(QFont(tr("Consolas"), 14));
         QTextCursor cursor = text->textCursor();
         cursor.movePosition(QTextCursor::Start);
         text->setTextCursor(cursor);
         w->setWindowTitle(ent_name);
         w->setWindowIcon(QIcon(":/img/img/b5498846b199e90948a50e196277c716.jpg"));
         w->setStyleSheet("background-image:url(:/img/img/c78b9ec7f088f2801b655badc550c2a3.jpg)");
         w->exec();
    }
}

void StudentMainWindow::on_pushButton_18_clicked()
{
    QString ent_id="003";
    QString S=QString("select ent_info,ent_name from ent_info where ent_id='%1'").arg(ent_id);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
         QString ent_detail=query.value(0).toString();
         QString ent_name=query.value(1).toString();
         QDialog *w=new QDialog;
         QTextEdit *text=new QTextEdit(w);
         text->append(ent_detail);
         text->setReadOnly(true);
         text->resize(1000,500);
         text->setFont(QFont(tr("Consolas"), 14));
         QTextCursor cursor = text->textCursor();
         cursor.movePosition(QTextCursor::Start);
         text->setTextCursor(cursor);
         w->setWindowTitle(ent_name);
         w->setWindowIcon(QIcon(":/img/img/b5498846b199e90948a50e196277c716.jpg"));
         w->setStyleSheet("background-image:url(:/img/img/c78b9ec7f088f2801b655badc550c2a3.jpg)");
         w->exec();
    }
}

void StudentMainWindow::on_pushButton_6_clicked()
{
    QString ent_id="004";
    QString S=QString("select ent_info,ent_name from ent_info where ent_id='%1'").arg(ent_id);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
         QString ent_detail=query.value(0).toString();
         QString ent_name=query.value(1).toString();
         QDialog *w=new QDialog;
         QTextEdit *text=new QTextEdit(w);
         text->append(ent_detail);
         text->setReadOnly(true);
         text->resize(1000,500);
         text->setFont(QFont(tr("Consolas"), 14));
         QTextCursor cursor = text->textCursor();
         cursor.movePosition(QTextCursor::Start);
         text->setTextCursor(cursor);
         w->setWindowTitle(ent_name);
         w->setWindowIcon(QIcon(":/img/img/b5498846b199e90948a50e196277c716.jpg"));
         w->setStyleSheet("background-image:url(:/img/img/c78b9ec7f088f2801b655badc550c2a3.jpg)");
         w->exec();
    }
}

void StudentMainWindow::on_pushButton_17_clicked()
{
    QString ent_id="005";
    QString S=QString("select ent_info,ent_name from ent_info where ent_id='%1'").arg(ent_id);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
         QString ent_detail=query.value(0).toString();
         QString ent_name=query.value(1).toString();
         QDialog *w=new QDialog;
         QTextEdit *text=new QTextEdit(w);
         text->append(ent_detail);
         text->setReadOnly(true);
         text->resize(1000,500);
         text->setFont(QFont(tr("Consolas"), 14));
         QTextCursor cursor = text->textCursor();
         cursor.movePosition(QTextCursor::Start);
         text->setTextCursor(cursor);
         w->setWindowTitle(ent_name);
         w->setWindowIcon(QIcon(":/img/img/b5498846b199e90948a50e196277c716.jpg"));
         w->setStyleSheet("background-image:url(:/img/img/c78b9ec7f088f2801b655badc550c2a3.jpg)");
         w->exec();
    }
}

void StudentMainWindow::on_pushButton_7_clicked()
{
    QString ent_id="006";
    QString S=QString("select ent_info,ent_name from ent_info where ent_id='%1'").arg(ent_id);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
         QString ent_detail=query.value(0).toString();
         QString ent_name=query.value(1).toString();
         QDialog *w=new QDialog;
         QTextEdit *text=new QTextEdit(w);
         text->append(ent_detail);
         text->setReadOnly(true);
         text->resize(1000,500);
         text->setFont(QFont(tr("Consolas"), 14));
         QTextCursor cursor = text->textCursor();
         cursor.movePosition(QTextCursor::Start);
         text->setTextCursor(cursor);
         w->setWindowTitle(ent_name);
         w->setWindowIcon(QIcon(":/img/img/b5498846b199e90948a50e196277c716.jpg"));
         w->setStyleSheet("background-image:url(:/img/img/c78b9ec7f088f2801b655badc550c2a3.jpg)");
         w->exec();
    }
}

void StudentMainWindow::on_pushButton_16_clicked()
{
    QString ent_id="007";
    QString S=QString("select ent_info,ent_name from ent_info where ent_id='%1'").arg(ent_id);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
         QString ent_detail=query.value(0).toString();
         QString ent_name=query.value(1).toString();
         QDialog *w=new QDialog;
         QTextEdit *text=new QTextEdit(w);
         text->append(ent_detail);
         text->setReadOnly(true);
         text->resize(1000,500);
         text->setFont(QFont(tr("Consolas"), 14));
         QTextCursor cursor = text->textCursor();
         cursor.movePosition(QTextCursor::Start);
         text->setTextCursor(cursor);
         w->setWindowTitle(ent_name);
         w->setWindowIcon(QIcon(":/img/img/b5498846b199e90948a50e196277c716.jpg"));
         w->setStyleSheet("background-image:url(:/img/img/c78b9ec7f088f2801b655badc550c2a3.jpg)");
         w->exec();
    }
}

void StudentMainWindow::on_pushButton_8_clicked()
{
    QString ent_id="008";
    QString S=QString("select ent_info,ent_name from ent_info where ent_id='%1'").arg(ent_id);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
         QString ent_detail=query.value(0).toString();
         QString ent_name=query.value(1).toString();
         QDialog *w=new QDialog;
         QTextEdit *text=new QTextEdit(w);
         text->append(ent_detail);
         text->setReadOnly(true);
         text->resize(1000,500);
         text->setFont(QFont(tr("Consolas"), 14));
         QTextCursor cursor = text->textCursor();
         cursor.movePosition(QTextCursor::Start);
         text->setTextCursor(cursor);
         w->setWindowTitle(ent_name);
         w->setWindowIcon(QIcon(":/img/img/b5498846b199e90948a50e196277c716.jpg"));
         w->setStyleSheet("background-image:url(:/img/img/c78b9ec7f088f2801b655badc550c2a3.jpg)");
         w->exec();
    }
}

void StudentMainWindow::on_pushButton_14_clicked()
{
    QString ent_id="009";
    QString S=QString("select ent_info,ent_name from ent_info where ent_id='%1'").arg(ent_id);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
         QString ent_detail=query.value(0).toString();
         QString ent_name=query.value(1).toString();
         QDialog *w=new QDialog;
         QTextEdit *text=new QTextEdit(w);
         text->append(ent_detail);
         text->setReadOnly(true);
         text->resize(1000,500);
         text->setFont(QFont(tr("Consolas"), 14));
         QTextCursor cursor = text->textCursor();
         cursor.movePosition(QTextCursor::Start);
         text->setTextCursor(cursor);
         w->setWindowTitle(ent_name);
         w->setWindowIcon(QIcon(":/img/img/b5498846b199e90948a50e196277c716.jpg"));
         w->setStyleSheet("background-image:url(:/img/img/c78b9ec7f088f2801b655badc550c2a3.jpg)");
         w->exec();
    }
}

void StudentMainWindow::on_pushButton_9_clicked()
{
    QString ent_id="010";
    QString S=QString("select ent_info,ent_name from ent_info where ent_id='%1'").arg(ent_id);
    QSqlQuery query;
    if(query.exec(S)&&query.next())
    {
         QString ent_detail=query.value(0).toString();
         QString ent_name=query.value(1).toString();
         QDialog *w=new QDialog;
         QTextEdit *text=new QTextEdit(w);
         text->append(ent_detail);
         text->setReadOnly(true);
         text->resize(1000,500);
         text->setFont(QFont(tr("Consolas"), 14));
         QTextCursor cursor = text->textCursor();
         cursor.movePosition(QTextCursor::Start);
         text->setTextCursor(cursor);
         w->setWindowTitle(ent_name);
         w->setWindowIcon(QIcon(":/img/img/b5498846b199e90948a50e196277c716.jpg"));
         w->setStyleSheet("background-image:url(:/img/img/c78b9ec7f088f2801b655badc550c2a3.jpg)");
         w->exec();
    }
}

void StudentMainWindow::on_save_pushButton_clicked()
{
    //简历赋值
    stu_id=ui->stunum_lineEdit->text();
    stu_name=ui->name_lineEdit_3->text();
    stu_date=ui->date_dateEdit->text();
    stu_phone=ui->phone_lineEdit->text();
    stu_email=ui->email_lineEdit_15->text();
    if(ui->man_radioButton->isChecked())
    {
        stu_sex=QStringLiteral("男");
    }
    else if(ui->woman_radioButton_2->isChecked())
    {
        stu_sex=QStringLiteral("女");
    }
    stu_idnum=ui->IdNum_lineEdit_3->text();
    stu_state=ui->state_comboBox->currentText();
    stu_startdate=ui->startdate_dateEdit_2->text();
    stu_place=ui->place_lineEdit_14->text();
    stu_school=ui->school_lineEdit_13->text();
    stu_professional=ui->professional_lineEdit_16->text();
    stu_wantjob=ui->wantjob_textEdit->toPlainText();
    stu_honour=ui->honour_textEdit_3->toPlainText();
    stu_education=ui->education_textEdit_5->toPlainText();
    stu_experience=ui->experience_textEdit_2->toPlainText();
    stu_ability=ui->ability_textEdit_4->toPlainText();
    stu_introduction=ui->introduction_textEdit_6->toPlainText();
    stu_break=QStringLiteral("0");
    if(stu_id==NULL|stu_name==NULL|stu_idnum==NULL|stu_phone==NULL|stu_place==NULL|stu_school==NULL|stu_professional==NULL)
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("请填写所有必填项"),QStringLiteral("确定"));
    }
    else
    {
        QString A=QString("select * from stu_resume where stu_id='%1'").arg(stu_id);
        QSqlQuery query1;
        if(query1.exec(A)&&query1.next())
        {
            QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("您的简历已经存在"),QStringLiteral("确定"));
        }
        else
        {
            QString S=QString("INSERT INTO stu_resume (stu_id, stu_name, stu_date, stu_phone, stu_email, stu_sex, stu_idnum, stu_state, stu_startdate, stu_place, stu_school, stu_professional, stu_wantjob, stu_honour, stu_education, stu_experience, stu_ability, stu_introduction, stu_break) "
                              "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13', '%14', '%15', '%16', '%17', '%18', '%19')")
                              .arg(stu_id).arg(stu_name).arg(stu_date).arg(stu_phone).arg(stu_email).arg(stu_sex).arg(stu_idnum).arg(stu_state).arg(stu_startdate).arg(stu_place).arg(stu_school).arg(stu_professional).arg(stu_wantjob).arg(stu_honour).arg(stu_education).arg(stu_experience).arg(stu_ability).arg(stu_introduction).arg(stu_break);
            QSqlQuery query;
            if(query.exec(S))
            {
                QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("保存成功"),QStringLiteral("确定"));
            }
        }
    }
}

void StudentMainWindow::on_delete_pushButton_3_clicked()
{
    DeleteDialog *del=new DeleteDialog;
    del->exec();
}

void StudentMainWindow::on_submit_pushButton_5_clicked()
{
    job_id=ui->id_lineEdit_6->text();
    job_class=ui->class_lineEdit_2->text();
    job_name=ui->name_lineEdit_5->text();
    job_depart=ui->depart_lineEdit_4->text();
    job_graduation=ui->graduation_comboBox_3->currentText();
    job_unitName=ui->unitname_lineEdit_21->text();
    job_code=ui->code_lineEdit_22->text();
    job_unitNature=ui->unitnature_comboBox_4->currentText();
    job_unitIndustry=ui->unitindustry_comboBox_5->currentText();
    job_unitPlace=ui->unitplace_lineEdit_23->text();
    job_position=ui->position_comboBox_6->currentText();
    job_linkman=ui->unitlink_lineEdit_24->text();
    job_linkPhone=ui->linkphone_lineEdit_25->text();
    job_unitPost=ui->unitpost_lineEdit_26->text();
    job_unitLocation=ui->unitlocation_lineEdit_27->text();

    if(job_id==NULL|job_class==NULL|job_name==NULL|job_depart==NULL)
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("请填写所有必填项"),QStringLiteral("确定"));
    }
    else
    {
        QString A=QString("select * from stu_employmentInformation where stu_id='%1'").arg(job_id);
        QSqlQuery query1;
        if(query1.exec(A)&&query1.next())
        {
            QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("您的信息已经提交，请勿重复提交！"),QStringLiteral("确定"));
        }
        else
        {
            QString S=QString("INSERT INTO stu_employmentInformation (stu_id, stu_class, stu_name, stu_department, stu_graduation, stu_unitName, stu_code, stu_unitNature, stu_unitIndustry, stu_unitPlace, stu_position, stu_unitLinkman, stu_linkPhone, stu_unitPostcode, stu_unitLocation) "
                              "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13', '%14', '%15')")
                              .arg(job_id).arg(job_class).arg(job_name).arg(job_depart).arg(job_graduation).arg(job_unitName).arg(job_code).arg(job_unitNature).arg(job_unitIndustry).arg(job_unitPlace).arg(job_position).arg(job_linkman).arg(job_linkPhone).arg(job_unitPost).arg(job_unitLocation);
            QSqlQuery query;
            if(query.exec(S))
            {
                QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("提交成功"),QStringLiteral("确定"));
                ui->submit_pushButton_5->setText(QStringLiteral("已提交！"));
                ui->submit_pushButton_5->setDisabled(true);
            }
        }

    }
}

QString StudentMainWindow::a="000";

QString StudentMainWindow::on_pushButton_19_clicked()
{
    a=QStringLiteral("001");
    QString S=QString("select  ent_info ent_name from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

QString StudentMainWindow::on_pushButton_20_clicked()
{
    a=QStringLiteral("002");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

QString StudentMainWindow::on_pushButton_21_clicked()
{
    a=QStringLiteral("003");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

QString StudentMainWindow::on_pushButton_22_clicked()
{
    a=QStringLiteral("004");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

QString StudentMainWindow::on_pushButton_23_clicked()
{
    a=QStringLiteral("005");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

QString StudentMainWindow::on_pushButton_3_clicked()
{
    a=QStringLiteral("006");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }

    return a;
}

QString StudentMainWindow::on_pushButton_10_clicked()
{
    a=QStringLiteral("007");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

QString StudentMainWindow::on_pushButton_11_clicked()
{
    a=QStringLiteral("008");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }

    return a;
}

QString StudentMainWindow::on_pushButton_12_clicked()
{
    a=QStringLiteral("009");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }

    return a;
}

QString StudentMainWindow::on_pushButton_13_clicked()
{
    a=QStringLiteral("010");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }

    return a;
}

QString StudentMainWindow::on_pushButton_24_clicked()
{
    a=QStringLiteral("011");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

QString StudentMainWindow::on_pushButton_25_clicked()
{
    a=QStringLiteral("012");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

QString StudentMainWindow::on_pushButton_26_clicked()
{
    a=QStringLiteral("013");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

QString StudentMainWindow::on_pushButton_27_clicked()
{
    a=QStringLiteral("014");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }

    return a;
}

QString StudentMainWindow::on_pushButton_28_clicked()
{
    a=QStringLiteral("015");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

QString StudentMainWindow::on_pushButton_4_clicked()
{
    a=QStringLiteral("016");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

QString StudentMainWindow::on_pushButton_29_clicked()
{
    a=QStringLiteral("017");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

QString StudentMainWindow::on_pushButton_30_clicked()
{
    a=QStringLiteral("018");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }

    return a;
}

QString StudentMainWindow::on_pushButton_31_clicked()
{
    a=QStringLiteral("019");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }

    return a;
}

QString StudentMainWindow::on_pushButton_32_clicked()
{
    a=QStringLiteral("020");
    QString S=QString("select ent_info from ent_info where ent_id='%1'").arg(a);
    QSqlQuery query;

    if( query.exec(S)&&query.next())
    {
        QString text = query.value(0).toString();
        SendResumeDialog *send=new SendResumeDialog;
        send->ui->jobDetails_textEdit->setText(text);
        send->exec();
    }
    return a;
}

void StudentMainWindow::on_disres_pushButton_clicked()
{
    //简历查看 tableview
    QString studetId=StudentLoginDialog::st_id;
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
    QSqlTableModel *model1=new QSqlTableModel(this);
    model1->setTable("stu_resume");
    model1->setSort(stu_id1,Qt::AscendingOrder);
    model1->setHeaderData(stu_name1,Qt::Horizontal,QStringLiteral("姓名"));
    model1->setHeaderData(stu_dat1,Qt::Horizontal,QStringLiteral("出生日期"));
    model1->setHeaderData(stu_phone1,Qt::Horizontal,QStringLiteral("电话"));
    model1->setHeaderData(stu_email1,Qt::Horizontal,QStringLiteral("邮箱"));
    model1->setHeaderData(stu_sex1,Qt::Horizontal,QStringLiteral("性别"));
    model1->setHeaderData(stu_idnum1,Qt::Horizontal,QStringLiteral("身份证号"));
    model1->setHeaderData(stu_state1,Qt::Horizontal,QStringLiteral("目前状态"));
    model1->setHeaderData(stu_startdate1,Qt::Horizontal,QStringLiteral("开始工作年份"));
    model1->setHeaderData(stu_place1,Qt::Horizontal,QStringLiteral("居住地"));
    model1->setHeaderData(stu_school1,Qt::Horizontal,QStringLiteral("学校"));
    model1->setHeaderData(stu_professional1,Qt::Horizontal,QStringLiteral("专业"));
    model1->setHeaderData(stu_wantjob1,Qt::Horizontal,QStringLiteral("求职意向"));
    model1->setHeaderData(stu_honour1,Qt::Horizontal,QStringLiteral("在校荣誉"));
    model1->setHeaderData(stu_education1,Qt::Horizontal,QStringLiteral("教育经历"));
    model1->setHeaderData(stu_experience1,Qt::Horizontal,QStringLiteral("工作经验"));
    model1->setHeaderData(stu_ability1,Qt::Horizontal,QStringLiteral("能力介绍"));
    model1->setHeaderData(stu_introduction1,Qt::Horizontal,QStringLiteral("自我介绍"));
    model1->setFilter(QObject::tr(" stu_id = '%1'").arg(studetId));
    model1->select();

    ui->resume_tableView->setModel(model1);
    ui->resume_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    //ui->resume_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->resume_tableView->setColumnHidden(stu_id1,true);
    ui->resume_tableView->setColumnHidden(stu_break,true);
    ui->resume_tableView->resizeColumnsToContents();
    ui->resume_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->resume_tableView->setFont(QFont(tr("Consolas"), 10));
    //ui->resume_tableView->verticalHeader();
    //ui->resume_tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(40,143,218);font:13pt '宋体';color: black;};");

    QHeaderView *header=ui->resume_tableView->verticalHeader();
    header->setFont(QFont(tr("Consolas"), 20,75));
    header->setStretchLastSection(true);

}

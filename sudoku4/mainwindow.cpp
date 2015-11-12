#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QMessageBox>
 QLineEdit *entries[9][9];
int n=9; //size
 int cell[9][9];
int invalid[9][9]={0};
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    entries[0][0]=ui->lineEdit_1;
    entries[0][1]=ui->lineEdit_2;
    entries[0][2]=ui->lineEdit_3;
    entries[0][3]=ui->lineEdit_4;
    entries[0][4]=ui->lineEdit_5;
    entries[0][5]=ui->lineEdit_6;
    entries[0][6]=ui->lineEdit_7;
    entries[0][7]=ui->lineEdit_8;
    entries[0][8]=ui->lineEdit_9;

    entries[1][0]=ui->lineEdit_10;
    entries[1][1]=ui->lineEdit_11;
    entries[1][2]=ui->lineEdit_12;
    entries[1][3]=ui->lineEdit_13;
    entries[1][4]=ui->lineEdit_14;
    entries[1][5]=ui->lineEdit_15;
    entries[1][6]=ui->lineEdit_16;
    entries[1][7]=ui->lineEdit_17;
    entries[1][8]=ui->lineEdit_18;

    entries[2][0]=ui->lineEdit_19;
    entries[2][1]=ui->lineEdit_20;
    entries[2][2]=ui->lineEdit_21;
    entries[2][3]=ui->lineEdit_22;
    entries[2][4]=ui->lineEdit_23;
    entries[2][5]=ui->lineEdit_24;
    entries[2][6]=ui->lineEdit_25;
    entries[2][7]=ui->lineEdit_26;
    entries[2][8]=ui->lineEdit_27;

    entries[3][0]=ui->lineEdit_28;
    entries[3][1]=ui->lineEdit_29;
    entries[3][2]=ui->lineEdit_30;
    entries[3][3]=ui->lineEdit_31;
    entries[3][4]=ui->lineEdit_32;
    entries[3][5]=ui->lineEdit_33;
    entries[3][6]=ui->lineEdit_34;
    entries[3][7]=ui->lineEdit_35;
    entries[3][8]=ui->lineEdit_36;


    entries[4][0]=ui->lineEdit_37;
    entries[4][1]=ui->lineEdit_38;
    entries[4][2]=ui->lineEdit_39;
    entries[4][3]=ui->lineEdit_40;
    entries[4][4]=ui->lineEdit_41;
    entries[4][5]=ui->lineEdit_42;
    entries[4][6]=ui->lineEdit_43;
    entries[4][7]=ui->lineEdit_44;
    entries[4][8]=ui->lineEdit_45;

    entries[5][0]=ui->lineEdit_46;
    entries[5][1]=ui->lineEdit_47;
    entries[5][2]=ui->lineEdit_48;
    entries[5][3]=ui->lineEdit_49;
    entries[5][4]=ui->lineEdit_50;
    entries[5][5]=ui->lineEdit_51;
    entries[5][6]=ui->lineEdit_52;
    entries[5][7]=ui->lineEdit_53;
    entries[5][8]=ui->lineEdit_54;

    entries[6][0]=ui->lineEdit_55;
    entries[6][1]=ui->lineEdit_56;
    entries[6][2]=ui->lineEdit_57;
    entries[6][3]=ui->lineEdit_58;
    entries[6][4]=ui->lineEdit_59;
    entries[6][5]=ui->lineEdit_60;
    entries[6][6]=ui->lineEdit_61;
    entries[6][7]=ui->lineEdit_62;
    entries[6][8]=ui->lineEdit_63;

    entries[7][0]=ui->lineEdit_64;
    entries[7][1]=ui->lineEdit_65;
    entries[7][2]=ui->lineEdit_66;
    entries[7][3]=ui->lineEdit_67;
    entries[7][4]=ui->lineEdit_68;
    entries[7][5]=ui->lineEdit_69;
    entries[7][6]=ui->lineEdit_70;
    entries[7][7]=ui->lineEdit_71;
    entries[7][8]=ui->lineEdit_72;


    entries[8][0]=ui->lineEdit_73;
    entries[8][1]=ui->lineEdit_74;
    entries[8][2]=ui->lineEdit_75;
    entries[8][3]=ui->lineEdit_76;
    entries[8][4]=ui->lineEdit_77;
    entries[8][5]=ui->lineEdit_78;
    entries[8][6]=ui->lineEdit_79;
    entries[8][7]=ui->lineEdit_80;
    entries[8][8]=ui->lineEdit_81;

    int i,j;
    black->setColor(QPalette::Text,Qt::black);
    red->setColor(QPalette::Text,Qt::black);
    yellow->setColor(QPalette::Text,Qt::black);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            entries[i][j]->setMaxLength(1);
            entries[i][j]->setValidator( new QIntValidator(1, 9, this) );
            black->setColor(QPalette::Text,Qt::black);

        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_clicked()
{
    close();
}

void MainWindow::on_reset_clicked()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           entries[i][j]->setText("");
           entries[i][j]->setValidator( new QIntValidator(1, 9, this) );
           entries[i][j]->setPalette(*black);

        }
    }
}

void MainWindow::on_solve_clicked()
{

    int i,j;
    int flag=0;
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        QString str = entries[i][j]->text();
        int number=str.toInt();
        if((number==0)&&(str!=""))
        {
            red->setColor(QPalette::Text,Qt::red);
            entries[i][j]->setPalette(*red);
            flag=1;
            entries[i][j]->setText("");
        }
    }
}

if(flag==1)
{

        QMessageBox *message = new QMessageBox();
        message->setWindowTitle("Error");
        message->setText("Out of range value.");
        message->setStandardButtons(QMessageBox::Ok);
        message->setDefaultButton(QMessageBox::Ok);
        message->setFocus();
        if(message->exec()==QMessageBox::Ok)
        {

        }
}

else
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {

        }
    }
}




}

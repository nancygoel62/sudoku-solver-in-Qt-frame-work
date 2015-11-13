#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QMessageBox>

#define TRUE 1
#define FALSE 0
#define SIZE 9

QLineEdit *entries[9][9];

int n=9; //size
int cell[9][9];
int invalid[9][9]={0};




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #808080;");



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
            entries[i][j]->setAlignment(Qt::AlignHCenter);
            entries[i][j]->setStyleSheet("font-size : 12pt ;font-weight:600;background-color: #fdeef4 ;");
        }
    }

    ui->reset->setStyleSheet("background-color : #FBF6D9;");

    ui->solve->setStyleSheet("background-color : #2B65EC;");

    ui->exit->setStyleSheet("background-color : #FBF6D9;");

}


bool checkSafe(int i, int j, int trialNumber)
{
    if(trialNumber==0) return TRUE;
    if(i>SIZE-1 || j>SIZE-1 || i<0 || j<0) return FALSE;
    //box is the sub-grids in which a number cannot be repeated.
    int boxCol, boxRow;
    boxCol = ((int)j/3)*3;
    boxRow = ((int)i/3)*3;

    //For checking in a box.
    for(int k=boxCol;k<boxCol+3;k++)
    {
        for(int l=boxRow; l<boxRow + 3;l++)
        {
            if(!(i==l && j==k))
            {
                if(cell[l][k]==trialNumber) return FALSE;
            }
        }
    }

    //Checking in jth column.
    for(int l=0;l<SIZE;l++)
    {
        if((i!=l && (cell[l][j]==trialNumber))) return FALSE;
    }

    //Checking in ith row.
    for(int l=0;l<SIZE;l++)
    {
        if((j!=l && (cell[i][l] == trialNumber))) return FALSE;
    }
    return TRUE;
}


bool findUnassigned(int &row, int &col)
{
    for(col=0;col<SIZE;col++)
    {
        for(row=0;row<SIZE;row++)
        {
            if(cell[row][col]==0) {return TRUE;}
        }
    }
    return FALSE;
}

//Main solver function
bool fillSudoku()
{
    int row, col;
    //Check whether grid is filled; if not then return first unassigned value
    if(!findUnassigned(row, col))
    {
        return TRUE;
    }

    //Backtracking is used here.
    int num;
    for(num=1;num<SIZE+1;num++)
    {
            if(checkSafe(row,col,num))
            {
                cell[row][col]=num;
                if(fillSudoku()) return TRUE;
                cell[row][col]=0;
            }
    }
    return FALSE;
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
           cell[i][j]=0;
           entries[i][j]->setStyleSheet("font-size : 12pt ;font-weight:600;background-color: #fdeef4 ;");
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
        if(number==0&&str!="")
        {
            red->setColor(QPalette::Text,Qt::black);
            entries[i][j]->setPalette(*red);
            flag=1;
            entries[i][j]->setText("");
        }
        if(number<=9&&number>=1)
            cell[i][j]=number;
    }
    }

if(flag==1) //any value is out of bound
{

        QMessageBox *message = new QMessageBox();
        message->setWindowTitle("Error");
        message->setText("Out of range value.");
        message->setStandardButtons(QMessageBox::Ok);
        message->setDefaultButton(QMessageBox::Ok);
        message->setFocus();
        if(message->exec()==QMessageBox::Ok)
        {
        black->setColor(QPalette::Text,Qt::black);
        }

black->setColor(QPalette::Text,Qt::black);
flag=0;
}

else // no value is out of bound
{

    int flag2=0; //  for invalid input

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(cell[i][j]!=0)
            {
                if(checkSafe(i,j,cell[i][j]))
                    continue;
                else
                {
                    flag2=1;red->setColor(QPalette::Text,Qt::red);
                    entries[i][j]->setPalette(*red);
                }
            }
        }
    }



    if(flag2==1) //yes there is invalid input
    {

    QMessageBox *message = new QMessageBox();
    message->setWindowTitle("Error");
    message->setText("Invalid input.");
    message->setStandardButtons(QMessageBox::Ok);
    message->setDefaultButton(QMessageBox::Ok);
    message->setFocus();
    if(message->exec()==QMessageBox::Ok)
    {}
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
        cell[i][j]=0;
        black->setColor(QPalette::Text,Qt::black);
        entries[i][j]->setPalette(*black);
        }
    }
    flag=0;
    }
    else
    {

    fillSudoku();

yellow->setColor(QPalette::Text,Qt::blue);
//entries[i][j]->setPalette(*yellow);
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        QString str = entries[i][j]->text();
        int number=str.toInt();
        if(str=="")
        {
            entries[i][j]->setPalette(*yellow);
            entries[i][j]->setText(QString::number(cell[i][j]));
        }
     }
 }


    }

}
}

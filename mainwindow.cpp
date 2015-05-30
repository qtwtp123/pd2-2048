#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<ctime>
#include<Qwidget>
#include<QKeyEvent>
#include<cstdlib>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    setNumber();
    checkgame();
    showwindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::setNumber()
{

    x=rand()%4;
    y=rand()%4;
    int z=rand()%2+1;
    if(game[x][y]==0)
        game[x][y]=2*z;
    else
        setNumber();
}

MainWindow::showwindow()
{
    ui->label_20->setNum(score);
    ui->label_22->setNum(high);

    QString str=QString::number(game[0][0]);
    ui->label->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[0][1]);
    ui->label_2->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[0][2]);
    ui->label_3->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[0][3]);
    ui->label_4->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[1][0]);
    ui->label_5->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[1][1]);
    ui->label_6->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[1][2]);
    ui->label_7->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[1][3]);
    ui->label_8->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[2][0]);
    ui->label_9->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[2][1]);
    ui->label_10->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[2][2]);
    ui->label_11->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[2][3]);
    ui->label_12->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[3][0]);
    ui->label_13->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[3][1]);
    ui->label_14->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[3][2]);
    ui->label_15->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

    str=QString::number(game[3][3]);
    ui->label_16->setPixmap(QPixmap(":/num/NUM/"+str+".png"));

}

void MainWindow::keyPressEvent(QKeyEvent *x)
{

    switch(x->key())
    {
    case Qt::Key_Left:

        count=0;

        for(i=0;i<4;i++)//把中間的0去掉(1)
        {
            check=0;
            for(j=0;j<4;j++)
            {
                if(game[i][j]!=0)
                {
                   trans[i][check]=game[i][j];
                   if(check!=j)
                       count++;
                   check++;
                }
            }
        }

        for(i=0;i<4;i++)//把相同的合起來
        {
            for(j=0;j<4;j++)
            {
                if(j!=3)
                {
                    if(trans[i][j]==trans[i][j+1])
                    {

                        if(trans[i][j]!=0)
                        {
                            trans[i][j]=trans[i][j]+trans[i][j+1];
                            trans[i][j+1]=0;
                            count=count+1;
                        }

                    }

                }
            }
        }

        for(i=0;i<4;i++)//回傳
        {
            for(j=0;j<4;j++)
            {
                   game[i][j]=trans[i][j];
            }
        }

        for(i=0;i<4;i++)//歸零
        {
            for(j=0;j<4;j++)
            {
                   trans[i][j]=0;
            }
        }

        for(i=0;i<4;i++)//把中間的0去掉(2)
        {
            check=0;
            for(j=0;j<4;j++)
            {
                if(game[i][j]!=0)
                {
                   trans[i][check]=game[i][j];
                   check++;
                }
            }
        }

        for(i=0;i<4;i++)//回傳
        {
            for(j=0;j<4;j++)
            {
                   game[i][j]=trans[i][j];
            }
        }

        for(i=0;i<4;i++)//歸零
        {
            for(j=0;j<4;j++)
            {
                   trans[i][j]=0;
            }
        }

        if(count!=0)
            setNumber();

        checkgame();

        showwindow();

        break;

    case Qt::Key_Right:

        count=0;

        for(i=0;i<4;i++)//把中間的0去掉(1)
        {
            check=3;
            for(j=3;j>-1;j--)
            {
                if(game[i][j]!=0)
                {
                   trans[i][check]=game[i][j];
                   if(check!=j)
                       count++;
                   check--;
                }
            }
        }

        for(i=0;i<4;i++)//把相同的合起來
        {
            for(j=3;j>-1;j--)
            {

                if(j!=0)
                {
                    if(trans[i][j]==trans[i][j-1])
                    {

                        if(trans[i][j]!=0)
                        {
                            trans[i][j]=trans[i][j]+trans[i][j-1];
                            trans[i][j-1]=0;
                            count=count+1;
                        }

                    }
                }
            }
        }

        for(i=0;i<4;i++)//回傳
        {
            for(j=0;j<4;j++)
            {
                   game[i][j]=trans[i][j];
            }
        }

        for(i=0;i<4;i++)//歸零
        {
            for(j=0;j<4;j++)
            {
                   trans[i][j]=0;
            }
        }

        for(i=0;i<4;i++)//把中間的0去掉(2)
        {
            check=3;
            for(j=3;j>-1;j--)
            {
                if(game[i][j]!=0)
                {
                   trans[i][check]=game[i][j];
                   check--;
                }
            }
        }

        for(i=0;i<4;i++)//回傳
        {
            for(j=0;j<4;j++)
            {
                   game[i][j]=trans[i][j];
            }
        }

        for(i=0;i<4;i++)//歸零
        {
            for(j=0;j<4;j++)
            {
                   trans[i][j]=0;
            }
        }

        if(count!=0)
            setNumber();

        checkgame();

        showwindow();

        break;

    case Qt::Key_Up:

        count=0;

        for(j=0;j<4;j++)//把中間的0去掉(1)
        {
            check=0;
            for(i=0;i<4;i++)
            {
                if(game[i][j]!=0)
                {
                    trans[check][j]=game[i][j];
                    if(check!=i)
                        count++;
                    check++;
                }
            }
        }

        for(j=0;j<4;j++)//把相同的合起來
        {
            for(i=0;i<4;i++)
            {
                if(i!=3)
                {

                    if(trans[i][j]==trans[i+1][j])
                    {
                        if(trans[i][j]!=0)
                        {
                            trans[i][j]=trans[i][j]+trans[i+1][j];
                            trans[i+1][j]=0;
                            count++;
                        }
                    }

                }
            }
        }

        for(i=0;i<4;i++)//回傳
        {
            for(j=0;j<4;j++)
            {
                   game[i][j]=trans[i][j];
            }
        }

        for(i=0;i<4;i++)//歸零
        {
            for(j=0;j<4;j++)
            {
                   trans[i][j]=0;
            }
        }

        for(j=0;j<4;j++)//把中間的0去掉(2)
        {
            check=0;
            for(i=0;i<4;i++)
            {
                if(game[i][j]!=0)
                {
                    trans[check][j]=game[i][j];
                    check++;
                }
            }
        }

        for(i=0;i<4;i++)//回傳
        {
            for(j=0;j<4;j++)
            {
                   game[i][j]=trans[i][j];
            }
        }

        for(i=0;i<4;i++)//歸零
        {
            for(j=0;j<4;j++)
            {
                   trans[i][j]=0;
            }
        }


        if(count!=0)
            setNumber();

        checkgame();

        showwindow();

        break;

    case Qt::Key_Down:

        count=0;

        for(j=0;j<4;j++)//把中間的0去掉(1)
        {
            check=3;
            for(i=3;i>-1;i--)
            {
                if(game[i][j]!=0)
                {
                   trans[check][j]=game[i][j];
                   if(check!=i)
                       count++;
                   check--;
                }
            }
        }

        for(j=0;j<4;j++)//把相同的合起來
        {
            for(i=3;i>-1;i--)
            {
                if(i!=0)
                {
                    if(trans[i][j]==trans[i-1][j])
                    {
                        if(trans[i][j]!=0)
                        {
                            trans[i][j]=trans[i][j]+trans[i-1][j];
                            trans[i-1][j]=0;
                            count++;
                        }
                    }


                }
            }
        }

        for(i=0;i<4;i++)//回傳
        {
            for(j=0;j<4;j++)
            {
                   game[i][j]=trans[i][j];
            }
        }

        for(i=0;i<4;i++)//歸零
        {
            for(j=0;j<4;j++)
            {
                   trans[i][j]=0;
            }
        }

        for(j=0;j<4;j++)//把中間的0去掉(2)
        {
            check=3;
            for(i=3;i>-1;i--)
            {
                if(game[i][j]!=0)
                {
                   trans[check][j]=game[i][j];
                   check--;
                }
            }
        }

        for(i=0;i<4;i++)//回傳
        {
            for(j=0;j<4;j++)
            {
                   game[i][j]=trans[i][j];
            }
        }

        for(i=0;i<4;i++)//歸零
        {
            for(j=0;j<4;j++)
            {
                   trans[i][j]=0;
            }
        }


        if(count!=0)
            setNumber();

        checkgame();

        showwindow();

        break;

    }


}

int MainWindow::checkgame()
{
    sum=0;

    count=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(game[i][j]==game[i][j+1])
                count++;
        }
    }
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            if(game[i][j]==game[i+1][j])
                count++;
        }
    }
    for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                   if(game[i][j]==0)
                    sum++;
                   if(game[i][j]==2048)
                   {

                       for(x=0;x<4;x++)
                       {
                           for(y=0;y<4;y++)
                           {
                               game[x][y]=0;
                           }
                       }
                       ui->label_18->setPixmap(QPixmap(":/NUM/win.png"));
                   }

                }
            }
    if(sum==0&&count==0)
    {
        for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                       game[i][j]=0;

                    }
                }
        ui->label_18->setPixmap(QPixmap(":/NUM/gameover.png"));
    }
    else
    {
        sum=0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
               sum+=game[i][j];

            }
        }
        score=sum;
        if(score>high)
            high=score;
    }

}



void MainWindow::on_pushButton_clicked()
{
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            game[i][j]=0;
        }
    }
    ui->label_18->setPixmap(QPixmap(""));
    setNumber();
    checkgame();
    showwindow();

}

void MainWindow::on_pushButton_2_clicked()
{
    exit(1);
}

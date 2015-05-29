#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<time.h>
#include<Qwidget>
#include<cstdlib>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int setNumber();
    int showwindow();
    void keyPressEvent(QKeyEvent *);
    int checkgame();




private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int game[4][4]={{0}};
    int trans[4][4]={{0}};
    int check;
    int x,y;
    int i,j;
    int count;
    int sum=0;
    int score=0;
    int high=0;
    QString str;

};

#endif // MAINWINDOW_H

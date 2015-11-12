#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLineEdit>
#include<QStackedWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);

    QPalette *black = new QPalette();
    QPalette *red = new QPalette();
    QPalette *yellow = new QPalette();


    ~MainWindow();

private slots:
    void on_exit_clicked();

    void on_reset_clicked();

    void on_solve_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

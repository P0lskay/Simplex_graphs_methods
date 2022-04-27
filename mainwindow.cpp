#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Лабораторная работа по методам оптимизации");

    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_variables_num_valueChanged(int arg1)
{
    if(arg1 != variables_num)
    {
        variables_num = arg1;
    }
}

void MainWindow::change_restriction_matrix()
{
    restriction_matrix.resize(restriction_num);
    for(auto& vec : restriction_matrix)
    {
        vec.resize(variables_num+1);
    }
}

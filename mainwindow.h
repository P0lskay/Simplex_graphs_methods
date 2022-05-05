#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QMessageBox>
#include<QDebug>
#include "simplex.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Simplex simplex= *new Simplex();

private slots:
    //При изменении кол-ва переменных или ограничений нужно поменять соответсвующие переменные и
    //Изменить кол-во строк/столбцов в таблице ввода
    void on_variables_num_valueChanged(int arg1);
    void on_restrictions_num_valueChanged(int arg1);

    //При нажатии на кнпоку нужно отправить данные на обработку в класс Симплекс метода
    void on_btn_send_into_data_released();

private:
    //Переменные хранящие кол-во ограничений и переменных
    int restriction_num = 0;
    int variables_num = 0;
    //Координаты в таблице симплекс метода
    int x = 0;
    int y = 0;
    //Вектора, хранящие значения переменных для основной задачи и для ограничений соответсвенно
    //Они будут отправляться в класс с симплекс методом и графическим методом
    std::vector<int> main_task;
    std::vector<std::vector<int>> restrictions_matrix;
    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H

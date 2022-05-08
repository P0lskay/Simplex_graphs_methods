#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <QMessageBox>
#include <QDebug>
#include <algorithm>
#include <QColor>
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
    Simplex simplex= *new Simplex();\


private slots:
    //При изменении кол-ва переменных или ограничений нужно поменять соответсвующие переменные и
    //Изменить кол-во строк/столбцов в таблице ввода
    void on_variables_num_valueChanged(int arg1);
    void on_restrictions_num_valueChanged(int arg1);

    //При нажатии на кнпоку нужно отправить данные на обработку в класс Симплекс метода
    void on_btn_send_into_data_released();

    void on_simplex_first_table_cellDoubleClicked(int row, int column);

    void on_btn_next_simplex_first_released();

    void on_btn_last_simplex_first_released();

private:
    bool common_fractions;
    int num_iter = 0; //Номер итерации вспомогательной задачи
    //Переменные хранящие кол-во ограничений и переменных
    int restriction_num = 0;
    int variables_num = 0;
    //Координаты в таблице симплекс метода
    int x = 0;
    int y = 0;
    //Вектора, хранящие заголовки матриц
    vector<string> current_matrix_row;
    vector<string> current_matrix_column;
    //Текущий базис
    pair<int, int> current_basis;
    //Вектора, хранящие значения переменных для основной задачи и для ограничений соответсвенно
    //Они будут отправляться в класс с симплекс методом и графическим методом
    vector<int> main_task;
    vector<vector<int>> restrictions_matrix;

    //Выделяет базис в координатах row, column
    void select_basis(int row, int column);
    //Вывод заголовка текущей матрицы для вспомогательной задачи
    void cout_matrix_header_first_table() const;

    void check_simplex_end();

    void start_simplex();

    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H

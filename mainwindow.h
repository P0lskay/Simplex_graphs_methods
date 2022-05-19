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
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


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

    void on_btn_next_simplex_second_released();

    void on_simplex_second_table_cellDoubleClicked(int row, int column);

private:
    Simplex simplex= *new Simplex();
    Graph graph = *new Graph();
    bool common_fractions;
    int num_iter = 0; //Номер итерации вспомогательной задачи
    int num_iter_main = 0; //Номер итерации исходной задачи
    //Переменные хранящие кол-во ограничений и переменных
    int restriction_num = 0;
    int variables_num = 0;
    //Координаты в таблице искусственного симплекс метода
    int x = 0;
    int y = 0;

    //Координаты в таблице симплекс метода
    int x1 = 0;
    int y1 = 0;

    //Вектора, хранящие заголовки матриц
    vector<int> current_matrix_row;
    vector<int> current_matrix_column;
    //Текущий базис
    pair<int, int> current_basis;
    //Вектора, хранящие значения переменных для основной задачи и для ограничений соответсвенно
    //Они будут отправляться в класс с симплекс методом и графическим методом
    vector<Fractions> main_task;
    vector<Fractions> graph_main_task;
    vector<vector<int>> restrictions_matrix;

    //Выделяет базис в координатах row, column
    void select_basis(int row, int column);
    void select_basis_main(int row, int column);
    //Вывод заголовка текущей матрицы для вспомогательной задачи
    void cout_matrix_header_first_table() const;
    void cout_matrix_header_second_table() const;
    //Построение матрицы для исходной задачи
    void start_main_task();

    bool check_simplex_end();
    //Метод, проверяющий, нужно ли решать задачу
    bool check_simplex_error();
    //Метод обновляющий главную задачу после решения вспомогательной задачи
    void refrsh_main_task();
    void refresh_graph_main_task(vector<vector<Fractions>> vec);

    void start_simplex();

    void full_vec_var(vector<Fractions>& vec);

    //Метод отвечающий за начало вычислений графическим методом
    void start_graph_method();


    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H

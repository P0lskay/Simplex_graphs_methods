#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <vector>
#include <stack>
#include <algorithm>
#include "fractions.h"
#include <string>
using namespace std;

struct Simplex_matrix
{
    explicit Simplex_matrix(vector<vector<int>>& matrix, bool comon_fractions = true);
    explicit Simplex_matrix(vector<vector<Fractions>> matrix, bool comon_fractions = true);
    Fractions translate_int_to_Fractions(const int x, const int y = 1);

public:
    const vector<vector<Fractions> > &getRestirctions_matrix() const;

private:
    vector<vector<Fractions>> restirctions_matrix;
};


class Simplex
{
    stack<Simplex_matrix> all_matrix;
    vector<Fractions> task_vec;
    //хранятся свободные переменные и свободные удаленные.
    //где свободная переменная - Xk, где k = m+i.
    vector<int> free_var;
    stack<int> deleted_free_var;
    bool min_task;
    bool common_fractions;
public:
    //Создав объект Симплекс, мы создаем первую матрицу задачи в классе Simplex_matrix
    //Там матрица переходит в формат обыкновенных дробей
    Simplex();
    explicit Simplex(vector<vector<int>> matrix, bool min_task = true, bool comon_fractions = true);
    //Возвращает вектор всех возможных базисов свободных переменных для последней матрицы в стеке
    vector<pair<int, int>> possible_basis_free();
    //Возвращает вектор всех возможных базисов для последней матрицы в стеке
    vector<pair<int, int>> possible_basis();
    vector<vector<Fractions>> getLast_matrix();
    int getSizeMatrixStack() const;
    void next_simplex_matrix_free(int x, int y);
    void next_simplex_matrix(int x, int y);

    void start_main_matrix(vector<Fractions> task, Fractions free_k);

    void del_last_matrix();
    void del_last_matrix_main();

    size_t getFreeVarSize() const;
};

#endif // SIMPLEX_H

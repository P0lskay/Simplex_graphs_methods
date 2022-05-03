#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <vector>
#include <stack>
#include "fractions.h"

using namespace std;

struct Simplex_matrix
{
    explicit Simplex_matrix(vector<vector<int>>& matrix, bool comon_fractions = true);
    Fractions translate_int_to_Fractions(const int x, const int y = 1);
private:
    vector<vector<Fractions>> restirctions_matrix;
};


class Simplex
{
    stack<Simplex_matrix> all_matrix;
    vector<Fractions> task_vec;
    bool min_task;
    bool common_fractions;
public:
    //Создав объект Симплекс, мы создаем первую матрицу задачи в классе Simplex_matrix
    //Там матрица переходит в формат обыкновенных дробей
    explicit Simplex(vector<vector<int>> matrix, vector<int> task, bool min_task = true, bool comon_fractions = true);
    //Возвращает вектор всех возможных базисов для последней матрицы в стеке
    vector<pair<int, int>> possible_basis();

    void next_simpex_matrix(int x, int y);
};

#endif // SIMPLEX_H

#include "simplex.h"
#include "fractions.h"

Simplex::Simplex(vector<vector<int>> matrix, vector<int> task, bool min_task, bool comon_fractions)
{
    Simplex_matrix first_matrix(matrix, comon_fractions);
    this->common_fractions = comon_fractions;
    this->min_task = min_task;
    all_matrix.push(first_matrix);
}

vector<pair<int, int>> Simplex::possible_basis()
{
    vector<pair<int, int>> result;

    //Получаем последнюю матрицу, с которой и будем работать
    vector<vector<Fractions>> last_matrix = all_matrix.top().getRestirctions_matrix();

    int index_last_row = last_matrix.size()-1;
    //Перебираем все колонки в поисках отрицательного элемента на последней строке
    for(int i = 0; i < last_matrix[index_last_row].size()-1; i++)
    {
        if(last_matrix[index_last_row][i] < 0)
        {
            //Собираем все Bi/Xi текущего столбца и находим там неотрицательный минимум
            vector<Fractions> this_column;
            for(int j = 0; j < index_last_row; j++)
            {
                if(last_matrix[j][i] > 0)
                    this_column.push_back(last_matrix[j][last_matrix[j].size()-1]/last_matrix[j][i]);
            }
            if(this_column.size()>0)
            {
                auto min_elem = *min_element(this_column.begin(), this_column.end());
                //Теперь добавляем все координаты, элементы которых равны минимуму
                for(int j = 0; j < index_last_row; j++)
                {
                    if(last_matrix[j][last_matrix[j].size()-1]/last_matrix[j][i] == min_elem)
                        result.push_back({j, i});
                }
            }
        }
    }
    return result;
}

void Simplex::next_simplex_matrix(int x, int y)
{
    //Получаем последнюю матрицу, с которой и будем работать
    Simplex_matrix last_matrix = all_matrix.top();

}


Simplex_matrix::Simplex_matrix(vector<vector<int>>& matrix, bool comon_fractions)
{
    //Сначала переводим всю матрицу в новую таблицу
    for(int i = 0; i < matrix.size(); i++)
    {
        restirctions_matrix.push_back({});
        for(int j = 0; j < matrix[i].size(); j++)
        {
            //если b < 0, то умножаем все неравенство на -1
            if(matrix[i][matrix[i].size()-1] >= 0)
                restirctions_matrix[i].push_back(translate_int_to_Fractions(matrix[i][j]));
            else
                restirctions_matrix[i].push_back(translate_int_to_Fractions((-1)*matrix[i][j]));
        }
    }
    //в новой таблице добавляем строку с инвертированной суммой каждого столбца
    restirctions_matrix.push_back({});
    for(int i = 0; i < restirctions_matrix[0].size(); i++)
    {
        Fractions sum(0, 1);
        for(int j = 0; j < restirctions_matrix.size()-1; j++)
        {
            sum = sum - restirctions_matrix[j][i];
        }
        restirctions_matrix[restirctions_matrix.size()-1].push_back(sum);
    }
}

Fractions Simplex_matrix::translate_int_to_Fractions(const int x, const int y)
{
    return Fractions(x, y);
}

const vector<vector<Fractions> > &Simplex_matrix::getRestirctions_matrix() const
{
    return restirctions_matrix;
}

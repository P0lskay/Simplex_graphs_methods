#include "graph.h"

Graph::Graph()
{

}

Graph::Graph(vector<vector<int> > matrix, bool min_task, bool comon_fractions)
{
    //Сначала нужно заполнить хранилище ограничений
    //Затем нужно провести метод Гаусса
    //Затем получит полученные уравнения с 2-мя переменными
    (new Fractions(1))->setCommon_fractions(comon_fractions);
    restrictions.resize(matrix.size());
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            restrictions[i].push_back(Fractions(matrix[i][j]));
        }
    }
    if(matrix.size() > 0 && matrix[0].size() > 3)
    {
        this->Gauss();
    }
    else
        task_is_true = false;
}

bool Graph::getTask_is_true() const
{
    return task_is_true;
}

const vector<vector<Fractions> > &Graph::getRestrictions() const
{
    return restrictions;
}

void Graph::Gauss()
{
    for(int row = 0; row < restrictions.size(); row++)
    {
        int max_elem_column = NULL;

        for(int i = row; i < restrictions.size(); i++)
        {
            if(max_elem_column == NULL ||restrictions[max_elem_column][row].absFraction() < restrictions[i][row].absFraction())
                max_elem_column = i;
        }
        if(max_elem_column == NULL)
        {
            task_is_true = false;
            break;
        }

        if (max_elem_column != row)
        {
            swap(restrictions[max_elem_column], restrictions[row]);
        }
        for (auto& a : restrictions[row])
            {
                a = a / restrictions[row][row];
            }
        for (int j = row + 1; j < restrictions.size(); j++)
        {
            for (int i = 0; i < restrictions[row].size(); i++)
                {
                    Fractions t = Fractions(-1) * restrictions[j][row];
                    restrictions[j][i] = restrictions[row][i]  * t + restrictions[j][i];
                }
        }

    }
}



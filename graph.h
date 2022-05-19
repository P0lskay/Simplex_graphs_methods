#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <map>
#include "fractions.h"

class Graph
{
public:
    Graph();
    explicit Graph(vector<vector<int>> matrix, bool min_task = true, bool comon_fractions = true);

    //Проверка на корректность уравнений
    bool getTask_is_true() const;

private:
    vector<vector<Fractions>> restrictions;
    bool task_is_true = true;

    void Gauss();
};

#endif // GRAPH_H

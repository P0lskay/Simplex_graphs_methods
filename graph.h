#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <map>
#include "pointgraph.h"
#include "fractions.h"

class Graph
{
public:
    Graph();
    explicit Graph(vector<vector<int>> matrix, bool min_task = true, bool comon_fractions = true);

    //Проверка на корректность уравнений
    bool getTask_is_true() const;

    const vector<vector<Fractions> > &getRestrictions() const;

    const vector<PointGraph> &getNice_points() const;

    int getMaxX() const;

    int getMaxY() const;

    int getMinX() const;

    int getMinY() const;

private:
    vector<vector<Fractions>> restrictions;
    vector<vector<Fractions>> equations;
    vector<PointGraph> nice_points;
    int maxX;
    int maxY;
    int minX;
    int minY;

    bool task_is_true = true;
    //Метод гаусса
    void Gauss();

    //Генерация уравнений из матрицы
    void generate_equaions();

    void generate_points();
};

#endif // GRAPH_H

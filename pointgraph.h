#ifndef POINTGRAPH_H
#define POINTGRAPH_H
#include <vector>
#include <utility>
#include "fractions.h"

//Данный класс отвечает за точку, у каждой точки есть:
//2 соседние точки, либо 1 точка и NULL, а так же 2 уравнения, на пересечении которых стоит точка
//Точки можно сравнивать на принадлежность уравнению
class PointGraph
{
public:
    PointGraph();
    PointGraph(Fractions x, Fractions y, vector<Fractions> equation1, vector<Fractions> equation2);

    Fractions getX() const;
    Fractions getY() const;

    PointGraph *getFirst_neighbour() const;
    void setFirst_neighbour(PointGraph *newFirst_neighbour);

    PointGraph *getSecond_neigbour() const;
    void setSecond_neigbour(PointGraph *newSecond_neigbour);

    const vector<Fractions> &getFirst_equation() const;

    const vector<Fractions> &getSecond_equation() const;

private:
    pair<Fractions*, Fractions*> point;
    PointGraph* first_neighbour = NULL;
    PointGraph* second_neigbour = NULL;
    vector<Fractions> first_equation;
    vector<Fractions> second_equation;
};

#endif // POINTGRAPH_H

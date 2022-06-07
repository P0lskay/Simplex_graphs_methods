#include "pointgraph.h"


PointGraph::PointGraph()
{

}

PointGraph::PointGraph(Fractions x, Fractions y, vector<Fractions> equation1, vector<Fractions> equation2)
{
    point = {x, y};
    first_equation = equation1;
    second_equation = equation2;
}

Fractions PointGraph::getX() const
{
    return point.first;
}

Fractions PointGraph::getY() const
{
    return point.second;
}

PointGraph *PointGraph::getFirst_neighbour() const
{
    return first_neighbour;
}

void PointGraph::setFirst_neighbour(PointGraph *newFirst_neighbour)
{
    first_neighbour = newFirst_neighbour;
}

PointGraph *PointGraph::getSecond_neigbour() const
{
    return second_neigbour;
}

void PointGraph::setSecond_neigbour(PointGraph *newSecond_neigbour)
{
    second_neigbour = newSecond_neigbour;
}

const vector<Fractions> &PointGraph::getFirst_equation() const
{
    return first_equation;
}

const vector<Fractions> &PointGraph::getSecond_equation() const
{
    return second_equation;
}

bool PointGraph::operator <(const PointGraph &pg) const
{
    return this->getX() < pg.getX() || (this->getX() == pg.getX() && pg.getY() < this->getY());
}

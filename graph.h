#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <map>
#include <set>
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

    const set<PointGraph> &getNice_points() const;

    int getMaxX() const;

    int getMaxY() const;

    int getMinX() const;

    int getMinY() const;

    bool getUp_restrictions() const;

    bool getRight_restrictions() const;

    const vector<pair<PointGraph, PointGraph> > &getMain_points() const;

private:
    vector<vector<Fractions>> restrictions;
    vector<vector<Fractions>> equations;
    set<PointGraph> nice_points;
    vector<pair<PointGraph, PointGraph>> main_points;
    int maxX;
    int maxY;
    int minX;
    int minY;

    bool up_restrictions = false;
    bool right_restrictions = false;

    void generate_main_points();
    void generate_points();
};

#endif // GRAPH_H

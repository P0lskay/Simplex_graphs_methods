#include "graph.h"
#include <QDebug>
Graph::Graph()
{

}

Graph::Graph(vector<vector<int> > matrix, bool min_task, bool comon_fractions)
{
    for(auto i : matrix)
    {
        if(i[0] != 0 && i[1] == 0)
            right_restrictions = true;
        if(i[0] == 0 && i[1] != 0)
            up_restrictions = true;
        if(i[0] > 0 && i[2] > 0)
            round_x_restrictions = true;
        if(i[1] > 0 && i[2] > 0)
            round_y_restrictions = true;
    }

    //Сначала нужно заполнить хранилище ограничений
    (new Fractions(1))->setCommon_fractions(comon_fractions);
    restrictions.resize(matrix.size());
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            restrictions[i].push_back(Fractions(matrix[i][j]));
        }
    }
    equations = restrictions;
    equations.push_back({Fractions(0), Fractions(1), Fractions(0)});
    equations.push_back({Fractions(1), Fractions(0), Fractions(0)});
    this->generate_main_points();
    this->generate_points();
}



const vector<vector<Fractions> > &Graph::getRestrictions() const
{
    return restrictions;
}

const set<PointGraph> &Graph::getNice_points() const
{
    return nice_points;
}

int Graph::getMaxX() const
{
    return maxX;
}

int Graph::getMaxY() const
{
    return maxY;
}

int Graph::getMinX() const
{
    return minX;
}

int Graph::getMinY() const
{
    return minY;
}

bool Graph::getUp_restrictions() const
{
    return up_restrictions;
}

bool Graph::getRight_restrictions() const
{
    return right_restrictions;
}

bool Graph::getRound_restrictions() const
{
    return round_x_restrictions && round_y_restrictions;
}

const vector<pair<PointGraph, PointGraph> > &Graph::getMain_points() const
{
    return main_points;
}

void Graph::generate_main_points()
{
    vector<Fractions> ordinate = {Fractions(0), Fractions(1), Fractions(0)};
    vector<Fractions> abcisse = {Fractions(1), Fractions(0), Fractions(0)};
    for(auto i : restrictions)
    {
        if(i[0] == Fractions(0) && i[1] == Fractions(0))
            throw exception("Одно из ограничений нулевое");
        else if(i[0] == Fractions(0))
        {
            main_points.push_back({PointGraph(Fractions(-200), i[2]/i[1], ordinate, i), PointGraph(Fractions(200), i[2]/i[1], ordinate, i)});
        }
        else if(i[1] == Fractions(0))
        {
            main_points.push_back({PointGraph(i[2]/i[0], Fractions(-200), abcisse, i), PointGraph(i[2]/i[0], Fractions(200), abcisse, i)});
        }
        else
        {
            Fractions x1 = Fractions(-100) * i[0];
            Fractions y1 = Fractions(-100) * i[1];
            Fractions y2 = Fractions(100) * i[1];
            if((i[2]-x1)/i[1] < Fractions(0))
                main_points.push_back({PointGraph(Fractions(-100), (i[2]-x1)/i[1], ordinate, i), PointGraph((i[2]-y2)/i[0], Fractions(100),  abcisse, i)});
            else
                main_points.push_back({PointGraph(Fractions(-100), (i[2]-x1)/i[1], ordinate, i), PointGraph((i[2]-y1)/i[0], Fractions(-100),  abcisse, i)});
        }
    }
}


void Graph::generate_points()
{

    vector<PointGraph> all_points;
    for(int i = 0; i < equations.size(); i++)
    {
        for(int j = 0; j < equations.size(); j++)
        {
            PointGraph newPoint;
            if(i != j && ((Fractions(0) != equations[j][1] && Fractions(0) != equations[j][0] && !((equations[i][0]/equations[j][0]) ==  (equations[i][1]/equations[j][1]))) ||
                    (((Fractions(0) != equations[j][0]) || (Fractions(0) == equations[j][0] && Fractions(0) != equations[i][0])) &&
                          ((Fractions(0) != equations[j][1]) || (Fractions(0) == equations[j][1] && Fractions(0) != equations[i][1])))) &&
                    !(Fractions(0) == equations[i][0] && Fractions(0) == equations[i][1]) && !(Fractions(0) == equations[j][0] && Fractions(0) == equations[j][1]))
            {
                if(Fractions(0) == equations[i][0] && Fractions(0) == equations[j][1] )
                {
                    newPoint = PointGraph( equations[j][2] /equations[j][0],  equations[i][2]/equations[i][1], equations[i], equations[j]);
                }
                else if(Fractions(0) == equations[i][1] && Fractions(0) == equations[j][0] )
                {
                    newPoint = PointGraph(equations[i][2] /equations[i][0], equations[j][2] /equations[j][1], equations[i], equations[j]);
                }
                else if(Fractions(0) == equations[i][0])
                {
                    Fractions y = (equations[i][2])/equations[i][1];
                    Fractions x =  equations[j][2];
                    Fractions t = y * equations[j][1];
                    x = x - t;
                    x = x/equations[j][0];
                    newPoint = PointGraph(x, y, equations[i], equations[j]);
                }
                else if (Fractions(0) == equations[i][1])
                {
                    Fractions x = equations[i][2]/equations[i][0];
                    Fractions y = equations[j][2];
                    Fractions t = x * equations[j][0];
                    y = y - t;
                    y = y / equations[j][1];
                    newPoint = PointGraph(x, y, equations[i], equations[j]);
                }
                else if(Fractions(0) == equations[j][0])
                {
                    Fractions y = (equations[j][2])/equations[j][1];
                    Fractions x =  equations[i][2];
                    Fractions t = y * equations[i][1];
                    x = x - t;
                    x = x/equations[i][0];
                    newPoint = PointGraph(x, y, equations[i], equations[j]);
                }
                else if (Fractions(0) == equations[j][1])
                {
                    Fractions x = equations[j][2]/equations[j][0];
                    Fractions y = equations[i][2];
                    Fractions t = x * equations[i][0];
                    y = y - t;
                    y = y / equations[i][1];
                    newPoint = PointGraph(x, y, equations[i], equations[j]);
                }
                else
                {
                    Fractions det = equations[i][1] * equations[j][0];
                    det = equations[i][0] * equations[j][1] - det;

                    Fractions x = equations[i][1] * equations[j][2];
                    x = equations[i][2] * equations[j][1] - x;
                    x = x / det;

                    Fractions y = equations[i][2] * equations[j][0];
                    y = equations[i][0] * equations[j][2] - y;
                    y = y / det;

                    newPoint = PointGraph(x, y, equations[i], equations[j]);
                }
                 qDebug() << QString::fromStdString((string) newPoint.getX()) << " " << QString::fromStdString((string) newPoint.getY());
                all_points.push_back(newPoint);
            }

        }
    }

    qDebug() << all_points.size();
    //Нужно проверить, что точка удовлетворяет всем неравенствам
    for(auto point : all_points)
    {
        bool nice_point = true;

        qDebug() << equations.size();
        for(auto equation : equations)
        {

            //qDebug() << QString::fromStdString((string) equation[0]) << " " << QString::fromStdString((string) equation[1]) << " " << QString::fromStdString((string) equation[2]);
            //qDebug() << QString::fromStdString((string) point.getX()) << " " << QString::fromStdString((string) point.getY());
            //Получаем сначала значение x и y затем складываем их со свободным членом
            //Если результат меньше 0, значит точка не удовлетворяет одному из неравенств
            Fractions x = point.getX() * equation[0];
            Fractions y = point.getY() * equation[1];
            if(!(equation[0] == Fractions(1) && equation[1]== Fractions(0) && equation[2] == Fractions(0)) &&
                    !(equation[0] == Fractions(0) && equation[1]== Fractions(1) && equation[2] == Fractions(0)))
            {
                y = Fractions(-1) * y;
                x = Fractions(-1) * x;
            }
            Fractions t = x + y + equation[2]; //ЗДЕСЬ ПРОБЛЕМА
            if(t < Fractions(0))
            {
                nice_point = false;
            }
        }

        if(nice_point)
        {
            nice_points.insert(point);
            if(nice_points.size() == 1) //Если в векторе только одна точка, значит у нас может быть только 1 минимум и максимум
            {
                maxX = point.getX().getFraction().first /point.getX().getFraction().second;
                minX = maxX;

                maxY = point.getY().getFraction().first / point.getY().getFraction().second;
                minY = maxY;
            }
            else
            {
                if(point.getX().getFraction().first / point.getX().getFraction().second > maxX)
                    maxX = point.getX().getFraction().first / point.getX().getFraction().second;

                if(point.getX().getFraction().first / point.getX().getFraction().second < minX)
                    minX = point.getX().getFraction().first / point.getX().getFraction().second;

                if(point.getY().getFraction().first / point.getY().getFraction().second > maxY)
                    maxY = point.getY().getFraction().first / point.getY().getFraction().second;

                if(point.getY().getFraction().first / point.getY().getFraction().second < minY)
                    minY = point.getY().getFraction().first / point.getY().getFraction().second;
            }
        }
    }

}



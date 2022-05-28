//#include "graph.h"
//#include <QDebug>
//Graph::Graph()
//{

//}

//Graph::Graph(vector<vector<int> > matrix, bool min_task, bool comon_fractions)
//{
//    //Сначала нужно заполнить хранилище ограничений
//    //Затем нужно провести метод Гаусса
//    //Затем получит полученные уравнения с 2-мя переменными
//    (new Fractions(1))->setCommon_fractions(comon_fractions);
//    restrictions.resize(matrix.size());
//    for(int i = 0; i < matrix.size(); i++)
//    {
//        for(int j = 0; j < matrix[i].size(); j++)
//        {
//            restrictions[i].push_back(Fractions(matrix[i][j]));
//        }
//    }
//    if(matrix.size() > 0 && matrix[0].size() > 3)
//    {
//        this->Gauss();
//        this->generate_equaions();
//        this->generate_points();
//    }
//    else
//        task_is_true = false;
//}

//bool Graph::getTask_is_true() const
//{
//    return task_is_true;
//}

//const vector<vector<Fractions> > &Graph::getRestrictions() const
//{
//    return restrictions;
//}

//const vector<PointGraph> &Graph::getNice_points() const
//{
//    return nice_points;
//}

//int Graph::getMaxX() const
//{
//    return maxX;
//}

//int Graph::getMaxY() const
//{
//    return maxY;
//}

//int Graph::getMinX() const
//{
//    return minX;
//}

//int Graph::getMinY() const
//{
//    return minY;
//}

//void Graph::Gauss()
//{
//    for(int row = 0; row < restrictions.size(); row++)
//    {
//        int max_elem_column = NULL;

//        for(int i = row; i < restrictions.size(); i++)
//        {
//            if((max_elem_column == NULL ||restrictions[max_elem_column][row].absFraction() < restrictions[i][row].absFraction()) && !(restrictions[i][row] == Fractions(0)))
//                max_elem_column = i;
//        }
//        if(max_elem_column == NULL)
//        {
//            task_is_true = false;
//            break;
//        }

//        if (max_elem_column != row)
//        {
//            swap(restrictions[max_elem_column], restrictions[row]);
//        }
//        Fractions t = restrictions[row][row];
//        for (auto& a : restrictions[row])
//            {
//                a = a / t;
//            }
//        for (int j = row + 1; j < restrictions.size(); j++)
//        {
//            Fractions t = restrictions[j][row] / restrictions[row][row];
//            for (int i = 0; i < restrictions[row].size(); i++)
//                {
//                Fractions a = t * restrictions[row][i];
//                    restrictions[j][i] = restrictions[j][i] - a;
//                }
//        }

//        for(int j = row -1; j > -1; j--)
//        {
//            Fractions t = restrictions[j][row] / restrictions[row][row];
//            for(int i = 0; i < restrictions[row].size(); i++)
//            {
//                Fractions a = t * restrictions[row][i];
//                restrictions[j][i] = restrictions[j][i] - a;
//            }
//        }

//    }
//}

//void Graph::generate_equaions()
//{
//    //Заполняем уравнения для графа, все они по-умолчанию >= 0
//    equations.resize(restrictions.size());
//    for(int i = 0; i < restrictions.size(); i++)
//    {
//        for(int j = restrictions.size(); j < restrictions[i].size()-1; j++)
//        {
//            equations[i].push_back(Fractions(-1) * restrictions[i][j]);
//        }
//        equations[i].push_back(restrictions[i][restrictions[i].size()-1]);
//        qDebug() << QString::fromStdString((string) equations[i][0]) << " " <<  QString::fromStdString((string) equations[i][1]) <<" " << QString::fromStdString((string) equations[i][2]);
//    }

//    //Добавляем к уравнениям оси Ox и Oy
//    equations.push_back({Fractions(1), Fractions(0), Fractions(0)});
//    equations.push_back({Fractions(0), Fractions(1), Fractions(0)});
//}

//void Graph::generate_points()
//{
//    qDebug() << "Start" << endl;
//    vector<PointGraph> all_points;
//    for(int i = 0; i < equations.size(); i++)
//    {
//        for(int j = 0; j < equations.size(); j++)
//        {
//            qDebug() << i << " " << j << endl;
//            PointGraph newPoint;
//            if(i != j && !((equations[i][0] == equations[j][0]) || (equations[i][1] == equations[j][1])) &&
//                    !(Fractions(0) == equations[i][0] && Fractions(0) == equations[i][1]) && !(Fractions(0) == equations[j][0] && Fractions(0) == equations[j][1]))
//            {
//                if(Fractions(0) == equations[i][0] && Fractions(0) == equations[j][1] )
//                {
//                    newPoint = PointGraph((Fractions(-1) * equations[j][2]) /equations[j][0], (Fractions(-1) * equations[i][2]) /equations[i][1], equations[i], equations[j]);
//                }
//                else if(Fractions(0) == equations[i][1] && Fractions(0) == equations[j][0] )
//                {
//                    newPoint = PointGraph((Fractions(-1) * equations[i][2]) /equations[i][0], (Fractions(-1) * equations[j][2]) /equations[j][1], equations[i], equations[j]);
//                }
//                else if(Fractions(0) == equations[i][0])
//                {
//                    Fractions y = (Fractions(-1) * equations[i][2])/equations[i][1];
//                    Fractions x = Fractions(-1) * equations[j][2];
//                    x = x - y;
//                    x = x/equations[j][0];
//                    newPoint = PointGraph(x, y, equations[i], equations[j]);
//                }
//                else if (Fractions(0) == equations[i][1])
//                {
//                    Fractions x = Fractions(-1)*equations[i][2]/equations[i][0];
//                    Fractions y = Fractions(-1)*equations[j][2];
//                    y = y - x;
//                    y = y / equations[j][1];
//                    newPoint = PointGraph(x, y, equations[i], equations[j]);
//                }
//                else if(Fractions(0) == equations[j][0])
//                {
//                    Fractions y = (Fractions(-1) * equations[j][2])/equations[j][1];
//                    Fractions x = Fractions(-1) * equations[i][2];
//                    x = x - y;
//                    x = x/equations[i][0];
//                    newPoint = PointGraph(x, y, equations[i], equations[j]);
//                }
//                else if (Fractions(0) == equations[j][1])
//                {
//                    Fractions x = Fractions(-1)*equations[j][2]/equations[j][0];
//                    Fractions y = Fractions(-1)*equations[i][2];
//                    y = y - x;
//                    y = y / equations[j][1];
//                    newPoint = PointGraph(x, y, equations[i], equations[j]);
//                }
//                else
//                {
//                    Fractions det = equations[i][1] * equations[j][0];
//                    det = equations[i][0] * equations[j][1] - det;

//                    Fractions x = equations[i][1] * equations[j][2];
//                    x = equations[i][2] * equations[j][1] - x;
//                    x = x / det;

//                    Fractions y = equations[i][2] * equations[j][0];
//                    y = equations[i][0] * equations[j][2] - y;
//                    y = y / det;

//                    newPoint = PointGraph(x, y, equations[i], equations[j]);
//                }
//                all_points.push_back(newPoint);
//            }
//        }
//    }

//    //Нужно проверить, что точка удовлетворяет всем неравенствам
//    for(auto point : all_points)
//    {
//        bool nice_point = true;

//        for(auto equation : equations)
//        {
//            //Получаем сначала значение x и y затем складываем их со свободным членом
//            //Если результат меньше 0, значит точка не удовлетворяет одному из неравенств
//            Fractions x = point.getX() * equation[0];
//            Fractions y = point.getY() * equation[1];
//            Fractions t = x + y + equation[2];
//            if(t < Fractions(0))
//            {
//                nice_point = false;
//            }

//        }

//        qDebug() << QString::fromStdString((string) point.getX()) << " " << QString::fromStdString((string) point.getY()) << " " << nice_point;
//        if(nice_point)
//        {
//            nice_points.push_back(point);
//            if(nice_points.size() == 1) //Если в векторе только одна точка, значит у нас может быть только 1 минимум и максимум
//            {
//                maxX = nice_points[0].getX().getFraction().first / nice_points[0].getX().getFraction().second;
//                minX = maxX;

//                maxY = nice_points[0].getY().getFraction().first / nice_points[0].getY().getFraction().second;
//                minY = maxY;
//            }
//            else
//            {
//                if(point.getX().getFraction().first / point.getX().getFraction().second > maxX)
//                    maxX = point.getX().getFraction().first / point.getX().getFraction().second;

//                if(point.getX().getFraction().first / point.getX().getFraction().second < minX)
//                    minX = point.getX().getFraction().first / point.getX().getFraction().second;

//                if(point.getY().getFraction().first / point.getY().getFraction().second > maxY)
//                    maxY = point.getY().getFraction().first / point.getY().getFraction().second;

//                if(point.getY().getFraction().first / point.getY().getFraction().second < minY)
//                    minY = point.getY().getFraction().first / point.getY().getFraction().second;
//            }
//        }
//    }
//    qDebug() << "LAST" << endl;
//    int i = 0;
//    //Следующим шагом будет - нахождение соседей для каждой точки
//    for(auto& point1 : nice_points)
//    {
//        qDebug() << i << endl;
//        i++;
//        for(auto& point2 : nice_points)
//        {
//            if(point1.getFirst_equation() == point2.getFirst_equation() || point1.getSecond_equation() == point2.getSecond_equation())
//            {
//                if(point1.getFirst_neighbour() == NULL)
//                    point1.setFirst_neighbour(&point2);
//                else if(point1.getSecond_neigbour() == NULL)
//                    point1.setSecond_neigbour(&point2);

//                if(point2.getFirst_neighbour() == NULL)
//                    point2.setFirst_neighbour(&point1);
//                else if(point2.getSecond_neigbour() == NULL)
//                    point2.setSecond_neigbour(&point1);
//            }
//        }
//    }

//    //Последним шагом будет - сортировка точек по очередности их вырисовывания
////    vector<PointGraph> vec_timer;
////    while(vec_timer.size() != nice_points.size())
////    {
////        //Индекс основного массива, чтобы не повторятся по нему.
////        int main_vec_index = 1;

////        vec_timer.push_back(nice_points[0]);
////    }
//}



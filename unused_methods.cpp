//ЗДЕСЬ ПРЕДСТАВЛЕНЫ НЕИСПОЛЬЗУЕМЫЕ МЕТОДЫ, КОТОРЫЕ ОТЛАЖЕНЫ И МОГУТ ПРИГОДИТЬСЯ

//void Graph::Gauss()
//{
//    qDebug() << restrictions.size();
//    for(int row = 0; row < restrictions.size(); row++)
//    {
//        int max_elem_column = -1;

//        for(int i = row; i < restrictions.size(); i++)
//        {
//            if((max_elem_column == -1 ||restrictions[max_elem_column][row].absFraction() < restrictions[i][row].absFraction()) && !(restrictions[i][row] == Fractions(0)))
//                max_elem_column = i;
//        }
//        if(max_elem_column == -1)
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
//        qDebug() << "GAUSS";
//        for (auto& a : restrictions[row])
//            {
//                qDebug() << QString::fromStdString((string) a) << "-";
//            }

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
//            equations[i].push_back(restrictions[i][j]);
//        }
//        equations[i].push_back( restrictions[i][restrictions[i].size()-1]);
//        qDebug() << QString::fromStdString((string) equations[i][0]) << " " <<  QString::fromStdString((string) equations[i][1]) <<" " << QString::fromStdString((string) equations[i][2]);
//    }

//    //Добавляем к уравнениям оси Ox и Oy
//    equations.push_back({Fractions(1), Fractions(0), Fractions(0)});
//    equations.push_back({Fractions(0), Fractions(1), Fractions(0)});
//}

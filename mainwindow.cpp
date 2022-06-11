#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Лабораторная работа по методам оптимизации");
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//При изменении кол-ва переменных или ограничений нужно поменять соответсвующие переменные и
//Изменить кол-во строк/столбцов в таблице ввода
void MainWindow::on_variables_num_valueChanged(int arg1)
{
    if(arg1 != variables_num)
    {
        variables_num = arg1;
        ui->table_task_data->setColumnCount(variables_num+1);
        ui->table_task_data->setRowCount(1);
        //char s = u8"\u2081";
        ui->table_task_data->setVerticalHeaderItem(0 ,new QTableWidgetItem("f(х)0"));


        for(int i = 0; i < variables_num; i++)
        {
            QString str = "C" + QString::number(i+1);
             ui->table_task_data->setHorizontalHeaderItem(i ,new QTableWidgetItem(str));
        }
         ui->table_task_data->setHorizontalHeaderItem(variables_num ,new QTableWidgetItem("C"));


         ui->table_restrictions_data->setColumnCount(variables_num+1);
         for(int i = 0; i < variables_num; i++)
         {
             QString str = "X" + QString::number(i+1);
              ui->table_restrictions_data->setHorizontalHeaderItem(i ,new QTableWidgetItem(str));
         }
          ui->table_restrictions_data->setHorizontalHeaderItem(variables_num ,new QTableWidgetItem("A"));

          for(int i = 0; i < variables_num+1; i++)
          {
                ui->table_task_data->setItem(0, i, new QTableWidgetItem("0"));
          }

          for(int i = 0; i < variables_num+1; i++)
          {
              for(int j = 0; j < restriction_num; j++)
                ui->table_restrictions_data->setItem(j, i, new QTableWidgetItem("0"));
          }
    }
}

void MainWindow::on_restrictions_num_valueChanged(int arg1)
{

    if(arg1 != restriction_num)
    {

            restriction_num = arg1;

            ui->table_restrictions_data->setRowCount(restriction_num);

            for(int i = 0; i < restriction_num; i++)
            {
                QString str = "f(x)" + QString::number(i+1);
                 ui->table_restrictions_data->setVerticalHeaderItem(i ,new QTableWidgetItem(str));
            }

            for(int i = 0; i < variables_num+1; i++)
            {
                  ui->table_task_data->setItem(0, i, new QTableWidgetItem("0"));
            }

            for(int i = 0; i < variables_num+1; i++)
            {
                for(int j = 0; j < restriction_num; j++)
                  ui->table_restrictions_data->setItem(j, i, new QTableWidgetItem("0"));
            }
    }
}

void MainWindow::on_restrictions_num_2_valueChanged(int arg1)
{
    if(arg1 != graph_restriction_num)
    {
        graph_restriction_num = arg1;

        ui->table_restrictions_data_2->setRowCount(graph_restriction_num);

        for(int i = 0; i < graph_restriction_num; i++)
        {
            QString str = "f(x)" + QString::number(i+1);
             ui->table_restrictions_data_2->setVerticalHeaderItem(i ,new QTableWidgetItem(str));
        }

        for(int i = 0; i < 3; i++)
        {
              ui->table_task_data->setItem(0, i, new QTableWidgetItem("0"));
        }

        for(int i = 0; i <3; i++)
        {
            for(int j = 0; j < graph_restriction_num; j++)
              ui->table_restrictions_data_2->setItem(j, i, new QTableWidgetItem("0"));
        }
    }
}


//При нажатии на кнпоку нужно отправить данные на обработку в класс Симплекс метода
void MainWindow::on_btn_send_into_data_released()
{

    QRegExp re("[-]*\\d*"); //Регулярное выражение для проверки на соответствие строки числу

    try
    {
        if(restriction_num >= variables_num)
            throw invalid_argument("");
        if(ui->type_fractions->currentText() == "Десятичный")
            common_fractions = false;
        else
            common_fractions = true;

        for (int i = 1; i < variables_num+1; i++) {
            current_matrix_row.push_back(i);
        }


        for (int i = variables_num + 1; i < restriction_num + variables_num+1; i++) {
            current_matrix_column.push_back(i);
        }

        for(int i = 0; i < variables_num+1; i++)
        {
            if(!re.exactMatch(ui->table_task_data->item(0, i)->text()))
                throw exception();

            main_task.push_back(Fractions(ui->table_task_data->item(0, i)->text().toInt()));

            if(ui->task_type->currentText() == "Максимизировать")
                main_task[i] = Fractions(-1) * main_task[i];
        }

        for(int i = 0; i < restriction_num; i++)
        {
            restrictions_matrix.push_back({});
            for(int j = 0; j < variables_num+1; j++)
            {
                if(!re.exactMatch(ui->table_restrictions_data->item(i, j)->text()))
                    throw exception();
                restrictions_matrix[i].push_back(ui->table_restrictions_data->item(i, j)->text().toInt());
            }
        }
        start_simplex();
        ui->btn_send_into_data->setEnabled(false);
        ui->btn_last_simplex_first->setEnabled(false);
        ui->btn_last_simplex_second->setEnabled(false);
        ui->btn_next_simplex_second->setEnabled(false);
        ui->btn_next_simplex_first->setEnabled(true);
        ui->pushButton->setEnabled(true);

    } catch (invalid_argument ex) {
        QMessageBox::warning(this, "Внимание","Калькулятор умеет решать только задачи, где число ограничений меньше числа переменных!");
    } catch (exception ex) {
        QMessageBox::warning(this, "Внимание","Вы можете ввести только ЦЕЛЫЕ ЧИСЛА!!!");
    }


}

//Кнопка решения для графического метода
void MainWindow::on_btn_send_into_data_2_released()
{
    QRegExp re("[-]*\\d*"); //Регулярное выражение для проверки на соответствие строки числу

    try
    {

        if(ui->task_type_2->currentText() == "Максимизировать")
            graph_min_task = false;
        else
            graph_min_task = true;

        for(int i = 0; i < 3; i++)
        {
            if(!re.exactMatch(ui->table_task_data_2->item(0, i)->text()))
                throw exception();

            graph_main_task.push_back(Fractions(ui->table_task_data_2->item(0, i)->text().toInt()));
        }

        for(int i = 0; i < graph_restriction_num; i++)
        {
            graph_restrictions_matrix.push_back({});
            for(int j = 0; j < 3; j++)
            {
                if(!re.exactMatch(ui->table_restrictions_data_2->item(i, j)->text()))
                    throw exception();
                graph_restrictions_matrix[i].push_back(ui->table_restrictions_data_2->item(i, j)->text().toInt());
            }
        }
        start_graph_method();
        ui->btn_send_into_data_2->setEnabled(false);

    }  catch (exception ex) {
        QMessageBox::warning(this, "Внимание","Вы можете ввести только ЦЕЛЫЕ ЧИСЛА!!!");
    }
}


void MainWindow::cout_matrix_header_first_table() const
{
    //Выводим заголовок столбцов матрицы X1 ... Xn b
    ui->simplex_first_table->setItem(x, y, new QTableWidgetItem(QString::fromStdString("X(" + to_string(num_iter) + ")")));

    for(int i = y+1, j = 0; j < current_matrix_row.size(); i++, j++)
    {
        ui->simplex_first_table->setItem(x, i, new QTableWidgetItem(QString::fromStdString("X(" + to_string(current_matrix_row[j]) + ")")));
    }

    ui->simplex_first_table->setItem(x, y + current_matrix_row.size() + 1, new QTableWidgetItem("b"));

    //Выводим заголовок строк матрицы Xn .. Xm
    for(int i = x + 1, j = 0; j < current_matrix_column.size(); i++, j++)
    {
        ui->simplex_first_table->setItem(i, y, new QTableWidgetItem(QString::fromStdString("X(" + to_string(current_matrix_column[j]) + ")")));
    }
}

void MainWindow::cout_matrix_header_second_table() const
{
    //Выводим заголовок столбцов матрицы X1 ... Xn b
    ui->simplex_second_table->setItem(x1, y1, new QTableWidgetItem(QString::fromStdString("X(" + to_string(num_iter_main) + ")")));

    for(int i = y1+1, j = 0; j < current_matrix_row.size(); i++, j++)
    {
        ui->simplex_second_table->setItem(x1, i, new QTableWidgetItem(QString::fromStdString("X(" + to_string(current_matrix_row[j]) + ")")));
    }

    ui->simplex_second_table->setItem(x1, y1 + current_matrix_row.size() + 1, new QTableWidgetItem("b"));

    //Выводим заголовок строк матрицы Xn .. Xm
    for(int i = x1 + 1, j = 0; j < current_matrix_column.size(); i++, j++)
    {
        ui->simplex_second_table->setItem(i, y1, new QTableWidgetItem(QString::fromStdString("X(" + to_string(current_matrix_column[j]) + ")")));
    }
}

void MainWindow::start_main_task()
{
    //Создаем вектор, в котором будут хранится все коэффициенты для последней строки новой матрицы
    vector<Fractions> vec;
    for(int i = 0; i < current_matrix_row.size(); i++)
    {
        vec.push_back(main_task[current_matrix_row[i]-1]);
    }
    simplex.start_main_matrix(vec, main_task[main_task.size()-1]);

    cout_matrix_header_second_table();

    vector<vector<Fractions>> current_matrix = simplex.getLast_matrix();
    for(int i = 0; i < current_matrix.size() ; i++)
    {
        for(int j = 0; j < current_matrix[i-x1].size(); j++)
        {
            //Заполняем матрицу
            ui->simplex_second_table->setItem(i+ x1 + 1, j+1, new QTableWidgetItem(QString::fromStdString((string) current_matrix[i][j])));
            //Выделяем все возможные базисы
            select_basis_main(i, j);
        }
    }

    ui->btn_last_simplex_first->setEnabled(false);
    ui->btn_next_simplex_first->setEnabled(false);
    ui->btn_last_simplex_second->setEnabled(true);
    ui->btn_next_simplex_second->setEnabled(true);

    num_iter_main++;
}

bool MainWindow::check_simplex_end()
{
    if(simplex.possible_basis().size() == 0)
    {
        return true;
    }
    return false;
}

bool MainWindow::check_simplex_error()
{
    vector<vector<Fractions>> current_matrix = simplex.getLast_matrix();

    bool result = false;

    for(int i = 0; i < current_matrix[0].size() -1; i++)
    {
        for(int j = 0; j < current_matrix.size(); j++)
        {
           if(current_matrix[j][i] < 0 ||current_matrix[j][i] == 0 )
           {
               result = true;
           }
           else
           {
               result = false;
               break;
           }
        }

        if(result)
            return result;
    }
    return result;
}


void MainWindow::refrsh_main_task()
{
    //Получаем последнюю матрицу
    vector<vector<Fractions>> current_matrix = simplex.getLast_matrix();

    for(int i = 0; i < current_matrix.size()-1; i++)
    {
        for(int j = 0; j < current_matrix[i].size()-1; j++)
        {
            //В главной задаче из j переменной вычитаем i переменную умноженную на коэффициент в уравнении i j
            auto t = main_task[current_matrix_column[i]-1] * current_matrix[i][j];
            main_task[current_matrix_row[j]-1] = main_task[current_matrix_row[j]-1] - t;
        }
        //последний элемент в уравнении знак не меняем, поэтому делаем тоже самое, но с +
        auto t = main_task[current_matrix_column[i]-1] * current_matrix[i][current_matrix[i].size()-1];
        main_task[main_task.size()-1] = main_task[main_task.size()-1] + t;
        //Уничтожаем в главной задаче текущую переменную
        main_task[current_matrix_column[i]-1] = Fractions(0);
    }
}

void MainWindow::refresh_graph_main_task(vector<vector<Fractions>> current_matrix)
{
    for(int i = 0; i < current_matrix.size()-1; i++)
    {
        for(int j = 0; j < current_matrix[i].size()-1; j++)
        {
            //В главной задаче из j переменной вычитаем i переменную умноженную на коэффициент в уравнении i j
            auto t = graph_main_task[i] * current_matrix[i][j];
            graph_main_task[j] = graph_main_task[j] - t;
        }
        auto t = graph_main_task[i] * current_matrix[i][current_matrix[i].size()-1];
        graph_main_task[graph_main_task.size()-1] = graph_main_task[graph_main_task.size()-1] + t;
        graph_main_task[i] = Fractions(0);
    }

}

void MainWindow::start_simplex()
{
    simplex = *new Simplex(restrictions_matrix, true , common_fractions);
    vector<vector<Fractions>> current_matrix = simplex.getLast_matrix();

    cout_matrix_header_first_table();


    for(int i = 0; i < current_matrix.size() ; i++)
    {
        for(int j = 0; j < current_matrix[i-x].size(); j++)
        {
            //Заполняем матрицу
            ui->simplex_first_table->setItem(i+ x + 1, j+1, new QTableWidgetItem(QString::fromStdString((string) current_matrix[i][j])));
            //Выделяем все возможные базисы

            select_basis(i, j);
        }
    }
    num_iter++;
}


void MainWindow::start_graph_method()
{
    //Создаем матрицу для графического метода
    graph = *new Graph(graph_restrictions_matrix, true , common_fractions);
    normal_building();
    if(true)
    {
        vector<vector<Fractions>> equation = graph.getRestrictions();
        set<PointGraph> points = graph.getNice_points();
        vector<pair<PointGraph, PointGraph>> main_points = graph.getMain_points();
        set<PointGraph> extremum_points = search_extr_points(points);
        Fractions extremum_value = search_extr_value(points);

        //Выводим ответ
        if(graph_up_task_ok && graph_right_task_ok)
        {
            string result = "f = " + (string) extremum_value + '\n';
            for(auto i : extremum_points)
            {
                result += "(" + (string) i.getX() + "; " + (string) i.getY() + ")" + '\n';
            }
            ui->cout_graph_task->setText(QString::fromStdString(result));
        }
        else if(!graph_up_task_ok && !graph_right_task_ok)
            ui->cout_graph_task->setText("Функция неограничена!");
        else if(!graph_up_task_ok)
            ui->cout_graph_task->setText("Функция неограничена сверху!");
        else if(!graph_right_task_ok)
            ui->cout_graph_task->setText("Функция неограничена справа!");


        //Выводим линии графа и выделяем точки пересечения
        ui->main_graph->xAxis->setRange(0, graph.getMaxX()+4);
        ui->main_graph->xAxis->setLabel("X1");
        ui->main_graph->yAxis->setRange(0, graph.getMaxY()+4);
        ui->main_graph->yAxis->setLabel("X2");



        for(int i = 0; i < main_points.size(); i++)
        {
            QVector<double> x(2), y(2);
            ui->main_graph->addGraph();
            x[0] = static_cast<double>(main_points[i].first.getX().getFraction().first) / static_cast<double>(main_points[i].first.getX().getFraction().second);
            x[1] = static_cast<double>(main_points[i].second.getX().getFraction().first) / static_cast<double>(main_points[i].second.getX().getFraction().second);
            y[0] = static_cast<double>(main_points[i].first.getY().getFraction().first) / static_cast<double>(main_points[i].first.getY().getFraction().second);
            y[1] = static_cast<double>(main_points[i].second.getY().getFraction().first) / static_cast<double>(main_points[i].second.getY().getFraction().second);
            ui->main_graph->graph(i)->setData(x, y);
            ui->main_graph->graph(i)->setPen(QPen(Qt::blue));
        }
        QVector<double> x1(points.size()), y1(points.size());
        int j = 0;
        for(auto& i : points)
        {
            x1[j] = static_cast<double>(i.getX().getFraction().first) / static_cast<double>(i.getX().getFraction().second);
            y1[j] = static_cast<double>(i.getY().getFraction().first) / static_cast<double>(i.getY().getFraction().second);
            j++;
        }
        QCPGraph *newCurve = new QCPGraph(ui->main_graph->xAxis, ui->main_graph->yAxis);
        newCurve->setData(x1, y1);
        newCurve->setLineStyle(QCPGraph::lsNone);
        newCurve->setScatterStyle(QCPScatterStyle::ssCircle);
        newCurve->setPen(QPen(QBrush(Qt::red), 5));

        ui->main_graph->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui->main_graph->replot();

    }
    else
    {
        if(graph.getUp_restrictions())
            ui->cout_graph_task->setText(QString::fromStdString("Функция неограничена справа"));
        else if(graph.getRight_restrictions())
            ui->cout_graph_task->setText(QString::fromStdString("Функция неограничена сверху"));
        else
            ui->cout_graph_task->setText(QString::fromStdString("Функция неограничена"));
    }

}

void MainWindow::normal_building()
{
    QVector<double> x(2), y(2);
    x[0] = 0;
    y[0] = 0;
    double x_finish_point, y_finish_point;
    if(graph_min_task)
    {
        x_finish_point = static_cast<double>(graph_main_task[0].getFraction().first)/static_cast<double>(graph_main_task[0].getFraction().second) * -1;
        y_finish_point = static_cast<double>(graph_main_task[1].getFraction().first)/static_cast<double>(graph_main_task[1].getFraction().second) * -1;
    }
    else
    {
        x_finish_point = static_cast<double>(graph_main_task[0].getFraction().first)/static_cast<double>(graph_main_task[0].getFraction().second);
        y_finish_point = static_cast<double>(graph_main_task[1].getFraction().first)/static_cast<double>(graph_main_task[1].getFraction().second);
    }
    x[1] = x_finish_point;
    y[1] = y_finish_point;

    draw_normal(x, y);

    if(y_finish_point > 0 && x_finish_point > 0 && !graph.getRound_restrictions())
    {
        graph_up_task_ok = false;
        graph_right_task_ok = false;
    }
    if(x_finish_point > 0 && y_finish_point <= 0 && !graph.getRight_restrictions() && !graph.getRound_restrictions())
    {
        graph_right_task_ok = false;
    }
    if(x_finish_point <= 0 && y_finish_point > 0 && !graph.getUp_restrictions() && !graph.getRound_restrictions())
    {
        graph_up_task_ok = false;
    }


}

void MainWindow::draw_normal(QVector<double> x, QVector<double> y)
{
    QCPItemLine *arrow = new QCPItemLine(ui->main_graph);
    arrow->start->setCoords(x[0], y[0]);
    arrow->end->setCoords(x[1], y[1]);
    arrow->setHead(QCPLineEnding::esSpikeArrow);
    arrow->setPen(QPen(QBrush(Qt::green), 2));

    QVector<double> normal_x(2), normal_y(2);
    if(y[1] > 0)
    {
        normal_x[0] = y[1] * -1;
        normal_x[1] = y[1];
        normal_y[0] = x[1];
        normal_y[1] = x[1] * -1;
    }
    else
    {
        normal_x[0] = y[1];
        normal_x[1] = y[1] * -1;
        normal_y[0] = x[1] * -1;
        normal_y[1] = x[1];
    }
    QCPCurve *normal = new QCPCurve(ui->main_graph->xAxis, ui->main_graph->yAxis);

    normal->setData(normal_x, normal_y);
    normal->setLineStyle(QCPCurve::lsLine);
    normal->setPen(QPen(QBrush(Qt::green), 2));

}

set<PointGraph> MainWindow::search_extr_points(set<PointGraph> points)
{
    Fractions extremum_value = search_extr_value(points);
    set<PointGraph> extremum_points;

    for(auto i : points)
    {
        Fractions t = i.getX() * graph_main_task[graph_main_task.size()-3];
        t = i.getY() * graph_main_task[graph_main_task.size()-2] + t;
        if(t == extremum_value)
            extremum_points.insert(i);
    }

    return extremum_points;
}

Fractions MainWindow::search_extr_value(set<PointGraph> points)
{
    if(points.size() == 0)
        return Fractions(0);
    Fractions extremum_value = (points.begin()->getX() * graph_main_task[graph_main_task.size()-3]);
    extremum_value = (points.begin()->getY() * graph_main_task[graph_main_task.size()-2]) + extremum_value;

    for(auto i : points)
    {
        Fractions t = i.getX() * graph_main_task[graph_main_task.size()-3];
        t = i.getY() * graph_main_task[graph_main_task.size()-2] + t;
        if(ui->task_type_2->currentText() == "Минимизировать")
        {
        if(t < extremum_value)
            extremum_value = t;
        }
        else
        {
            if(extremum_value < t)
                extremum_value = t;
        }
    }
    return extremum_value;
}


void MainWindow::full_vec_var(vector<Fractions> &vec)
{
    vector<vector<Fractions>> current_matrix = simplex.getLast_matrix();
    for(int i = 0; i < current_matrix.size()-1; i++)
    {
        vec[current_matrix_column[i]-1] = current_matrix[i][current_matrix[i].size()-1];
    }
}


void MainWindow::on_simplex_first_table_cellDoubleClicked(int row, int column)
{
    vector<pair<int, int>> all_basis = simplex.possible_basis_free();


    pair<int, int> check_basis = {row-x-1, column-y-1};
    if(all_basis.size()>0 && current_basis != check_basis)
    {
        if(std::find(all_basis.begin(), all_basis.end(), check_basis) != all_basis.end())
        {
            ui->simplex_first_table->item(row, column)->setBackgroundColor(QColor(0, 255, 0));

            ui->simplex_first_table->item(current_basis.first + x + 1, current_basis.second + y + 1)->setBackgroundColor(QColor(255, 0, 0));

            current_basis = check_basis;
        }
    }

}

void MainWindow::select_basis(int row, int column)
{
    vector<pair<int, int>> all_basis = simplex.possible_basis_free();
    pair<int, int> check_basis = {row, column};
    if(all_basis.size()>0)
    {
        current_basis = all_basis[0];
        if(std::find(all_basis.begin(), all_basis.end(), check_basis) != all_basis.end())
        {
            ui->simplex_first_table->item(row+ x + 1, column+y+1)->setBackgroundColor(QColor(255, 0, 0));
        }
        if(check_basis == current_basis)
        {
            ui->simplex_first_table->item(row + x + 1, column + y +1)->setBackgroundColor(QColor(0, 255, 0));
        }
    }

    else if(simplex.possible_basis().size() > 0)
    {
        all_basis = simplex.possible_basis();
        current_basis = all_basis[0];
        if(std::find(all_basis.begin(), all_basis.end(), check_basis) != all_basis.end())
        {
            ui->simplex_first_table->item(row+ x + 1, column+y+1)->setBackgroundColor(QColor(255, 0, 0));
        }
        if(check_basis == current_basis)
        {
            ui->simplex_first_table->item(row + x + 1, column + y +1)->setBackgroundColor(QColor(0, 255, 0));
        }
    }

}

void MainWindow::select_basis_main(int row, int column)
{
    vector<pair<int, int>> all_basis = simplex.possible_basis();
    pair<int, int> check_basis = {row, column};
    if(all_basis.size()>0)
    {

        current_basis = all_basis[0];
        if(std::find(all_basis.begin(), all_basis.end(), check_basis) != all_basis.end())
        {
            ui->simplex_second_table->item(row + x1 + 1, column+y1+1)->setBackgroundColor(QColor(255, 0, 0));
        }
        if(check_basis == current_basis)
        {
            ui->simplex_second_table->item(row + x1 + 1, column + y1 +1)->setBackgroundColor(QColor(0, 255, 0));
        }
    }
}

void MainWindow::set_new_headers()
{
    //считаем заголовки с текущей матрицы, затем переведем их в числа и обновим вектора
    current_matrix_column.clear();
    current_matrix_row.clear();

    auto current_matrix = simplex.getLast_matrix();
    if(current_matrix.size() > 0)
    {
        for(int i = y+1, j = 0; j < current_matrix[0].size()-1; i++, j++)
        {
            QString header = ui->simplex_first_table->item(x, i)->text();
            header = header.right(header.size()-2);
            header = header.left(header.size()-1);
            int num = header.toInt();
            current_matrix_row.push_back(num);
        }
    }


        for(int i = x + 1, j = 0; j <current_matrix.size()-1; i++, j++)
        {
            QString header = ui->simplex_first_table->item(i, y)->text();
            header = header.right(header.size()-2);
            header = header.left(header.size()-1);
            int num = header.toInt();
            current_matrix_column.push_back(num);
        }
}


void MainWindow::on_btn_next_simplex_first_released()
{
    ui->btn_last_simplex_first->setEnabled(true);
    //Проверяем базисы искусственных переменных
    if(simplex.possible_basis_free().size() > 0)
    {

        x+= restriction_num + 3;

        simplex.next_simplex_matrix_free(current_basis.first, current_basis.second);

        vector<vector<Fractions>> current_matrix = simplex.getLast_matrix();

        current_matrix_column[current_basis.first] = current_matrix_row[current_basis.second];

        current_matrix_row.erase(current_matrix_row.begin()+current_basis.second);


        cout_matrix_header_first_table();


        for(int i = 0; i < current_matrix.size() ; i++)
        {
            for(int j = 0; j < current_matrix[i].size(); j++)
            {
                //Заполняем матрицу
                ui->simplex_first_table->setItem(i+ x + 1, j+1, new QTableWidgetItem(QString::fromStdString((string) current_matrix[i][j])));
                //Выделяем все возможные базисы
                select_basis(i, j);
            }
        }
        num_iter++;
    }
    else if(simplex.possible_basis().size() > 0)
    {
        x+= restriction_num + 3;

        simplex.next_simplex_matrix(current_basis.first, current_basis.second);

        vector<vector<Fractions>> current_matrix = simplex.getLast_matrix();

        int t = current_matrix_column[current_basis.first];

        current_matrix_column[current_basis.first] = current_matrix_row[current_basis.second];

        current_matrix_row[current_basis.second] = t;


        cout_matrix_header_first_table();


        for(int i = 0; i < current_matrix.size() ; i++)
        {
            for(int j = 0; j < current_matrix[i].size(); j++)
            {
                //Заполняем матрицу
                ui->simplex_first_table->setItem(i+ x + 1, j+1, new QTableWidgetItem(QString::fromStdString((string) current_matrix[i][j])));
                //Выделяем все возможные базисы
                select_basis(i, j);
            }
        }
        num_iter++;
    }

    if(check_simplex_end())
    {
        ui->btn_next_simplex_first->setEnabled(false);
        refrsh_main_task();
        string res_cout = "f* = ";
        for (int i = 0; i < main_task.size()-1; i++)
        {
            if(!(main_task[i] == 0))
            {
                if(res_cout.length() > 5)
                {

                    res_cout += "+ (" + string(main_task[i]) + ")X" + to_string(i+1) + " ";
                }
                else
                    res_cout += "(" + string(main_task[i]) + ")X" + to_string(i+1) + " ";
            }
        }
         res_cout += "+ (" + string(main_task[main_task.size()-1]) + ")" ;
        ui->cout_simplex_task_first->setText(QString::fromStdString(res_cout));

        start_main_task();

        qDebug() << "Off";
    }
    else if(check_simplex_error())
    {
        ui->btn_next_simplex_first->setEnabled(false);
        ui->cout_simplex_task_first->setText(QString::fromStdString("Функция не ограничена. Решения нет!"));
    }
}


void MainWindow::on_btn_last_simplex_first_released()
{
    ui->cout_simplex_task_first->setText("");
    ui->btn_next_simplex_first->setEnabled(true);

    vector<vector<Fractions>> current_matrix = simplex.getLast_matrix();


    for(int i = 0; i < current_matrix.size()+1 ; i++)
    {
        for(int j = 0; j < current_matrix[0].size()+1; j++)
        {
            //Заполняем матрицу
            ui->simplex_first_table->setItem(i+ x, j, new QTableWidgetItem(""));
            ui->simplex_first_table->item(i+ x, j)->setBackgroundColor(QColor(255, 255, 255));
        }
    }
    simplex.del_last_matrix();

    x-= restriction_num + 3;

    //Обновляем вектор с заголовками
    set_new_headers();
    qDebug() << "OK";
    current_matrix = simplex.getLast_matrix();

    for(int i = 0; i < current_matrix.size() ; i++)
    {
        for(int j = 0; j < current_matrix[i].size(); j++)
        {
            ui->simplex_first_table->item(i+ x + 1, j+1)->setBackgroundColor(QColor(255, 255, 255));
            //Выделяем все возможные базисы
            select_basis(i, j);
        }
    }
    qDebug() << "OKOK";
    num_iter--;

    if(simplex.getSizeMatrixStack() == 1)
    {
        ui->btn_last_simplex_first->setEnabled(false);
    }
}


void MainWindow::on_btn_next_simplex_second_released()
{
    if(simplex.possible_basis().size() > 0)
    {
        x1 += restriction_num + 3;

        simplex.next_simplex_matrix(current_basis.first, current_basis.second);

        vector<vector<Fractions>> current_matrix = simplex.getLast_matrix();

        int t = current_matrix_column[current_basis.first];

        current_matrix_column[current_basis.first] = current_matrix_row[current_basis.second];

        current_matrix_row[current_basis.second] = t;


        cout_matrix_header_second_table();


        for(int i = 0; i < current_matrix.size() ; i++)
        {
            for(int j = 0; j < current_matrix[i].size(); j++)
            {
                //Заполняем матрицу
                ui->simplex_second_table->setItem(i+ x1 + 1, j+1, new QTableWidgetItem(QString::fromStdString((string) current_matrix[i][j])));
                //Выделяем все возможные базисы
                select_basis_main(i, j);
            }
        }
        num_iter_main++;
    }

    if(check_simplex_error())
    {
        ui->btn_next_simplex_second->setEnabled(false);
        ui->cout_simplex_task_second->setText(QString::fromStdString("Функция не ограничена. Решения нет!"));
    }
    else if(check_simplex_end())
    {
        string res_x = "x = ( ";
        string res_f = "f = ";
        vector<Fractions> var_cur;
        for(int i = 0; i < variables_num; i++)
            var_cur.push_back(Fractions(0));
        full_vec_var(var_cur);
        for(auto i : var_cur)
        {
            res_x += (string) i + "; ";
        }
        res_x += ")";

        Fractions counter(0);
        for(int i = 0; i < variables_num; i++)
        {
            main_task[i] = main_task[i]*var_cur[i];
            counter = counter + main_task[i];
        }
        counter = counter + main_task[main_task.size()-1];

        res_f += (string) counter;

        ui->cout_simplex_task_second->setText(QString::fromStdString(res_x + '\n' + res_f));

        ui->btn_next_simplex_second->setEnabled(false);

    }
}


void MainWindow::on_simplex_second_table_cellDoubleClicked(int row, int column)
{
    vector<pair<int, int>> all_basis = simplex.possible_basis_free();


    pair<int, int> check_basis = {row-x-1, column-y-1};
    if(all_basis.size()>0 && current_basis != check_basis)
    {
        if(std::find(all_basis.begin(), all_basis.end(), check_basis) != all_basis.end())
        {
            ui->simplex_second_table->item(row, column)->setBackgroundColor(QColor(0, 255, 0));

            ui->simplex_second_table->item(current_basis.first + x1 + 1, current_basis.second + y + 1)->setBackgroundColor(QColor(255, 0, 0));

            current_basis = check_basis;
        }
    }
}


void MainWindow::on_pushButton_released()
{
    while(ui->btn_next_simplex_first->isEnabled())
    {
        this->on_btn_next_simplex_first_released();
    }
}


void MainWindow::on_btn_restart_simplex_released()
{
    //Обнуляем переменные
    variables_num = 0;
    restriction_num = 0;
    x = 0;
    y = 0;
    num_iter = 0;
    num_iter_main = 0;
    x1 = 0;
    y1 = 0;

    //Очищаем все  таблицы
    current_matrix_row.clear();
    current_matrix_column.clear();
    main_task.clear();
    restrictions_matrix.clear();
    ui->table_task_data->clear();
    ui->table_restrictions_data->clear();
    ui->simplex_first_table->clear();
    ui->simplex_second_table->clear();
    ui->table_restrictions_data->clear();
    ui->cout_simplex_task_first->clear();
    ui->cout_simplex_task_second->clear();
    //Обнуляем кол-во столбцов и ставим 0 значения
    ui->table_task_data->setColumnCount(0);
    ui->table_task_data->setRowCount(0);
    ui->table_restrictions_data->setColumnCount(0);
    ui->table_restrictions_data->setRowCount(0);
    ui->variables_num->setValue(0);
    ui->restrictions_num->setValue(0);
    //Обновляем доступность кнопок
    ui->btn_send_into_data->setEnabled(true);
    ui->btn_last_simplex_first->setEnabled(false);
    ui->btn_last_simplex_second->setEnabled(false);
    ui->btn_next_simplex_first->setEnabled(false);
    ui->btn_next_simplex_second->setEnabled(false);
    ui->pushButton->setEnabled(false);
}


void MainWindow::on_btn_restart_graph_released()
{
    graph_restriction_num = 0;
    graph_up_task_ok = true;
    graph_right_task_ok = true;


    graph_main_task.clear();
    graph_restrictions_matrix.clear();

    ui->main_graph->clearGraphs();
    ui->main_graph->clearItems();
    ui->main_graph->clearPlottables();
    ui->table_restrictions_data_2->clear();
    ui->table_restrictions_data_2->setRowCount(0);
    ui->restrictions_num_2->setValue(0);
    ui->cout_graph_task->clear();

    ui->btn_send_into_data_2->setEnabled(true);

    ui->main_graph->replot();
}


void MainWindow::on_save_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this);
        if (fileName.isEmpty()) {
            return;
        }
        ModelStorage::save(fileName, ui->table_task_data, ui->table_restrictions_data);
}


void MainWindow::on_load_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
        if (fileName.isEmpty()) {
            return;
        }
        ModelStorage::load(fileName, ui->table_task_data, ui->table_restrictions_data, ui->variables_num, ui->restrictions_num);
}


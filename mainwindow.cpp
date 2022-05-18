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
//При нажатии на кнпоку нужно отправить данные на обработку в класс Симплекс метода и Графического метода
void MainWindow::on_btn_send_into_data_released()
{

    QRegExp re("[-]*\\d*"); //Регулярное выражение для проверки на соответствие строки числу

    try
    {
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
            //ПОКА ЧТО ПРИ ВВОДЕ НЕЧИСЕЛ ПРОГРАММА ЗАВЕРШАЕТСЯ, В БУДУЩЕМ НУЖНО ИСПРАВИТЬ
            if(!re.exactMatch(ui->table_task_data->item(0, i)->text()))
                throw exception();

            main_task.push_back(Fractions(ui->table_task_data->item(0, i)->text().toInt()));
        }

        for(int i = 0; i < restriction_num; i++)
        {
            restrictions_matrix.push_back({});
            for(int j = 0; j < variables_num+1; j++)
            {
                //ПОКА ЧТО ПРИ ВВОДЕ НЕЧИСЕЛ ПРОГРАММА ЗАВЕРШАЕТСЯ, В БУДУЩЕМ НУЖНО ИСПРАВИТЬ
                if(!re.exactMatch(ui->table_restrictions_data->item(i, j)->text()))
                    throw exception();
                restrictions_matrix[i].push_back(ui->table_restrictions_data->item(i, j)->text().toInt());
            }
        }
        start_graph_method();
        start_simplex();

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

}


void MainWindow::refrsh_main_task()
{
    vector<vector<Fractions>> current_matrix = simplex.getLast_matrix();

    for(int i = 0; i < current_matrix.size()-1; i++)
    {
        for(int j = 0; j < current_matrix[i].size()-1; j++)
        {
            auto t = main_task[current_matrix_column[i]-1] * current_matrix[i][j];
            main_task[current_matrix_row[j]-1] = main_task[current_matrix_row[j]-1] - t;
        }
        auto t = main_task[current_matrix_column[i]-1] * current_matrix[i][current_matrix[i].size()-1];
        main_task[main_task.size()-1] = main_task[main_task.size()-1] + t;
        main_task[current_matrix_column[i]-1] = Fractions(0);
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
    //graph = *new Graph(restrictions_matrix, true , common_fractions);

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
    //Если есть базис искусственных переменных, то выделяем только его, иначе все возможные базисы
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

    qDebug() << "1";
    if(check_simplex_end())
    {
        qDebug() << "On";
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
    if(simplex.getSizeMatrixStack() < 2)
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
    if(check_simplex_end())
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


    }
    else if(check_simplex_error())
    {
        ui->btn_next_simplex_first->setEnabled(false);
        ui->cout_simplex_task_second->setText(QString::fromStdString("Функция не ограничена. Решения нет!"));
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


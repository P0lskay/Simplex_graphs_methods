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
//При нажатии на кнпоку нужно отправить данные на обработку в класс Симплекс метода
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
            current_matrix_row.push_back(to_string(i));
        }


        for (int i = variables_num + 1; i < restriction_num + variables_num+1; i++) {
            current_matrix_column.push_back(to_string(i));
        }

        for(int i = 0; i < variables_num+1; i++)
        {
            //ПОКА ЧТО ПРИ ВВОДЕ НЕЧИСЕЛ ПРОГРАММА ЗАВЕРШАЕТСЯ, В БУДУЩЕМ НУЖНО ИСПРАВИТЬ
            if(!re.exactMatch(ui->table_task_data->item(0, i)->text()))
                throw exception();

            main_task.push_back(ui->table_task_data->item(0, i)->text().toInt());
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
        ui->simplex_first_table->setItem(x, i, new QTableWidgetItem(QString::fromStdString("X(" + current_matrix_row[j] + ")")));
    }

    ui->simplex_first_table->setItem(x, y + current_matrix_row.size() + 1, new QTableWidgetItem("b"));

    //Выводим заголовок строк матрицы Xn .. Xm
    for(int i = x + 1, j = 0; j < current_matrix_column.size(); i++, j++)
    {
        ui->simplex_first_table->setItem(i, y, new QTableWidgetItem(QString::fromStdString("X(" + current_matrix_column[j] + ")")));
    }
}

void MainWindow::start_simplex()
{
    simplex = *new Simplex(restrictions_matrix, main_task, true , common_fractions);
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
}


void MainWindow::on_btn_next_simplex_first_released()
{
    ui->btn_last_simplex_first->setEnabled(true);

    x+= restriction_num + 3;

    simplex.next_simplex_matrix(current_basis.first, current_basis.second);

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
}


void MainWindow::on_btn_last_simplex_first_released()
{
    if(simplex.getSizeMatrixStack() < 2)
    {
        ui->btn_last_simplex_first->setEnabled(false);
    }
}


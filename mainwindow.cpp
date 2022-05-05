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
    QRegExp re("\\d*"); //Регулярное выражение для проверки на соответствие строки числу

    try
    {
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

        simplex = *new Simplex(restrictions_matrix, main_task, true , true);

        vector<pair<int, int>> all_basis = simplex.possible_basis();
        vector<vector<Fractions>> current_matrix = simplex.getLast_matrix();

        for(int i = x; i < x + current_matrix.size(); i++)
        {
            for(int j = 0; j < current_matrix[i-x].size(); j++)
            {
                ui->simplex_first_table->setItem(i, j, new QTableWidgetItem(QString::fromStdString((string) current_matrix[i-x][j])));
            }
        }

    }  catch (exception ex) {
        QMessageBox::warning(this, "Внимание","Вы можете ввести только ЦЕЛЫЕ ЧИСЛА!!!");
    }


}


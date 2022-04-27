#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_variables_num_valueChanged(int arg1);

private:
    //Переменные хранящие кол-во ограничений, переменных, а также матрицу ограничений
    int restriction_num = 0;
    int variables_num = 0;
    std::vector<std::vector<int>> restriction_matrix;

    Ui::MainWindow *ui;

    //Метод для изменения матрицы ограничений
    void change_restriction_matrix();
};
#endif // MAINWINDOW_H

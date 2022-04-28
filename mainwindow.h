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

    void on_restrictions_num_valueChanged(int arg1);

private:
    //Переменные хранящие кол-во ограничений и переменных
    int restriction_num = 0;
    int variables_num = 0;

    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

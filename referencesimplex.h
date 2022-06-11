#ifndef REFERENCESIMPLEX_H
#define REFERENCESIMPLEX_H

#include <QDialog>

namespace Ui {
class referenceSimplex;
}

class referenceSimplex : public QDialog
{
    Q_OBJECT

public:
    explicit referenceSimplex(QWidget *parent = nullptr);
    ~referenceSimplex();

private:
    Ui::referenceSimplex *ui;
};

#endif // REFERENCESIMPLEX_H

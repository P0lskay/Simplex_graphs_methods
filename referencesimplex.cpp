#include "referencesimplex.h"
#include "ui_referencesimplex.h"

referenceSimplex::referenceSimplex(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::referenceSimplex)
{
    ui->setupUi(this);
}

referenceSimplex::~referenceSimplex()
{
    delete ui;
}

#include "referencegraph.h"
#include "ui_referencegraph.h"

referenceGraph::referenceGraph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::referenceGraph)
{
    ui->setupUi(this);
}

referenceGraph::~referenceGraph()
{
    delete ui;
}

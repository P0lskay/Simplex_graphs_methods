#ifndef REFERENCEGRAPH_H
#define REFERENCEGRAPH_H

#include <QDialog>

namespace Ui {
class referenceGraph;
}

class referenceGraph : public QDialog
{
    Q_OBJECT

public:
    explicit referenceGraph(QWidget *parent = nullptr);
    ~referenceGraph();

private:
    Ui::referenceGraph *ui;
};

#endif // REFERENCEGRAPH_H

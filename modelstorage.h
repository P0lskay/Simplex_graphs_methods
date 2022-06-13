#ifndef MODELSTORAGE_H
#define MODELSTORAGE_H

#include <QStandardItemModel>
#include <QStandardItem>
#include <QSpinBox>
#include <QTableWidget>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class ModelStorage
{
public:
    static bool load(const QString& fileName, QTableWidget* simplex_task, QTableWidget* simplex_restrictions, QSpinBox* variables, QSpinBox* restrictions, QTableWidget* graph_task, QTableWidget* graph_restrictions,
                     QSpinBox* restrictionsGraph);
    static bool save(const QString& fileName, const QTableWidget* simplex_task, const QTableWidget* simplex_restrictions, const QTableWidget* graph_task, const QTableWidget* graph_restrictions);
};

#endif // MODELSTORAGE_H

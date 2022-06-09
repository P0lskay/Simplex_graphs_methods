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
    static bool load(const QString& fileName, QTableWidget* model_task, QTableWidget* model_restrictions, QSpinBox* variables, QSpinBox* restrictions);
    static bool save(const QString& fileName, const QStandardItemModel& model_task, const QStandardItemModel& model_restrictions);
};

#endif // MODELSTORAGE_H

#include "modelstorage.h"
#include <QDebug>


bool ModelStorage::load(const QString& fileName, QTableWidget* simplex_task, QTableWidget* simplex_restrictions, QSpinBox* variables, QSpinBox* restrictions,
                        QTableWidget* graph_task, QTableWidget* graph_restrictions, QSpinBox* restrictionsGraph) {
    QFile loadFile(fileName);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }
    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc = QJsonDocument::fromJson(saveData);
    QJsonObject json = loadDoc.object();

    simplex_task->clear();

    const int rowCount = json["rowCountRestrictions"].toInt();
    const int rowCountGraph = json["rowCountRestrictionsGraph"].toInt();
    const int columnCount = json["columnCountTask"].toInt();
    QJsonArray data = json["data_task"].toArray();

    variables->setValue(columnCount-1);
    restrictions->setValue(rowCount);
    restrictionsGraph->setValue(rowCountGraph);
    if(columnCount > 0 && rowCount > 0)
    {
        for (int i = 0; i < 1; i++)
        {
            QJsonArray row = data[i].toArray();

            for (int j = 0; j < columnCount; j++) {
                simplex_task->setItem(i, j, new QTableWidgetItem(row[j].toString()));
            }
        }


        data = json["data_restrictions"].toArray();
        for (int i = 0; i < rowCount; i++)
        {
            QJsonArray row = data[i].toArray();

            for (int j = 0; j < columnCount; j++) {
                simplex_restrictions->setItem(i, j, new QTableWidgetItem(row[j].toString()));
            }
        }
    }

    data = json["data_taskGraph"].toArray();
    for (int i = 0; i < 1; i++)
    {
        QJsonArray row = data[i].toArray();

        for (int j = 0; j < 3; j++) {
            graph_task->setItem(i, j, new QTableWidgetItem(row[j].toString()));
        }
    }
    data = json["data_restrictionsGraph"].toArray();
    for (int i = 0; i < rowCountGraph; i++)
    {
        QJsonArray row = data[i].toArray();

        for (int j = 0; j < 3; j++) {
            graph_restrictions->setItem(i, j, new QTableWidgetItem(row[j].toString()));
        }
    }

    return true;
}

bool ModelStorage::save(const QString& fileName,const QTableWidget* simplex_task, const QTableWidget* simplex_restrictions, const QTableWidget* graph_task, const QTableWidget* graph_restrictions) {
    QFile saveFile(fileName);
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QJsonObject json;
    json["rowCountTask"] = simplex_task->rowCount();
    json["columnCountTask"] = simplex_task->columnCount();

    QJsonArray data;
    for (int i = 0; i < simplex_task->rowCount(); i++) {
        QJsonArray row;

        for (int j = 0; j < simplex_task->columnCount(); j++) {
            row.append(QJsonValue(simplex_task->item(i, j)->text()));
        }

        data.append(row);
    }
    json["data_task"] = data;
    data = {};


    for (int i = 0; i < graph_task->rowCount(); i++) {
        QJsonArray row;

        for (int j = 0; j < graph_task->columnCount(); j++) {
            row.append(QJsonValue(graph_task->item(i, j)->text()));
        }

        data.append(row);
    }
    json["data_taskGraph"] = data;
    data = {};

    json["rowCountRestrictions"] = simplex_restrictions->rowCount();
    json["columnCountRestrictions"] = simplex_restrictions->columnCount();
    json["rowCountRestrictionsGraph"] = graph_restrictions->rowCount();
    json["columnCountRestrictionsGraph"] = graph_restrictions->columnCount();

    for (int i = 0; i < simplex_restrictions->rowCount(); i++) {
        QJsonArray row;

        for (int j = 0; j < simplex_restrictions->columnCount(); j++) {
            row.append(QJsonValue(simplex_restrictions->item(i, j)->text()));
        }

        data.append(row);
    }
    json["data_restrictions"] = data;
    data = {};


    for (int i = 0; i < graph_restrictions->rowCount(); i++) {
        QJsonArray row;

        for (int j = 0; j < graph_restrictions->columnCount(); j++) {
            row.append(QJsonValue(graph_restrictions->item(i, j)->text()));
        }

        data.append(row);
    }
    json["data_restrictionsGraph"] = data;

    QJsonDocument saveDoc(json);
    saveFile.write(saveDoc.toJson());

    return true;
}

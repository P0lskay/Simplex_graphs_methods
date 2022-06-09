#include "modelstorage.h"


bool ModelStorage::load(const QString& fileName, QTableWidget* model_task, QTableWidget* model_restrictions, QSpinBox* variables, QSpinBox* restrictions) {
    QFile loadFile(fileName);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }
    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc = QJsonDocument::fromJson(saveData);
    QJsonObject json = loadDoc.object();

    model_task->clear();

    const int rowCount = json["rowCount"].toInt();
    const int columnCount = json["columnCount"].toInt();
    QJsonArray data = json["data"].toArray();

    variables->setValue(columnCount-1);
    restrictions->setValue(rowCount-1);

    for (int i = 0; i < rowCount; i++) {
        QJsonArray row = data[i].toArray();

        for (int j = 0; j < columnCount; j++) {
            model_task->setItem(i, j, new QTableWidgetItem(row[j].toString()));
        }
    }

    return true;
}

bool ModelStorage::save(const QString& fileName,const QStandardItemModel& model_task, const QStandardItemModel& model_restrictions) {
    QFile saveFile(fileName);
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QJsonObject json;
    json["rowCountTask"] = model_task.rowCount();
    json["columnCountTask"] = model_task.columnCount();

    QJsonArray data;
    for (int i = 0; i < model_task.rowCount(); i++) {
        QJsonArray row;

        for (int j = 0; j < model_task.columnCount(); j++) {
            row.append(QJsonValue(model_task.item(i, j)->text()));
        }

        data.append(row);
    }
    json["data"] = data;

    QJsonDocument saveDoc(json);
    saveFile.write(saveDoc.toJson());

    return true;
}

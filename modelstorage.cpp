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

    const int rowCount = json["rowCountRestrictions"].toInt();
    const int columnCount = json["columnCountTask"].toInt();
    QJsonArray data = json["data_task"].toArray();

    variables->setValue(columnCount-1);
    restrictions->setValue(rowCount+1);

    for (int i = 0; i < 1; i++) {
        QJsonArray row = data[i].toArray();

        for (int j = 0; j < columnCount; j++) {
            model_task->setItem(i, j, new QTableWidgetItem(row[j].toString()));
        }
    }


    data = json["data_restrictions"].toArray();

        for (int i = 0; i < rowCount+1; i++) {
            QJsonArray row = data[i].toArray();

            for (int j = 0; j < columnCount; j++) {
                model_restrictions->setItem(i, j, new QTableWidgetItem(row[j].toString()));
            }
        }

    return true;
}

bool ModelStorage::save(const QString& fileName,const QTableWidget* model_task, const QTableWidget* model_restrictions) {
    QFile saveFile(fileName);
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    QJsonObject json;
    json["rowCountTask"] = model_task->rowCount();
    json["columnCountTask"] = model_task->columnCount();

    QJsonArray data;
    for (int i = 0; i < model_task->rowCount(); i++) {
        QJsonArray row;

        for (int j = 0; j < model_task->columnCount(); j++) {
            row.append(QJsonValue(model_task->item(i, j)->text()));
        }

        data.append(row);
    }
    json["data_task"] = data;

    json["rowCountRestrictions"] = model_restrictions->rowCount();
    json["columnCountRestrictions"] = model_restrictions->columnCount();

    for (int i = 0; i < model_restrictions->rowCount(); i++) {
        QJsonArray row;

        for (int j = 0; j < model_restrictions->columnCount(); j++) {
            row.append(QJsonValue(model_restrictions->item(i, j)->text()));
        }

        data.append(row);
    }
    json["data_restrictions"] = data;

    QJsonDocument saveDoc(json);
    saveFile.write(saveDoc.toJson());

    return true;
}

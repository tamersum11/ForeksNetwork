#pragma once

#include <QObject>
#include <QtWidgets/QWidget>
#include <QVBoxLayout>
#include <QIcon>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>

#include "foreksframe.h"
#include "forekstablewidget.h"

class ForeksNetworkView : public QWidget
{
    Q_OBJECT

public:
    explicit ForeksNetworkView(QWidget *parent = Q_NULLPTR);
    ~ForeksNetworkView();

    void setJsonDocument(QJsonDocument newDocument);

private:
    void setCentralFrame(void);
    void setForeksTableWidgetItems(void);

private:
    ForeksFrame* centralFrame;
    QVBoxLayout* centralLayout;
    QVBoxLayout* centralFrameLayout;
    ForeksTableWidget* table;

    QJsonDocument* document;
};

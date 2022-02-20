#include "ForeksNetworkView.h"

ForeksNetworkView::ForeksNetworkView(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color:#0d1117;");
    resize(800, 1000);
    setWindowTitle("NetWork");
    setWindowIcon(QIcon(QPixmap(":/new/prefix1/server.svg")));
    
    centralLayout = new QVBoxLayout();
    setCentralFrame();
    centralLayout->addWidget(centralFrame);
    setLayout(centralLayout);

    document = new QJsonDocument();
}

ForeksNetworkView::~ForeksNetworkView()
{
    delete document;
    document = nullptr;

    delete table;
    table = nullptr;

    delete centralFrameLayout;
    centralFrameLayout = nullptr;

    delete centralFrame;
    centralFrame = nullptr;

    delete centralLayout;
    centralLayout = nullptr;
}

void ForeksNetworkView::setJsonDocument(QJsonDocument newDocument)
{
    *document = newDocument;
    setForeksTableWidgetItems();
}

void ForeksNetworkView::setCentralFrame(void)
{
    centralFrame = new ForeksFrame();
    centralFrameLayout = new QVBoxLayout();
    table = new ForeksTableWidget();
    centralFrameLayout->addWidget(table);
    centralFrame->setLayout(centralFrameLayout);
}

void ForeksNetworkView::setForeksTableWidgetItems(void)
{
    int i = 1;
    for(const QJsonValue& value: document->array())
    {
        QJsonObject obj = value.toObject();
        table->setItem(i, 1, new QTableWidgetItem(obj["_id"].toString()));
        table->setItem(i, 2, new QTableWidgetItem(obj["code"].toString()));
        table->setItem(i, 3, new QTableWidgetItem(obj["status"].toString()));
        table->setItem(i, 4, new QTableWidgetItem(obj["legacyCode"].toString()));
        table->setItem(i, 5, new QTableWidgetItem(obj["name"].toString()));
        table->setItem(i, 6, new QTableWidgetItem(obj["description"].toString()));
        table->setItem(i, 7, new QTableWidgetItem(obj["marketSector"].toString()));
        table->setItem(i, 8, new QTableWidgetItem(obj["securityType"].toString()));
        table->setItem(i, 9, new QTableWidgetItem(obj["bicCode"].toString()));
        table->setItem(i, 10, new QTableWidgetItem(obj["country"].toString()));
        table->setItem(i, 11, new QTableWidgetItem(obj["type"].toString()));
        table->setItem(i, 12, new QTableWidgetItem(obj["lastUpdateTime"].toString()));

        i++;
    }
}

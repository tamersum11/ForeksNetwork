#include "ForeksNetworkModel.h"

ForeksNetworkModel::ForeksNetworkModel(QObject *parent)
	: QObject(parent)
{
    document = new QJsonDocument();
	manager = new QNetworkAccessManager();

    QObject::connect(manager, &QNetworkAccessManager::finished, this, &ForeksNetworkModel::getJSON);

    QNetworkRequest request(QUrl("http://test.feed.frks.net/broker/search"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    manager->get(request);
}

ForeksNetworkModel::~ForeksNetworkModel()
{
	delete manager;
	manager = nullptr;

    delete document;
    document = nullptr;
}

QJsonDocument ForeksNetworkModel::getJsonDocument(void) const
{
    return *document;
}

void ForeksNetworkModel::getJSON(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) 
    {
        QByteArray result = reply->readAll();
        *document = QJsonDocument::fromJson(result);
        QJsonArray array = document->array();

        emit setView();
    }
    else
    {
        QMessageBox::critical(nullptr, "ERROR", "Network Error");
    }

    reply->deleteLater();
}
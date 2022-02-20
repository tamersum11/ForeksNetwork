#pragma once

#include <QObject>
#include <QtNetwork>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QMessageBox>
#include <QJsonDocument>
#include <QDebug>

class ForeksNetworkModel : public QObject
{
	Q_OBJECT

public:
	explicit ForeksNetworkModel(QObject *parent = nullptr);
	~ForeksNetworkModel();

	QJsonDocument getJsonDocument(void) const;

public slots:
	void getJSON(QNetworkReply* reply);

signals:
	void setView();

private:
	QNetworkAccessManager* manager;
	QJsonDocument* document;
};

#pragma once

#include <QObject>
#include <QDebug>

#include "ForeksNetworkModel.h"
#include "ForeksNetworkView.h"

class ForeksNetworkController : public QObject
{
	Q_OBJECT

public:
	explicit ForeksNetworkController(QObject *parent = nullptr);
	~ForeksNetworkController();

	ForeksNetworkView& getView(void) const;

public slots:
	void setForeksNetworkView();

private:
	ForeksNetworkView* view;
	ForeksNetworkModel* model;
};

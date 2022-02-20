#include "ForeksNetworkController.h"

ForeksNetworkController::ForeksNetworkController(QObject *parent)
	: QObject(parent)
{
	view = new ForeksNetworkView();
	model = new ForeksNetworkModel();

	QObject::connect(model, &ForeksNetworkModel::setView, this, &ForeksNetworkController::setForeksNetworkView);
}

ForeksNetworkController::~ForeksNetworkController()
{
	delete view;
	view = nullptr;

	delete model;
	model = nullptr;
}

ForeksNetworkView& ForeksNetworkController::getView(void) const
{
	return *view;
}

void ForeksNetworkController::setForeksNetworkView()
{
	view->setJsonDocument(model->getJsonDocument());
}

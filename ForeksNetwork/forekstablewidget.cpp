#include "forekstablewidget.h"

ForeksTableWidget::ForeksTableWidget(QWidget *parent)
	: QTableWidget(parent)
{
	QString styleSheet = "border-radius:30px;border:1px solid #bdc1c6;background:transparent;background-color:white;color:black;";

	font = new QFont("Century Gothic");
	font->setBold(true);
	font->setPointSizeF(14);

	setFont(*font);
	setStyleSheet(styleSheet);
	setColumnCount(12);
	QStringList headerLabels;
	headerLabels << "_id" << "code" << "status" << "legacyCode" << "name" << "description" 
				 << "marketSector" << "securityType" << "bicCode" << "country" << "type" << "lastUpdateTime";
	setHorizontalHeaderLabels(headerLabels);
	setShowGrid(true);
}

ForeksTableWidget::~ForeksTableWidget()
{
	delete font;
	font = nullptr;
}
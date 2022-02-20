#pragma once

#include <QTableWidget>
#include <QStringList>
#include <QFont>

class ForeksTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	explicit ForeksTableWidget(QWidget *parent = nullptr);
	~ForeksTableWidget();

private:
	QFont* font;
};

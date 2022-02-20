#include <QtWidgets/QApplication>

#include "ForeksNetworkController.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ForeksNetworkController c;
    c.getView().show();

    return a.exec();
}

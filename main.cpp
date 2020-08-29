#include "igis.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IGIS w;
    w.show();
    return a.exec();
}

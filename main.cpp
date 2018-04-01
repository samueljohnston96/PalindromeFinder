#include "palindromefinder.h"
#include <QApplication>
#include <QAbstractButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PalindromeFinder w;
    w.show();

    return a.exec();
}

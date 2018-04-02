#ifndef PALINDROMEFINDER_H
#define PALINDROMEFINDER_H

#include <QMainWindow>
#include <QPushButton>
#include <QInputDialog>
#include <QIntValidator>
#include <QGridLayout>
#include <QObject>
#include <cmath>

namespace Ui {
class PalindromeFinder;
}

class PalindromeFinder : public QMainWindow
{
    Q_OBJECT
public:
    explicit PalindromeFinder(QWidget *parent = 0);
    ~PalindromeFinder();
public slots:
    void FindPalindrome();

private:
    Ui::PalindromeFinder *ui;
};

#endif // PALINDROMEFINDER_H

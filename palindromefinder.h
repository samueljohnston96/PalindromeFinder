#ifndef PALINDROMEFINDER_H
#define PALINDROMEFINDER_H

#include <QMainWindow>

namespace Ui {
class PalindromeFinder;
}

class PalindromeFinder : public QMainWindow
{
    Q_OBJECT

public:
    explicit PalindromeFinder(QWidget *parent = 0);
    ~PalindromeFinder();

private:
    Ui::PalindromeFinder *ui;
};

#endif // PALINDROMEFINDER_H

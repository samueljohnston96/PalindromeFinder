#include "palindromefinder.h"
#include "ui_palindromefinder.h"

PalindromeFinder::PalindromeFinder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PalindromeFinder)
{
    ui->setupUi(this);
}

PalindromeFinder::~PalindromeFinder()
{
    delete ui;
}

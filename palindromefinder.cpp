#include "palindromefinder.h"
#include "ui_palindromefinder.h"

PalindromeFinder::PalindromeFinder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PalindromeFinder)
{
    ui->setupUi(this);
    //Connect button click with FindPalindrome function.
    QObject::connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(FindPalindrome()));
}

PalindromeFinder::~PalindromeFinder()
{
    delete ui;
}

//Function Palindrome Finder.  Finds the largest palindrome between the two numbers inside of the input boxes.
//Does not require the numbers to be entered in any order.
//Will have error message if any non-numeric character is entered.  Assumes "" is a 0.
void PalindromeFinder::FindPalindrome(){
    QString first = this->ui->firstNumber->toPlainText();                       //Pulls the 2 numbers from their respective text boxes
    QString second = this->ui->secondNumber->toPlainText();
    QRegExp re("\\d*");                                                         //Regex for numbers only (or nothing)
    if (not re.exactMatch(first) || not re.exactMatch(second)){
        this->ui->resultsBox->setPlainText("Error!  Please enter a number.");
        return;
    }
    if(first == ""){                                                            //Check if either number is empty
        first = "0";
    }
    if(second == ""){
        second = "0";
    }                                                                           //Replace error message if any is there for now.
    this->ui->resultsBox->setPlainText("Calculating...\n...\n...\njk this is going to be implemented after I make the ui pretty.");
    int max = first.toInt();
    int min = second.toInt();                                                   //Set max and min value to make calculations easier.
    if(max < min){
        int temp = min;
        min = max;
        max = temp;
    }
}

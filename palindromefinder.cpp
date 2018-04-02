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
    this->ui->resultsBox->setPlainText("");                                     //Empties results box so that the previous answer doesn't affect the current answer.
    QString first = this->ui->firstNumber->toPlainText();                       //Pulls the 2 numbers from their respective text boxes
    QString second = this->ui->secondNumber->toPlainText();
    QRegExp re("\\d*");                                                         //Regex for numbers only (or nothing)
    if (not re.exactMatch(first) || not re.exactMatch(second)){
        this->ui->resultsBox->setPlainText("Error!  Please enter a number.");   //Error message
        return;
    }
    if(first == ""){                                                            //Check if either number is empty
        first = "0";
    }
    if(second == ""){
        second = "0";
    }
    int max = first.toInt();
    int min = second.toInt();                                                   //Set max and min value to make sure the first is larger
    if(max < min){                                                              //If first isn't larger swap the values.
        QString temp = second;
        second = first;
        first = temp;
        int tempInt = min;
        min = max;
        max = tempInt;
    }
    int n = first.length();
    int x = 1;
    std::vector<int> palin;
    std::vector<int> maxval;
    while(first[x] == "0"){                                                     //When the number loses digits (any multiple of 10) it messes up my algorithm since it cannot lose digits
        x++;                                                                    //This prevents any issues by printing out the proper number of 9's and returning
    }
    if(x == n){
        if(first[0] == "1"){
            for(x = 0; x < n-1; x++){
                this->ui->resultsBox->moveCursor (QTextCursor::End);
                this->ui->resultsBox->insertPlainText (QString::number(9));
            }
            return;

        }
    }
                                                                                //Create the vectors to work with
    for(int x = 0; x < n; x++){
        palin.push_back(first[x].digitValue());
        maxval.push_back(first[n-(x+1)].digitValue());
    }
    for(int x = 0; x < n; x++){                                                 //If the front digit is greater than or equal to then replace it with the lower value from the other end.
        if(maxval[x] >= maxval[n-(x+1)]){                                       //Since it must be the largest between the range you need to go down from the largest value to get there quicker.
            palin[x] = maxval[n-(x+1)];
            maxval[x] = palin[x];
        }
        else if(maxval[x] < maxval[n-(x+1)]){                                   //If the value is smaller then you must "borrow" 10 from the next digit, and then swap.
            int y = 1;
            while(maxval[x+y] == 0){                                            //Corner case where the next digit is a zero so you must borrow higher up.
                maxval[x+y] = 9;
                y++;
            }
            maxval[x+y] = maxval[x+y] - 1;                                      //Borrow, change value, then set the correct values.
            maxval[x] = maxval[n-(x+1)];
            palin[x] = maxval[x];
        }
    }
    int answer = 0;
    QString result = "";
    for(int x = 0; x < n; x++){                                                 //Create the result by concatenating the vector's pieces.  Simple base math.
        answer = answer + (palin[n-(x+1)] * pow(10, x));
    }
    if(answer < second.toInt()){
          result = "None Possible.  Please increase range.";                    //Error checking to see if the value actually went too low and fell out of the range.
    }
    else{
        result = QString::number(answer);
    }
    this->ui->resultsBox->setPlainText(result);                                 //print result then exit function
    return;
}

/*Design a class called Date that has integer data members to store month, day, and year. 
The class should have a three-parameter default constructor that allows the date to be set at the time a new Date object is created. 
If the user creates a Date object without passing any arguments, or if any of the values passed are invalid, the default values of 
1, 1, 2001 (i.e., January 1, 2001) should be used. 

The class should have member functions to print the date in the following formats:
    - 3/15/20
    - March 15, 2020
    - 15 March 2020

Demonstrate the class by writing a program that uses it. Be sure your program only accepts reasonable values for month and day. 
The month should be between 1 and 12. The day should be between 1 and the number of days in the selected month.*/

#include <iostream>
using namespace std;

// whole date can be updated at once and it will reset to default if that fails
// day month and year can be changed independently but it won't update the date if given invalid input
class Date{

private:
    int day;
    int month;
    int year;

    void printMonthStr();

public:
    Date(int d = 1, int m = 1, int y = 2001);

    void setDate(int d, int m, int y);

    bool setDay(int d);
    bool setMonth(int m);

    bool setYear(int y);

    void printSlashed();

    void printMonthFirst();

    void printDayFirst();
};

Date::Date(int d, int m, int y){
    setDate(d,m,y);
}

void Date::printMonthStr(){
    string monthStr = "null";
    switch(month){
        case 1:
            monthStr = "January";
            break;
        case 2:
            monthStr = "Febuary";
            break;
        case 3:
            monthStr = "March";
            break;
        case 4:
            monthStr = "April";
            break;
        case 5:
            monthStr = "May";
            break;
        case 6:
            monthStr = "June";
            break;
        case 7:
            monthStr = "July";
            break;
        case 8:
            monthStr = "August";
            break;
        case 9:
            monthStr = "September";
            break;
        case 10:
            monthStr = "October";
            break;
        case 11:
            monthStr = "November";
            break;
        case 12:
            monthStr = "December";
            break;
    }

    cout << monthStr;
}

void Date::setDate(int d, int m, int y){
    if(!setYear(y) || !setMonth(m)  || !setDay(d)){
        this->day = 1;
        this->month = 1;
        this->year = 2001;
    }
}

bool Date::setDay(int d){
    if(d < 0 || d > 31)
        return false;
        
    int maxDays = 31;

    if(month == 2)
        maxDays = year % 4 == 0 ? 29 : 28;

    switch(month){
        case 4:
        case 6:
        case 9:
        case 11:
            maxDays = 30;
            break;
    }

    if(d > maxDays)
        return false;
    
    day = d;
    return true;
}

bool Date::setMonth(int m){
    if(m < 0 || m > 12)
        return false;

    month = m;
    return true;
}

bool Date::setYear(int y){
    if(y < 0)
        return false;

    year = y;
    return true;
}
void Date::printSlashed(){
    cout << this->month << "/" << this->day << "/" << this->year << '\n';
}

void Date::printMonthFirst(){
    printMonthStr();
    printf(" %d, %d\n", day, year);
}

void Date::printDayFirst(){
    printf("%d ", day);
    printMonthStr();
    printf(" %d\n", year);
}

int main(){

    printf("Working date:\n");
    Date newDate(15,10,1078);
    newDate.printSlashed();
    newDate.printMonthFirst();
    newDate.printDayFirst();

    printf("\nBad day:\n");
    newDate.setDate(40,6,2025);
    newDate.printSlashed();
    newDate.printMonthFirst();
    newDate.printDayFirst();

    printf("\nBad month:\n");
    newDate.setDate(16,13,2069);
    newDate.printSlashed();
    newDate.printMonthFirst();
    newDate.printDayFirst();

    printf("\nBad year: \n");
    newDate.setDate(5,11,-1);
    newDate.printSlashed();
    newDate.printMonthFirst();
    newDate.printDayFirst();

    printf("\nValid:\n");
    newDate.setDate(7,3,2021);
    newDate.printSlashed();
    newDate.printMonthFirst();
    newDate.printDayFirst();

    printf("\nNot leap year:\n");
    newDate.setDate(29,2,2022);
    newDate.printSlashed();
    newDate.printMonthFirst();
    newDate.printDayFirst();

    printf("\nLeap year:\n");
    newDate.setDate(29,2,2024);
    newDate.printSlashed();
    newDate.printMonthFirst();
    newDate.printDayFirst();

    //delete newDate;  // dynamicly allocated before but now its not so I dont need to free the memory anymore
    //newDate = nullptr;
    return 0;
}
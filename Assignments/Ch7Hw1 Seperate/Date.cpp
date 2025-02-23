
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

#include "./Date.h"
#include <iostream>

using namespace std;

Date::Date(int d, int m , int y){
    setDate(d,m,y);
};

void Date::setDate(int d, int m , int y){
    if(!setYear(y) || !setMonth(m)  || !setDay(d)){
        this->day = 1;
        this->month = 1;
        this->year = 2001;
    }
}

bool Date::setDay(int d){
    if(d < 0 || day > 31)
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
};

void Date::printSlashed(){
    cout << this->month << "/" << this->day << "/" << this->year << '\n';
};

void Date::printMonthFirst(){
    printMonthStr();
    printf(" %d, %d\n", day, year);
};

void Date::printDayFirst(){
    printf("%d ", day);
    printMonthStr();
    printf(" %d\n", year);
};


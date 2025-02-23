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
#include "./Date.h"
using namespace std;

int main(){

    printf("Working date:\n");
    Date* newDate = new Date(15,10,1078);
    newDate->printSlashed();
    newDate->printMonthFirst();
    newDate->printDayFirst();

    printf("\nBad day:\n");
    newDate->setDate(40,6,2025);
    newDate->printSlashed();
    newDate->printMonthFirst();
    newDate->printDayFirst();

    printf("\nBad month:\n");
    newDate->setDate(16,13,2069);
    newDate->printSlashed();
    newDate->printMonthFirst();
    newDate->printDayFirst();

    printf("\nBad year: \n");
    newDate->setDate(5,11,-1);
    newDate->printSlashed();
    newDate->printMonthFirst();
    newDate->printDayFirst();

    printf("\nValid:\n");
    newDate->setDate(7,3,2021);
    newDate->printSlashed();
    newDate->printMonthFirst();
    newDate->printDayFirst();

    return 0;
}
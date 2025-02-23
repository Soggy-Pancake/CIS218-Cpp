#ifndef DATE_CLASS
#define DATE_CLASS

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

#endif
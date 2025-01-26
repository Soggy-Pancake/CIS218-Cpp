/*Type in Program 1-1 from the textbook.*/

#include <iostream>
using namespace std;

int main(){

    double hours, rate, pay;

    // Get the number of hours worked.
    cout << "How many hours did you work? ";
    cin >> hours;

    // Get the hourly pay rate.
    cout << "How much do you get paid per hour? ";
    cin  >> rate;

    pay = hours * rate;

    cout << "You have earned $" << pay << endl;
    return 0;

}
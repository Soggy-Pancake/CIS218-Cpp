
/*Write a program that calculates how much a Little League baseball team spent last year to purchase new baseballs. 
The program should prompt the user to enter the number of baseballs purchased and the cost of each baseball. 
It should then calculate and display the total amount spent to purchase the baseballs.*/

#include <iostream>
using namespace std;

int main(){

    double balls, cost;

    cout << "Baseballs purchased: ";
    cin >> balls;

    cout << "Price per ball: ";
    cin  >> cost;

    cout << "Total spent: $" << balls * cost << '\n';
    return 0;

}
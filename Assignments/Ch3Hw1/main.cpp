/*Write a program that asks the user to enter their monthly costs for each of the 
following housing-related expenses:

 - rent or mortgage payment
 - phones
 - Internet service utilities
 - cable

The program should then display the total monthly cost of these expenses and 
the total annual cost of these expenses.*/

#include <iostream>
using namespace std;

int main(){

    double house, phone, isp, cable;

    printf("Anual cost calculator:\n");
    printf("Monthly rent/mortgage payment: $");
    cin >> house;

    printf("Monthly phone bill: $");
    cin >> phone;

    printf("Monthly internet bill: $");
    cin >> isp;

    printf("Monthly cable bill: $");
    cin >> cable;

    double mTotal = house + phone + isp + cable;
    double yTotal = mTotal * 12;

    printf("\nMonthly total: $%.2f\n", mTotal);
    printf("Yearly total: $%.2f\n", yTotal);

    return 0;

}
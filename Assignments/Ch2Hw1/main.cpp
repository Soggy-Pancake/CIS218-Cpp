
/*Write a program that computes the tax and tip on a restaurant bill for a diner with a $44.50 meal charge. 
The tax should be 6.75 percent of the meal charge. The tip should be 15 percent of the total after adding tax. 
Display the meal cost, tax amount, tip amount, and total bill on the screen.*/

#include <iostream>
using namespace std;

int main(){

    double meal, taxAmount, tipAmount, total;
    double tip = 0.15;
    double tax = 0.0675;

    cout << "Meal price: ";
    cin >> meal;

    taxAmount = tax * meal;
    tipAmount = tip * meal;
    total = meal + tipAmount + taxAmount;   

    printf("Tax (%.2f%%): $%.3f\n", tax * 100, taxAmount);
    printf("Tip (%.2f%%): $%.3f\n", tip * 100, tipAmount);
    printf("Total: $%0.2f\n", total);

    return 0;

}
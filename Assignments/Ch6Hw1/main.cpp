/*Write a program that asks the user to enter an item’s wholesale cost and its markup percentage. 
It should then display the item’s retail price. For example:

* If an item's wholesale cost is $5.00 and its markup percentage is 100 percent, then the item’s retail price is $10.00.
* If an item's wholesale cost is $5.00 and its markup percentage is 50 percent, then the item’s retail price is $7.50.

The program should have a function named calculateRetail that receives the wholesale cost 
and the markup percentage as arguments and returns the retail price of the item.*/

#include <iostream>
using namespace std;

double calculateRetail(double ws, double markup){
    return ws * (1.0 + (markup / 100.0));
}

int main(){

    double wholesale, markup, retail;

    cout << "Wholesale cost: ";
    cin >> wholesale;

    cout << "Markup %: ";
    cin  >> markup;

    retail = calculateRetail(wholesale, markup);

    printf("The retail price is $%.2f\n", retail);
    return 0;

}
/* Change for a Dollar Game
Create a change-counting game that asks the user to enter what coins to use to make exactly one dollar. 
The program should ask the user to enter the number of pennies, nickels, dimes, and quarters. 
If the total value of the coins entered is equal to one dollar, the program should congratulate the user 
for winning the game. Otherwise, the program should display a message indicating whether the amount entered 
was more or less than one dollar. Use constant variables to hold the coin values.*/

#include <iostream>
using namespace std;

int main(){

    // Seriously how am I still typing in the same exact program as 1-1 but slightly different still?
    const int nickelVal = 5;
    const int dimeVal = 10;
    const int quarterVal = 25;

    int pennies, nickels, dimes, quarters, total;

    printf("Enter various numbers of coins that added together make a dollar:\n");

    printf("Pennies: ");
    cin >> pennies;

    printf("Nickels: ");
    cin >> nickels;

    printf("Dimes: ");
    cin >> dimes;

    printf("Quarters: ");
    cin >> quarters;

    total = pennies + (nickels * nickelVal) + (dimes * dimeVal) + (quarters * quarterVal);

    if(total == 100){
        printf("Correct! You made exactly $1\n");
        return 0;
    }

    if(total < 100) {
        printf("Not enough! You made $%.2f\n", total / 100.0);
        return 0;
    }

    if(total > 100){
        printf("Too much! You made $%.2f\n", total / 100.0);
        return 0;
    }

    return 1;

}
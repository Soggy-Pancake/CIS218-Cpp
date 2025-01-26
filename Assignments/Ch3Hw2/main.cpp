/* How many Calories?
A bag of cookies holds 30 cookies. The calorie information on the bag claims that there are 10 "servings"
in the bag and that a serving equals 240 calories. Write a program that asks the user to input how many cookies 
they actually ate and then reports how many total calories were consumed.*/

#include <iostream>
using namespace std;

int main(){

    int calPerCookie = 80;
    double servingCount;
    int totalCalories, ate;

    printf("Cookies eaten: ");
    cin >> ate;

    servingCount = ate / 3.0;
    totalCalories = ate * calPerCookie;

    printf("Servings eaten: %.2f\n", servingCount);
    printf("Total calories: %d\n", totalCalories);

    return 0;

}

/*A particular employee earns $39,000 annually. Write a program that determines and displays what 
the amount of his gross pay will be for each pay period if he is paid twice a month 
(24 paychecks per year) and if he is paid bi-weekly (26 checks per year).*/

#include <iostream>
using namespace std;

int main(){

    double income = 39000;

    double twiceMonthly = 39000 / 24;
    double biWeekly = 39000 / 26;

    printf("2x Month: $%.2f\n", twiceMonthly);
    printf("biWeekly: $%.2f\n", biWeekly);

    return 0;

}
/* Min Max
Write a program with a loop that lets the user enter a series of integers, followed by the end sentinel 
−99 to signal the end of the series. After all the numbers have been entered, 
the program should display the largest and smallest numbers entered.*/

#include <iostream>
#include <string>
using namespace std;

int askInt(string message){

    int val;

    while(true){

        printf("%s", message.c_str());
        cin >> val;

        if(!cin.fail()){
            cin.clear();
            break;
        } 

        cin.clear();
        cin.ignore(10000, '\n');
        printf("Type a whole number! (1,2,3...)\n");
    }

    return val;
}

int main(){

    int smallest, largest, input;

    input = askInt("Enter an integer (or -99 to quit): ");

    if(input == -99){
        printf("Exited before any input!\n");
        return 0;
    }

    smallest = input;
    largest = input;

    while(true){

        input = askInt("Enter another integer (or -99 to quit): ");

        if(input == -99)
            break;

        if(input < smallest)
            smallest = input;

        if(input > largest)
            largest = input;
    }

    printf("\nThe largest number you entered was %d.\nThe smallest number you entered was %d.\n", largest, smallest);
    return 0;

}
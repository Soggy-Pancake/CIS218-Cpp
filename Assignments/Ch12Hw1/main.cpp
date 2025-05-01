/*
6. Sum of Digits in a String
Write a program that asks the user to enter a series of single-digit numbers with nothing separating them. 
Read the input as a C-string or a string object. The program should display the sum of all the single-digit numbers in the string. 
For example, if the user enters 2514, the program should display 12, which is the sum of 2, 5, 1, and 4. 
The program should also display the highest and lowest digits in the string.
*/

#include <iostream>
#include <string>

using namespace std;

int main(){

    int highest, lowest, total, val, i;
    string input;

    while(1){
        printf("Enter a string of digits: ");
        getline(cin, input);

        lowest = 9;
        highest = 0;
        total = 0;

        for(i = 0; i < input.length(); i++){
            if(input[i] < '0' || input[i] > '9'){
                printf("[ERROR] Invalid character at index %d.\n\n");
                break;
            }
            val = input[i] - '0';
            total += val;

            if(val < lowest)
                lowest = val;

            if(val > highest)
                highest = val;
        }

        if(i < input.length())
            continue; // Broke out of string early

        printf("\nThe sum of digits is %d\n", total);
        printf("The minimum digit is %d\n", lowest);
        printf("The maximum digit is %d\n", highest);
        break;
    }
    

    return 0;
}
/*Charge Account Validation
Write a program that lets the user enter a charge account number. The program should determine 
if the number is valid by checking for it in the following list:

5658845	4520125	7895122	8777541	8451277	1302850
8080152	4562555	5552012	5050552	7825877	1250255
1005231	6545231	3852085	7576651	7881200	4581002

Initialize a one-dimensional array with these values. Then use a simple linear search to locate the number entered by the user. 
If the user enters a number that is in the array, the program should display a message saying the number is valid. 
If the user enters a number not in the array, the program should display a message indicating it is invalid.*/

#include <iostream>
#include <string>
using namespace std;

int validIDs[] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 1005231, 6545231, 3852085, 7576651, 7881200, 4581002};

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

    int accNum = askInt("Please enter a 7-digit account number: ");

    bool valid = false;

    for(int i = 0; i < 18; i++)
        if(validIDs[i] == accNum){
            valid = true;
            break;
        }

    if(valid)
        printf("The number you entered is valid.\n");
    else
        printf("The number you entered is invalid.\n");
        

    return 0;
}
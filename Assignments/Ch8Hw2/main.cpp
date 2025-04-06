/*Lottery
Write a program that simulates a lottery. The program should have an array of five integers named winningDigits, 
with a randomly generated number in the range of 0 through 9 for each element in the array. 
The program should ask the user to enter five digits and should store them in a second integer array named player. 
The program must compare the corresponding elements in the two arrays and count how many digits match.


*/

#include <iostream>
#include <random>
#include <string>
using namespace std;

int* getPlayerNums(){

    int* player = new int[5];

    string vals;
    while(true){
        printf("Enter the 5 digits of your lottery number, separated by blanks: ");
        getline(cin, vals);

        if(vals.length() > 9) // Trim in case of extra space or extra digits
            vals = vals.substr(0,9);

        int valid = 0;

        if(vals.length() == 9){
            for(int i = 0;vals.length();){
                if(vals[i] >= '0' && vals[i] <= '9'){
                    if(i == vals.length() - 1){
                        player[valid++] = vals[i] - '0';
                        break;
                    }

                    if(vals[i + 1] == ' '){
                        player[valid++] = vals[i] - '0';
                        i += 2;
                    }
                } else {
                    printf("Invalid input!\n");
                    break;
                }       
            }
        }

        if(valid == 5)
            break;

        printf("Type 5 numbers between 0 and 9 with a space between! (1 2 3 4 5)\n");

    }

    return player;
}


int* genWinning(){

    int* winningDigits = new int[5];

    for(int i = 0; i < 5; i++)
        winningDigits[i] = rand() % 10;

    return winningDigits;
}

void printArray(int* array){

    for(int i = 0; i < 5; i++)
        printf("%d", array[i]);
    printf("\n");

    return;
}

int main(){

    int* winningDigits = genWinning();
    int* player = getPlayerNums();

    int matching = 0;
    for(int i = 0; i < 5; i++){
        if(player[i] == winningDigits[i])
            matching++;
    }

    printf("\nWinning number:\t");
    printArray(winningDigits);

    printf("Your number:\t");
    printArray(player);
    

    printf("\nYou have %d matching digit", matching);
    if(matching == 1)
        printf(".\n");
    else
        printf("s.\n");

    //for(int i = 0; i < scoreCount; i++){ // just proving scores were stored
    //    printf("%d\n", scores[i]);
    //}

    delete[] winningDigits;
    delete[] player;

    return 0;

}
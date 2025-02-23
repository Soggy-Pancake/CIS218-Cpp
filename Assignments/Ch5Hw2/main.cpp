/* Sales Bar Chart
Write a program that asks the user to enter today’s sales rounded to the nearest $100 for each of three stores. 
The program should then produce a bar graph displaying each store’s sales. Create each bar in the graph 
by displaying a row of asterisks. Each asterisk should represent $100 of sales.*/

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

    int stores[] = {0,0,0}; // using array since its easier for using in a loop

    stores[0] = askInt("Enter today's sales for store 1: ");
    stores[1] = askInt("Enter today's sales for store 2: ");
    stores[2] = askInt("Enter today's sales for store 3: ");

    // Im not going to make the user round it themselves or trust that they did
    stores[0] = (int)round(stores[0] / 100.0);
    stores[1] = (int)round(stores[1] / 100.0);
    stores[2] = (int)round(stores[2] / 100.0);

    //printf("\n%d\n%d\n%d\n", store1, store2, store3);
    printf("\nDAILY SALES\n(each * = $100)\n\n");

    for(int i = 0; i < 3; i++){

        printf("Store %d: ", i + 1);

        for(int j = 0; j < stores[i]; j++){
            printf(j == stores[i] - 1 ? "*\n" : "*");
        }
    }

    return 0;
}
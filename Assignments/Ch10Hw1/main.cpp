
/*Pie a la Mode
Write a program that determines how many pieces of pie most people eat in a year. 
Set up an integer array that can hold responses from 30 people. 
For each person, enter the number of pieces they say they eat in a year. 
Then write a function that finds the mode of these 30 values. 
This will be the number of pie slices eaten by the most people. 
The function that finds and returns the mode should accept two arguments, an array of integers, 
and a value indicating how many elements are in the array.*/

#include <iostream>
#include <string>
using namespace std;

#define MAX_RESPONSES 10 // Sure ill change it to only 10 but its gonna be written in a way thats independent of the number entered unless the max is hit


int askInt(string message){
    int val;
    while(true){

        printf("%s", message.c_str());
        cin >> val;

        if(!cin.fail() && val >= -1){
            cin.clear();
            break;
        } 

        cin.clear();
        cin.ignore(10000, '\n');
        printf("Type a whole positive number! (1,2,3...)\n");
    }

    return val;
}

void sort(int *arr, int len){
    int tmp;

    for(int i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            if(arr[i] > arr[j]){
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

int getMode(int* arr, int len){
    if(len == 0) {
        printf("Empty array! Mode is null ig\n");
        return -1; // Empty array so its nothing
    }

    int mode = arr[0]; 
    int modeCount = 1;    
    int count = 0;

    for(int i = 0; i < len; i++){
        //printf("%d ", arr[i]);
        ++count;
        if((i > 0 && arr[i-1] != arr[i]) || i == len - 1){ // different number reset counter and check last num
            if(i == len - 1) ++count;
            if(count > modeCount){
                mode = arr[i-1];
                modeCount = count; // remove extra since we actually go one past
            }
            count = 0;
        }
    }

    //printf("Max count: %d\n", modeCount);

    return mode;
}

int* getEntries(int &count){

    int* entries = new int[MAX_RESPONSES];

    //for(int i = 0; i < MAX_RESPONSES; i++) // Dont actually need to do this
    //    entries[i] = -1; // Init

    for(count = 0; count < MAX_RESPONSES; count++){
        int val = askInt("");
        if(val == -1)
            break;

        entries[count] = val;
        if(count == MAX_RESPONSES - 1)
            printf("Max entry count reached!\n");
    }

    return entries;
}

int main(){

    printf("This program computes the mode of a sequence of numbers.\n");
    printf("Enter your sequence of numbers (max %d) and I will tell you the mode (enter -1 if finished):\n", MAX_RESPONSES);

    int numEntries;
    int* entries = getEntries(numEntries);

    printf("The mode of the list\n");

    // Input Validation
    for(int i = 0; i < numEntries; i++)
        printf("%d ", entries[i]);
    printf("\n");
    
    sort(entries, numEntries);

    // Sort Validation
    /*printf("Entry count: %d\n", numEntries);
    for(int i = 0; i < numEntries; i++)
        printf("%d ", entries[i]);
    printf("\n");*/

    int mode = getMode(entries, numEntries);
    printf("is %d.\n", mode);

    delete[] entries;
    return 0;
}
/*Recursive Array Sum
Write a function that accepts two arguments, an array of integers, and a number indicating the number of elements in the array. 
The function should recursively calculate the sum of all the numbers in the array. 
Demonstrate the use of the function in a program that asks the user to enter an array of numbers and prints its sum.*/

#include <iostream>
#include <string>

using namespace std;

int recursiveSum(int* arr, int size){
    if(--size == 0) // decrementing here is a hack to not need to subtract later for the recursive call
        return *arr;

    return *(arr + size) + recursiveSum(arr, size);
}

string trimWhitespace(string* str){

    string trimmed;
    char n, c;

    if(str->length() == 0)
        return *str;

    c = str->at(0);
    for(int i = 0; i < str->length(); i++){

        if(i == str->length() - 1){
            if(c != ' ')
                trimmed += c;
            break;
        }

        n = str->at(i+1);
        if(n == '\n' || n == '\t' || n == '\r')
            n = ' ';

        if(c != ' ' || (c == ' ' && n != ' ')){
            trimmed += c;
        }

        c = n;
    }

    //printf("Trimmed :%s...\n", trimmed.c_str());
    return trimmed;
}

bool isStringNumeric(string *inp){

    string str = *inp;

    for(int i = 0; i < str.length(); i++){
        if(str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
            return false;
    }

    return true;
}

int* getNums(int &size){ // FREE RETURN ARRAY

    string input;
    int* nums;

    while(1){
        // not going to ask for the size ill calculate it myself
        printf("Enter the list of numbers, separated by spaces:\n");

        getline(cin, input);

        input = trimWhitespace(&input);

        if(input.length() == 0 || !isStringNumeric(&input)){
            printf("Input only integers!\n");
            continue;
        }

        size = 1;
        for(int i = 0; i < input.size(); i++)
            if(input[i] == ' ')
                ++size;

        nums = new int[size];

        int start, count;
        start = 0;
        count = 0;

        for(int i = 0; i < input.size(); i++){
            if(i == input.size() - 1){
                nums[count++] = stoi(input.substr(start, i - start + 1));
            }
            if(input[i] == ' '){
                nums[count++] = stoi(input.substr(start, i - start));
                start = i + 1;
            }
        }

        return nums;
    }
}

int main(){

    printf("This program computes the sum of a list of integer numbers.\n");

    int size;
    int *array; // free this
    
    array = getNums(size);

    int total = recursiveSum(array, size);
    printf("\nThe sum of these numbers is: %d\n", total);

    delete[] array;
    return 0;
}
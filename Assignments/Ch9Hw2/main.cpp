/*String Selection Sort

Modify the selectionSort function presented in this chapter so it sorts an array of strings instead of an array of ints.*/

#include <iostream>
#include <cstdint>
#include <string>
using namespace std;

const int Size = 20;
string name[Size] = 
{"Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim", 
 "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill", 
 "Allison, Jeff", "Moreno, Juan", "Wolfe, Bill", "Whitman, Jean",
 "Moretti, Bella", "Wu, Eric", "Patel, Renee", "Harrison, Rose",
 "Smith, Cathy", "Conroy, Pat", "Kelly, Sean", "Holland, Beth"};


string stringToLower(string str){
    int len = str.length();
    if(len == 0)
        return str;

    int chr;
    for(int i = 0; i < len; i++){
        chr = str[i];
        if(chr >= 'A' && chr <= 'Z')
            str[i] += 32;
    }

    return str;
}

int getCharVal(string str, int idx){ // This might be overkill over just comparing each char directly
    int len = str.length() - idx;
    uint8_t bytes[4];
    for(int i = 0; i < 4; i++){
        if(i >= len)
            bytes[i] = 0;
        else
            bytes[i] = str[idx + i];
    }

    // just converting 4 chars into an int to compare so im basically doing 4 at a time
    return (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3]; 
}

void selectionSort(string* names, int size){
    // Modifies in place so no return 

    // Store here instead of constantly reallocating memory
    string selected;
    string compare;
    string tmp; // Used during swaps
    int minLen, a, b;

    for(int i = 0; i < size; i++){
        selected = stringToLower(names[i]);

        for(int s = i + 1; s < size; s++){
            compare = stringToLower(names[s]);
            minLen = min(selected.size(), compare.size());

            for(int c = 0; c < minLen; c += 4){
                a = getCharVal(selected, c);
                b = getCharVal(compare, c);

                if(a > b) { // Swap!
                    tmp = names[i];
                    names[i] = names[s];
                    names[s] = tmp;
                    //printf("Swapped %d with %d\n", i, s);
                    // Swap working vars as well
                    //printf("Working var swap before: %s | %s\n", selected.c_str(), compare.c_str());
                    tmp = compare;
                    compare = selected;
                    selected = tmp;
                    //printf("Working var swap after: %s | %s\n", selected.c_str(), compare.c_str());
                }

                if(b == a)
                    continue;

                break; // sorted
            }
        }
    }
    

}

int main(){

    selectionSort(name, Size);

    printf("The names in sorted order are:\n\n");
    for(int i = 0; i < Size; i++)
        printf("%s\n", name[i].c_str());
        

    return 0;
}
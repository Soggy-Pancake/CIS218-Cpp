
/*Test Scores #1
Write a program that dynamically allocates an array large enough to hold a user-defined number of test scores. 
Once all the scores are entered, the array should be passed to a function that sorts them in ascending order. 
Another function should be called that calculates the average score. 
The program should display the sorted list of scores and averages with appropriate headings. 
Use pointer notation rather than array notation whenever possible.

Input Validation: Do not accept negative numbers for test scores.*/

#include <iostream>
#include <string>
using namespace std;


int askInt(string message){

    int val;
    while(true){
        printf("%s", message.c_str());
        cin >> val;

        if(!cin.fail() && val >= 0){
            cin.clear();
            break;
        } 

        cin.clear();
        cin.ignore(10000, '\n');
        printf("Type a whole positive number! (1,2,3...)\n");
    }

    return val;
}

void sort(int* arr, int len){ // Pointer notation variant
    int tmp;

    // this is far less readable and I have no idea how much faster this is over the normal setup I had before
    for(int* i = arr; i < arr + len - 1; i++){
        for(int* j = i + 1; j < arr + len; j++){
            if(*i > *j){
                tmp = *j;
                *j = *i;
                *i = tmp;
            }
        }
    }
}

string* stringSplit(string str, int &count){
    // generic split function that should remove spaces between things, not configurable to split on anything that isnt one char tho

    bool seenNonSpace = false;
    int splitCount = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] != ' ')
            seenNonSpace = true;

        if((str[i] == ' ' && seenNonSpace) || (seenNonSpace && i == str.length() - 1)){
            seenNonSpace = false;
            ++splitCount;
            //printf("Found valid string! total: %d\n", splitCount);
        }
    }

    string* split = new string[splitCount];
    int strStart, strEnd;
    int foundStrs = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] != ' ' && !seenNonSpace){
            seenNonSpace = true;
            strStart = i;
        }

        if((str[i] == ' ' && seenNonSpace) || (seenNonSpace && i == str.length() - 1)){
            // abusing that true is 1 to add to the end of the substring for the last char
            split[foundStrs++] = str.substr(strStart, i - strStart + (i == str.length() - 1));
            //printf("%s.\n", split[foundStrs - 1].c_str());
            seenNonSpace = false;
        }
    }

    //printf("stringSplit splitcount %d\n", splitCount);
    count = splitCount;
    return split;
}

int* getScores(int &total){

    total = askInt("Enter number of Scores: ");
    int* entries = new int[total];

    cin.ignore(1000000, '\n');
    string line;
    while(true){
        printf("Enter the %d scores separated by spaces: \n", total);
        getline(cin, line);

        int splitCount;
        string* ints = stringSplit(line, splitCount);

        if(splitCount != total){
            printf("You entered %d numbers instead of %d. Try again\n", splitCount, total);
            continue;
        }

        printf("\nScores entered:\n");
        bool validInts = true;
        for(int i = 0; i < splitCount; i++){
            entries[i] = stoi(ints[i]);
            printf("%d ", entries[i]);
            if(entries[i] < 0){
                printf("\nNegative numbers aren't allowed!\n");
                validInts = false;
                break;
            }
        }
        
        // Delete here since if a negative number is found it will make a new array and leave the current ints array behind without freeing
        delete[] ints; 
        if(!validInts) continue;

        printf("\n\n");   
        
        break;
    }

    return entries;
}

double calcAvg(int* nums, int len){

    int total;
    for(int* i = nums; i < nums + len; i++)
        total += *i;

    return total / (double)len;
}

int main(){

    int numEntries;
    int* entries = getScores(numEntries);
    
    sort(entries, numEntries);

    // Sort Validation
    printf("The list of sorted scores is:\n");
    for(int i = 0; i < numEntries; i++)
        printf("%d ", entries[i]);
    printf("\n");

    printf("\nThe average is: %.4f\n", calcAvg(entries, numEntries));

    delete[] entries;
    return 0;
}
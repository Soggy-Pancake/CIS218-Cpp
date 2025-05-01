/*Check Writing
Design a class Numbers that can be used to translate whole dollar amounts in the range 0 through 9999 into an English description of the number. 
For example, the number 713 would be translated into the string seven hundred thirteen, and 8203 would be translated into eight thousand two hundred three.

The class should have a single integer member variable

`int number;`

and a collection of static string members that specify how to translate key dollar amounts into the desired format. For example, you might use static strings such as

string lessThan20[ ] = {"zero", "one", …, "eighteen", "nineteen" };
string hundred = "hundred";
string thousand = "thousand";

The class should have a constructor that accepts a non-negative integer and uses it to initialize the Numbers object. 
It should have a member function print() that prints the English description of the Numbers object. Demonstrate the class by writing a main program 
that asks the user to enter a number in the proper range and then prints out its English description.


SAMPLE RUN RESULTS


This program translates whole dollar amounts into words for the for the purpose of writing checks.
Entering a negative terminates the program.

Enter an amount for be translated into words: 1234
> one thousand two hundred thirty four

Enter another number: 34
> thirty four

Enter another number: 13453
> thirteen thousand four hundred fifty three

*/

#include <iostream>
#include <string>
using namespace std;

class Numbers{

private:
    int num;
    const char* numbers[99] = {
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
        "seventeen", "eighteen", "nineteen",
        "twenty", "twenty one", "twenty two", "twenty three", "twenty four",
        "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine",
        "thirty", "thirty one", "thirty two", "thirty three", "thirty four",
        "thirty five", "thirty six", "thirty seven", "thirty eight", "thirty nine",
        "forty", "forty one", "forty two", "forty three", "forty four",
        "forty five", "forty six", "forty seven", "forty eight", "forty nine",
        "fifty", "fifty one", "fifty two", "fifty three", "fifty four",
        "fifty five", "fifty six", "fifty seven", "fifty eight", "fifty nine",
        "sixty", "sixty one", "sixty two", "sixty three", "sixty four",
        "sixty five", "sixty six", "sixty seven", "sixty eight", "sixty nine",
        "seventy", "seventy one", "seventy two", "seventy three", "seventy four",
        "seventy five", "seventy six", "seventy seven", "seventy eight", "seventy nine",
        "eighty", "eighty one", "eighty two", "eighty three", "eighty four",
        "eighty five", "eighty six", "eighty seven", "eighty eight", "eighty nine",
        "ninety", "ninety one", "ninety two", "ninety three", "ninety four",
        "ninety five", "ninety six", "ninety seven", "ninety eight", "ninety nine"
    };
    
public:
    Numbers(int n){
        if(!(n >= 0 && n < 100000)){
            printf("Invalid input!");
            num = 0;
            return;
        }

        num = n;
    }

    void print(){

        int val = num;
        int c;

        if(val == 0){
            printf("zero");
            return;
        }

        if(val >= 1000){
            for(c = -1; val >= 1000; c++){
                val -= 1000;
            }

            if(c < 100){
                printf("%s thousand ", numbers[c]);
            } else {
                printf("[ERROR] Something went wrong during thousands calc!");
                val / 0; // Kill
            }
        }

        if(val >= 100){
            for(c = -1; val >= 100; c++){
                val -= 100;
            }

            if(c < 100){
                printf("%s hundred ", numbers[c]);
            } else {
                printf("[ERROR] Something went wrong during hundreds calc!");
                val / 0; // Kill
            }
        }

        if(val >= 0){
            for(c = -1; val > 0; c++){
                --val;
            }

            if(c < 100){
                printf("%s", numbers[c]);
            } else {
                printf("[ERROR] Something went wrong during ones calc!");
                val / 0; // Kill
            }
        }

        putchar('\n');
    }
};

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

    int input;
    bool firstRun = false;

    printf("This program translates whole dollar amounts into words for the for the purpose of writing checks.\nEntering a negative terminates the program.\n\n");

    while(true){

        if(!firstRun)
            input = askInt("\nEnter an amount for be translated into words: ");
        else
            input = askInt("\nEnter another number: ");

        if(input < 0)
            return 0;

        Numbers num(input);
        num.print();
    }
    

    return 1;
}
/* Color Mixer
Write a program that prompts the user to enter the names of two primary colors to mix. 
If the user enters anything other than red, blue, or yellow display an error message. 
Otherwise, display the name of the secondary color produced.*/

#include <iostream>
#include <string>
using namespace std;

enum Color {
    red,
    blue,
    yellow
};

Color getColor(int num){

    string color;
    Color val;

    while(true){

        printf("Color %d: ", num);
        cin >> color;
        
        for (char &c : color) {
            c = std::tolower(c);
        }
        
        // dangit cpp doesnt support strings in switch blocks

        if(color == "red") {
            val = red;
            return val;
        }

        if(color == "blue"){
            val = blue;
            return val;
        }

        if(color == "yellow") {
            val = yellow;
            return val;
        }

        printf("Invalid color! Valid colors are red, blue, and yellow.\n");
        cin.clear();
        cin.ignore(100000, '\n');
    }
}

int main(){

    Color color1;
    Color color2;

    printf("Color Mixer\n");

    color1 = getColor(1);
    color2 = getColor(2);

    if(color1 == color2){
        if(color1 == red)
            printf("Its still red...\n");
        if(color1 == blue)
            printf("Its still blue...\n");
        if(color1 == yellow)
            printf("Its still yellow...\n");
        
        return 0;
    }

    if((color1 == red && color2 == blue) || (color1 == blue && color2 == red)){
        printf("Made purple!\n");
        return 0;
    }

    if((color1 == red && color2 == yellow) || (color1 == yellow && color2 == red)){
        printf("Made orange!\n");
        return 0;
    }

    if((color1 == blue && color2 == yellow) || (color1 == yellow && color2 == blue)){
        printf("Made green!\n");
        return 0;
    }

    printf("I have no idea what went wrong...");
    return 0;

}
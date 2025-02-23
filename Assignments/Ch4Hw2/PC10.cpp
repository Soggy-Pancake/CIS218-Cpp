/* Geometry Calculator
Prints a menu and asks for a value. 1 asks for inputs for a circle, 2 asks for inputs for a rectangle,
3 asks for a triangles base and height, 4 exits.*/

#include <iostream>
#include <string>
using namespace std;

// Finally something different

const double PI = 3.141592653589793238462643383279502884197169; 
// just took a few digits from piday.org/million/ since c++ isnt just giving it to me

void printMenu(){
    system("cls");
    printf("Area Calculator\n");
    printf("\t1. Circle\n");
    printf("\t2. Rectangle\n");
    printf("\t3. Triangle\n");
    printf("\t4. Exit\n");
}

double askNum(string message){

    double val;
    while(true){
        printf("%s", message.c_str());
        cin >> val;

        if(!cin.fail()){
            
            cin.clear();
            break;
        }

        cin.clear();
        cin.ignore(10000, '\n');
        printf("Input a number!\n");        
    }

    return val;
}

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

void pause(){
    printf("Enter to continue... ");
    cin.ignore(10000, '\n');
    cin.get();
}

void calcCircle(){
    
    double r = askNum("Radius: ");

    printf("Area (Circle): %f\n", PI * r * r);
    
    pause();
}

void calcRect(){

    double w = askNum("Width: ");
    double l = askNum("Length: ");

    printf("Area (Rect): %f\n", w * l);

    pause();
}

void calcTrangle(){

    double b = askNum("Base: ");
    double h = askNum("Height: ");

    printf("Area (Triangle): %f\n", b * h / 2.0);

    pause();
}

int main(){

    int selection;
    bool invalidSelection;

    while(true){

        printMenu();
        if(invalidSelection){
            printf("Last selection invalid!\n");
            invalidSelection = false;
        }

        selection = askInt(": ");
        
        switch(selection){
            case 1:
                calcCircle();
                break;

            case 2:
                calcRect();
                break;
            
            case 3:
                calcTrangle();
                break;

            case 4:
                return 0;

            default:
                invalidSelection = true;
                break;
        }
    }

    return 1;
}
/*Write a program that determines which of a company’s four divisions (Northeast, Southeast, Northwest, and Southwest) 
had the greatest sales for a quarter. It should include the following two functions, which are called by main.

double getSales() is passed the name of a division. It asks the user for a division’s quarterly sales figure, 
validates that the input is not less than 0, then returns it. It should be called once for each division.

void findHighest() is passed the four sales totals. It determines which is the largest and prints the name of the high grossing division, 
along with its sales figure.*/

#include <iostream>
#include <string>
using namespace std;

void findHighest(double array[]){
    int largestIndex = 0;
    double largest = array[0];

    for(int i = 1; i < 4; i++){
        if(array[i] > largest){
            largestIndex = i;
            largest = array[i];
        }
    }

    // Start formatting for money

    largest = round(largest * 100.0) / 100.0;
    string saleStr = to_string(largest);
    int decimalPos = saleStr.find('.');

    saleStr = saleStr.substr(0, decimalPos + 3); // truncate to cents
    int commas = (decimalPos - 1) / 3;
    
    //printf("%.2f, Decimal pos: %d, Commas needed: %d\n", largest, decimalPos, commas);

    for(int i = 1; i < commas + 1; i++){
        saleStr.insert(saleStr.begin() + decimalPos - (i * 3), ',');
    }
    saleStr.insert(saleStr.begin(), '$');

    // Done formatting money
    //cout << "Maybe? " << saleStr << endl;

    cout << "The ";
    switch(largestIndex){
        case 0:
            cout << "Northeast";
            break;
        case 1:
            cout << "Southeast";
            break;
        case 2:
            cout << "Northwest";
            break;
        case 3:
            cout << "Southwest";
            break;
    }

    cout << " division had the highest sales this quarter.\n";
    printf("Their sales were %s\n", saleStr.c_str());
}

double getSales(string message){
    double val;

    while(true){
        printf("%s", message.c_str());
        cin >> val;

        if(!cin.fail() && val >= 0){
            break;
        } 

        cin.clear();
        cin.ignore(100000, '\n');
        printf("Type a positive number! (1, 2.1, 3.14...)\n");
    }
    //cout << val << endl;
    return val;
}

int main(){
    double sales[4];

    sales[0] = getSales("Enter the quarterly sales for the Northeast division: ");
    sales[1] = getSales("Enter the quarterly sales for the Southeast division: ");
    sales[2] = getSales("Enter the quarterly sales for the Northwest division: ");
    sales[3] = getSales("Enter the quarterly sales for the Southwest division: ");

    printf("\n");
    findHighest(sales);

    return 0;
}
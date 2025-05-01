/*Corporate Sales
A corporation has six divisions, each responsible for sales to different geographic locations. 
Design a DivSales class that keeps sales data for a division, with the following members:

An array with four elements for holding four quarters of sales figures for the division.
A private static variable for holding the total corporate sales for all divisions for the entire year.
A member function that takes four arguments, each assumed to be the sales for a quarter. 
The value of the arguments should be copied into the array that holds the sales data. 
The total of the four arguments should be added to the static variable that holds the total yearly corporate sales.

A function that takes an integer argument within the range of 0 to 3. 
The argument is to be used as a subscript into the division quarterly sales array. 
The function should return the value of the array element with that subscript.

Write a program that creates an array of six DivSales objects. 
The program should ask the user to enter the sales for four quarters for each division. 
After the data is entered, the program should display a table showing the division sales for each quarter. 
The program should then display the total corporate sales for the year.

*/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

#define DIV_NUM 6

double askNum(string message){
    double val;
    while(true){

        printf("%s", message.c_str());
        cin >> val;

        if(!cin.fail() && val >= 0){
            cin.clear();
            break;
        } 

        cin.clear();
        cin.ignore(10000, '\n');
        printf("Type a positive number! (1, 2.5, 3.1, ...)\n");
    }

    return val;
}

class DivSales{

private:
    static int total;
    int sales[4]; 

    string formatMoney(double val){
        val /= 100.0;
        string saleStr = to_string(val);
        int decimalPos = saleStr.find('.');

        saleStr = saleStr.substr(0, decimalPos + 3); // truncate to cents
        int commas = (decimalPos - 1) / 3;

        for(int i = 1; i < commas + 1; i++){
            saleStr.insert(saleStr.begin() + decimalPos - (i * 3), ',');
        }
        saleStr.insert(saleStr.begin(), '$');

        return saleStr;
    }
    
public:
    DivSales(){
        /*for(int i = 0; i < 4; i++){
            char buf[50];
            sprintf(buf, "  Quarter %d: ", i + 1);
            string str(buf);
            double inp = askNum(str);
            sales[i] = (int)(round(inp * 100.0));
            total += sales[i];
        }*/
    }

    void setSales(double q1, double q2, double q3, double q4){
        if(q1 < 0 || q2 < 0 || q3 < 0 || q4 < 0)
            return;

        q1 *= 100;
        q2 *= 100;
        q3 *= 100;
        q4 *= 100;

        sales[0] = q1;
        sales[1] = q2;
        sales[2] = q3;
        sales[3] = q4;

        total += q1 + q2 + q3 + q4;
    }

    string getTotalStr(){
        return formatMoney(total);
    }

    double getTotal(){
        return total / 100.0;
    }

    void printQuarter(int q){
        if(q < 0 || q > 3)
            return;
        printf("%s", formatMoney(sales[q]).c_str());
    }

    double getQuarter(int q){
        if(q < 0 || q > 3)
            return 0;
        return sales[q] / 100.0;
    }
};
int DivSales::total = 0;



int main(){
    DivSales divisions[DIV_NUM];

    for(int i = 0; i < DIV_NUM; i++){
        printf("Enter sales data for Divison %d\n", i + 1);

        double q1, q2, q3, q4;
        q1 = askNum("  Quarter 1: ");
        q2 = askNum("  Quarter 2: ");
        q3 = askNum("  Quarter 3: ");
        q4 = askNum("  Quarter 4: ");

        divisions[i].setSales(q1, q2, q3, q4);
    }

    putchar('\n');
    
    for(int i = 0; i < DIV_NUM; i++){
        printf("Sales for Division %d\n", i + 1);
        for(int q = 0; q < 4; q++){
            printf("  Quarter %d: ", q + 1);
            divisions[i].printQuarter(q);
            putchar('\n');
        }
    }

    printf("Total Corporate Sales: %s\n", divisions[0].getTotalStr().c_str());

    return 0;
}
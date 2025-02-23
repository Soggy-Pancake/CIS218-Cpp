/*Write a class named Car that has the following member variables:

 - year : An int that holds the car’s model year.
 - make: A string object that holds the make of the car.
 - speed: An int that holds the car’s current speed.

In addition, the class should have the following member functions.

 * Constructor:
The constructor should accept the car’s year and make as arguments and assign these values to the object’s year and make member variables. 
The constructor should initialize the speed member variable to 0.

Accessors. 
Appropriate accessor functions should be created to allow values to be retrieved from an object’s year, make, and speed member variables.

accelerate. 
The accelerate function should add 5 to the speed member variable each time it is called.

brake. 
The brake function should subtract 5 from the speed member variable each time it is called.

Demonstrate the class in a program that creates a Car object and then calls the accelerate function five times. 
After each call to the accelerate function, get the current speed of the car and display it. Then, call the brake function five times. 
After each call to the brake function, get the current speed of the car and display it.*/

#include <iostream>
#include <string>
using namespace std;

class Car{
private:
    int year;
    string make;
    int speed;

public: 
    Car(int year, string make);

    int getYear();
    string getMake();
    int getSpeed();

    void accelerate();
    void brake();
};

Car::Car(int year, string make){
    this->year = year;
    this->make = make;
    this->speed = 0;
}

int Car::getYear(){
    return this->year;
}

string Car::getMake(){
    return this->make;
}

int Car::getSpeed(){
    return this->speed;
}

void Car::accelerate(){
    this->speed += 5;
}

void Car::brake(){
    this->speed -= 5;
}

int main(){

    Car car(2019, "Mazda hot rod");

    printf("I'm in my %d %s\n\n", car.getYear(), car.getMake().c_str());

    printf("I'm accelerating ...\n");
    for(int i = 0; i < 5; i++){
        car.accelerate();
        printf("Current speed: %d mph.\n", car.getSpeed());
    }

    printf("\nNow I'm braking ...\n");
    for(int i = 0; i < 5; i++){
        car.brake();
        printf("Current speed: %d mph.\n", car.getSpeed());
    }

    return 0;

}
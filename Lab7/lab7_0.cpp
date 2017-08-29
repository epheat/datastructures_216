//course: CS216-00x
//Project: Lab Assignment 7
//Program: lab7_1.cpp
//Date: 03/24/2015
//Purpose: Use as the lab assignment example
//
//Author: (your name)


#include <iostream>
#include <string>
using namespace std;
 
//define your own exception class
class Matherr { public: string errname; };
class DivideByZero : public Matherr
{
    public:
        DivideByZero() {this->errname = "Division by zero";}
};
 
double divide(int a, int b) {
    /*
    if(b == 0)
        throw DivideByZero();
    */
    return (double) a / b;
}
 
int main() {
       double d = divide(4, 0);
       cout << d << endl;
       return 0;
}

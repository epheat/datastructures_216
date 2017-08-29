// Evan Heaton
// Programming Assignment 3
// CS216
// 4/2/2015

#ifndef ESTACK_H
#define ESTACK_H

#include <iostream>
#include <vector>

using namespace std;

class EStack
{
private:
	vector<string> data;
public:
	EStack();
	string pop();	
	void push(string d);
	string peek();
	~EStack() {};
};
#endif
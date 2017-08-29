// Evan Heaton
// Programming Assignment 3
// CS216
// 4/2/2015

#include "EStack.h"

EStack::EStack()
{
	vector<string> data;
}

//Pop also returns the string to make it easier. Peek is sort of useless here.
string EStack::pop()
{
	if (data.size()==0)
		return "Empty";
	else
	{
		string temp = data.back();
		data.pop_back();
		return temp;
	}
}

//Check the next data item. Ok
string EStack::peek()
{
	if (data.size()==0)
		return "Empty";
	else
		return data.back();
}

//Add a new data item. Cool
void EStack::push(string d)
{
	data.push_back(d);
}
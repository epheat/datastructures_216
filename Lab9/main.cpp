//Evan Heaton
//CS216
//Lab 9

#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
	cout << "Please input integers (type Q to quit)\n";	

	int size = 0;
	int* array = read_data(size);
	
	for (int i=0;i<size;i++)
		cout << array[i] << ", ";
	
	cout << "and the second greatest value is " << second_greatest(array, size) << "\n";
	
	return 0;
}

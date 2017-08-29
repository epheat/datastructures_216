//Evan Heaton
//CS216
//Lab9

#include <iostream>

using namespace std;

int* read_data(int &size)
{
	size = 0;
	int temp;
	int old_size = 10;
	int* array = new int[old_size];
	bool keep_going = true;
	while (keep_going)
	{
		if (!(cin >> temp))
		{
			cin.clear();
			char check_for_q = cin.get();
			if (check_for_q == 'q' || check_for_q == 'Q')
				keep_going = false;  //no break statement :^)
			else
				cin.ignore(256, '\n');
		}
		else
		{
			if (size == old_size)  //The next addition would be out of bounds
			{
				old_size*=2;
				int* new_array = new int[old_size];
				for (int i=0;i<size;i++)
					new_array[i] = array[i];
				delete[] array; //never forget to deleterino
				array = new_array;
				new_array = NULL;
			}
			array[size] = temp;
			size++;
		}
	}
	int* final_array = new int[size];  //the last array of perfect size
	for (int i=0;i<size;i++)
		final_array[i] = array[i];
	delete[] array;

	return final_array;
}

//evan heaton
//cs216:003
//lab2
//purpose: to read a file users.txt and print each user currently logged on

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	string name;
	int number_of_names = 0;
	ifstream in;
	in.open("users.txt");
	while(in >> name)
	{
		cout << "Hello, " << name << "\n";
		number_of_names++;
		getline(in,name);
	}
	cout << "The number of users currently logged in is: " << number_of_names << "\n";
	in.close();
}

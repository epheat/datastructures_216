//Evan Heaton
//3/25/2015
//CS216
//Lab7

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Err {public: string errorname; virtual string getName() {return this->errorname; }};

class DivideByZero : public Err
{
	public:
		DivideByZero() {this->errorname = "Division by zero";}
		virtual string getName() {return this->errorname;}
};
class OutOfRange : public Err
{
	public:
		OutOfRange() {this->errorname = "Out of range";}
		virtual string getName() {return this->errorname;}
};

//preconditions: Send a vector of doubles within the range 0-100
//postconditions: returns the average of the doubles in the vector
//note: will throw "OutOfBounds" if a score is not between 0-100
//      will throw "DivideByZero" if the vector is of size 0
double calculateAverage(vector<double> scores)
{
        if (scores.size() == 0)
                throw DivideByZero();
        double total = 0.0;
        for (int i=0;i<scores.size();i++)
        {
                if (scores[i] < 0.0 || scores[i] > 100.0)
                        throw OutOfRange();
                else
                        total+=scores[i];
        }
        return total / scores.size();
}

int main()
{
	cout << "Enter Q or q to stop adding scores\n:";
	double entry;
	vector<double> entries;
	cin >> entry;
	while (!cin.fail())
	{
		entries.push_back(entry);
		cout << ":";
		cin >> entry;
	}

	try
	{
		cout << calculateAverage(entries) << endl;
	}	
	catch (Err& er)
	{
		cout << "Exception: " << er.getName() << endl;
	}
	cout << "program completed\n";
	return 0;
}

//CS216:003
//2/12/2015
//Programming Assignment 1
//Evan Heaton

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream sec1,sec2,course;
	sec1.open("sec1students.txt");
	sec2.open("sec2students.txt");
	course.open("studentcourses.txt");
	//check if any files are missing. If one is missing, display a message and abort the program
	if (sec1.fail())
	{
		cout << "file sec1students.txt could not be opened. Exiting...\n";
		return 1;
	}
	if (sec2.fail())
	{
		cout << "file sec2students.txt could not be opened. Exiting...\n";
		return 1;
	}
	if (course.fail())
	{
		cout << "file studentcourses.txt could not be opened. Exiting...\n";
		return 1;
	}
	
	string student_number;
	
	cout << "Enter student number to search: ";
	cin >> student_number;	
	
	bool found = false;
	string looping_number, first, last, major, section, coursenum, grade;

	//first loop through sec1students to find the student
	while (!found && sec1 >> looping_number)
	{
		sec1 >> first >> last >> major;
		if (looping_number == student_number)
		{
			found = true;
			section = "day-time";
		}
	}
	
	//now loop through sec2students to find student (if not already found)
	while (!found && sec2 >> looping_number)
	{
		sec2 >> first >> last >> major;
		if (looping_number == student_number)
		{
			found = true;
			section = "evening";
		}
	}
	//print the results before the last step
	if (!found)
	{
		cout << "Invalid student number!\n";
		return 0;
	}
	else
	{
	cout << "Name: " << last << ", " << first << "\nSection: " << section;
	}

	//last step is to loop through studentcourses.txt to find the courses the student is enrolled in
	bool has_courses = false;
	while (course >> looping_number)
	{
		course >> coursenum >> grade;
		if (looping_number == student_number)
		{
			cout << "\n" << coursenum;
			has_courses = true;
		}
	}
	if (!has_courses)
	{
		cout << "\nis not taking any courses\n";
	}
	else
	{
		cout << "\n";
	}


	sec1.close();
	sec2.close();
	course.close();
	return 0;	
}

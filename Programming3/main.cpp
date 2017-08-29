// Evan Heaton
// Programming Assignment 3
// CS216
// 4/2/2015

#include "EStack.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

string read_expression();
bool valid(string s);
string infix_to_postfix(string in);
int evaluate(string post);

int main()
{

	int choice=0;
	string infix = "";
	string postfix = "";

	while (choice != 4)
	{
		cout << "--------------------------------------------------\n"
			 << "1. Read an expression in infix notation.\n"
			 << "2. Convert infix to postfix.\n"
			 << "3. Evaluate the expression using postfix notation.\n"
			 << "4. Exit.\n"
			 << "--------------------------------------------------\n"
			 << "?";
		cin >> choice;
		if (cin.fail())  //Check for non-integers. If it's not an integer then just say invalid choice and repeat until they enter 4.
		{
			cout << "Invalid choice.\n";
			cin.clear();
			cin.ignore(256,'\n');
		}
		else
		{
			if (choice == 1)  //Read an expression in infix notation
			{
				infix = read_expression();
				if (infix == "")
					cout << "The infix expression was not valid.\n\n";
				else
					cout << "The infix expression was read successfully\n\n";
			}
			else if (choice == 2)  //Convert infix to postfix
			{
				if (infix == "")  //No infix expression has been entered yet
					cout << "No infix expression has been entered yet.\n\n";
				else
				{
					cout << "Infix expression: " << infix << "\n";
					postfix = infix_to_postfix(infix);
					if (postfix == "")
						cout << "There was an error evaluating the postfix expression.\n\n";
					else
						cout << "Postfix expression: " << postfix << "\n\n";
				}
			}
			else if (choice == 3)  //Evaluate the expression using postfix notation
			{
				if (postfix == "")  //No postfix expression has been calculated yet
					cout << "No postfix expression has been calculated yet.\n\n";
				else
				{
					cout << "Infix expression: " << infix << "\n";
					cout << "Postfix expression: " << postfix << "\n";
					cout << "Evaluation of this expression: " << evaluate(postfix) << "\n\n";
				}
			}
			else if (choice == 4)  //Exit
			{
				cout << "Program terminated. Press ENTER to exit...";
				cin.ignore(256,'\n');
				cin.get();
				return 0;
			}
			else  //Invalid choice
				cout << "Invalid choice.\n\n";
		}
	}
}

//asks the user to input an infix expression (with spaces between all operators)
string read_expression()
{
	string exp;
	cout << "Enter an infix expression:\n";
	cin.ignore(256,'\n');
	getline(cin, exp);

	if (valid(exp))  //make sure the infix expression is valid
		return exp;
	else
		return "";
}

//returns true if the infix expression is valid, and false otherwise. Only really checks for spacing errors, nothing like 2 + + 2
bool valid(string in)
{
	if (in.size() == 0)
		return false;
	else
	{
		int i = 0;
		char temp = in[i];
		char prev;
		while (temp != '\0')
		{
			prev = temp;
			temp = in[i+1];
			if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '(' || temp == ')')  //character is an operator
			{
				if (prev != ' ')  //previous character must be a space
					return false;
			}
			else if (temp == '0' || temp == '1' || temp == '2' || temp == '3' || temp == '4' || temp == '5' || temp == '6' || temp == '7' || temp == '8' || temp == '9')  //character is an integer
			{
				if (!(prev == ' ' || prev == '0' || prev == '1' || prev == '2' || prev == '3' || prev == '4' || prev == '5' || prev == '6' || prev == '7' || prev == '8' || prev == '9'))  //previous character must be either an integer or a space
					return false;
			}
			i++;
		}
		return true;
	}
}

//converts an infix expression to a postfix expression
string infix_to_postfix(string in)
{
	string result = "";
	EStack stackerino;  //Step1
	stringstream ss(in);
	string operand;

	while (ss >> operand)  //Step2
	{	
		if (operand == "+" || operand == "-")  //low precedence
		{
			while (!(stackerino.peek() == "(" || stackerino.peek() == "Empty"))
				result += stackerino.pop() + " ";

			stackerino.push(operand);  //Step4.1
		}
		else if (operand == "/" || operand == "*")  //high precedence
		{
			while (!(stackerino.peek() == "(" || stackerino.peek() == "+" || stackerino.peek() == "-" || stackerino.peek() == "Empty"))
				result += stackerino.pop() + " ";

			stackerino.push(operand);  //Step4.2
		}
		else if (operand == "(")  //highest precedence
			stackerino.push(operand);  //Step5

		else if (operand == ")")
		{
			while (stackerino.peek() != "(")
				result += stackerino.pop() + " ";  //Step6

			stackerino.pop();  //to get rid of the opening parenthesis
		}
		else
		{
			result = result + operand + " ";  //Step3
		}
	}

	while (stackerino.peek() != "Empty")
	{
		result += stackerino.pop();
		if (stackerino.peek() != "Empty")
			result += " ";
	}
	return result;
}

//returns the evaluated postfix expression
int evaluate(string post)
{
	int result = 0;
	EStack stackerino;  //Step1
	stringstream ss(post);
	stringstream converter;
	string operand;

	while (ss >> operand)  //Step2
	{
		if (operand == "+")
		{
			int first_term, second_term;
			converter.str("");
			converter.clear();
			converter << stackerino.pop();
			converter >> second_term;
			converter.str("");
			converter.clear();
			converter << stackerino.pop();
			converter >> first_term;
			converter.str("");
			converter.clear();
			converter << first_term + second_term;
			stackerino.push(converter.str());  //Holy hell. Pop two strings, convert them to ints, add them, then push that value converted back to a string
			//a lot of work here just converting between strings and ints. Ouch.
		}
		else if (operand == "-")
		{
			int first_term, second_term;
			converter.str("");
			converter.clear();
			converter << stackerino.pop();
			converter >> second_term;
			converter.str("");
			converter.clear();
			converter << stackerino.pop();
			converter >> first_term;
			converter.str("");
			converter.clear();
			converter << first_term - second_term;
			stackerino.push(converter.str());
		}
		else if (operand == "*")
		{
			int first_term, second_term;
			converter.str("");
			converter.clear();
			converter << stackerino.pop();
			converter >> second_term;
			converter.str("");
			converter.clear();
			converter << stackerino.pop();
			converter >> first_term;
			converter.str("");
			converter.clear();
			converter << first_term * second_term;
			stackerino.push(converter.str());
		}
		else if (operand == "/")
		{
			int first_term, second_term;
			converter.str("");
			converter.clear();
			converter << stackerino.pop();
			converter >> second_term;
			converter.str("");
			converter.clear();
			converter << stackerino.pop();
			converter >> first_term;
			converter.str("");
			converter.clear();
			converter << first_term / second_term;
			stackerino.push(converter.str());
			//dont forget to swap the order of division. This one's a bit more finnicky
		}
		else
		{
			stackerino.push(operand);
		}
	}

	result = atoi(stackerino.pop().c_str());
	return result;
}

//
//  main.cpp
//  EvanHeatonProgramming4
//
//  Created by Evan Heaton on 4/17/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include "ETree.h"
#include "EStack.h"

using namespace std;

bool valid(string in);
string read_expression();
string infix_to_postfix(string in);
int evaluate(string post);


int main(int argc, const char * argv[]) {

    ETree EvanTree;
    int choice=0;
    string infix = "";
    string postfix = "";
    
    
    while (choice != 6)
    {
        cout << "--------------------------------------------------\n"
        << "1. Read an expression in infix notation.\n"
        << "2. Display the prefix expression.\n"
        << "3. Display the infix expression.\n"
        << "4. Display the postfix expression.\n"
        << "5. Evaluate the expression using postfix notation.\n"
        << "6. Exit.\n"
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
            if (choice == 1)  //Read an expression in infix notation (and convert to postfix)
            {
                infix = read_expression();
                if (infix == "")
                    cout << "The infix expression was not valid.\n\n";
                else
                    cout << "The infix expression was read successfully\n\n";
                postfix = infix_to_postfix(infix);
                if (postfix == "")
                    cout << "There was an error converting your infix expression to postfix.\n\n";
                EvanTree.BuildTree(postfix);
            }
            else if (choice == 2)  //Display prefix
            {
                if (postfix == "")  //No infix expression has been entered yet
                    cout << "No infix expression has been entered yet.\n\n";
                else
                {
                    cout << "Prefix expression:\n";
                    EvanTree.PreTraversal();
                    cout << "\n";
                }
            }
            else if (choice == 3)  //Display infix
            {
                if (postfix == "")  //No infix expression has been entered yet
                    cout << "No infix expression has been entered yet.\n\n";
                else
                {
                    cout << "Infix expression:\n";
                    EvanTree.InTraversal();
                    cout << "\n";
                }
            }
            else if (choice == 4)  //Display postfix
            {
                if (postfix == "")  //No infix expression has been entered yet
                    cout << "No infix expression has been entered yet.\n\n";
                else
                {
                    cout << "Postfix expression:\n";
                    EvanTree.PosTraversal();
                    cout << "\n";
                }
            }
            else if (choice == 5)  //Evaluate the expression using postfix notation
            {
                if (postfix == "")  //No postfix expression has been calculated yet
                    cout << "No infix expression has been entered yet.\n\n";
                else
                {
                    cout << "Infix expression: " << infix << "\n";
                    cout << "Postfix expression: " << postfix << "\n";
                    cout << "Evaluation of this expression: " << evaluate(postfix) << "\n\n";
                }
            }
            else if (choice == 6)  //Exit
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
    
    
    
    
    /*   (DEBUGGING STUFF)
    cout << "\nPretraversal: ";
    EvanTree.PreTraversal();
    cout << "\nIntraversal: ";
    EvanTree.InTraversal();
    cout << "\nPostraversal: ";
    EvanTree.PosTraversal();
    
    cout << "\n";
    */
    
    return 0;
}

string infix_to_postfix(string in)
{
    bool was_operator = true;
    string result = "";
    EStack stackerino;  //Step1
    stringstream ss, converter;
    ss.str(in);
    int operand = 0;
    
    while (!ss.fail())
    {
        if (was_operator && ss >> operand)  //Step2
        {
            converter.str("");
            converter.clear();
            converter << operand;
            result = result + converter.str() + " ";  //Step3
            was_operator = false;
        }
        else
        {
            ss.clear();
            if (!was_operator)
                ss.get();  //get rid of the space
            char temp = ss.get();
            was_operator = true;
            
            //cout << "res: " << result << "\noper: " << operand << "\ntemp: '" << temp << "'";
            //cin.ignore(256, '\n');
            //cin.get();
            
            if (temp == '+' || temp == '-')  //low precedence
            {
                while (!(stackerino.peek() == "(" || stackerino.peek() == "Empty"))
                {
                    result += stackerino.pop() + " ";
                }
                stackerino.push(string(1,temp));  //Step4
            }
            else if (temp == '/' || temp == '*')  //high precedence
            {
                while (!(stackerino.peek() == "(" || stackerino.peek() == "+" || stackerino.peek() == "-" || stackerino.peek() == "Empty"))
                {
                    result += stackerino.pop() + " ";
                }
                stackerino.push(string(1,temp));  //Step4
            }
            else if (temp == '(')  //highest precedence
            {
                stackerino.push(string(1,temp));  //Step5
                //cout << "pushed (";
            }
            else if (temp == ')')
            {
                while (stackerino.peek() != "(")
                {
                    result += stackerino.pop() + " ";  //Step6
                }
                stackerino.pop();  //to get rid of the opening parenthesis
            }
            //else
            //return "";
        }
    }
    while (stackerino.peek() != "Empty")
    {
        result += stackerino.pop() + " ";
    }
    
    return result;
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
    
    converter.str("");
    converter.clear();
    converter << stackerino.pop();
    converter >> result;
    return result;
}

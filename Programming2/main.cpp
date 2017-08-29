//
//  ePh
//  main.cpp
//  EvanHeatonProgramming2
//
//  Created by Evan Heaton on 3/2/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "ELinkedList.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    if (argc != 2)
    {
        cout << "no command line argument found. Text file needed.\nPress ENTER to exit...";
        cin.get();
	return 0;
    }
    
    //Handling the textfile input
    fstream to_from_file (argv[1], ios::in);
    ELinkedList TextFile;
    string temp;
    int line_number;
    char tempchar;
    int iter = 0;
    while (!to_from_file.fail())
    {
        temp = "";
        tempchar = to_from_file.get();
	if (to_from_file.fail())
	{
		break;
	}
        while (tempchar!='\n' && !to_from_file.fail())
        {
            temp+=tempchar;
            tempchar = to_from_file.get();
        }
        TextFile.insertion(iter, temp);
        iter++;
    }
    cout << "File loaded successfully.\n\n";
    to_from_file.close();
    
    temp = "I"; //just to enter the loop initially. temp represents their initial response
                //line number represents the "n"; which line will be affected
    string inserted_string;
    while (temp == "I" || temp == "D" || temp == "L" || temp == "i" || temp == "d" || temp == "l")
    {
        cout << "?";
        cin >> temp;
        if (temp == "I" || temp == "i")
        {
            cin >>  line_number;
            cout << line_number << "] ";
            cin.ignore(256,'\n');
            inserted_string = "";
            tempchar = cin.get();
            //get the whole line. Probably should have made this a function, oh well.
            while (tempchar!='\n')
            {
                inserted_string += tempchar;
                tempchar = cin.get();
            }
            TextFile.insertion(line_number, inserted_string);
            cout << "<<Inserted line " << line_number << ">>\n";
        }
        else if (temp == "D" || temp == "d")
        {
            bool success = false;
            cin >> line_number;
            if (TextFile.deletion(line_number)) //deletion() returns true if it was successful
                success = true;
            if (success)
                cout << "<<Deleted line " << line_number << ">>\n";
            else
                cout << "<<Line " << line_number << " failed to delete: out of bounds>>\n";
        }
        else if (temp == "L" || temp == "l")
        {
            TextFile.print(cout, true);
        }
    }
    
    to_from_file.open(argv[1], ios::out | ios::trunc );
    TextFile.print(to_from_file, false);
    
    return 0;
}

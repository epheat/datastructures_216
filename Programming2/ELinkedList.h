//
//  ELinkedList.h
//  EvanHeatonProgramming2
//
//  Created by Evan Heaton on 3/2/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#ifndef ELINKEDLIST_H
#define ELINKEDLIST_H

#include "ENode.h"
#include <iostream>

class ELinkedList
{
private:
	ENode* head;
public:
    ELinkedList();
    ENode* find(std::string lin);
    bool insertion(int place, std::string lin);       //returns true for successful, false for unsuccessful
    bool deletion(int place);                         //returns the value contained in the deleted Enode2
    void print(std::ostream& outS, bool LineNumbers);
    ~ELinkedList();
};

#endif

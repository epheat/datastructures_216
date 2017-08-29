//
//  ENode.h
//  EvanHeatonProgramming2
//
//  Created by Evan Heaton on 3/2/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#ifndef ENODE_H
#define ENODE_H

#include <iostream>
#include <string>

//Should have made a .cpp file for this one but
//all the methods were so simple I put it all in here
class ENode
{
private:
    std::string line;
    ENode* next;
public:
    ENode() { line = ""; next = NULL; } ;
    std::string get_line() { return line; };
    void set_line(std::string lin) { line = lin; };
    void set_next(ENode* nex) { next = nex; };
    ENode* next_ENode() { return next; } ;
    ~ENode() {}
};

#endif

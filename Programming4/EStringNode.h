//
//  EStringNode.h
//  EvanHeatonProgramming4
//
//  Created by Evan Heaton on 4/17/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#ifndef __EvanHeatonProgramming4__EStringNode__
#define __EvanHeatonProgramming4__EStringNode__

#include <stdio.h>
#include <string>
#include "ETreeNode.h"

class EStringNode: public ETreeNode {
public:
    void PrePrint();
    void InPrint();
    void PostPrint();
    void del();
    EStringNode();
    EStringNode(std::string d);
    ~EStringNode() {};
    //?friend class ETree;
private:
    std::string data;
};

#endif /* defined(__EvanHeatonProgramming4__EStringNode__) */

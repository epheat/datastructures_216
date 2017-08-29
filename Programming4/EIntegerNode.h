//
//  EIntegerNode.h
//  EvanHeatonProgramming4
//
//  Created by Evan Heaton on 4/17/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#ifndef __EvanHeatonProgramming4__EIntegerNode__
#define __EvanHeatonProgramming4__EIntegerNode__

#include <stdio.h>
#include "ETreeNode.h"

class EIntegerNode: public ETreeNode {
public:
    void PrePrint();
    void InPrint();
    void PostPrint();
    void del();
    EIntegerNode();
    EIntegerNode(int d);
    ~EIntegerNode() {};
    //?friend class ETree;
private:
    int data;
};

#endif /* defined(__EvanHeatonProgramming4__EIntegerNode__) */

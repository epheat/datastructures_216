//
//  ETree.h
//  EvanHeatonProgramming4
//
//  Created by Evan Heaton on 4/17/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#ifndef __EvanHeatonProgramming4__ETree__
#define __EvanHeatonProgramming4__ETree__

#include "ETreeNode.h"
#include <stdio.h>
#include <string>
#include <iostream>

class ETree {
public:
    ETree();
    ~ETree();
    void BuildTree(std::string pos);
    
    void PreTraversal();
    void InTraversal();
    void PosTraversal();
    
private:
    ETreeNode* root;
};



#endif /* defined(__EvanHeatonProgramming4__ETree__) */

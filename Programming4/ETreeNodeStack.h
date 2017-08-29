//
//  ETreeNodeStack.h
//  EvanHeatonProgramming4
//
//  Created by Evan Heaton on 4/17/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#ifndef __EvanHeatonProgramming4__ETreeNodeStack__
#define __EvanHeatonProgramming4__ETreeNodeStack__

#include <stdio.h>
#include <vector>
#include "ETreeNode.h"

class ETreeNodeStack {
    
private:
    std::vector<ETreeNode*> data;
public:
    ETreeNodeStack();
    ETreeNode* pop();
    void push(ETreeNode*);
    ETreeNode* peek();
    ~ETreeNodeStack() {};
    
    
};

#endif /* defined(__EvanHeatonProgramming4__ETreeNodeStack__) */

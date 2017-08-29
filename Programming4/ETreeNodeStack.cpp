//
//  ETreeNodeStack.cpp
//  EvanHeatonProgramming4
//
//  Created by Evan Heaton on 4/17/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#include "ETreeNodeStack.h"
#include <vector>

using namespace std;

ETreeNodeStack::ETreeNodeStack() {
    vector<ETreeNode*> data;
}

ETreeNode* ETreeNodeStack::pop() {
    if (data.size()==0)
        return NULL;
    else
    {
        ETreeNode* temp = data.back();
        data.pop_back();
        return temp;
    }
}

void ETreeNodeStack::push(ETreeNode* d) {
    data.push_back(d);
}

ETreeNode* ETreeNodeStack::peek() {
    if (data.size()==0)
        return NULL;
    else
        return data.back();
}
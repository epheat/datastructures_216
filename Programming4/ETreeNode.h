//
//  ETreeNode.h
//  EvanHeatonProgramming4
//
//  Created by Evan Heaton on 4/17/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#ifndef __EvanHeatonProgramming4__ETreeNode__
#define __EvanHeatonProgramming4__ETreeNode__

#include <stdio.h>

class ETreeNode {
public:
    virtual ~ETreeNode() {};
    virtual void PrePrint() = 0; //PURE VIRTUAL FUNCTIONS NO WAY
    virtual void InPrint() = 0;
    virtual void PostPrint() = 0;
    virtual void del() = 0;
    friend class ETree;
protected:
    ETreeNode* right;
    ETreeNode* left;
};

#endif /* defined(__EvanHeatonProgramming4__ETreeNode__) */

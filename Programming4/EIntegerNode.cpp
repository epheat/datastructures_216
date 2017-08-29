//
//  EIntegerNode.cpp
//  EvanHeatonProgramming4
//
//  Created by Evan Heaton on 4/17/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#include "EIntegerNode.h"
#include <iostream>

EIntegerNode::EIntegerNode() {
    data = 0;
    right = NULL;
    left = NULL;
}

EIntegerNode::EIntegerNode(int d) {
    data = d;
    right = NULL;
    left = NULL;
}

void EIntegerNode::del() {
    //std::cout << "deleted " << data;
    delete this;
}

void EIntegerNode::PrePrint() {
    std::cout << this->data << " ";
}

void EIntegerNode::InPrint() {
    std::cout << this->data << " ";
}

void EIntegerNode::PostPrint() {
    std::cout << this->data << " ";
}

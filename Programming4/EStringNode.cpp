//
//  EStringNode.cpp
//  EvanHeatonProgramming4
//
//  Created by Evan Heaton on 4/17/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#include "EStringNode.h"
#include <iostream>

EStringNode::EStringNode() {
    data = "";
    left = NULL;
    right = NULL;
}

EStringNode::EStringNode(std::string d) {
    data = d;
    left = NULL;
    right = NULL;
}

void EStringNode::del() {
    left->del();
    right->del();
    //std::cout << "deleted " << data;
    delete this;
}

void EStringNode::PrePrint() {
    std::cout << this->data << " ";
    left->PrePrint();
    right->PrePrint();
}

void EStringNode::InPrint() {
    std::cout << "( ";
    left->InPrint();
    std::cout << this->data << " ";
    right->InPrint();
    std::cout << ") ";
}

void EStringNode::PostPrint() {
    left->PostPrint();
    right->PostPrint();
    std::cout << this->data << " ";
}
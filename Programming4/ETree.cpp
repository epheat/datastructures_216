//
//  ETree.cpp
//  EvanHeatonProgramming4
//
//  Created by Evan Heaton on 4/17/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#include "ETree.h"
#include "ETreeNodeStack.h"
#include "EIntegerNode.h"
#include "EStringNode.h"
#include <sstream>

using namespace std;

ETree::ETree() {
    root = NULL;
}

ETree::~ETree() {
    if (root != NULL)
        root->del();
    root = NULL;
    //NEED DELETES HERE!!!!!!!! done I think
}

void ETree::BuildTree(std::string pos) {
    
    ETreeNodeStack stack;
    string extracted;
    stringstream ss(pos);
    stringstream converter;
    
    while (ss >> extracted)  //I commented out all my debugging stuff, just so you could see how much I had to do to figure this crap out. And it still doesn't even work completely
    {
        if (extracted == "+" || extracted == "-" || extracted == "*" || extracted == "/") //token is an operator
        {
            ETreeNode* temp = new EStringNode(extracted); //make a stringNode with the operator
            //cout << "\nright: " << stack.peek() << "   ";
            //stack.peek()->InPrint();
            temp->right = stack.pop();
            //cout << "\nleft: " << stack.peek() << "   ";
            //stack.peek()->InPrint();
            temp->left = stack.pop();
            stack.push(temp);
            //cout << "\nPushed operator " << extracted;
        }
        else
        {
            converter.clear();
            converter.str("");
            int operand;
            converter << extracted;
            converter >> operand;
            ETreeNode* temp = new EIntegerNode(operand);
            stack.push(temp);
            //cout << "\nPushed operand " << extracted;
        }
    }
    //cout << "root: " << stack.peek() << "   ";
    //stack.peek()->InPrint();
    
    root = stack.pop();
    if (stack.peek() != NULL)
        cout << stack.peek() << " EEEERRROROROROROROR";
    //cout << "\nPushed root";
}

void ETree::PreTraversal() {
    root->PrePrint();
}
void ETree::InTraversal() {
    root->InPrint();
}
void ETree::PosTraversal() {
    root->PostPrint();
}


//
//  ELinkedList.cpp
//  EvanHeatonProgramming2
//
//  Created by Evan Heaton on 3/2/15.
//  Copyright (c) 2015 Evan Heaton. All rights reserved.
//

#include "ELinkedList.h"
#include <iostream>

using namespace std;

ELinkedList::ELinkedList()
{
	head = NULL;
}

ELinkedList::~ELinkedList()
{
	if (!(head == NULL))
	{
		ENode* temp = head;
		ENode* temp_behind = head;
		while (temp->next_ENode() != NULL)
		{
			temp = temp->next_ENode();
			delete temp_behind;
			temp_behind = temp;
		}
	}
}

ENode* ELinkedList::find(string lin)
{
    if (head == NULL)     //empty ELinkedList
    {
        return NULL;
    }
    else
    {
        ENode* tempnode = head;
        while (tempnode != NULL)   //while current node is not null, check for sent val
        {
            if (lin == tempnode->get_line())
            {
                return tempnode;
            }
            else
            {
                if (tempnode->next_ENode() == NULL)    //if next ENode is null, it was not found
                {
                    return NULL;
                }
                else
                {
                    tempnode = tempnode->next_ENode();   //go to next ENode
                }
            }
        }
    }
    return NULL;
}

bool ELinkedList::insertion(int place, string lin)
{
    ENode* new_ENode = new ENode();
    new_ENode->set_line(lin);
    
    if (head == NULL)  //empty ELinkedList
    {
        if (place == 0)
        {
            head = new_ENode;
            return true;
        }
        else { delete new_ENode; return false; }
    }
    else               //non-empty ELinkedList
    {
        if (place == 0)
        {
            new_ENode->set_next(head);
            head = new_ENode;
            return true;
        }
        else
        {
            ENode* current_node = head;
            for (int i=0;i<place-1;i++)
            {
                if (current_node->next_ENode() == NULL)
                {
                    current_node->set_next(new ENode());
                    current_node = current_node->next_ENode();
                    //Add logic here to insert blank lines between insertions out of range
                }
                else
                {
                    current_node = current_node->next_ENode();
                }
            }
            if (current_node->next_ENode() == NULL)
            {
                new_ENode->set_next(NULL);
                current_node->set_next(new_ENode);
                return true;
            }
            else
            {
                new_ENode->set_next(current_node->next_ENode());
                current_node->set_next(new_ENode);
                return true;
            }
        }
        
    }
    //can it even get here?
    return false;
}

//return 0 for unsuccessful, 1 for successful
bool ELinkedList::deletion(int place)
{
    if (head == NULL)  //empty ELinkedList
        return 0;
    else
    {
        ENode* current_node = head;
        ENode* current_node2 = current_node;
        
        if (place == 0 || head->next_ENode() == NULL)  //1 length list or 1st item
        {
            head = current_node->next_ENode();
            delete current_node;
            current_node=NULL;
            return 1;
        }
        
        for (int i=0;i<place-1;i++) //travel through the linkedlist, up until the node before the node that must be deleted
        {
            if (current_node->next_ENode() == NULL) //if the next node is null while traveling, then the deletion place is higher than the list extends
            {
                current_node = NULL;
                return 0;
            }
            else
            {
                current_node = current_node->next_ENode();
            }
        }
        if (current_node->next_ENode() == NULL) // Couldn't find this bug, it occurs when the deletion place is one larger than the length of the linkedlist
        {
            current_node=NULL;
            return 0;
        }
        else
	{
	    current_node2 = current_node->next_ENode();  //do this to save the no longer referenced node
            current_node->set_next((current_node->next_ENode())->next_ENode());
	}

        delete current_node2;
	current_node = NULL;
	current_node2 = NULL;
        return 1;

    }
    //don't think it's possible to get here
    return 1;
}

void ELinkedList::print(ostream& outS, bool LineNumbers)
{
    //simple print function, edited to look nicer
    //outline based off Lab4 LinkedList
    
    ENode* current_ENode = head;
    if (current_ENode == NULL)
    {
        if (LineNumbers)
            outS << "Empty ELinkedList\n";
        return;
    }
    if (current_ENode->next_ENode() == NULL)
    {
        if (LineNumbers)
            outS << "0] ";
        outS << current_ENode->get_line() << "\n";
    }
    else
    {
        int counter = 0;
        while (current_ENode != NULL)
        {
            if (LineNumbers)
                outS << counter << "] ";
            outS << current_ENode->get_line();
            if (LineNumbers || !(current_ENode->next_ENode()==NULL))
                outS << "\n";
            current_ENode = current_ENode->next_ENode();
            counter++;
        }
    }
    return;
}



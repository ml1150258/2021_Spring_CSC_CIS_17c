/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.cpp
 * Author: Jason
 * 
 * Created on April 3, 2021, 9:50 AM
 */

#include "List.h"

List::List()
{
    
}

List::List(Link* list)
{
    head = list;
}

List::Link *create(int)    //Create a Link with Data
{
    Link *nxtLink=new Link;
    nxtLink->data=n;
    nxtLink->lnkNext=NULL;
   
    return nxtLink;
}
//Push a link to the front
void pshFrnt(Link *)
{
    //temporary instance of the link
    Link* newLink;
    //put in the data
    newLink=create(rand() % 9+1);
    cout << "Pushing a " <<  newLink->data << " to the font..." << endl;
    //link the front to the new node
    newLink->lnkNext=front;
    //make the new link the front of the list
    front=newLink;     
}
//Push a link to the end
void pshBack(Link *)
{
    //temporary instance of the link
    Link* newLink;
    //put in the data
    newLink=create(rand() % 9+1);
    cout << "Pushing a " <<  newLink->data << " to the back..." << endl;
    //make the new link point to NULL
    //newLink->lnkNext = NULL;
    //if the linked list is empty then the new link will be the front
    if  (link == NULL)
    {
        link = newLink;
    }
    //temp traversal pointer
    Link* linkPtr = link;
    //else traverse the list till the last node
    while (linkPtr->lnkNext != NULL)
    {
        linkPtr = linkPtr->lnkNext;
    }
    //make the new link the last link
    linkPtr->lnkNext = newLink;
    return;

}
//Pull/pop a link from the front
Link *popFrnt()
{
    //check to see if the list is empty
    if (front == NULL)
    {
        cout << " the list is empty" << endl;
        return NULL;
    }
    //creating the temp link to hold the link to be returned (front)
    Link* linkPtr = front;
    //moving the front over after the pop
    front = front->lnkNext;
    //deleting the popped link
    delete linkPtr;
    //return
    return front;

}
//Pull/pop a link from the back
Link *popBack()
{
    //check to see if the list is empty
    if (link == NULL)
    {
        cout << " the list is empty" << endl;
        return NULL;
    }
    //creating the temp link to hold the link to be returned
    Link* linkPtr = link;
    //find the link before the last
    while (linkPtr->lnkNext->lnkNext)
    {
     linkPtr = linkPtr->lnkNext;   
    }
    //deleting the popped link
    delete linkPtr->lnkNext->lnkNext;
    //make the new link the tail by pointing to NULL
    linkPtr->lnkNext = NULL;
    //return
    return link; 

}


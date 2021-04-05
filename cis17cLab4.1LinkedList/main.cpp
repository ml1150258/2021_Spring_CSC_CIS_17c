/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021  1:12pm
    Purpose:Create the 5 functions for Version 4 of this code.
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //NULL pointer
using namespace std;   //Library Name-space

//User Libraries
#include "Link.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
Link *fillLst(int);
void prntLst(Link *);
void destroy(Link *);

//Prototype function you are to consider for Wednesday
Link *create(int);    //Create a Link with Data
void pshFront(Link *&); //Push a link to the front
void pshBack(Link *&); //Push a link to the end
Link *popFront(Link *&);      //Pull/pop a link from the front
Link *popBack(Link *&);      //Pull/pop a link from the back

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    Link *lnk1=fillLst(5);
    
    
    //Printing all the data elements in the linked list
    cout << "Here is the linked list with 5 elements..." << endl;
    prntLst(lnk1);
    
    //Printing after the push front
    cout << "\nHere is the linked list with an element pushed on the front..."<< endl;
    pshFront(lnk1);
    prntLst(lnk1);
    
    //Printing after the push back
    cout << "\nHere is the linked list with an element pushed on the back..."<< endl;
    pshBack(lnk1);
    prntLst(lnk1);
    
    //Printing after the pop front
    cout << "\nHere is the linked list with an element popped off the front..."<< endl;
    popFront(lnk1);
    prntLst(lnk1);
    
    //Printing after the pop back
    cout << "\nHere is the linked list with an element popped off the back..."<< endl;
    popBack(lnk1);
    prntLst(lnk1);
    
    //Delete all the allocated memory
    destroy(lnk1);
    
    //Exit stage right
    return 0;
}

Link *fillLst(int n){
    //Initially create the front pointer/beginning pointer
    Link *front=new Link;
    front->data=1;
    front->lnkNext=NULL;
    //If n>1 then fill with the data and links to the next
    Link *temp=front;
    for(int i=2;i<=n;i++){
        Link *nxtLink=new Link;
        nxtLink->data=i;
        temp->lnkNext=nxtLink;
        temp=nxtLink;
    }
    temp->lnkNext=NULL;
    //Return the front of the list
    return front;
}

void prntLst(Link *next){
    while(next!=NULL){
        cout<<next->data<<endl;
        next=next->lnkNext;
    }
}

void destroy(Link *front){
    while(front!=NULL){
        Link *temp=front;
        front=front->lnkNext;
        delete temp;
    }
}

//Create a Link with Data
Link *create(int n)    
{
    Link *nxtLink=new Link;
    nxtLink->data=n;
    nxtLink->lnkNext=NULL;
   
    return nxtLink;
}
//Push a link to the front
void pshFront(Link * &front) 
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
void pshBack(Link * &link)
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
//Link *popFrnt();      
Link *popFront(Link * &front)
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
//Link *popBack()
Link *popBack(Link * &link)
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
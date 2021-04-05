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
#include "List.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
Link *fillLst(int);
void prntLst(Link *);
void destroy(Link *);


//Execution Begins Here
int main(int argc, char** argv) 
{
    //Set the Random number seed
    //List *myHead = new List(5);
    
    
    
    //Declare variables
    //Link *lnk1=fillLst(5);
    List* myList = new List(fillLst(5));
    
    //Printing all the data elements in the linked list
    cout << "Here is the linked list with 5 elements..." << endl;
    prntLst(myList->head);
    
    //Printing after the push front
    cout << "\nHere is the linked list with an element pushed on the front..."<< endl;
    pshFront(myList->head);
    prntLst(myList->head);
    
    //Printing after the push back
    cout << "\nHere is the linked list with an element pushed on the back..."<< endl;
    pshBack(myList->head);
    prntLst(myList->head);
    
    //Printing after the pop front
    cout << "\nHere is the linked list with an element popped off the front..."<< endl;
    popFront(myList->head);
    prntLst(myList->head);
    
    //Printing after the pop back
    cout << "\nHere is the linked list with an element popped off the back..."<< endl;
    popBack(myList->head);
    prntLst(myList->head);
    
    
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
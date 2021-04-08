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
void pshFrnt(Link *); //Push a link to the front
void pshBack(Link *); //Push a link to the end
Link *popFrnt();      //Pull/pop a link from the front
Link *popBack();      //Pull/pop a link from the back

//Things to add next!
void insrtB4(Link *,int);//Insert Before
void inAftr(Link *,int);//Insert After
Link *delB4(int);       //Delete Before
Link *delAftr(int);     //Delete After

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    front=fillLst(5);
    
    //Printing all the data elements in the linked list
    prntLst(front);
    
    //Push some data to the front
    for(int i=10;i<=15;i++){
        pshFrnt(create(i));
    }
    
    //Printing all the data elements in the linked list
    prntLst(front);
    
    //Pop some data off the front
    cout<<"Getting rid of the data"<<endl;
    for(int i=1;i<=3;i++){
        cout<<"There it goes -> "<<popFrnt()->data<<endl;
    }
    
    //Printing all the data elements in the linked list
    prntLst(front);
    
    //Push some data to the back
    for(int i=20;i<=25;i++){
        pshBack(create(i));
    }
    
    //Printing all the data elements in the linked list
    prntLst(front);
    
    //Pop some data off the front
    cout<<"Getting rid of the data"<<endl;
    for(int i=1;i<=3;i++){
        cout<<"There it goes -> "<<popBack()->data<<endl;
    }
    
    //Printing all the data elements in the linked list
    prntLst(front);
    
    //Insert some data after
    cout<<"Adding Links after a Value"<<endl;
    for(int i=1;i<=3;i++){
        inAftr(create(i+100),i);
    }
    
    //Printing all the data elements in the linked list
    prntLst(front);
    
    //Insert some data before
    cout<<"Adding Links before a value"<<endl;
    for(int i=1;i<=3;i++){
        insrtB4(create(i+200),i);
    }
    
    //Printing all the data elements in the linked list
    prntLst(front);
    
    //Delete all the allocated memory
    destroy(front);
    
    //Exit stage right
    return 0;
}

void inAftr(Link * insert,int data){
    Link *next=front;
    while(next->data!=data){
        next=next->lnkNext;
    }
    insert->lnkNext=next->lnkNext;
    next->lnkNext=insert;
}

void insrtB4(Link * insert,int data){
    Link *next=front;
    Link *last=front;
    while(next->data!=data){
        last=next;
        next=next->lnkNext;
    }
    last->lnkNext=insert;
    insert->lnkNext=next;
}

Link *popBack(){
    Link *next=front;
    Link *last=front;
    while(next->lnkNext!=NULL){
        last=next;
        next=next->lnkNext;
    }
    last->lnkNext=NULL;
    return next;
}


void pshBack(Link *back){
    Link *next=front;
    Link *last=front;
    while(next!=NULL){
        last=next;
        next=next->lnkNext;
    }
    last->lnkNext=back;
}

Link *popFrnt(){
    Link *remove=front;
    front=front->lnkNext;
    return remove;
}

void pshFrnt(Link *nwLink){
    nwLink->lnkNext=front;
    front=nwLink;
}

Link *create(int data){
    Link *nwLink=new Link;
    nwLink->data=data;
    return nwLink;
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
    cout<<"Print of the List"<<endl;
    while(next!=NULL){
        cout<<next->data<<endl;
        next=next->lnkNext;
    }
    cout<<endl;
}

void destroy(Link *front){
    while(front!=NULL){
        Link *temp=front;
        front=front->lnkNext;
        delete temp;
    }
}
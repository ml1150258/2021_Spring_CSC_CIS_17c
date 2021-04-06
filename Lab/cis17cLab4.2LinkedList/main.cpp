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
//#include "Link.h"
#include "List.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
Link* fillLst(int);
void prntLst(Link*);
void destroy(Link*);


//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed

    //Declare variables
    //Link* lnk1 = fillLst(5);
    List* myList = new List(fillLst(5));

    //Printing all the data elements in the linked list
    cout << "Here is the linked list with 5 elements..." << endl;
    prntLst(myList->head);

    //Printing after the push front
    cout << "\nHere is the linked list with an element pushed on the front..." << endl;
    myList->pshFrnt();
    prntLst(myList->head);

    //Printing after the push back
    cout << "\nHere is the linked list with an element pushed on the back..." << endl;
    myList->pshBack();
    prntLst(myList->head);

    //Printing after the pop front
    cout << "\nHere is the linked list with an element popped off the front..." << endl;
    myList->popFrnt();
    prntLst(myList->head);

    //Printing after the pop back
    cout << "\nHere is the linked list with an element popped off the back..." << endl;
    myList->popBack();
    prntLst(myList->head);

    //Delete all the allocated memory
    destroy(myList->head);

    //Exit stage right
    return 0;
}
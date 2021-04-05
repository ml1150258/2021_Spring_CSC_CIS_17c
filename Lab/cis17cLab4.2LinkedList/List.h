/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.h
 * Author: Jason
 *
 * Created on April 3, 2021, 9:50 AM
 */
#include "Link.h"

#ifndef LIST_H
#define LIST_H

class List 
{
private:

    
public:
    struct Link
    {
        int data;     //Some type of data
        Link *lnkNext; //Next Link in the chain    
    };
    Link* head;     
    List();
    List(Link*);
    ~List();

    Link *create(int);    //Create a Link with Data
    void pshFrnt(Link *); //Push a link to the front
    void pshBack(Link *); //Push a link to the end
    Link *popFrnt();      //Pull/pop a link from the front
    Link *popBack();      //Pull/pop a link from the back
};

#endif /* LIST_H */


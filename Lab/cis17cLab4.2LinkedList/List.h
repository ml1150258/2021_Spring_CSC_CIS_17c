#include <iostream>
#include "Link.h"

using namespace std;

#ifndef LIST_H
#define LIST_H

class List
{
    
public:
    Link* head;
    List(Link* fillList)
    {
        head = fillList;
    }
    //Prototype function you are to consider for Wednesday
    Link* create(int num)    //Create a Link with Data
    {
        Link* newLink = new Link;
        newLink->data = num;
        newLink->lnkNext = nullptr;

        return newLink;
    }
    void pshFrnt() //Push a link to the front
    {
        Link* newLink = create((rand() % 9 + 1));
        newLink->lnkNext = head;
        head = newLink;
    }
    void pshBack() //Push a link to the end
    {
        Link* newLink = create((rand() % 10 + 1));

        if (head == nullptr)
        {            
            head = newLink;
            return;
        }

        Link* t = head;
        for (; t->lnkNext != nullptr; t = t->lnkNext);
        t->lnkNext = newLink;
    }
    Link* popFrnt()      //Pull/pop a link from the front
    {
        if (head == nullptr)
            return nullptr;

        Link* victim = head;
        head = head->lnkNext;
        delete victim;
    }
    Link* popBack()      //Pull/pop a link from the back
    {
        if (head == nullptr)
            return nullptr;

        for (Link* prev = head; prev != NULL; prev = prev->lnkNext)
        {
            if (prev->lnkNext->lnkNext == NULL)
            {
                Link* victim = prev->lnkNext;
                prev->lnkNext = nullptr;
                victim->lnkNext = nullptr;
                delete victim;
            }
        }
    }
};

#endif /* LINK_H */
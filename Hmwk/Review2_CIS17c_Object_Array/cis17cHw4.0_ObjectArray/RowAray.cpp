/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   RowAray.cpp
 * Author: Jason Jones
 *
 * Created on March 22, 2021, 11:23 AM
 */
#include "RowAray.h"
#include "cstdlib"

RowAray::RowAray(unsigned int cols) 
{
    size = cols;
    rowData = new int[size];
    
    for (int i = 0; i < size; i++)
    {
        *(rowData+i) = rand() % 90 +10;
        //rowData[i] = rand() % 90 +10;
    }
}

void RowAray::setData(int i,int data)
{
    rowData[i] = data;
}

RowAray::~RowAray() {delete [] rowData;}




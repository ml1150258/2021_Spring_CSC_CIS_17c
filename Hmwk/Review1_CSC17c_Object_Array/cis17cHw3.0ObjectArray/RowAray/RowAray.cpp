/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RowAray.cpp
 * Author: Jason
 * 
 * Created on March 21, 2021, 7:42 PM
 */

#include "RowAray.h"
#include <iostream>

RowAray::RowAray(int cols)
{
    size=cols;//set cols into size
    rowData=new int[size];//create pointer
  
    for(int j=0;j<size;j++){//fill in pointer
        rowData[j]=rand()%90+10;
    }
}

RowAray::RowAray(int row,int col)
{
    size = row*col;//multiply row and col and set to size
    rowData = new int[size];//create pointer with size
}

void RowAray::Fill(int j)
{
    rowData[j]=rand()%90+10;   //fill from 10-99
}

RowAray::~RowAray()
{
    delete []rowData;//de allocates rowData
}

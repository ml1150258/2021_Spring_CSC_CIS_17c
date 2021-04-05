/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.cpp
 * Author: Jason
 * 
 * Created on March 21, 2021, 7:43 PM
 */
#include "Table.h"

Table::Table(int rows, int cols)
{
    //Setting sizes for Table
    szRow = rows;//sets rows to szRow
    szCol = cols;//set cols to szCol
    records = new RowAray*[szRow];//creates a pointer for record
    //creates space for 2dArray
    for (int j=0; j<szRow;j++){
        records[j] = new RowAray(szRow,szCol);//pointer to pointer
    }
    //fill the array
    for(int j=0;j<szRow;j++){
        for(int v=0;v<szCol;v++){
            records[j]->Fill(v);//fills my 2d array
        }
    }       
}

int Table::getData(int row, int col)
{
    return records[row]->getData(col);//returns the data at location
}

Table::~Table()
{
    for(int j = 0; j < szRow; ++j) {
        delete [] records[j]; //deallocate records 2 degree of pointer
    }
    delete [] records;//deallocate records
}
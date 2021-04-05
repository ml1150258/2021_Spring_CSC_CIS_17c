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

#include "Table.h"

Table::Table(unsigned int rows, unsigned int cols)
{
    szRow = rows;
    szCol = cols;
    columns = new RowAray *[szRow];
    
    for(int i = 0; i < szRow; i++)
    {
        columns[i] = new RowAray(szCol);
    }
}

Table::Table(const Table& tab2)
{
    szRow = tab2.getSzRow();
    szCol = tab2.getSzCol()00;
    columns = new RowAray *[szRow];
    
    for(int i = 0; i < szRow; i++)
    {
        columns[i] = new RowAray(szCol);
    }
    
    
//    Table newTab (tab2.getSzRow(), tab2.getSzCol());
//    
    for(int i = 0; tab2.szRow; i++)
    {
        for(int j = 0; tab2.szCol; j++)
        {
            setData(i,j,tab2.getData(i,j));
        }
    }
    
} 

Table::getData(int row, int col) const
{
    return columns[row]->getData(col);
}

void Table::setData(int row, int col, int data)
{
    columns[row]->setData(col, data); 
}


Table::~Table(){delete []columns;}
        
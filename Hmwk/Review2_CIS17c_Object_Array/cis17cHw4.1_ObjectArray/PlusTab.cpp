/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * File:   RowAray.cpp
 * Author: Jason Jones
 * Created on March 22, 2021, 11:23 AM
 */

#include "PlusTab.h"
using namespace std;

PlusTab PlusTab::operator+(const PlusTab &right){
    PlusTab tab(right.szRow, right.szCol);
    for(int i = 0; i < this->szRow; i++){
        for(int j = 0; j < this->szCol; j++){
            tab.setData(i, j, this->getData(i,j) + right.getData(i,j));
        }
    }
    return tab;
    
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * File:   RowAray.cpp
 * Author: Jason Jones
 * Created on March 22, 2021, 11:23 AM
 */

#include "RowAray.h"
#include "AbsRow.h"
#include <cstdlib>
using namespace std;

RowAray::RowAray(int s){
    this->size = s;
    this->rowData = new int[s];
    
    for(int i = 0; i < s; i++){
        this->rowData[i] = rand() % 100;
    }
}

RowAray::~RowAray(){
    delete[] this->rowData;
}

void RowAray::setData(int index, int x){
    this->rowData[index] = x;
}
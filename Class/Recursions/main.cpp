/*
    Author: Dr. Mark E. Lehr
    Date:   April 19th, 2021  1:40pm
    Purpose:All Forms of Recursion
 */

//System Libraries
#include <iostream>    //Input/Output Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
float fvRec(float,float,int);
float fvNoRec(float,float,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Compare functions for Future Value/Savings
    float   pv=100.0f,//$100
            intRate=0.06f;//6 percent
    int     nCmpds=12;//Rule of 72 when fv~2*pv;
    cout<<"For-Loop Savings  = "<<"FV("<<pv<<","<<intRate<<","<<nCmpds<<") = $"
        <<fvNoRec(pv,intRate,nCmpds)<<endl;
    cout<<"Recursive Savings = "<<"FV("<<pv<<","<<intRate<<","<<nCmpds<<") = $"
        <<fvRec(pv,intRate,nCmpds)<<endl;
    
    
    //Exit stage right
    return 0;
}

float fvNoRec(float pv,float intRate,int nCmpds){
    for(int i=1;i<=nCmpds;i++){
        pv*=(1+intRate);
    }
}

float fvRec(float pv,float intRate,int nCmpds){
    //Base Conditions
    if(nCmpds<=0)return pv;
    //Recursive Calculation
    return fvRec(pv,intRate,nCmpds-1)*(1+intRate);
}
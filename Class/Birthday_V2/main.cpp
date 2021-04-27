/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 19, 2021, 11:51 AM
 * Purpose:  Birthday Collisions
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
#include <cstdlib>    //Random Numbers
#include <iomanip>
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions
//constants to follow

//Function Prototypes
int   simVal(int,int);//Simulate the Birthday Collisions
float expRec(int,int);//Expected Value Recursively Calculate Birthday Collisions
float expFrm(int,int);//Expected Value using derived formula
int *dstVal(int,int);//A single Distribution

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables - Known and Unknown, units, range, description
    
    //Initialize Variables
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<endl<<"Comparison of Simulation, Recursion and Closed Form Solution"<<endl;
    cout<<"The Birthday Problem, Expected Number of Students with Same Birthday"<<endl;
    cout<<endl<<"M Birthdays  Simulation  Recursion  Closed Form   Collisions"<<endl;
    int dysYr=365;
    for(int students=0;students<=dysYr;students+=4){
        float avg=0,nLoop=100000;
        for(int i=1;i<=nLoop;i++){
            avg+=simVal(dysYr,students);
        }
        avg/=(1.0f*nLoop);
        cout<<setw(10)<<students<<setw(11)<<avg
                <<setw(11)<<expRec(dysYr,students)
                <<setw(11)<<expFrm(dysYr,students)
                <<setw(11)<<static_cast<int>(students-avg)<<endl;
    }
    int *dist=dstVal(dysYr,dysYr);
    cout<<endl<<"Max Collisions = "<<dist[0]<<endl;
    cout<<"Birthday Distributions Single Simulation"<<endl;
    for(int i=1;i<=dist[0]+1;i++){
        cout<<i-1<<"->"<<dist[i]<<endl;
    }
    
    //Clean up - File closing, memory deallocation, etc....
    delete dist;

    //Exit Stage Right!
    return 0;
}

//Function Implementations

float expFrm(int n,int m){
    float c=1-1.0f/n;
    return n*(1-pow(c,m));
}

float expRec(int n,int m){
    //Base Condition
    if(m==0)return 0;
    if(m==1)return 1;
    //Recursion
    float c=1-1.0f/n;
    return c*expRec(n,m-1)+1;
}

int simVal(int n,int m){
    //Static array of Birthdays
    char birthday[n];
    //Initialize the arrays to all zeroes
    for(int i=0;i<n;i++){
        birthday[i]=0;
    }
    //Choose random birthdays
    for(int i=1;i<=m;i++){
        int random=rand()%n;
        birthday[random]=1;
    }
    //Sum the number of unique birthdays
    //Note:  The larger m, the more collisions
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=birthday[i];
    }
    return sum;
}

int *dstVal(int n,int m){
    //Static array of Birthdays
    char birthday[n];
    //Initialize the arrays to all zeroes
    for(int i=0;i<n;i++){
        birthday[i]=0;
    }
    //Choose random birthdays
    for(int i=1;i<=m;i++){
        int random=rand()%n;
        birthday[random]+=1;
    }
    //Find the max and size the array accordingly
    int max=0;
    for(int i=0;i<n;i++){
        if(birthday[i]>max)max=birthday[i];
    }
    //Create an array to count the number of collisions
    int *dist=new int[max+2];
    for(int i=0;i<max+2;i++){
        dist[i]=0;
    }
    //Find the distribution
    for(int i=0;i<n;i++){
        dist[birthday[i]+1]++;
    }
    dist[0]=max;
    return dist;
}
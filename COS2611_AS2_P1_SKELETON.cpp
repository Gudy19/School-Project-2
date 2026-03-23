// COS2611_2024_As2_P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// School Project
//Your name

#include <iostream>
#include <vector>
//#include "COS2611_As2_P1.h"
using namespace std;


//Function for the first sorting algorithm



//Function for the second sorting algorithm



//Function to generate a random array of a given size
vector<int> generateRandomArray(int size) {

    vector<int> arr(size);
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000; //adjust the range to play around with it
    }
           
    return arr;

} //generateRandomArray


//you can make this more code efficient - did it this way for more clarity purposes

void measureSortingTimeFirstSortingAlgorithm(vector<int>& arr, double& timeExecuted, double& timeComplexity) {

    //measure start time
    clock_t startTime = clock();
    
    //Call your first sorting algorithm


    //measure end time

    clock_t endTime = clock();

    //calculate executation time in secods for first sorting algorithm

    timeExecuted = (endTime - startTime) / CLOCKS_PER_SEC;

    //calculate time comlexity for your sorting algorithm

    timeComplexity = 0; //this will then be the time complexity - you must provide the code

} //measureSortingTimeFirstSortingAlgorithm



void measureSortingTimeSecondSortingAlgorithm(vector<int>& arr , double  &timeExecuted, double &timeComplexity   ) {

    //measure start time
    clock_t startTime = clock();

    //Call your second algortihm


    //measure end time

    clock_t endTime = clock();

    //calculate executation time in secods for first sorting algorithm

    timeExecuted = (endTime - startTime) / CLOCKS_PER_SEC;
    
    //calculate time comlexity for your sorting algorithm

    timeComplexity = 0; //this will then be the time complexity - you must provide the code

} //measureSortingTimeSecondSortingAlgorithm




int main()
{
   

    cout << "COS2611 Assessment 2 Project 1 - Skeleton \n";
    cout << "ARRAYS";

    //generate an array with 100 random elements

    double timeExecuted1, timeExecuted2;
    double timeComplexity1, timeComplexity2;

    vector<int> inputSizes = { 100,1000,5000 };

    for (int size : inputSizes) {
        vector<int> arr = generateRandomArray(size);

        //measure the sorting time for sorting algorithm
        
        measureSortingTimeFirstSortingAlgorithm(arr,timeExecuted1,timeComplexity1);
                
        measureSortingTimeSecondSortingAlgorithm(arr,timeExecuted2,timeComplexity2);

        //The display of your results will go here.

    }

    //the above may not be the best way to code it - it is just to give you a headstart.



    return 0;
} //main


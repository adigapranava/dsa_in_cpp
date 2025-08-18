/*
    Move all zeros to left, keeping all non zero elements in the right order
*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> arr = {1,0, 0, 4, 3, 6, 0,6,0};

    int nonZeroIndex = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            arr[nonZeroIndex++] = arr[i]; 
        }
    }

    while(nonZeroIndex < arr.size()){
        arr[nonZeroIndex++] = 0; 
    }
    
    
    
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout<<" "<<arr[i]<<" ";
    }
    
}
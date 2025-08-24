#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void moveRight(vector<int>& arr, int index){
        if (index >= arr.size())
            return;
        for (int i = arr.size()-2; i >= index; i--)
            arr[i+1] = arr[i];
        arr[index] = 0;
    }

    void duplicateZeros(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == 0){
                moveRight(arr, i+1);
                i+=1;
            }
        }
    }

void duplicateZeros2(vector<int>& arr){
    int numOfZeroes = 0, n = arr.size();

    // Count total zeros
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            numOfZeroes++;

    int i = n - 1;                 // pointer to original array
    int j = n + numOfZeroes - 1;   // pointer to virtual extended array

    while (i < j) {
        if (arr[i] != 0) {
            if (j < n) {
                arr[j] = arr[i];   // copy non-zero once
            } 
        } else {
            if (j < n) {
                arr[j] = 0;        // first copy of zero
                j--;
                arr[j] = 0;        // second copy of zero
            }else{
                j--;
            }
        }
        i--;
        j--;
    }
}
};

int main() {
    Solution sol;
    vector<int> arr = {0,4,1,0,0,8,0,0,3}; // Example input
    sol.duplicateZeros2(arr);

    // Print the modified array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
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
};

int main() {
    Solution sol;
    vector<int> arr = {0,4,1,0,0,8,0,0,3}; // Example input
    sol.duplicateZeros(arr);

    // Print the modified array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
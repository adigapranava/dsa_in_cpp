#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;
        int c = 0;
        for (int i = 0; i < nums.size(); i++){
            while(freq[c]==0){
                c++;
            }
            nums[i] = c;
            freq[c]--;
        }        
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 0, 2, 1, 1, 0}; // Example input
    solution.sortColors(nums);
    
    cout << "Sorted colors: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;   
}
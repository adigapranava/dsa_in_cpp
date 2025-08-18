#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums_sq(n);
        int left = 0, right= nums.size()-1, i = n-1;
        while(left<=right){
            if(abs(nums[left]) < abs(nums[right])){
                nums_sq[i] = (nums[right] * nums[right]);
                right--;
            }else{
                nums_sq[i] = (nums[left] * nums[left]);
                left++;
            }
            i--;
        }
        return nums_sq;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-7,-3,2,3,11}; // Example input
    vector<int> result = sol.sortedSquares(nums);
    
    // Print the sorted squares
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
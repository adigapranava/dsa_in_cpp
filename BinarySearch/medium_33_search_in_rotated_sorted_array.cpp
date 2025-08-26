#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int m = (l + r) / 2;
            
            if (nums[m] == target) return m;
            
            // Left half is sorted
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        
        return -1;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout<<sol.search(nums,target);
    return 0;
}
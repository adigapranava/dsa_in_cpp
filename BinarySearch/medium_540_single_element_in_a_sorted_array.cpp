#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m;

        // Binary search loop
        // At the end, l == r and points to the single element
        while (l < r)
        {
            m = (l + r) / 2;

            // Ensure m is even so we can compare pairs (m, m+1)
            // Example: if m = 5 (odd), shift it back to 4
            if (m % 2 != 0)
                m--;

            // Case 1: nums[m] == nums[m+1]
            // → the pair at m and m+1 is complete
            // → so the single element must be to the right
            if (nums[m] == nums[m + 1]) {
                l = m + 2;  // skip this pair
            }
            // Case 2: nums[m] != nums[m+1]
            // → the single element is on the left side (or at m)
            else {
                r = m;
            }
        }

        // When loop exits, l == r
        // This index points to the single element
        return nums[l];
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,1,2,2,3,3,4,4,8,8};
    cout<<sol.singleNonDuplicate(nums);
    return 0;
}
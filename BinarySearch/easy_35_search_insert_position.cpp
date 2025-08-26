#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1, m;
        while (l< r)
        {
            m = (l+r)/2;
            if (nums[m] == target)
                break;
            else if(nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return nums[m] < target ? m + 1 :  m ;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,3,5,6};
    int target = 2;
    cout<<sol.searchInsert(nums, target);
    return 0;
}
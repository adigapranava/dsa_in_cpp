#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, m;
        while (l < r)
        {
            m = l + (r-l)/2;
            if (nums[m] > nums[n-1])
            {
                l = m + 1;
            }else{
                r = m;
            }
        }
        return nums[l];
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout<<sol.findMin(nums);
    return 0;
}
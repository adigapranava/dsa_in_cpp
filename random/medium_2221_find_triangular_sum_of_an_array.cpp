#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int triangularSum2(vector<int>& nums) {
        int n = nums.size(), ans;
        vector<int> temp = nums;
        while (nums.size() > 1)
        {
            temp.clear();
            for (int i = 0; i < nums.size()-1; i++)
            {
                int s = nums[i] + nums[i+1];
                s %= 10;
                temp.push_back(s);
            }
            nums.clear();
            nums = temp;
        }
        return temp[0];
    }

    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> newNums;
            for (int i = 0; i < nums.size() - 1; i++) {
                newNums.push_back((nums[i] + nums[i+1]) % 10);
            }
            nums = newNums;
        }
        return nums[0];
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    cout<<sol.triangularSum(nums);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start =0, min_size_sub_array = INT32_MAX, sum =0;
        for (int end = 0; end < nums.size(); end++)
        {
            sum += nums[end];
            while (sum >= target)
            {
                min_size_sub_array = min(min_size_sub_array, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }
        return min_size_sub_array == INT32_MAX ? 0 : min_size_sub_array;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,4,4}; // Example input
    int target = 5; // Example target sum
    int result = sol.minSubArrayLen(target, nums);
    
    cout << "Minimum Size Subarray Sum: " << result << endl; // Output the result

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, product = 1;
        int total_products = 0;

        if (nums.size() < 1)
            return 0;

        for (int end = 0; end < nums.size(); end++)
        {
            product *= nums[end];
            while (product >= k && start <= end)
            {
                product /= nums[start];
                start++;
            }
            total_products+= end-start+1;
        }
        
        return total_products;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3}; // Example input
    int k = 2; // Example threshold
    int result = sol.numSubarrayProductLessThanK(nums, k);
    
    cout << "Number of Subarrays with Product Less Than " << k << ": " << result << endl; // Output the result

    return 0;
}
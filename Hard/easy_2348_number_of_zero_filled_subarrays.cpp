#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum = 0;
        int left = 0, right = 0;
        for(int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0 && nums[left] == 0)
                continue;
            if (nums[left] == 0) {
                int len = right - left;
                sum += len;
                left= right + 1;
            }
            else {
                left =right;
            }
        }
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4}; // Example input
    long long result = sol.zeroFilledSubarray(nums);
    
    cout << "Number of zero-filled subarrays: " << result << endl; // Output the result

    return 0;
}
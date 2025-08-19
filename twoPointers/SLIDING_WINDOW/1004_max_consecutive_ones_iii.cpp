#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, longest_ones = 0, num_of_0s=0;
        for (int end = 0; end < nums.size(); end++)
        {
            if(nums[end] != 1){
                while(num_of_0s>=k){
                    num_of_0s = (nums[start++] ? num_of_0s : num_of_0s -1);
                }
                num_of_0s++;
            }
            longest_ones = max(longest_ones, end - start + 1);
        }
        return longest_ones;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}; // Example input
    int k = 3; // Maximum number of zeros to flip
    int result = sol.longestOnes(nums, k);
    
    cout << "Maximum length of consecutive ones after flipping at most " << k << " zeros: " << result << endl; // Output the result

    return 0;
}
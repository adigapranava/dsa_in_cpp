#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int min_v = INT32_MAX;
        for (int i = 0; i <= nums.size()-l; i++)
        {
            int s = 0;
            for (int offset = 0; offset < r; offset++)
            {
                if(i+offset >= nums.size()) break;
                s += nums[i + offset];

                if (s > 0 && offset+1 >= l)
                {
                    min_v = min(min_v, s);
                }
            }
        }
        return min_v == INT32_MAX ? -1 : min_v;
    }

    int minimumSumSubarray2(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_v = INT32_MAX;

        // try each starting index
        for (int i = 0; i < n; i++) {
            int s = 0;
            // grow the subarray length from 1 up to r
            for (int len = 1; len <= r && i + len - 1 < n; len++) {
                s += nums[i + len - 1]; // extend window
                if (s > 0 && len >= l) {
                    min_v = min(min_v, s);
                }
            }
        }

        return min_v == INT32_MAX ? -1 : min_v;
    }

};

int main() {
    Solution sol;
    vector<int> nums = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
    int l = 75; // Minimum length of subarray
    int r = 87; // Maximum length of subarray
    int result = sol.minimumSumSubarray2(nums, l, r);

    // Print the result
    cout << "Minimum sum of subarray: " << result << endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        long long result = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int T = target - nums[i];
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum_lr = nums[left] + nums[right];
                if (sum_lr < T) {
                    left++;
                } else if (sum_lr > T) {
                    right--;
                } else { 
                    if (nums[left] != nums[right]) {
                        int countLeft = 1;
                        while (left + 1 < right && nums[left] == nums[left + 1]) {
                            countLeft++;
                            left++;
                        }
                        int countRight = 1;
                        while (right - 1 > left && nums[right] == nums[right - 1]) {
                            countRight++;
                            right--;
                        }
                        result += (long long)countLeft * countRight;
                        result %= MOD;
                        left++;
                        right--;
                    } else {
                        int count = right - left + 1;
                        result += (long long)count * (count - 1) / 2;
                        result %= MOD;
                        break;
                    }
                }
            }
        }

        return (int)(result % MOD);
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1,1,2,2,3,3,4,4,5,5};
    int target = 8;
    
    int closestSum = solution.threeSumMulti(nums, target);
    cout << "The sum that is closest to the target " << target << " is: " << closestSum << endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        if (nums.size() < 3) return 0;
        
        int closest = nums[0] + nums[1] + nums[2]; ;
        long long sum = 0;
        int left = 0, right = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            left = i + 1;
            right = nums.size() - 1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if (abs(target- closest) > abs(target - sum))
                    closest = sum;
                
                if (sum == target)
                {
                    left++;
                    right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;

            }
        }
        return closest;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1,1,1,1};
    int target = -100;
    
    int closestSum = solution.threeSumClosest(nums, target);
    cout << "The sum that is closest to the target " << target << " is: " << closestSum << endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace  std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return ksum(nums, target, 4, 0);
    }

private:
    vector<vector<int>> ksum(vector<int>& nums, long long target, int k, int start){
        vector<vector<int>> res;
        if (k == 2)
        {
            int l = start;
            int r = nums.size() - 1;
            while (l<r)
            {
                long long sum = (long long)nums[l] + nums[r];
                if (sum == target)
                {
                    res.push_back({nums[l], nums[r]});
                    while(l < r && nums[r] == nums[r - 1]) r--;
                    while(l < r && nums[l] == nums[l + 1]) l++;

                    r--;
                    l++;
                }else if (sum < target){
                    l++;
                }else{
                    r--;
                }
            }
        }else{
            for (int i = start; i < nums.size(); i++)
            {
                if (i > start && nums[i] == nums[i-1])
                    continue;
                
                vector<vector<int>> subRes = ksum(nums,(long long) target - nums[i], k - 1 , i + 1);
                for (auto &&v : subRes)
                {
                    v.push_back(nums[i]);
                    res.push_back(v);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    int target = -294967296;
    
    vector<vector<int>> result = solution.fourSum(nums, target);
    cout << "The quadruplets that sum to the target " << target << " are: ";
    for (const auto& quad : result) {
        cout << "[";
        for (int num : quad) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}
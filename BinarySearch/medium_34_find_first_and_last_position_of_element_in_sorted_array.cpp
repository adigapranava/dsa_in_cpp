#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        while (l <= r)
        {
            m = (l+r)/2;
            if (nums[m] == target){
                int m_l = m, m_r = m;
                while (m_l >= 0 && nums[m_l] == target) m_l--;
                while (m_r < nums.size() && nums[m_r] == target) m_r++;
                return {m_l + 1, m_r - 1};
            }else if (nums[m]> target)
            {
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return {-1,-1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1} ;//{5,7,7,8,8,10};
    int target = 1;
    vector<int> result = sol.searchRange(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}

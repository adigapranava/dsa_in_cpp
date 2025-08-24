/*
Problem: Two Sum (Standard Version)
-----------------------------------
Given an array of integers nums and an integer target,
return the indices of the two numbers such that they add up to target.

You may assume that:
    - Each input would have exactly one solution.
    - You may not use the same element twice.
    - The order of indices does not matter.

Example:
--------
    Input: nums = [3, 2, 4], target = 6
    Output: [1, 2]   // nums[1] + nums[2] = 2 + 4 = 6

Approach (Two Pointers after Sorting):
    1. Store each number along with its original index.
    2. Sort the array by value.
    3. Use two pointers to find a pair whose sum equals the target.
    4. Return their original indices.

Time Complexity:
    - O(n log n) due to sorting.
    - O(n) for two-pointer scan.
Overall: O(n log n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left< right)
        {
            int sum = nums[left] + nums[right];
            if(sum == target){
                return {left, right};
            }
            if (sum < target){
                left++;
            }else{
                right++;
            }
        }
        return {};
    }

    vector<vector<int>> threeSum(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int sum = 0, left = 0, right = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == nums[i-1] && i > 0)
                continue;

            left = i + 1;
            right = nums.size() - 1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == target)
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;

            }
        }
        return result;
    }

    vector<int> twoSumHashmap(vector<int>& nums, int target) {
        // int i=0;
        vector<int> soln;
        unordered_map<int, int> hmap;

        for (int j = 0; j < nums.size(); j++)
        {
            int reqd = target - nums[j];
            if(hmap.find(reqd) != hmap.end()){
                return {hmap[reqd], j};
            }
            hmap[nums[j]] = j;
        }
        return soln;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSumHashmap(nums, target);

    if (!result.empty()) {
        cout << "Indices of the two numbers that add up to " << target << ": ";
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "No two numbers add up to " << target << endl;
    }

        vector<int> nums2 = {-1,0,1,2,-1,-4};
        int target2 = 0;
        vector<vector<int>> result2 = sol.threeSum(nums2, target2);
        cout << "Triplets that add up to " << target2 << ": " << endl
                << "[";
        for (const auto& triplet : result2) {
            cout << "[";
            for (int num : triplet) {
                cout << num << " ";
            }
            cout << "]";
        }
        cout << "]" << endl;

    return 0;
}

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
        int i=0;
        vector<int> soln;
        
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int i = 0; i < j; i++)
            {
                if(nums[i]+nums[j] == target){
                    soln.push_back(i);
                    soln.push_back(j);
                }
            }
            
        }
        return soln;
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

    return 0;
}

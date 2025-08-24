#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

    class Solution {
    public:
        int maxOperations(vector<int>& nums, int k) {
            int c = 0;
            unordered_map<int, int> map;

            for (int i = 0; i < nums.size(); i++)
            {
                if (map.find(k - nums[i]) == map.end() || map[k - nums[i]] == 0) {
                    map[nums[i]]++;
                }else{
                    c++;
                    map[k - nums[i]]--;
                }
            }
            return c;
        }

        int maxOperations2(vector<int>& nums, int k){
            sort(nums.begin(), nums.end());

            int l = 0, r = nums.size()-1, numOfOp = 0;
            while (l<r)
            {
                int sum = nums[l] + nums[r];
                if (sum == k)
                {
                    numOfOp++;
                    l++;
                    r--;
                }else if(sum < k){
                    l++;
                }else{
                    r--;
                }
            }
            return numOfOp;
        }
    };


int main() {
    Solution sol;
    vector<int> nums = {2,5,4,4,1,3,4,4,1,4,4,1,2,1,2,2,3,2,4,2}; // Example input
    int k = 3; // Target sum
    int result = sol.maxOperations2(nums, k);

    // Print the result
    cout << "Maximum number of operations: " << result << endl;

    return 0;
}
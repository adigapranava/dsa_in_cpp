#include<iostream>
#include<vector>
#include<unordered_map>
using namespace  std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longestSubArrayLen = 0;
        int l = 0;
        bool deletedOneElement = false;
        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] == 0)
            {
                if (deletedOneElement)
                {
                    while (nums[l] != 0)
                        l++;
                    l++;
                    // deletedOneElement = false;
                }else{
                    //mark this zero as deleted
                    deletedOneElement = true;
                }
            }
            int len =  r - l;
            longestSubArrayLen = max(longestSubArrayLen, len);
        }
        return longestSubArrayLen;
    }
};

int main (){
    Solution solution;
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
    
    int result = solution.longestSubarray(nums);
    cout << "The length of the longest subarray of 1s after deleting one element is: " << result << endl;
    return 0;
}
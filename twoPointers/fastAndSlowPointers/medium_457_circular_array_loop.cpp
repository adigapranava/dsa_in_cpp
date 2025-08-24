#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int move(int i, vector<int> nums){
        return (i + nums[i]) % nums.size();
    }

    bool circularArrayLoop(vector<int>& nums) {
        int slow=0, fast = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            slow = i;
            while (nums[i])
            {
                /* code */
            }
            
        }
    }
};
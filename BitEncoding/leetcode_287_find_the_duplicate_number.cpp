#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int b_c, n_c, duplicate=0, n = nums.size()-1;
        int bit = 1;
        for (int bit = 0; bit < 32; bit++)
        {
            int mask = 1 << bit;
            b_c = 0, n_c = 0;
            for (int i = 1; i < n+1; i++)
                if(i & mask)
                    b_c++;

            for (int i = 0; i < nums.size(); i++)
                if (nums[i] & mask)
                    n_c++;
            
            if (n_c > b_c)
                    duplicate |= mask;
        }
        return duplicate;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2}; // Example input
    int duplicate = sol.findDuplicate(nums);
    
    cout << "The duplicate number is: " << duplicate << endl;

    return 0;
}
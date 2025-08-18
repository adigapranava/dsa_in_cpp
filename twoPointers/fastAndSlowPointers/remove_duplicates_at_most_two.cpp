#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, size = nums.size(), min_ele = nums[0]-1, inc;
        while (j < size)
        {
            int count = 0;
            while(nums[i] == nums[j]){
                count++;
                j++;
            }
            i += min(2, count);
            while(i < j){
                nums[i] = min_ele;
                i++;
            }
        }

        int nonMinIndex =0;
        for (int i = 0; i < size; i++)
        {
            if(nums[i] != min_ele)
                nums[nonMinIndex++] = nums[i];
        }
        
        
        return nonMinIndex;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1};
    
    int newLength = sol.removeDuplicates(nums);
    
    // Print the modified array
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
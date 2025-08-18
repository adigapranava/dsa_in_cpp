/*
    1. Remove Duplicates from Sorted Array (Leetcode #26)
Remove duplicates in-place and return the length of the new array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int i = 0;

            for (int j = i + 1; j < nums.size(); j++){
                if(nums[i] != nums[j] && i <= j){
                    nums[++i] = nums[j];
                }
            }
            return i + 1;
        }

        void moveZeroes(vector<int>& nums) {
            int i = 0;
            for (int j = 0; j < nums.size(); j++){
                if (nums[j] != 0)
                {
                    swap(nums[i], nums[j]);
                    i += 1;
                }
            }
            
            
        }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};

    int newLength = sol.removeDuplicates(nums);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;

}
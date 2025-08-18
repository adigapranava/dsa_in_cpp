#include <vector>
#include <iostream>
using namespace std;

/**
 * Function: removeElement
 * -----------------------
 * Removes all occurrences of a given value `val` from the input array `nums`.
 * The removal is done in-place, and the relative order of elements can be changed.
 * After the operation, the first `k` elements of `nums` will contain the values not equal to `val`.
 * 
 * @param nums: A reference to a vector of integers
 * @param val: The integer value to remove from the array
 * @return The count of elements remaining in the array after removal (i.e., not equal to val)
 *
 * Example:
 * --------
 * Input: nums = [3, 2, 2, 3], val = 3
 * Output: 2
 * Modified nums: [2, 2, _, _]   // Underscores represent ignored values
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int i = -1;
            for (int j = 0; j < nums.size(); j++){
                if(nums[j] != val && i < j){
                    i += 1;
                    nums[i] = nums[j];
                }
            }
            return i + 1;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 20;

    int newLength = sol.removeElement(nums, val);

    // Output the results
    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
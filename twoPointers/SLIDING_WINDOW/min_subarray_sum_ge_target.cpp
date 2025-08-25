#include<iostream>
#include<vector>
using namespace std;

/*
    Problem: Minimum Size Subarray Sum ≥ Target

    Given an array of positive integers `nums` and an integer `target`, 
    find the minimal length of a contiguous subarray of which the sum is 
    greater than or equal to `target`. If no such subarray exists, return 0.

    Constraints:
    - All elements in nums are positive integers
    - Array is not necessarily sorted

    Input:
    - vector<int> nums: the input array
    - int target: the required minimum sum

    Output:
    - int: the length of the smallest contiguous subarray with sum ≥ target,
           or 0 if no such subarray exists

    Examples:

    Example 1:
    ----------
    Input:
        target = 7
        nums = [2, 3, 1, 2, 4, 3]

    Output:
        2

    Explanation:
        The subarray [4,3] has a sum of 7 and length 2.

 */

int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 3};
    int target = 7;

    int sum = 0;
    int min_size_arr = INT_MAX;
    int i = 0;

    for (int j = 0; j < arr.size(); j++) {
        sum += arr[j];
        while(sum >= target && i <= j){
          min_size_arr = min(min_size_arr, j - i + 1);
          sum -= arr[i++];
        }
    }
    cout << min_size_arr;
    
}
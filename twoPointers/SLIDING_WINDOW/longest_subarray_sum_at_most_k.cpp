#include<iostream>
#include<vector>
using namespace std;

/*
    Problem: Longest Subarray with Sum ≤ K

    Given an array of non-negative integers and an integer K,
    find the length of the longest contiguous subarray 
    whose sum is less than or equal to K.

    Constraints:
    - The array may be unsorted.
    - All elements are non-negative integers.
    - The solution must run in linear time (O(n)).

    Input:
    - A vector of integers `arr`
    - An integer `k`

    Output:
    - An integer representing the length of the longest valid subarray

    Example:

    Input:
        arr = {1, 2, 1, 0, 1, 1, 0}
        k = 3

    Output:
        5

    Explanation:
        The longest subarray with sum ≤ 4 is:
        {1, 0, 1, 1, 0}, which has a sum of 3 and length 5.
*/

int main() {
    vector<int> arr = {1, 2, 1, 0, 1, 1, 0};
    int target = 3;
    
    int i = 0;                  // Left pointer of the sliding window
    int max_sub_array = 0;      // Maximum length of valid subarray found so far
    int sum = 0;                // Current sum of the window

    for (int j = 0; j < arr.size(); j++)
    {
        sum += arr[j];          // Expand the window to the right by adding arr[j]

        // While the sum exceeds the target, shrink the window from the left
        while (sum > target && i <= j){
            sum -= arr[i];      // Subtract element at the left of the window
            i++;                // Move the left pointer to the right
        }
        max_sub_array = max(max_sub_array, j - i + 1);
    }
    
    cout<<max_sub_array;
}
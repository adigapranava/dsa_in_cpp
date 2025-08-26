#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Steps for O(m log n) [staircase search]
Start at top-right element (row = 0, col = n-1).
Compare with target:

If matrix[row][col] == target → return true.
If matrix[row][col] > target → move left (col--).
If matrix[row][col] < target → move down (row++).
Repeat until out of bounds → return false.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n -1;
        while (row < m && row >= 0 && col < n && col >= 0)
        {
            if (matrix[row][col] == target)
                return true;
            else if(matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 100;
    cout<<sol.searchMatrix(matrix, target);
    return 0;
}
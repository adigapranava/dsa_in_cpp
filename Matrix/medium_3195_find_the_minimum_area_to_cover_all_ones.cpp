#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int bottom = INT32_MAX, top = INT32_MIN, width, height;
        bool found =false;
        int left = INT32_MAX, right = INT32_MIN;
        //find width;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j])
                {
                    left = min(left, j);
                    right = max(right, j);
                    bottom = min(bottom, i);
                    top = max(top, i);
                    found = true;
                }
            }
        }
        width = right - left + 1;
        height = top - bottom + 1;

        return found ? width * height: 0;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0}
    };
    
    int area = solution.minimumArea(grid);
    cout << "Minimum area to cover all ones: " << area << endl;

    return 0;
}
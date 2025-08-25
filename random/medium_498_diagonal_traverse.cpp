#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int m = mat.size(), i = 0;
        int n = mat[0].size(), j = 0;
        bool direction = true;
        while(i != m-1 || j!= n-1)
        {
            res.push_back(mat[i][j]);

            if (direction)
            {
                //top right
                if (i == 0)
                {
                    if (j == n-1)
                    {
                        i++;
                    }else{
                        j++;
                    }
                    direction=!direction;
                    continue;
                }
                if (j == n-1)
                {
                    i++;
                    direction=!direction;
                    continue;
                }
                i--;
                j++;
            }else{
                //bottom left
                if (i == m-1)
                {
                    j++;
                    direction=!direction;
                    continue;
                }
                if (j == 0)
                {
                    i++;
                    direction = !direction;
                    continue;
                }
                i++;
                j--;
            }
            
        }
        res.push_back(mat[i][j]);
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1,2,3,4},{4,5,6,7},{7,8,9, 10}, {10,11,12,13}}; // Example input
    vector<int> result = sol.findDiagonalOrder(mat);
    
    cout << "Diagonal Traverse: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
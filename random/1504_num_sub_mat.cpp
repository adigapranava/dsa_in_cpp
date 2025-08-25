#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findSubmatsContinuity(vector<vector<int>>& mat){

    }
    
    int numSubmat(vector<vector<int>>& mat) {
        int count = 0;
        for (int column = 0; column < mat.size(); column++)
        {
            for (int row = 0; row < mat[column].size(); row++)
            {
                int num_matrix = 0;
                if (mat[column][row] == 1){
                    int max_continuity = mat[column].size() - row;
                    for (int i = 0; i < mat.size() - column; i++)
                    {
                        for (int j = 0; j < mat[column + i].size() - row; j++)
                        {
                            if (mat[column + i][row + j] != 1 || j > max_continuity)
                            {
                                max_continuity = j-1;
                                break;
                            }else{
                                num_matrix++;
                            }
                        }
                    }
                }
                count+=num_matrix;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{0,1,1,0},{0,1,1,1},{1,1,1,0}};
    int result = sol.numSubmat(mat);

    // Print the result
    cout << "Number of submatrices with all 1s: " << result << endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int isElementInArray(vector<int> arr, int target){
        if(target < arr[0]) return -1;
        if (target > arr[arr.size()-1]) return 1;
        return 0;
        
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int m_l = 0, m_r = m - 1, m_m;
        while (m_l <= m_r)
        {
            m_m = m_l + (m_r - m_l)/2;
            int present = isElementInArray(matrix[m_m], target);
            if (present == 0)
            {
                int n_l = 0, n_r = n - 1, n_m;
                while (n_l <= n_r)
                {
                    n_m = n_l + (n_r - n_l)/2;
                    if (matrix[m_m][n_m] == target)
                        return true;
                    else if(matrix[m_m][n_m] > target){
                        n_r = n_m - 1;
                    }else{
                        n_l = n_m + 1;
                    }
                }
                return false;
            }else if(present > 0){
                m_l = m_m + 1;
            }else{
                m_r = m_r - 1;
            }
        }
        return false;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 300;
    cout<<sol.searchMatrix(matrix, target);
    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double max_d = 0;
        vector<int> max_s;

        for (int i = 0; i < dimensions.size(); i++)
        {
            int length = dimensions[i][0];
            int width = dimensions[i][1];
            double diag = sqrt(length * length + width * width);
            if (diag == max_d)
                max_s.push_back(i);
            else if (diag > max_d){
                max_s.clear();
                max_s.push_back(i);
            }
            
            max_d = max(max_d, diag);
        }
        if (max_s.size() > 1)
        {
            int max_area = 0;
            for (int i = 0; i < max_s.size(); i++)
            {
                max_area = max(max_area, dimensions[max_s[i]][0] * dimensions[max_s[i]][1]);
            }
            return max_area;
        }else{
            return dimensions[max_s[0]][0] * dimensions[max_s[0]][1];
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> dimensions = {{2,6},{5,1},{3,10},{8,4}};
    cout<<sol.areaOfMaxDiagonal(dimensions);
    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res; 
        for (int i = 0; i < numRows; i++)
        {
            if (i==0)
            {
                res.push_back({1});
            }else if (i == 1)
            {
                res.push_back({1,1});
            }else{
                auto prev = res[i-1];
                vector<int> subRes;
                subRes.push_back(1);
                for (int i = 0; i < prev.size()-1; i++)
                {
                    subRes.push_back(prev[i] + prev[i+1]);
                }
                subRes.push_back(1);
                res.push_back(subRes);
            }
        }
        return res;
    }
};


int main(){
    Solution sol;
    int numRows = 5;
    vector<vector<int>> result = sol.generate(numRows);
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;   
}
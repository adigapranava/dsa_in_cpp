#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>  powers, reslts;
        const int MOD = 1e9 + 7;
        int pow = 1, bit = 1, n_copy = n;
        while(n_copy > 0){
            if(n_copy & 1)
                powers.push_back(bit);
            bit <<= 1;
            n_copy >>= 1;
        }

       for (auto &q : queries) {
            long long res = 1;
            for (int j = q[0]; j <= q[1]; j++) {
                res = (res * powers[j]) % MOD;
            }
            reslts.push_back((int)res);
        }
        return reslts;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> queries = {{0, 0}};
    int n = 2; // Example value for n
    vector<int> result = sol.productQueries(n, queries);

    // Print the results
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
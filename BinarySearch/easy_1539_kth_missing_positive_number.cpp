#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int p = 0;
        for (int i = 1; i <= arr[arr.size()-1]; i++)
        {
            if (i != arr[p])
            {
                k--;
                if (k==0)
                    return i;
            }else{
                p++;
            }
        }
        return arr[arr.size()-1] + k;
    }

    int findKthPositiveBS(vector<int>& arr, int k) {
        int l = 0, r = arr.size() - 1;

        // Binary search to find the first index where missing(i) >= k
        while (l <= r) {
            int m = (l + r) / 2;

            // Number of missing elements until arr[m]
            int missing = arr[m] - (m + 1);

            if (missing < k) {
                // Still haven't reached k missing numbers → move right
                l = m + 1;
            } else {
                // Already missing >= k → move left
                r = m - 1;
            }
        }

        // After binary search, l is the first index where missing >= k
        // Formula: k + l gives the answer
        return k + l;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 2, 3,4,7,11};
    int k = 2;
    cout<<sol.findKthPositiveBS(arr,k);
    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, m;
        while (l < r)
        {
            m = l + (r - l)/2;
            if (isBadVersion(m))
                r = m;
            else
                l = m + 1;
        }
        return r;
    }
};

bool isBadVersion(int version){
    if (version >= 4)
        return true;
    return false;
}

int main(){
    Solution sol;
    int n = 5;
    cout<<sol.firstBadVersion(n);
    return 0;
}
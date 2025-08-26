#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

 int  guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n, m;
        while (l <= r)
        {
            m = l + (r - l)/2;
            int gu = guess(m);
            if (gu == 0)
                return m;
            else if(gu < 0)
                r = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
};

int guess(int num){
    int pick = 6;
    if (num == pick)
        return 0;
    else if (num < pick)
        return 1;
    else
        return -1;
}

int main(){
    Solution sol;
    int n = 10;
    cout<<sol.guessNumber(n);
    return 0;
}
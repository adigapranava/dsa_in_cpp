#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1, m =0;
        char nextG = letters[0];
        while (l <= r)
        {
            m = (r + l) / 2;
            if (letters[m] > target)
            {
                nextG = letters[m];
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return nextG;        
    }
};

int main(){
    Solution sol;
    vector<char> letters = {'x','x','y','y'};
    char target = 'z';
    cout<<sol.nextGreatestLetter(letters, target);
    return 0;
}
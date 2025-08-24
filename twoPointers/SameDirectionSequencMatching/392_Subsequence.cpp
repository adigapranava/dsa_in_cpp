#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length())
            return false;
        if (s.length() == 0 &&t.length() == 0)
            return true;
        
        bool isSubScequence = false;
        int s_i = 0, t_i = 0;

        while(t_i < t.length()){
            if(s[s_i] == t[t_i])
                s_i++;
            if (s_i == s.length())
            {
                isSubScequence = true;
                break;
            }
            t_i++;
        }
        return isSubScequence;
    }
};

int main(){
    Solution sol;
    string s = "abc", t = "ahbgdc";
    bool res = sol.isSubsequence(s, t);
    cout << res << endl;
    return 0;
}
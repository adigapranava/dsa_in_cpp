#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r && !isalnum(s[l])){
            l++;
        }
        while(l < r && !isalnum(s[r])){
            r--;
        }
        if (l > r)
            return false;

        while (l < r)
        {
            char c_l = tolower(s[l]);
            char c_r = tolower(s[r]);

            if (c_l != c_r)
                return false;
            
            do{
                l++;
            }while(!isalnum(s[l]));
            do{
                r--;
            }while(!isalnum(s[r]));
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "0P";
    bool result = sol.isPalindrome(s);  
    cout << "Is palindrome: " << (result ? "true" : "false") << endl;
    return 0;
}
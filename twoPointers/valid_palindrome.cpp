#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            cout<<(int)s[i]<<" ";
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s = "az AZ 09";
    bool result = sol.isPalindrome(s);  
    cout << "Is palindrome: " << (result ? "true" : "false") << endl;
    return 0;
}
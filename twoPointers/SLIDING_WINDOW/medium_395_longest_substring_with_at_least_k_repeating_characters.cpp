#include<iostream>
#include<vector>
#include<unordered_map>
using namespace  std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int start = 0;
        for (int end = 0; end < s.size(); end++)
        {
            
        }
    }
};

int main() {
    Solution solution;
    string s = "aaabb";
    int k = 3;
    
    int result = solution.longestSubstring(s, k);
    cout << "The length of the longest substring where each character appears at least " << k << " times is: " << result << endl;
    return 0;
}
#include<vector>
#include <iostream>
#include <unordered_map>
using namespace std;
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int longest_substring = 0;
        unordered_map<char, int> charMap;

        for (int end = 0; end < s.size(); end++)
        {
            if(charMap.find(s[end]) != charMap.end() && charMap[s[end]] >= start){
                int index = charMap[s[end]];
                start = index+1;
            }
            charMap[s[end]] = end;
            longest_substring = max(longest_substring, end - start + 1);
        }

        return longest_substring;
    }
};

int main() {
    Solution sol;
    string s = "pwwkew"; // Example input
    int result = sol.lengthOfLongestSubstring(s);
    
    cout << "Length of Longest Substring Without Repeating Characters: " << result << endl; // Output the result

    return 0;
}
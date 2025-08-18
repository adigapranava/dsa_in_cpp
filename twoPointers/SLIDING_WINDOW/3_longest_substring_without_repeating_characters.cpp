#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, longest_substring = 0;
        unordered_map<char, int> charMap;;

        for (int end = 0; end < s.size(); end++)
        {
            if(charMap.find(s[end]) != charMap.end()){
                charMap[s[end]] = end;
            }else{
                int index = charMap[s[end]];
                longest_substring = max(longest_substring, end - start);
                start = index+1;
                charMap.erase(s[end]);
            }
        }

        return longest_substring;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb"; // Example input
    int result = sol.lengthOfLongestSubstring(s);
    
    cout << "Length of Longest Substring Without Repeating Characters: " << result << endl; // Output the result

    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // If needle is empty, return 0
        if (haystack.size() < needle.size()) return -1; // If haystack is smaller than needle, return -1
        for (int i = 0; i <= haystack.size()-needle.size(); i++)
        {
            bool found = true;
            for (int j = 0; j < needle.size(); j++)
            {
                if (haystack[i+j] != needle[j])
                {
                    found = false;
                    break;
                }
            }
            if(found) return i;
        }
        return -1;
    }
};


int main() {
    Solution sol;
    string haystack = "aaa";
    string needle = "aaaaa";
    int result = sol.strStr(haystack, needle);

    // Print the result
    cout << "First occurrence index: " << result << endl;

    return 0;
}
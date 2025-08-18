#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> map(26), temp(26);
        // for abc -> [1,1,1,0,0,0...] of 26 size
        for (int i = 0; i < p.size(); i++)
            map[p[i]-'a']++;
        
        // vector<int> temp(26);
        int start = 0;
        for (int end = 0; end < s.size(); end++)
        {
            int len = end - start + 1;
            temp[s[end]-'a']+=1;
            if (len == p.size())
            {
                if(map == temp){
                    res.push_back(start);
                }
                temp[s[start]-'a']-=1;
                start++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "caadbacbadba"; // Example input string
    string p = "bad"; // Example pattern string
    vector<int> result = sol.findAnagrams(s, p);
    sort(result.begin(), result.end());
    
    // Print the indices of anagrams found
    cout << "Anagram indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int get_max_freq(unordered_map<char, int> freq){
        auto max_it = max_element(
            freq.begin(), freq.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            }
        );
        return max_it != freq.end() ? max_it->second: 0; 
    }

    int characterReplacement(string s, int k) {
        int left = 0;
        unordered_map<char, int> freq;
        int longest = 0;
        int current_length = 0;
        int max_freq = 0;

        for (int right = 0; right < s.size(); right++)
        {
            freq[s[right]]+=1;
            max_freq =  max(max_freq,freq[s[right]]); //get_max_freq(freq);
            current_length = right - left + 1;
            if (current_length - max_freq > k)
            {
                freq[s[left]]-=1;
                left++;
                current_length--;
            }
            longest = max(longest, current_length);
        }

        return longest;
    }
};

int main() {
    Solution sol;
    string s = "AABABBA"; // Example input
    int k = 2; // Example number of replacements allowed
    int result = sol.characterReplacement(s, k);
    
    cout << "Length of Longest Substring with Replacements: " << result << endl; // Output the result

    return 0;
}
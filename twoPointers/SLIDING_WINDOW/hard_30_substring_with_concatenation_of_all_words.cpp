#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res = {};
        int word_len = words[0].size();
        int start = 0, curr_len = 0;
        int num_of_words = words.size();
        unordered_map<string, int> words_map = {};
        unordered_map<string, int> words_found = {};
        for (int i = 0; i < num_of_words; i++)
            words_map[words[i]] += 1;

        int curr_num_of_words = 0;
        for (int end = 0; end < s.size(); end++)
        {
            curr_len = end - start + 1;
            if (curr_len % word_len == 0)
            {
                string word = s.substr(end - word_len + 1, word_len);
                words_found[word] += 1;
                curr_num_of_words++;

                if (curr_num_of_words == num_of_words)
                {
                    if (words_found == words_map)
                        res.push_back(start);

                    string word_to_remove = s.substr(start, word_len);
                    words_found.erase(word_to_remove);
                    curr_num_of_words--;
                    start += word_len;
                }
            }
        }
        return res;
    }

int main() {
    string s = "lingmindraboofoowingdingbarrwingmonkeypoundcake"; // Example input string
    vector<string> words = {"fooo","barr","wing","ding","wing"}; // Example words to concatenate
    vector<int> result = findSubstring(s, words);
    
    // Print the starting indices of the substrings found
    cout << "Starting indices of substrings: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}



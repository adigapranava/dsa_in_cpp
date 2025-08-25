#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int val= 0, pos = 0;
        while(pos < s.size()){
            int value = map[s[pos]];
            if (pos < s.size()-1 && value < map[s[pos+1]])
            {
                val +=(map[s[pos+1]] - value);
                pos +=2;
            }else{
                val += value;
                pos+=1;
            }
        }
        return val;
    }
};


int main() {
    Solution sol;
    string s = "MCMXCIV"; // Example input
    int result = sol.romanToInt(s);
    
    cout << "Roman to Integer: " << result << endl; // Output the result

    return 0;   
}
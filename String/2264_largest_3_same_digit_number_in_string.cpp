#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string s = "9876543210";
        for (int i = 0; i < s.size(); i++)
        {
            int c =0;
            for (int j = 0; j < num.size(); j++)
            {
                if(num[j]==s[i]){
                    c++;
                }else{
                    c = 0;
                }
                if (c==3)
                {
                    return num.substr(j-2, 3);
                }
            }            
        }
        return "";
    }
};

int main() {
    Solution sol;
    string num = "2300019"; // Example input
    string result = sol.largestGoodInteger(num);
    
    cout << "The largest good integer is: " << result << endl;

    return 0;
}
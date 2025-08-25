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
    int value(char a){
        switch (a)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;        
        default:
            return 0;
        }
    }

    char rValue(int v){
        switch (v)
        {
        case 1:
            return 'I';
        case 5:
            return 'V';
        case 10:
            return 'X';
        case 50:
            return 'L';
        case 100:
            return 'C';
        case 500:
            return 'D';
        case 1000:
            return 'M';        
        default:
            return ' ';
        }
    }

    string intToRoman(int num) {
        vector<int> digits;
        vector<string> ans;
        int temp = num, tens=1;
        while (temp)
        {
            int digit = temp % 10;
            int val = digit * tens; 
            string s = "";
            if (digit == 1 || digit == 5){
                s+=rValue(val);
            }else if (digit == 4){
                s+=rValue(tens);
                s+=rValue(5*tens);
            }else if(digit == 9){
                s+=rValue(tens);
                s+=rValue(tens*10);
            }else{
                if (digit < 5)
                {
                    for (int i = 0; i < digit; i++)
                        s += rValue(tens);
                }else{
                    int k = 5* tens;
                    s += rValue(k);
                    for (int i = 5; i < digit; i++)
                        s += rValue(tens);
                }
            }
            temp/=10;
            tens*=10;
            ans.push_back(s);
        }
        string s ="";
        for (int i = ans.size() - 1; i >= 0; i--)
            s += ans[i];
        return s;
    }

        string intToRoman2(int num) {
            int arr[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            string romans[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
            string ans = "";
            while(num > 0) {
                for(int i = 0; i < 13; i++) {
                    if(num >= arr[i]) {
                        num -= arr[i];
                        ans += romans[i];
                        break;
                    }
                }
            }

            return ans;
        }
};

int main() {
    Solution sol;
    int num = 3749; // Example input
    string result = sol.intToRoman2(num);
    
    cout << "Integer to Roman: " << result << endl; // Output the result

    return 0;   
}
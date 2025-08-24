#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n < 10 && n != 1) return false;
        if (n == 1) return true;
        
        int temp = n;
        int new_num=0;
        while (temp)
        {
            int dig = temp % 10;
            new_num += dig*dig;
            temp/=10;
        }
        return isHappy(new_num);
    }
};

int main() {
    Solution solution;
    int n = 19; // Example input
    bool result = solution.isHappy(n);
    cout << (result ? "Happy number" : "Not a happy number") << endl;
    return 0;
}
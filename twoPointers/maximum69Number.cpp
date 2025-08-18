#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        vector<int> k;
        while(temp){
            int r = temp%10;
            k.push_back(r);
            temp /= 10;
        }
        temp = 0;
        bool c =false;
        for(int i=k.size()-1; i>=0; i--){
            if(k[i]==6 && c==false){
                temp += 9 *pow(10, i);
                c = true;
                continue; 
            }
            temp += k[i] * pow(10, i);
        }
        return temp;
    }
};

int main() {
    Solution sol;
    int num = 9669; // Example input
    int result = sol.maximum69Number(num);
    
    cout << "Maximum 69 Number: " << result << endl; // Output the result

    return 0;
}
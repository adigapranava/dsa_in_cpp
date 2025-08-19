#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left =0;
        unordered_map<int, int> basket;
        int max_fruits= 0;
        int fruit_type=0;

        for (int right = 0; right < fruits.size(); right++)
        {
            basket[fruits[right]]+=1;
            fruit_type = basket[fruits[right]] == 1 ? fruit_type+1: fruit_type;
            
            if (fruit_type > 2)
            {
                basket[fruits[left]]-=1;
                fruit_type = basket[fruits[left]] == 0 ? fruit_type-1: fruit_type;
                left++;
            }
            max_fruits = max(max_fruits, right-left+1);
        }
        return max_fruits;
    }
};


int main() {
    Solution sol;
    vector<int> fruits = {1,2,3,2,2}; // Example input
    int result = sol.totalFruit(fruits);
    
    cout << "Maximum number of fruits in two baskets: " << result << endl; // Output the result

    return 0;
}
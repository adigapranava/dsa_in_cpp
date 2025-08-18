#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //[0,1,2,3,4,5,6,7,8,9] array of all digits
    array<int, 10> getDigitsArr(long long n) {
        array<int, 10> freq{};
        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }
        return freq;
    }

    bool reorderedPowerOf2(int n) {
        auto target = getDigitsArr(n);
        long long num = 1;

        for (int i = 0; i < 64; i++) { 
            if (getDigitsArr(num) == target)
                return true;
            num <<= 1;  // multiply by 2 using shifitinng operator
        }
        return false;
    }
};

int main() {
    Solution sol;
    int n = 10; // Example input
    bool result = sol.reorderedPowerOf2(n);
    // cout << result << endl;
    if (result) {
        cout << n << " can be reordered to form a power of 2." << endl;
    } else {
        cout << n << " cannot be reordered to form a power of 2." << endl;
    }

    return 0;
}



// class Solution {
// public:
//     int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
//         int freeTime = eventTime;
//         for (int i = 0; i < startTime.size(); i++)
//             freeTime -= (endTime[i] - startTime[i]);
//         return freeTime;
//     }
// };
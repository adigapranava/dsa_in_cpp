#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    double log_base_3(int x) {
        return log(x) / log(3.0);
    }
    bool isInteger(double x) {
        return fmod(x, 1.0) == 0.0;
    }
    
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double a = log(n) / log(3.0);
        double eps = 1e-10; // small tolerance
        return abs(a - round(a)) < eps;
    }

    bool isPowerOfThree2(int n) {
        if (n == 1) return true;
        if (n <= 0 || n % 3 != 0) return false;
        return isPowerOfThree(n / 3);
    }

    bool isPowerOfThree3(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

int main() {
    Solution sol;
    int n = 243; // Example value for n
    bool result = sol.isPowerOfThree2(n);

    // Print the result
    cout << "Is " << n << " a power of three? " << (result ? "true" : "false") << endl;

    return 0;
}


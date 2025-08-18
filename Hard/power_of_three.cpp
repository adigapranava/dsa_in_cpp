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

};

int main() {
    Solution sol;
    int n = 243; // Example value for n
    bool result = sol.isPowerOfThree(n);

    // Print the result
    cout << "Is " << n << " a power of three? " << (result ? "true" : "false") << endl;

    return 0;
}


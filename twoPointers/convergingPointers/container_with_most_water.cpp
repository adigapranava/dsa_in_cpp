#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0, right = height.size()-1;
        while (left<right)
        {
            int area = min(height[left], height[right]) * (right-left);
            max_area = max(max_area, area);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return max_area;
    }
};

int main() {
    Solution sol;
    vector<int> height = {8, 7, 2, 1}; // Example heights
    int result = sol.maxArea(height);

    // Print the result
    cout << "Maximum area of water container: " << result << endl;

    return 0;
}
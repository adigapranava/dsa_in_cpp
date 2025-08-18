#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void rightShift(vector<int>& nums, int pos){
        if (nums.size() <= 1)
            return;
        
        for (int i = nums.size()-2; i >= pos ; i--)
            nums[i+1] = nums[i];
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_p = 0, nums2_p=0;
        if(n == 0) 
            return;
        while (nums1_p < m && nums2_p < n)
        {
            if(nums1[nums1_p] > nums2[nums2_p]){
                rightShift(nums1, nums1_p);
                nums1[nums1_p] = nums2[nums2_p++];
                m++;
            }
            nums1_p++;
        }
        while (nums2_p < n)
            nums1[nums1_p++] = nums2[nums2_p++];
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 0};
    vector<int> nums2 = {1};
    int m = 1; // Number of initialized elements in nums1
    int n = 1; // Number of elements in nums2
    sol.merge(nums1, m, nums2, n);

    // Print the merged array
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}   
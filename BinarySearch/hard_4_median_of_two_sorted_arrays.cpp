#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    double findMedian(vector<int> nums){
        int s = nums.size();
        if (s % 2 == 0 )
            return (nums[s / 2 - 1] + nums[s / 2]) / 2.0;
        else
            return nums[s/ 2];
    }

    void insert(vector<int>& nums, int ele){
        int l = 0, r = nums.size() - 1, m;
        while (l <= r)
        {
            m = (l+r)/2;
            if (nums[m] > ele)
            {
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        //r is the right pos
        nums.push_back(0);
        for (int i = nums.size()-1; i >= l && i > 0; i--)
            nums[i] = nums[i-1];
        nums[l] = ele;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums2.size(); i++)
            insert(nums1, nums2[i]);
        return findMedian(nums1);
    }   
};

int main() {
    Solution sol;
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    cout<<sol.findMedianSortedArrays(nums1,nums2);
    return 0;
}
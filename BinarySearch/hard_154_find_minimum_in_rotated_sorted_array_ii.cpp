#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Initialize low = 0, high = n-1.
While low < high:
Find mid = (low + high) // 2.
Compare nums[mid] with nums[high]:
If nums[mid] < nums[high] → min is in left half (including mid) → set high = mid.
If nums[mid] > nums[high] → min is in right half → set low = mid + 1.
If nums[mid] == nums[high] → can’t decide → shrink search space safely → high -= 1.
At the end, low == high → return nums[low].
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, m;

        while (l < r)
        {
            m = l + (r-l)/2;
            if (nums[m] < nums[r])
            {
                r = m;
            }else if (nums[m] > nums[r]){
                l = m + 1;
            }else{
                r--;
            }
        }
        
        return nums[l];
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,2,2,0,1};
    cout<<sol.findMin(nums);
    return 0;
}
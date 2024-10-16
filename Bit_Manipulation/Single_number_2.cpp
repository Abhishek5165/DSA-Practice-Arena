// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int ans = 0;
    int count = 0;
    for(int i=0;i<nums.size();i++){
    ans = (ans^nums[i]) & (~count);
    count = (count^nums[i]) & (~ans);
    }
    return ans;
    }
};
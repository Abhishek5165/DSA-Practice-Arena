// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int maxxi = *max_element(nums.begin(),nums.end());
    int longest = 0,currentLen = 0;
    
    for(int i=0;i<n;i++){
    if(maxxi == nums[i]){
    currentLen++;
    longest = max(longest,currentLen);
    }
    else{
    currentLen = 0;
    }
    }
    return longest;
    }
};
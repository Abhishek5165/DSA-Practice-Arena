// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int maxxi = INT_MIN;
    int n = nums.size();
    for(int i=0;i<n;i++){
    if(nums[i] == 1){
    count++;
    maxxi = max(maxxi,count);
    }
    else{
    count = 0;
    }
    }  
    if(maxxi == INT_MIN){
    maxxi = 0;
    }  
    return maxxi;
    }
};
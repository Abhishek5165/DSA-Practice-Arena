// Time complexity : O(n) + O(n);
// Space complexity : O(1);

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
    double maxxi = INT_MIN;
    double prefix = 1;
    double sufix = 1;
    int n = nums.size();

    for(int i=0;i<n;i++){
    
    prefix *= nums[i];
    sufix *= nums[n-i-1];
    maxxi = max({maxxi,sufix,prefix});
    if(prefix == 0){
    prefix = 1;
    }
    if(sufix == 0){
    sufix = 1;
    }
    }
    return maxxi;
    }
};
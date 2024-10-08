// time Complexity : O(nlogn)
// space Complexity : O(1)

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

    sort(nums.begin(),nums.end());
    int n = nums.size();
    int count = 0;

    for(int i=1;i<n;i++){

    if(nums[i] <= nums[i-1]){
    int num = nums[i-1] - nums[i] + 1;
    nums[i] += num;
    count += num;
    }
    }  
    return count;
    }
};
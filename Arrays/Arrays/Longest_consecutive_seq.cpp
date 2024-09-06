// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
public:
    int n;
    bool linearS(vector<int>&nums,int num){
    
    for(int i=0;i<n;i++){
    if(nums[i] == num){
    return true;
    break;
    }
    }
    return false;
    }
    int longestConsecutive(vector<int>& nums) {
    int longest = 0;
    n = nums.size();
    for(int i=0;i<n;i++){
    int count = 1;
    int x = nums[i];
    while(linearS(nums,x+1) == true){
    x += 1;
    count++;
    }
    longest = max(longest,count);
    }
    return longest;
    }
};
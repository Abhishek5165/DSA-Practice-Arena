// Time Complexity : O(N);
// Space Comlexity : O(1);

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    next_permutation(nums.begin(),nums.end()); 
    }
};
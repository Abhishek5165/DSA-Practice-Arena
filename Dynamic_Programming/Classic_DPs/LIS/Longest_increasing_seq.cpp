// Time Complexity : (n*n);
// Space Complexity : (1);

// Approch - 1 Recurrsion + Memoization.
 
class Solution {
public:
    int dp[2501][2501];

    int solve(vector<int>& nums, int i, int prev) {

        int n = nums.size();

        if (i >= n) {
            return 0;
        }
        if (prev != -1 && dp[i][prev] != -1) {
            return dp[i][prev];
        }
        int take = 0;
        if (prev == -1 || nums[prev] < nums[i]) {
            take = 1 + solve(nums, i + 1, i);
        }
        int skip = solve(nums, i + 1, prev);
        if (prev != -1) {
            dp[i][prev] = max(take, skip);
        }
        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        int index = 0;
        int prev = -1;

        memset(dp, -1, sizeof(dp));

        int ans = solve(nums, index, prev);
        return ans;
    }
};
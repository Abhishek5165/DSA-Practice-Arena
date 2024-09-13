// Time Complexity : O(N*N);
// Space Complexity : O(1);

// Brute Force ....

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = i + 1; j < n; j++) {
                long long ans = 2 * nums[j];
                if (num > ans) {
                    count++;
                }
            }
        }
        return count;
    }
};
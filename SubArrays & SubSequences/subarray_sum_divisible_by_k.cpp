// Approch - 1 (Brute force) TLE

// Time complexity : O(n^2);
// Space complexity : O(1);

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int sum = nums[i];
            if (sum % k == 0) {
                count++;
            }

            for (int j = i + 1; j < n; j++) {
                sum += nums[j];
                if (sum % k == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};


// Approch - 2

// Time complexity : O(n);
// Space complexity : O(n);
 

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> mpp;
        int result = 0;
        int sum = 0;
        mpp.insert({0, 1});

        for (int i = 0; i < n; i++) {

            sum += nums[i];
            int remain = sum % k;

            if (remain < 0) {
                remain += k;
            }
            if (mpp.find(remain) != mpp.end()) {
                result += mpp[remain];
            }
            mpp[remain]++;
        }
        return result;
    }
};
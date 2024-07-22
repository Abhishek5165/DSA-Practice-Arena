// Approch - 1 (Brute force) TLE

// Time complexity : O(n^2);
// Space complexity : O(1);

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {

            int sum = nums[i];
            if (sum == k) {
                count++;
            }
            for (int j = i + 1; j < n; j++) {
                sum += nums[j];

                if (sum == k) {
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
    int subarraySum(vector<int>& nums, int k) {

    int result = 0;
    int sum = 0;
    unordered_map<int,int>mpp;
    mpp.insert({0,1});

    for(auto &it:nums){
    sum += it;
    
    if(mpp.find(sum-k) != mpp.end()){
    result += mpp[sum-k];
    }
    mpp[sum]++;
    } 
    return result;
    }
};
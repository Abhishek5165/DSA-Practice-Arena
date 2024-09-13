// Time Complexity : O(N*N);
// Space Complexity : O(1);

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};


// Optimize Approch :

// Time Complexity: O(N) or O(N*logN)
// Space Complexity : O(N)


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    unordered_map<int,int>mpp;
    mpp[0] = 1;

    int PrefixSum = 0;
    for(int i=0;i<n;i++){

    PrefixSum += nums[i];
    int rest = PrefixSum - k;
    count += mpp[rest];

    mpp[PrefixSum] += 1;
    }  
    return count;
    }
};
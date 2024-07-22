// Time Complexity : O(n);
// Space Complexity : O(n);

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

    unordered_map<int,int>mpp;
    mpp[0] = -1;
    int sum = 0;

    for(int i=0;i<nums.size();i++){
    sum += nums[i];
    int remain = sum%k;

    if(mpp.find(remain) != mpp.end()){
    int size = i-(mpp[remain]);
    if(size >= 2){
    return true;
    break;
    }
    }
    mpp.insert({remain,i});
    }
    return false;
    }
};
// Time Complexity : O(NLogN);
// Space Complexity : O(1);

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int count = 1, maxCount = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                // Skip duplicates
                continue;
            } 
            else if (nums[i] == nums[i-1] + 1) {
                // If consecutive, increase count
                count++;
            } else {
                // If not consecutive, reset count to 1
                maxCount = max(maxCount, count);
                count = 1;
            }
        }
        // Final check to update maxCount
        maxCount = max(maxCount, count);
        
        return maxCount;
    }
};



// Time Complexity :  O(N*N);
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

// Optimize approch --

// Time Complexity: O(N) + O(2*N);
// Space Complexity : O(N);


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int>st;
    int maxxi = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
    st.insert(nums[i]);
    }
    for(auto &it:st){
    if(st.find(it-1) == st.end()){
    int count = 1;
    int x = it;
    while(st.find(x+1) != st.end()){
    x += 1;
    count++;
    }
    maxxi = max(maxxi,count);
    }
    }
    return maxxi;
    }
};
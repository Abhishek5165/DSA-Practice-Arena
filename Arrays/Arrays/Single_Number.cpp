// Using map ....

// Time Complexity : O(N*logM) + O(M);  M = size of the map i.e. M = (N/2)+1
// Space Complexity : O(M);

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    unordered_map<int,int>mpp;
    int n = nums.size();
    for(int i=0;i<n;i++){
    mpp[nums[i]]++;
    } 
    for(auto &it : mpp){
    if(it.second == 1){
    return it.first;
    break;
    }
    }
    return -1;
    }
};


// Time Complexity : O(N);
// Space Complexity : O(1);


class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int XOR = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
    XOR = XOR ^ nums[i];
    } 
    return XOR;  
    }
};
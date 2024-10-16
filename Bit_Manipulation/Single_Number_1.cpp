// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int XOR = 0;
    for(auto it : nums){
    XOR = XOR ^ it;
    }   
    return XOR;
    }
};
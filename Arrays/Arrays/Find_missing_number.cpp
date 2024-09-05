// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int num = n*(n+1)/2;
    int sum = 0;
    for(int i=0;i<n;i++){
    sum += nums[i];
    }   
    return (num-sum);
    }
};

// Using XOR properties ......
// Time Complexity : O(N);
// Space Complexity : O(1);


class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int XOR1 = 0,XOR2 = 0;
    int n = nums.size();   
    for(int i=0;i<n;i++){
    XOR2 = XOR2 ^ nums[i];
    XOR1 = XOR1 ^ i+1;
    }
    return XOR1^XOR2;
    }
};
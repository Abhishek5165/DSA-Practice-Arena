// Giving TLE 
// recursion .....

class Solution {
public:
    int climbStairs(int n) {
        
    if(n<0){
    return 0;
    }
    if(n == 0){
    return 1;
    }
    return climbStairs(n-1) + climbStairs(n-2);
    }
};

// Using top Down ....
// Time Complexity O(2^N);
// Space Complexity O(N);

vector<int>dp(46,-1); 

class Solution {
public: 
    int climbStairs(int n) {
    if(n < 0){
    return 0;
    }
    if(dp[n] != -1){
    return dp[n];
    }
    if(n == 0){
    return 1;
    }
    return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};

// using bottom up...
// Time Complexity O(N);
// Space Complexity O(N);





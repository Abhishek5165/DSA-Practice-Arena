// Giving TLE 
// Using top Down ....
// Time Complexity O(2^N);
// Space Complexity O(N);

class Solution {
public: 
    int fib(int n) {

    vector<int>dp(n+1,-1);

    if(n<=1){
    return n;
    }
    if(dp[n] != -1){
    return dp[n];
    }
    return dp[n] = fib(n-1) + fib(n-2);
    }
};

// using bottom up...
// Time Complexity O(N);
// Space Complexity O(N);

vector<int>dp(31,-1);

class Solution {
public:

    int fib(int n) {
    
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
    dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
    }
};

// Using Space optimization .....
// Time Complexity : O(n);
// Space Complexity : O(1);

class Solution {
public:
    int fib(int n) {
    if(n <=1){
    return n;
    }
    int a = 0;
    int b = 1;
    for(int i=2;i<=n;i++){
    int c = a+b;
    a = b;
    b = c;
    }
    return b;
    }
};
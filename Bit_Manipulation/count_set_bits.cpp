// Time Complexity: O(n log n)
// Space Complexity: O(1)

// Giving TLE ...

class Solution{
    public:
    
    int C(int n){
    int count = 0;
    while(n != 1){
    if(n&1){
    count++;
    }
    n = n>>1;
    }
    if(n==1){
    count++;
    }
    return count;
    }
    
    int countSetBits(int n){
    int count = 0;
    for(int i=1;i<=n;i++){
    count += C(i);
    }
    return count;
    }
};




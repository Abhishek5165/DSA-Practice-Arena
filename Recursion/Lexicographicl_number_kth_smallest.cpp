// Time Complexity : O(logn)^2;
// Space Complexity : O(logn);


class Solution {
public:
    int solve(long curr,long next,int limit){
    int count = 0;
    while(curr <= limit){

    count += (next - curr);

    curr *= 10;
    next *= 10;

    next = min(next,long(limit+1));
    }
    return count;
    }

    int findKthNumber(int n, int k) {

    long long curr = 1;
    k -= 1;

    while(k > 0){
    int count = solve(curr,curr+1,n);
    if(count <= k){
    curr++;
    k -= count;
    }
    else{
    curr *= 10;
    k -= 1;
    }
    }
    return curr;
    }
};
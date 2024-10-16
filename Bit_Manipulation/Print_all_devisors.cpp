// Time Complexity : O(logn * sqrt(N));
// Space Complexity : O(1);

class Solution {
  public:
    void print_divisors(int n) {
    vector<int>ans;
    for(int i=1;i*i<=n;i++){
     if(n%i == 0){
        ans.push_back(i);
     if(n/i != i){
       ans.push_back(n/i);
     }
     }
    }
    sort(ans.begin(),ans.end());
    for(auto it : ans){
     cout<<it<<" ";
    }
    }
};
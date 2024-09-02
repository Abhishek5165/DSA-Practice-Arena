// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        
    int n = arr.size();
    int SS = INT_MAX;
    int S = INT_MAX;
    
    for(int i=0;i<n;i++){
    if(arr[i] < S){
    SS = S;
    S  = arr[i];
    }
    else if(arr[i] < SS && arr[i] != S){
    SS = arr[i];
    }
    }
    if(SS==INT_MAX)
    return {-1};
    else 
    return {S,SS};
    }
};
// Time Complexity : O(N);  By using 2 passes..
// Space Complexity : O(1);

class Solution {
  public:
    int print2largest(vector<int> &arr) {
    int SL = -1;
    int L = arr[0];
    int n = arr.size();
    
    for(int i=0;i<n;i++){
    if(arr[i] > L){
    L = arr[i];
    }
    }
    for(int i=0;i<n;i++){
    if(arr[i] > SL && arr[i] != L){
    SL = arr[i];
    }
    }
    return SL;
    }
};


// Time Complexity : O(N);  By using single pass..
// Space Complexity : O(1);


class Solution {
  public:
    int print2largest(vector<int> &arr) {
    int SL = -1;
    int L = arr[0];
    int n = arr.size();
    
    for(int i=0;i<n;i++){
    if(arr[i] > L){
    SL = L;
    L = arr[i];
    }
    else if(arr[i] > SL && arr[i] != L){
    SL = arr[i];
    }
    }
    return SL;
    }
};

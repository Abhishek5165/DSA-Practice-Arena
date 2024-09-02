// Brute Force ....

// Time Complexity : O(N*LogN);
// Space Complexity : O(1);

class Solution {
  public:
    int largest(vector<int> &arr) {
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
    }
};


// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
  public:
    int largest(vector<int> &arr) {
    int L = arr[0];
    int n = arr.size();
    
    for(int i=0;i<n;i++){
    if(arr[i] > L){
    L = arr[i];
    }
    }
    return L;
    }
};
// Brute Force ...

// Time Complexity : O(N*N);
// Space Complexity : O(1);

class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
    int n = arr.size();
    for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
    if(arr[i] > arr[j]){
    return false;
    break;
    }
    }
    }
    return true;
    }
};

// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
    int n = arr.size();
    for(int i=1;i<n;i++){
    if(arr[i] < arr[i-1]){
    return false;
    break;
    }
    }
    return true;
    }
};

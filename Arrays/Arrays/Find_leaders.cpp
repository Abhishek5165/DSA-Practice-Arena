// TIme Complexity : O(N);
// Space Complexity : O(1);

class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
    int maxxi = 0;
    vector<int>ans;
    
    for(int i=0;i<n;i++){
        
    int element = arr[i];
    maxxi = 0;
    
    for(int j=i+1;j<n;j++){
    maxxi = max(arr[j],maxxi);
    }
    if(element >= maxxi){
    ans.push_back(element);
    }
    }
    return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity : O(1);

vector<int> superiorElements(vector<int>&a) {
  int n = a.size();
  vector<int>ans;

  int maxxi = a[n-1];
  ans.push_back(maxxi);
  
  for(int i=n-2;i>=0;i--){
  if(a[i] > maxxi){
  ans.push_back(a[i]);
  maxxi = a[i];
  }
  }
  return ans;
}
class Solution {
  public:
  
    vector<int>ans;
    
    int Added(vector<int>&temp){
    int sum = 0;
    
    for(int i=0;i<temp.size();i++){
    sum += temp[i];
    }
    return sum;
    }
    
    void solve(vector<int>&temp,vector<int>&arr, int n,int index){
        
    if(index >= n){
    
    int sum = Added(temp);
    ans.push_back(sum);
    return;
    }
    
    temp.push_back(arr[index]);
    solve(temp,arr,n,index+1);
    
    temp.pop_back();
    solve(temp,arr,n,index+1);
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
    
    vector<int>temp;
    solve(temp,arr,n,0);
    return ans;
    }
};
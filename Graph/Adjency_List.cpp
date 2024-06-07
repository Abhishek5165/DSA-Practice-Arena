class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        
    vector<vector<int>>ans(V);
    
    for(auto it:edges){
        
    int u = it.first;
    int v = it.second;
    
    ans[u].push_back(v);
    ans[v].push_back(u);
    }
    return ans;
    }
};
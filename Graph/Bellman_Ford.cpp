// This is applicable for Directed & Undirected Graph with negative weights,
// In case of Undirected (here one condition for making to directed graph weights should be positive).

// Time Complexity : O(V*E);
// Space Complexity : O(E+V);

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S){
    vector<int>result(V,1e8);
    
    result[S] = 0;
    
    for(int i=1;i<=V-1;i++){
    
    for(auto &vec : edges){
    
    int u = vec[0];
    int v = vec[1];
    int wt = vec[2];
    
    if(result[u] != 1e8 && result[u] + wt < result[v]){
    result[v] = result[u] + wt;
    }
    }
    }
    for(auto &vec : edges){
    
    int u = vec[0];
    int v = vec[1];
    int wt = vec[2];
    
    if(result[u] != 1e8 && result[u] + wt < result[v]){
    return {-1};
    }
    }
    return result;
    } 
};

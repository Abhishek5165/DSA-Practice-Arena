// Time complexity : O(V+E);
// Space complexity : O(V);

class Solution {
  public:
    
    bool isCycle(vector<int> adj[],int u, vector<bool>&visited,int parent){
        
    visited[u] = true;
    for(auto &it:adj[u]){
    if(it == parent){
    continue;
    }
    if(visited[it]){
    return true;
    }
    if(isCycle(adj,it,visited,u)){
    return true;
    }
    }
    return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
    vector<bool>visited(V,false);
    
    for(int i=0;i<V;i++){
        
    if(!visited[i] && isCycle(adj,i,visited,-1)){
    return true;
    }
    }
    return false;
    }
};
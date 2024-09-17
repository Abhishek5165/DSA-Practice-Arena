// Time complexity : O(V+E);
// Space complexity : O(V);

class Solution {
  public:
    bool solve(int start,vector<int> adj[],vector<int>&visited,
    vector<int>&pathvisited){
        
    visited[start] = 1;
    pathvisited[start] = 1;
    
    for(auto &it:adj[start]){
    if(!visited[it]){
    if(solve(it,adj,visited,pathvisited) == true){
    return true;
    }
    }
    else if(pathvisited[it]){
    return true;
    }
    }
    pathvisited[start] = 0;
    return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
    vector<int>visited(V,0);
    vector<int>pathvisited(V,0);
    
    for(int i=0;i<V;i++){
    if(!visited[i]){
    if(solve(i,adj,visited,pathvisited) == true){
    return true;
    }
    }
    }
    return false;
    }
};
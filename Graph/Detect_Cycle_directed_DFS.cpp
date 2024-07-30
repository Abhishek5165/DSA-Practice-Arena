// Time complexity : O(V+E);
// Space complexity : O(V);

class Solution {
  public:
    
    bool Cycle(int start,vector<int> adj[],vector<bool>&visited,vector<bool>&inrecurr){
    
    visited[start] = true;
    inrecurr[start] = true;
    
    for(auto &it : adj[start]){
        
    if(visited[it] == false && Cycle(it,adj,visited,inrecurr)){
    return true;
    }
    else if(visited[it] == true && inrecurr[it] == true){
    return true;
    }
    }
    inrecurr[start] = false;
    return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
    vector<bool>visited(V,false);
    vector<bool>inrecurr(V,false);

    for(int i=0;i<V;i++){
        
    if(!visited[i] && Cycle(i,adj,visited,inrecurr)){
    return true;
    }
    }
    return false;
    }
};
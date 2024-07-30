// Time complexity : O(V+E);
// Space complexity : O(V);

class Solution {
  private:
  
  bool detect(int start,vector<int>&visited,vector<int> adj[]) {
      
    queue<pair<int,int>>Q;
    Q.push({start,-1});
    
    visited[start] = 1;
    
    while(!Q.empty()){
        
    int node = Q.front().first;
    int parent = Q.front().second;
    
    Q.pop();
    
    for(auto it:adj[node]){
        
    if(!visited[it]){
    
    Q.push({it,node});
    visited[it] = 1;
    }
    else if(parent != it){
    return true;
    }
    }
    }
    return false;
  }
  
  public:
    bool isCycle(int V, vector<int> adj[]) {
      
    vector<int>visited(V,0);
    int start = 0;
    
    for(int i=0;i<V;i++){
        
    if(!visited[i] && detect(i,visited,adj)){
        
    return true;
    }
    }
    return false;
    }
};
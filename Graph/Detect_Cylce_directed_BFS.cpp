// Time complexity : O(V+E);
// Space complexity : O(V);

// using topological sort - kahn's algorithms ..... DAG only 

class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
    
    vector<int>indegree(V,0);
    
    for(int i=0;i<V;i++){
    for(auto &v : adj[i]){
    indegree[v]++;
    }
    }
    vector<int>ans;
    queue<int>Q;
    
    for(int i=0;i<V;i++){
    
    if(indegree[i] == 0){
    Q.push(i);
    }
    }
    int count = 0;
    while(!Q.empty()){
    
    int node = Q.front();
    count++;
    Q.pop();
    
    for(auto &v : adj[node]){
    indegree[v]--;
    if(indegree[v] == 0){
    Q.push(v);
    }
    }
    }
    
    if(count == V){
    return false;
    }
    return true;
    }
};

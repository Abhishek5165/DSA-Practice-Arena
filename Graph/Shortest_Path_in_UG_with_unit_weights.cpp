// Expected Time Complexity: O(N + E)
// Expected Space Complexity: O(N)

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, 
    int N,int M, int src){
        
    vector<int>adj[N];
    int distance[N];
    
    for(int i=0;i<N;i++){
    distance[i] = 1e9;
    }
    
    for(auto it : edges){
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
    }
    queue<int>Q;
    Q.push(src);
    distance[src] = 0;
    
    while(!Q.empty()){
    int node = Q.front();
    Q.pop();
    
    for(auto it : adj[node]){
    
    if(1 + distance[node] < distance[it]){
    distance[it] = 1 + distance[node];
    Q.push(it);
    }
    }
    }
    vector<int>ans(N,-1);
    for(int i=0;i<N;i++){
    if(distance[i] != 1e9){
    ans[i] = distance[i];
    }
    }
    return ans;
    }
};

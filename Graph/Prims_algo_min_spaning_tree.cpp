// Time Complexity : O(E * 2(logV));
// Space Complexity : O(V);

class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
    vector<bool>visited(V,false);
    int sum = 0;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,
    greater<pair<int,int>>>pq;
    
    pq.push({0,0});
    
    while(!pq.empty()){
        
    auto & vec = pq.top();
    int node = vec.second;
    int wt = vec.first;
    pq.pop();
    
    if(visited[node] == true){
    continue;
    }
    visited[node] = true;
    sum += wt;
    
    for(auto &it : adj[node]){
    
    int temp_node = it[0];
    int temp_wt = it[1];
    
    if(visited[temp_node] == false){
    pq.push({temp_wt,temp_node});
    }
    }
    }
    return sum;
    }
};

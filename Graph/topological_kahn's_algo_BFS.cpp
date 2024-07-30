// Time complexity : O(V+E);
// Space complexity : O(V);

class Solution
{
	public:
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	vector<int>ans;
	vector<int>indegree(V,0);
	
	for(int u=0;u<V;u++){
	for(auto &v:adj[u]){
	indegree[v]++;
	}
	}
	
	queue<int>Q;
	
	for(int i=0;i<V;i++){
	if(indegree[i] == 0){
	 Q.push(i);
	}
	}
	
	while(!Q.empty()){
	
	int node = Q.front();
	ans.push_back(node);
	Q.pop();
	
	for(auto &v:adj[node]){
	  
	indegree[v]--; 
	
	if(indegree[v]==0){
    Q.push(v);
	}
	}
	}
	return ans;
	}
};
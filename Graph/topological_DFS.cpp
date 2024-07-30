// Time complexity : O(V+E);
// Space complexity : O(V);

class Solution
{
	public:
	void solve(int start,vector<int>adj[],stack<int>&st,vector<bool>&visited){
	    
	visited[start] = true;
	
	for(auto &v : adj[start]){
	if(!visited[v]){
	solve(v,adj,st,visited);
	}
	}
	st.push(start);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	 vector<int>ans;
	 stack<int>st;
	 
	 vector<bool>visited(V,false);
	 
	 for(int i=0;i<V;i++){
	 if(!visited[i]){
	   solve(i,adj,st,visited);
	 }
	 }
	 while(!st.empty()){
	 ans.push_back(st.top());
	 st.pop();
	}
	 return ans;
	}
};
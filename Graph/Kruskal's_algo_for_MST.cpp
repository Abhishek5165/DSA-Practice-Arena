// Time Complexity : O(E*logV) OR O(E* logE) + O(E* log V);
// here logV & logE both are same. because maximum posible vertexes are V*V
// Space Complexity : O(V+E);

// This is only for undirected Graph ........

class Solution{
	public:
	vector<int>parent;
	vector<int>size;
	
	int find(int node){
	 if(node == parent[node]){
	   return node;
	 }
	 return parent[node] = find(parent[node]);
	}
	
	void solve(int u,int v){
	  
	int u_parent = find(u);
	int v_parent = find(v);
	
	if(size[u_parent] > size[v_parent]){
	  parent[v_parent] = u_parent;
	  size[u_parent] += size[v_parent];
	}
	else if(size[u_parent] < size[v_parent]){
	  parent[u_parent] = v_parent;
	  size[v_parent] += size[u_parent];
	}
	else{
	parent[v_parent] = u_parent;
	size[u_parent] += size[v_parent];
	}
	}
	
	int kruskal(vector<vector<int>>&vec){
	    
	int sum = 0;
	
	for(auto & it : vec){
	
	int u  = it[0];
	int v  = it[1];
	int wt = it[2];
	
	int u_parent = find(u);
	int v_parent = find(v);
	
	if(u_parent != v_parent){
	 solve(u,v);
	 sum += wt;
	}
	}
	return sum;
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
    vector<vector<int>>vec;
    
    parent.resize(V);
    size.resize(V,1);
    
    for(int i=0;i<V;i++){
    parent[i] = i;
    }
    
    for(int u=0;u<V;u++){
    for(auto &temp : adj[u]){
    int v  = temp[0];
    int wt = temp[1];
    
    vec.push_back({u,v,wt});
    }
    }
    auto comparator = [&](vector<int>&vec1 , vector<int>&vec2){
    return vec1[2] < vec2[2];
    };
    sort(begin(vec),end(vec),comparator);
    return kruskal(vec);
    }
};
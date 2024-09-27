// Time complexity : O(V*(logV + E*(logV));
// Sace complexity : O(V+E);

// Approch - 1 Using Priority Queue .....

class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
    priority_queue<pair<int,int>,vector<pair<int,int>>,
    greater<pair<int,int>>>pq; // Min Heap
    
    vector<int>result(V,INT_MAX);
    result[S] = 0;
    
    pq.push({0,S});
    
    while(!pq.empty()){
    
    int d = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    
    for(auto &vec : adj[node]){
        
    int adjNode = vec[0];
    int wt = vec[1];
    
    if(d + wt < result[adjNode]){
     result[adjNode] = d + wt;
     pq.push({d+wt,adjNode});
    }
    }
    }
    return result;
    }
};

// Approch - 2 Using Set slightly improved ........

class Solution{
    
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
    set<pair<int,int>>st;
    
    vector<int>result(V,INT_MAX);
    result[S] = 0;
    st.insert({0,S});
    
    while(!st.empty()){
    
    auto &it = *st.begin();
    int dist = it.first;
    int node = it.second;
    st.erase(it);
    
    
    for(auto &vec : adj[node]){
    int newNode = vec[0];
    int wt = vec[1];
    
    if(dist + wt < result[newNode]){
    
    if(result[newNode] != INT_MAX){
    st.erase({result[newNode],newNode});
    }
    
    result[newNode] = dist + wt;
    st.insert({dist+wt,newNode});
    }
    }
    }
    return result;
    }
};
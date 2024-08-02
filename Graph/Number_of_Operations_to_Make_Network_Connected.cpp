// Time Complexity : O(E+n);
// Space Complexity : O(n);

class Solution {
public:
    
    vector<int>parents;
    vector<int>rank;

    int find(int node,vector<int>&parents){

    if(node == parents[node]){
    return node;
    }
    return parents[node] = find(parents[node],parents);
    }

    void solve(int u,int v, vector<int>&parents,vector<int>&rank){

    int u_parent = find(u,parents);
    int v_parent = find(v,parents);

    if(rank[u_parent] > rank[v_parent]){
    parents[v_parent] = u_parent;
    }
    else if(rank[u_parent] < rank[v_parent]){
    parents[u_parent] = v_parent;
    }
    else{
    parents[v_parent] = u_parent;
    rank[u_parent]++;
    }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

    parents.resize(n);
    rank.resize(n,0);
    
    for(int i=0;i<n;i++){
    parents[i] = i;
    }

    if (connections.size() < n - 1){
    return -1;
    }
    int count = n;

    for(auto &it : connections){
    
    int u_parent = find(it[0],parents);
    int v_parent = find(it[1],parents);

    if(u_parent != v_parent){
    count--;
    solve(u_parent,v_parent,parents,rank);
    }
    }
    return count-1;
    }
};
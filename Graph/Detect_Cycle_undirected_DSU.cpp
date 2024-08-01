// Time Complexity: 𝑂(𝐸⋅𝛼(𝑉))O(E⋅α(V)) ....
// Space Complexity: 𝑂(𝑉+𝐸) O(V+E) ....


// Time & Space Complexity of DSU ....

// A) Time Complexity of Find operation without Path compression : O(n)
// A) Time Complexity of Find operation with Path compression : O(α(n))

// where α is the Inverse Ackermann function. For all practical purposes, 𝛼(𝑛)
// is a very slow-growing function, making it effectively constant-time for all reasonable values of 𝑛.


// B) Union Operation

// Without Union by Rank/Size: The time complexity can be 𝑂(𝑛)O(n) in the worst case.

// With Union by Rank/Size: The time complexity is 𝑂(𝛼(𝑛))
// O(α(n)) amortized. This is achieved by always attaching the smaller tree under the root of the larger tree or by maintaining tree height to ensure that the tree remains balanced.

// -------------------------------------------------------------------

// Space Complexity: O(n)

class Solution {
  public:
    int find(int node,vector<int>&parent){
    
    if(node == parent[node]){
    return node;
    }
    return parent[node] = find(parent[node],parent);
    }
    
    void U(int u,int v,vector<int>&parent,vector<int>&rank){
    
    int u_parent = find(u,parent);
    int v_parent = find(v,parent);
    
    if(rank[u_parent] > rank[v_parent]){
    parent[v_parent] = u_parent;
    }
    else if(rank[u_parent] < rank[v_parent]){
    parent[u_parent] = v_parent;
    }
    else{
        
    parent[v_parent] = u_parent;
    rank[v_parent]++;
    }
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
    vector<int>parent(V,0);
    vector<int>rank(V,0);
    
    for(int i=0;i<V;i++){
    parent[i] = i;
    }
    
    for(int u=0;u<V;u++){
    for(auto &v : adj[u]){
    
    if(u < v){
       
    int u_parent = find(u,parent);
    int v_parent = find(v,parent);
    
    if(u_parent == v_parent){
    return true;
    }
    U(u,v,parent,rank);
    }
    }
    }
    return false;
    }
};

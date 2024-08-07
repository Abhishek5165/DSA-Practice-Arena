class Solution
{
public:
  vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
  {
    vector<vector<int>> ans(V);

    for (auto it : edges)
    {

      int u = it.first;
      int v = it.second;

      ans[u].push_back(v);
      ans[v].push_back(u);
    }
    return ans;
  }
};

// In case of vector<int> adj[] ,the adjancy list, This is vector of vector
// (vector<int> adj[]) .................for directed graph.

unordered_map<int, vector<int>> mpp;

for (int u = 0; u < V; u++){

  for (auto v = adj[u].begin(); v < adj[u].end(); v++){
    mpp[u].push_back(*v);
  }
}

// for 2-D vector vector<vector<int>>isConnected adj will be.

unordered_map<int, vector<int>> adj;

// making the graph ..........

for (int i = 0; i < n; i++)
{
  for (int j = 0; j < n; j++)
  {

    if (isConnected[i][j] == 1)
    {
      adj[i].push_back(j);
      adj[j].push_back(i);
    }
  }
}

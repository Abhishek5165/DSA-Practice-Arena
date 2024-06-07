class Solution
{
public:
    void dfs(int start, vector<int> &ans, vector<int> adj[], vector<int> &visited)
    {
        ans.push_back(start);
        visited[start] = 1;

        for (auto it : adj[start])
        {

            if (!visited[it])
            {

                dfs(it, ans, adj, visited);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {

        vector<int> ans;
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {

            if (!visited[i])
            {
                dfs(0, ans, adj, visited);
            }
        }
        return ans;
    }
};
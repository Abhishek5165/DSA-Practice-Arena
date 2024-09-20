// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

class Solution {
public:
    int timer = 1;
    void solve(int start, int parent, 
    vector<int> adj[], 
    vector<int>& dist,vector<int>& low, 
    vector<int>& visited,vector<vector<int>>& ans) {

        visited[start] = 1;
        low[start] = dist[start] = timer;
        timer++;

        for (auto it : adj[start]) {
            if (it == parent) {
                continue;
            }
            if (!visited[it]) {
                solve(it, start, adj, dist, low, 
                visited, ans);
                low[start] = min(low[it], low[start]);
                if (low[it] > dist[start]) {
                    ans.push_back({it, start});
                }
            } 
            else {
                low[start] = min(low[it], low[start]);
            }
        }
    }

    vector<vector<int>> 
    criticalConnections(int n,
    vector<vector<int>>& connections) {

        vector<vector<int>> ans;
        vector<int> adj[n];

        vector<int> dist(n, -1);
        vector<int> low(n, -1);
        vector<int> visited(n, 0);
        int parent = -1;

        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve(0, parent, adj, dist, low, visited, ans);
        return ans;
    }
};
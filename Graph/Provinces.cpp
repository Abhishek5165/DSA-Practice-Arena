
// By making new Adjancy list & DFS ...
// Time complexity : O(V+E);
// Space complexity : O(V);

class Solution{
    void dfs(int start, vector<int> &visited, vector<int> adj[])
    {
        visited[start] = 1;
        for (auto it : adj[start])
        {

            if (!visited[it])
            {
                dfs(it, visited, adj);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(i, visited, adj);
            }
        }
        return count;
    }
};

// using the given matrix only...

class Solution
{

    void dfs(int start, vector<int> &visited,
             vector<vector<int>> &isConnected)
    {

        visited[start] = 1;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (isConnected[start][i] == 1 && !visited[i])
            {
                dfs(i, visited, isConnected);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int n = isConnected.size();

        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(i, visited, isConnected);
            }
        }
        return count;
    }
};


// Using BFS ....

// Time complexity : O(V+E);
// Space complexity : O(V);

class Solution {
public:
    int n;
    void solve(int u, vector<vector<int>>& isConnected,
     vector<bool>&visited) {

        queue<int> Q;
        Q.push(u);
        visited[u] = true;

        while (!Q.empty()) {

            int node = Q.front();
            Q.pop();

            for (int v = 0; v < n; v++) {
                if (!visited[v] && isConnected[u][v] == 1) {
                   solve(v,isConnected,visited);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        n = isConnected.size();
        int count = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                solve(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};
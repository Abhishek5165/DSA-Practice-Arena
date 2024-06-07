
// By making new Adjancy list

class Solution
{

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

// using the given matrix only

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
// Time complexity : O(V+E);
// Space complexity : O(V);

// Using DFS ...

class Solution {
public:
    bool solve(int u,vector<vector<int>>&graph,
     vector<int>& colors,int currentColor) {

        colors[u] = currentColor;

        for (auto &v : graph[u]) {

            if(colors[v] == colors[u]) return false;

            if (colors[v] == -1) {
                int newColor = 1 - currentColor;
                if (solve(v, graph, colors, newColor) == false) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (solve(i, graph , colors, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};
// Time complexity : O(V+E);
// Space complexity : O(V);

// Using BFS ...

class Solution {
public:
    bool solve(int u, vector<vector<int>>& graph, vector<int>& colors,
               int currColor) {

        queue<int> Q;
        Q.push(u);
        colors[u] = currColor;

        while (!Q.empty()) {

            int node = Q.front();
            Q.pop();

            for (auto& it : graph[node]) {

                if (colors[it] == colors[node]) {
                    return false;
                }
                else if (colors[it] == -1) {
                    colors[it] = 1 - colors[node];
                    Q.push(it);
                }
            }
        }
    return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        int currColor = 1;
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (solve(i, graph, colors, currColor) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};
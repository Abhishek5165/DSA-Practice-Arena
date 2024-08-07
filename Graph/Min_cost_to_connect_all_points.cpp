// Time Complexity : O(E*logV) OR O(E* logE) + O(E* log V);
// here logV & logE both are same. because maximum posible vertexes are V*V
// Space Complexity : O(V+E);

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int node) {

        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    void solve(int u, int v) {

        int u_parent = find(u);
        int v_parent = find(v);

        if (u_parent == v_parent) {
            return;
        }
        if (rank[u_parent] > rank[v_parent]) {
            parent[v_parent] = u_parent;
        } 
        else if (rank[u_parent] > rank[v_parent]) {
            parent[u_parent] = v_parent;
        } 
        else {
            parent[v_parent] = u_parent;
            rank[u_parent]++;
        }
    }

    int kruskal(vector<vector<int>>& vec) {
        int sum = 0;

        for (auto& it : vec) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            int u_parent = find(u);
            int v_parent = find(v);

            if (u_parent != v_parent) {
                solve(u_parent, v_parent);
                sum += wt;
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<vector<int>> vec;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int wt = abs(x1 - x2) + abs(y1 - y2);
                vec.push_back({i, j, wt});
            }
        }
        auto comparator = [&](vector<int>& vec1, vector<int>& vec2) {
            return vec1[2] < vec2[2];
        };

        sort(begin(vec), end(vec), comparator);
        return kruskal(vec);
    }
};
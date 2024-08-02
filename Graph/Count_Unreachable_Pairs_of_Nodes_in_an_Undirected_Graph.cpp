// Time Complexity : O(E+n);
// Space Complexity : O(n);

class Solution {
public:
    vector<int> parents;
    vector<int> rank;

    int find(int node, vector<int>& parents) {

        if (node == parents[node]) {
            return node;
        }
        return parents[node] = find(parents[node], parents);
    }

    void solve(int u, int v, vector<int>& parents, vector<int>& rank) {

        int u_parent = find(u, parents);
        int v_parent = find(v, parents);

        if (rank[u_parent] > rank[v_parent]) {
            parents[v_parent] = u_parent;
        } else if (rank[u_parent] < rank[v_parent]) {
            parents[u_parent] = v_parent;
        } else {
            parents[v_parent] = u_parent;
            rank[u_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {

        parents.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        for (auto& vec : edges) {
            long long u = vec[0];
            long long v = vec[1];

            solve(u, v, parents, rank);
        }
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            int parent = find(i, parents);
            mpp[parent]++;
        }
        long long ans = 0;
        long long remain = n;

        for (auto& it : mpp) {

            long long size = it.second;
            ans += size * (remain - size);
            remain = remain - size;
        }
        return ans;
    }
};
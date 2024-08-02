// Time complexity : O(V*(logV + E*(logV));
// Sace complexity : O(V+E);

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> result(n + 1, INT_MAX);
        result[k] = 0;
        set<pair<int, int>> st;
        st.insert({0, k});

        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& vec : times) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            adj[u].push_back({v, w});
        }

        while (!st.empty()) {
            auto it = *st.begin();
            int dist = it.first;
            int node = it.second;
            st.erase(it);

            for (auto& vec : adj[node]) {
                int v = vec.first;
                int wt = vec.second;

                if (dist + wt < result[v]) {
                    st.erase({result[v], v});
                    result[v] = dist + wt;
                    st.insert({dist + wt, v});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, result[i]);
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};

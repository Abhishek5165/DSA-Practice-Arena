// Time Complexity : O(n);
// Space Complexity : O(1);

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int node, vector<int>& parent) {

        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node], parent);
    }

    void solve(int u, int v, vector<int>& parent, vector<int>& rank) {

        int u_parent = find(u, parent);
        int v_parent = find(v, parent);

        if (rank[u_parent] > rank[v_parent]) {
            parent[v_parent] = u_parent;
        } 
        else if (rank[u_parent] < rank[v_parent]) {
            parent[u_parent] = v_parent;
        } 
        else {
            parent[v_parent] = u_parent;
            rank[u_parent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        for(int i=0;i<26;i++){
        parent[i] = i;
        }

        for (string& s : equations) {
            if (s[1] == '=') {
                solve(s[0] - 'a', s[3] - 'a', parent, rank);
            }
        }
        for (string& s : equations) {
            if (s[1] == '!') {
                int parent_a = find(s[0] - 'a', parent);
                int parent_b = find(s[3] - 'a', parent);
                if (parent_a == parent_b) {
                    return false;
                }
            }
        }
        return true;
    }
};
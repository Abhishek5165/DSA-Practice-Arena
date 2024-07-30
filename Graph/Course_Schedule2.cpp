// Using Kahn's Algorithms....
// Time complexity : O(E)+O(V)+O(V) = O(V+E)
// Space complexity : O(V)

class Solution {
public:
    vector<int> solve(int numCourses,
    unordered_map<int, vector<int>>& adj,vector<int>& indegree) {

        vector<int> ans;
        int count = 0;
        queue<int> Q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                Q.push(i);
                count++;
            }
        }
        while (!Q.empty()) {

            int node = Q.front();
            ans.push_back(node);
            Q.pop();
            for (auto& v : adj[node]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    Q.push(v);
                    count++;
                }
            }
        }
        if(count == numCourses){
        return ans;
        }
        return {};
    }

    vector<int> findOrder(int numCourses, 
    vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses, 0);

        unordered_map<int, vector<int>> adj;
        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return solve(numCourses, adj, indegree);
    }
};
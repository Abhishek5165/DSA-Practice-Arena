// Using Kahn's Algorithms....
// Time complexity : O(E)+O(V)+O(V)=O(V+E)
// Space complexity : O(V)

class Solution {
public:
    bool solve(unordered_map<int, vector<int>>& adj,
     vector<int>& indegree,int num) {

        queue<int> Q;
        int count = 0;
        for (int i = 0; i < num; i++) {
            if (indegree[i] == 0) {
                count++;
                Q.push(i);
            }
        }
        while (!Q.empty()) {

            int node = Q.front();
            Q.pop();

            for (auto& v : adj[node]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    Q.push(v);
                    count++;
                }
            }
        }
        if (count == num) {
            return true;
        }
        return false;
    }

    bool canFinish(int numCourses, 
    vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }
        return (solve(adj, indegree, numCourses));
    }
};
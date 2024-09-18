// Time Complexity : O(V+E);
// Space Complexity : O(V+E);

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
    int n = graph.size();
    vector<int>indegree(n,0);
    vector<int>adj[n];

    for(int i=0;i<n;i++){
    for(auto & it : graph[i]){
    adj[it].push_back(i);
    indegree[i]++;
    }
    }
    queue<int>Q;
    for(int i=0;i<n;i++){
    if(indegree[i] == 0){
    Q.push(i);
    }
    }
    vector<int>ans;
    while(!Q.empty()){
    int node = Q.front();
    ans.push_back(node);
    Q.pop();
    for(auto it:adj[node]){
    indegree[it]--;
    if(indegree[it] == 0){
    Q.push(it);
    }
    }
    }
    sort(begin(ans),end(ans));
    return ans;
    }
};
#include <bits/stdc++.h>
vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {

  vector<int> ans;
  vector<int> visited(n, 0);

  queue<int> Q;
  int start = 0;

  Q.push(start);
  visited[start] = 1;

  while (!Q.empty()) {

    int node = Q.front();
    ans.push_back(node);
    Q.pop();

    for (auto it : adj[node]) {

      if (!visited[it]) {

        visited[it]=1;
        Q.push(it);
      }
    }
  }
  return ans;
}
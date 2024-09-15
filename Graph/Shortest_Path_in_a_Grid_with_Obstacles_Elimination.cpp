// Time Complexity : O(4(N∗M))
// Space Complexity : O(N*M)

class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int visited[41][41][1601] = {0};  // Initialize visited array with 0
        
        queue<vector<int>> Q;
        Q.push({0, 0, k});
        visited[0][0][k] = 1;

        int steps = 0;

        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                auto it = Q.front();
                Q.pop();
                int curri = it[0];
                int currj = it[1];
                int obs = it[2];

                if (curri == n - 1 && currj == m - 1) {
                    return steps;
                }

                for (auto& dir : directions) {
                    int nrow = curri + dir[0];
                    int ncol = currj + dir[1];

                    if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m) {
                        continue;
                    }

                    if (!visited[nrow][ncol][obs] && 
                    grid[nrow][ncol] == 0) {
                        Q.push({nrow, ncol, obs});
                        visited[nrow][ncol][obs] = 1;
                    } 
                    else if (obs > 0 && !visited[nrow][ncol][obs - 1] 
                    && grid[nrow][ncol] == 1) {
                        Q.push({nrow, ncol, obs - 1});
                        visited[nrow][ncol][obs - 1] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

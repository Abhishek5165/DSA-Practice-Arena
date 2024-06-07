class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> Q;
        int visited[n][m];

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {

                    Q.push({{i, j}, 0});
                    visited[i][j] = 2;
                } else {

                    visited[i][j] = 0;
                }
            }
        }
        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!Q.empty()) {

            auto it = Q.front();
            int row = it.first.first;
            int col = it.first.second;
            int tm = it.second;
            Q.pop();

            time = max(time, tm);

            for (int i = 0; i < 4; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n &&
                 ncol >= 0 && ncol < m &&
                    visited[nrow][ncol] == 0 &&
                     grid[nrow][ncol] == 1) {
                        
                    Q.push({{nrow, ncol}, tm + 1});
                    visited[nrow][ncol] = 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (visited[i][j] != 2 && grid[i][j] == 1) {

                    return -1;
                }
            }
        }
        return time;
    }
};
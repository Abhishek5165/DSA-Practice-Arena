// Time Complexity: O(N) + O(M) + O(NxMx4) ~ O(N x M)
// Space Complexity ~ O(N x M)

class Solution {
public:
    vector<vector<int>> directions = 
    {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void solve(int row, int col, vector<vector<char>>& board,
    vector<vector<int>>& visited) {
        int n = board.size();
        int m = board[0].size();
        visited[row][col] = 1;

        for (auto direction : directions) {
            int nrow = row + direction[0];
            int ncol = col + direction[1];

            if (nrow >= 0 && nrow < n && ncol >= 0 && 
            ncol < m && board[nrow][ncol] == 'O' && 
            !visited[nrow][ncol]) {
                solve(nrow, ncol, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
    
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (!visited[i][0] && board[i][0] == 'O') {
                solve(i, 0, board, visited);
            }
            if (!visited[i][m-1] && board[i][m-1] == 'O') {
                solve(i, m-1, board, visited);
            }
        }

        for (int j = 0; j < m; j++) {
            if (!visited[0][j] && board[0][j] == 'O') {
                solve(0, j, board, visited);
            }
            if (!visited[n-1][j] && board[n-1][j] == 'O') {
                solve(n-1, j, board, visited);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

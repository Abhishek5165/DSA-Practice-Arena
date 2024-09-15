// Time Complexity : O(4(N∗M))
// Space Complexity : O(N*M)

class Solution {
public:

    bool solve(int row, int col, vector<vector<int>>& 
    grid, int health, vector<vector<int>>& visited) {

        int n = grid.size();
        int m = grid[0].size();
        
        if (row < 0 || row >= n || col < 0 || col >= m)
            return false;
        
        if (grid[row][col] == 1)
            health -= 1;
        
        if (health < 1)
            return false;

        if (row == n - 1 && col == m - 1)
            return true;
        
        if (health <= visited[row][col])
            return false;

        visited[row][col] = health;
        
    bool A = solve(row+1,col,grid,health,visited);
    bool B = solve(row,col+1,grid,health,visited);
    bool C = solve(row-1,col,grid,health,visited);
    bool D = solve(row,col-1,grid,health,visited);
        
    return (A || B || C || D);
    }
    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        return solve(0, 0, grid, health,visited);
    }
};
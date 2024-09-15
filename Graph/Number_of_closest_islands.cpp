// Time Complexity : O(N*M);
// Space Complexity : O(N*M);

class Solution {
public:
    bool dfs(int r,int c,vector<vector<int>>& grid){

    int n = grid.size();
    int m = grid[0].size();

    if(r < 0 || r >= n || c < 0 || c >= m){
    return false;
    }
    if(grid[r][c] == 1){
    return true;
    }
    grid[r][c] = 1;

    bool left = dfs(r,c-1,grid);
    bool right = dfs(r,c+1,grid);
    bool up = dfs(r-1,c,grid);
    bool down = dfs(r+1,c,grid);

    return (left && right && up && down);
    }

    int closedIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    if(grid[i][j] == 0){
    if(dfs(i,j,grid) == true){
    count++;
    }
    }
    }
    }
    return count;
    }
};
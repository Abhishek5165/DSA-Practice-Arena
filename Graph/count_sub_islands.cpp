// Time Complexity : O(N*M);
// Space Complexity : O(N*M);

class Solution {
public:
    void solve(int r,int c,vector<vector<int>>& 
    grid1, vector<vector<int>>& grid2,int& flag){

    int n = grid2.size();
    int m = grid2[0].size();
    if(r < 0 || r >= n || c < 0 || c >= m){
    return;
    }
    if(grid2[r][c] == 0){
    return;
    }
    if(grid2[r][c] == 1){
    
    if(grid1[r][c] == 0){
    flag = 0;
    return;
    }
    grid2[r][c] = 0;
    }
    solve(r,c-1,grid1,grid2,flag);
    solve(r,c+1,grid1,grid2,flag);
    solve(r-1,c,grid1,grid2,flag);
    solve(r+1,c,grid1,grid2,flag);
    }

    int countSubIslands(vector<vector<int>>& 
    grid1, vector<vector<int>>& grid2) {
    int count = 0;

    int n = grid1.size();
    int m = grid1[0].size();
    int flag = 1;

    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    flag = 1;
    if(grid2[i][j] == 1){
    solve(i,j,grid1,grid2,flag);
    if(flag == 1){
    count++;
    }
    }
    }
    }
    return count;
    }
};
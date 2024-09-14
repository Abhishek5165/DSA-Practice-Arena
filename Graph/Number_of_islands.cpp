	
// Number of Distinct Islands............
// Time Complexity ~ O(N² + NxMx9);
// Space Complexity ~ O(N²);

class Solution {
public: 
    void solve(int row,int col,vector<vector<int>>&visited,
    vector<vector<char>>& grid){

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>>Q;
    Q.push({row,col});
    visited[row][col] = 1;

    while(!Q.empty()){
    
    auto it = Q.front();
    Q.pop();
    int ro = it.first;
    int co = it.second;

     int dro[] = {-1, 1, 0, 0};
    int dco[] = {0, 0, -1, 1};

    for(int i=0;i<4;i++){
        
    int newRow = ro + dro[i];
    int newCol = co + dco[i];

    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
    !visited[newRow][newCol] && grid[newRow][newCol] == '1'){
    Q.push({newRow,newCol});
    visited[newRow][newCol] = 1;
    }
    }
    }
    }
    int numIslands(vector<vector<char>>&grid) {

    int n = grid.size();
    int m = grid[0].size();

    int count = 0;

    vector<vector<int>>visited(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    if(!visited[i][j] && grid[i][j] == '1'){
    count++;
    solve(i,j,visited,grid);
    }
    }
    }
    return count;
    }
};

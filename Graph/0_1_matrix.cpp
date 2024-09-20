// Time Complexity : O(N*M);
// Space Complexity : O(N*M);

class Solution {
public:
    vector<vector<int>> updateMatrix
    (vector<vector<int>>& mat) {
    
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>>visited(n,vector<int>(m,0));
    vector<vector<int>>temp(n,vector<int>(m,0));

    queue<pair<pair<int,int>,int>>Q;

    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    if(mat[i][j] == 0){
    Q.push({{i,j},0});
    visited[i][j] = 1;
    }
    else{
    visited[i][j] = 0;
    }
    }
    }
    int drow[] = {-1,0,+1,0};
    int dcol[] = {0,1,0,-1};

    while(!Q.empty()){

    int row = Q.front().first.first;
    int col = Q.front().first.second;
    int steps = Q.front().second;
    temp[row][col] = steps;
    Q.pop();

    for(int i=0;i<4;i++){

    int nrow = row + drow[i];
    int ncol = col + dcol[i];

    if(nrow >= 0 && nrow < n && ncol < m && ncol >= 0 
    && !visited[nrow][ncol]){
    Q.push({{nrow,ncol},steps+1});
    visited[nrow][ncol] = 1;
    }
    }
    }
    return temp;
    }
};
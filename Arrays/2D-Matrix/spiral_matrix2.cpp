// time complexity : O(n*m);
// space complexity : O(n*m);

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    int m = n*n;

    int top = 0, down = n-1;
    int left = 0, right = n-1;

    int direction = 0;
    vector<vector<int>> ans(n, vector<int>(n));
    int count = 1;

    while(top <= down && left <= right && count <= m){
    
    if(direction == 0){
    
    for(int i=left;i<=right;i++){
    ans[top][i] = count;
    count++;
    }
    top++;
    }
    if(direction == 1){
    
    for(int i=top;i<=down;i++){
    ans[i][right] = count;
    count++;
    }
    right--;
    }
    if(direction == 2){
    
    for(int i=right;i>=left;i--){
    ans[down][i] = count;
    count++;
    }
    down--;
    }
    if(direction == 3){
    
    for(int i=down;i>=top;i--){
    ans[i][left] = count;
    count++;
    }
    left++;
    }
    direction++;
    if(direction > 3){
    direction = 0;
    }
    }
    return ans;
    }
};
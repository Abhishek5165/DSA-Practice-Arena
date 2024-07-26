// Approch - 1 Using Memoization.

// Time complexity : O(k*n^2);
// Space complexity : O(k*n^2);

class Solution {
public:

    unordered_map<string,double>mpp;
    
    double solve(int n,int row,int column,int k){
     
    if(row < 0 || row >= n || column < 0 || column >= n){
    return 0;
    }
    if(k == 0){
    return 1;
    }

    string key = to_string(k) + "_" + to_string(row) 
    + "_" + to_string(column);

    if(mpp.find(key) != mpp.end()){
    return mpp[key];
    }

    double result = 0;

    vector<pair<int,int>> direction = {{1,2},{1,-2},{-1,2},{-1,-2},
    {2,1},{2,-1},{-2,1},{-2,-1}};

    for(auto &it:direction){

    int newRow = row + it.first;
    int newCol = column + it.second;

    result += (double)solve(n,newRow,newCol,k-1);
    }
    return mpp[key] = (double)(result/8.0);
    }

    double knightProbability(int n, int k, int row, int column) {
    return solve(n,row,column,k);
    }
};
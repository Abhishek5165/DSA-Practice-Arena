// Time Complexity: O(N*logN) + O(2*N);

// Space Complexity: O(N), as we are using an answer list to store the merged intervals.....

#include<vector>
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){

int n = arr.size();
sort(arr.begin(),arr.end());
vector<vector<int>>ans;

for(int i=0;i<n;i++){

int start = arr[i][0];
int end = arr[i][1];

if(!ans.empty() && end <= ans.back()[1]){
continue;
}
for(int j=i+1;j<n;j++){
if(arr[j][0] <= end){
end = max(end,arr[j][1]);
}
else{
break;
}
}
ans.push_back({start,end});
}
return ans;
}

// Optimal approch .....

// Time Complexity : O(NLogN) + O(N);
// Space Complexity O(N) for storing the ans;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

    vector<vector<int>>ans;
    sort(intervals.begin(),intervals.end());
    
    int n = intervals.size();

    for(int i=0;i<n;i++){
    if(ans.empty() || ans.back()[1] < intervals[i][0]){
    ans.push_back(intervals[i]);
    }
    else{
    ans.back()[1] = max(ans.back()[1],intervals[i][1]);
    }
    }
    return ans;
    }
};
// Time Complexity : O(NLogn);
// Space Complexity : O(1);

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
    int n = timePoints.size();
    vector<int>minutes(n);
    for(int i=0;i<n;i++){
    string time = timePoints[i];

    string hours   = time.substr(0,2);
    string minute  = time.substr(3);

    int H = stoi(hours);
    int M = stoi(minute);

    int total = ((H*60) + M);
    minutes[i] = total;
    }
    sort(minutes.begin(),minutes.end());
    int ans = INT_MAX;
    for(int i=1;i<n;i++){
    ans = min(ans,minutes[i]-minutes[i-1]);
    }
    return min(ans,(24*60 - minutes[n-1]) + minutes[0]);
    }
};
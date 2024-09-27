// Time Complexity : O(n * L + k + E)

// L = max word length;
// Space Complexity : O(k + E)

class Solution {
  public:
    vector<int>solve(int k,vector<int>adj[]){
    
    int indegree[k] = {0};
    vector<int>ans;
    
    for(int i=0;i<k;i++){
    for(auto it : adj[i]){
    indegree[it]++;
    }
    }
    queue<int>Q;
    for(int i=0;i<k;i++){
    if(indegree[i] == 0){
    Q.push(i);
    }
    }
    while(!Q.empty()){
    
    int node = Q.front();
    ans.push_back(node);
    Q.pop();
    
    for(auto &it : adj[node]){
    indegree[it]--;
    if(indegree[it] == 0){
    Q.push(it);
    }
    }
    }
    return ans;
    }
    
    string findOrder(string dict[], int n, int k) {
    vector<int>adj[k];
    
    for(int i=0;i<n-1;i++){
        
    string s1 = dict[i];
    string s2 = dict[i+1];
    int len = min(s1.size(),s2.size());
    for(int ptr=0;ptr<len;ptr++){
    if(s1[ptr] != s2[ptr]){
    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
    break;
    }
    }
    }
    vector<int>topo = solve(k,adj);
    string ans = "";
    for(int i=0;i<topo.size();i++){
    ans += topo[i]+'a';
    }
    return ans;
    }
};
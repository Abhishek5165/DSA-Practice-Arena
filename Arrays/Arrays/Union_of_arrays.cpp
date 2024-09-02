// Time Compleixty : O( (m+n)log(m+n));
// Space Complexity : O(m+n);

class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m){
    vector<int>ans;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
    mpp[arr1[i]]++;
    }
    for(int i=0;i<m;i++){
    mpp[arr2[i]]++;
    }
    for(auto &it : mpp){
    ans.push_back(it.first);
    }
    return ans;
    }
};

// Time Compleixty : O( (m+n)log(m+n));
// Space Complexity : O(m+n);

class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m){
    vector<int>ans;
    set<int>st;
    for(int i=0;i<n;i++){
    st.insert(arr1[i]);
    }
    for(int i=0;i<m;i++){
    st.insert(arr2[i]);
    }
    for(auto &it : st){
    ans.push_back(it);
    }
    return ans;
    }
};

// Time Compleixty : O( (m+n);
// Space Complexity : O(m+n);

class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m){
    
    vector<int>ans;
    int i=0;
    int j=0;

    while(i<n && j<m){
    
    if(arr1[i] <= arr2[j]){
    if(ans.size() == 0 || ans.back() != arr1[i]){
    ans.push_back(arr1[i]);
    }
    i++;
    }
    else{
    if(ans.size() == 0 || ans.back() != arr2[j]){
    ans.push_back(arr2[j]);
    }
    j++;
    }
    }
    while(i<n){
    if(ans.back() != arr1[i]){
    ans.push_back(arr1[i]);
    }
    i++;
    }
    while(j<m){
    if(ans.back() != arr2[j]){
    ans.push_back(arr2[j]);
    }
    j++;
    }
    return ans;
    }
};

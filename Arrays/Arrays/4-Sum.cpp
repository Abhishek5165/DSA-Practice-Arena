// Better Approch  .....
// Time Complexity : O(N^3*log(M))
// Space Complexity : O(N);

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>>st;
    int n = nums.size();

    for(int i=0;i<n;i++){
    int first = nums[i];

    for(int j=i+1;j<n;j++){
    set<long long>hashset;
    int second = nums[j];

    for(int k=j+1;k<n;k++){
    int third = nums[k];
    long long sum = first;
    sum += second;
    sum += third;

    long long forth = target-sum;

    if(hashset.find(forth) != hashset.end()){
    vector<int>temp = {first,second,third,(int)forth};
    sort(temp.begin(),temp.end());
    st.insert(temp);
    }
    hashset.insert(nums[k]);
    }
    }
    } 
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
    }
};



// Time Complexity : O(N*N*N);
// Space Complexity : O(1);

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    int n = nums.size();

    for(int i=0;i<n;i++){
    if(i != 0 && nums[i] == nums[i-1]){
    continue;
    }
    for(int j=i+1;j<n;j++){
    if(j != i+1 && nums[j] == nums[j-1]){
    continue;
    }

    int k = j+1;
    int l = n-1;

    while(k < l){

    long long sum = nums[i];
    sum += nums[j];
    sum += nums[k];
    sum += nums[l];

    if(sum == target){
    vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
    k++;
    l--;
    ans.push_back(temp);
    while(k < l && nums[k] == nums[k-1]) k++;
    while(k < l && nums[l] == nums[l+1]) l--;
    }
    else if(sum < target){
    k++;
    }
    else{
    l--;
    }
    }
    }
    }
    return ans;   
    }
};
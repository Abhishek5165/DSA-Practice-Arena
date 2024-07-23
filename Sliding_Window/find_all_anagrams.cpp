// Time Complexity : O(n);
// Space Complexity : O(n);

class Solution{
public:
    
    bool allZero(vector<int>&counter){
        
    for(auto &it : counter){
    if( it != 0){
    return false;
    }
    }
    return true;
    }
	int search(string pat, string txt) {
	 
	int n = txt.size();
	int i=0;
	int j=0;
	int count = 0;
	
	vector<int>counter(26,0);
	
	for(int i=0;i<pat.size();i++){
	char ch = pat[i];
	counter[ch-'a']++;
	}
	int k = pat.size();
	
	while(j<n){
	   
	counter[txt[j]-'a']--;
	
	if(j-i+1 == k){
	
	if(allZero(counter)){
	  count++;
	}
	counter[txt[i]-'a']++;
	i++;
	}
	j++;
	}
	return count;
	}
};
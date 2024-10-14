#include<bits/stdc++.h>

struct Node{
Node* Links[26];

bool containsKey(char ch){
return Links[ch-'a'] != NULL;
}

void put(char ch,Node* node){
Links[ch-'a'] = node;
}

Node* get(char ch){
return Links[ch-'a'];
}
};

int countDistinctSubstrings(string &s){
int count = 0;
Node* root = new Node();

for(int i=0;i<s.size();i++){
Node* node = root;
for(int j=i;j<s.length();j++){
if(!node->containsKey(s[j])){
count++;
node->put(s[j],new Node());
}
node = node->get(s[j]);
}
}
return count+1;
}
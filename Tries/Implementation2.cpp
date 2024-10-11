// Time Complexity All the function is O(N);
// Space Complexity : O(1);

#include <bits/stdc++.h> 
struct Node{
    Node* Links[26];
    int ew = 0;
    int cp = 0;

    bool containsKey(char ch){
    return (Links[ch-'a'] != NULL);
    }
    void put(char ch,Node* node){
    Links[ch-'a'] = node;
    }

    Node* get(char ch){
    return Links[ch-'a'];
    }
    void increaseCp(){
    cp++;
    }
    void increaseEw(){
    ew++;
    }
     void decreaseCp(){
    cp--;
    }
    void decreaseEw(){
    ew--;
    }
    int CP(){
    return cp;
    }
    int EW(){
    return ew;
    }
};

class Trie{
    private: Node* root;
    public:

    Trie(){
    root = new Node();
    }

    void insert(string &word){
    Node* node = root;
    for(int i=0;i<word.size();i++){
    if(!node->containsKey(word[i])){
    node->put(word[i],new Node());
    }
    node = node->get(word[i]);
    node->increaseCp();
    }
    node->increaseEw();
    }

    int countWordsEqualTo(string &word){
    Node* node = root;
    for(int i=0;i<word.size();i++){
    if(node->containsKey(word[i])){
    node = node->get(word[i]);
    }
    else{
    return 0;
    }
    }
    return node->EW();
    }

    int countWordsStartingWith(string &word){
    Node* node = root;
    for(int i=0;i<word.size();i++){
    if(node->containsKey(word[i])){
    node = node->get(word[i]);
    }
    else{
    return 0;
    }
    }
    return node->CP();
    }

    void erase(string &word){
    Node* node = root;
    for(int i=0;i<word.size();i++){
    if(node->containsKey(word[i])){
    node = node->get(word[i]);
    node->decreaseCp();
    } else {
    return;
    }
    node->decreaseEw();
    }
    }
};

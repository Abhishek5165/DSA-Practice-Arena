struct Node{
Node* links[26];
bool flag = false;

bool containsKey(char ch){
return links[ch-'a'] != NULL;
}

void put(char ch,Node* node){
links[ch-'a'] = node;
}
Node* get(char ch){
return links[ch-'a'];
}
void setEnd(){
flag = true;
}

bool isEnd(){
return flag;
}
};

class Trie {

private: Node* root;

public:
    Trie() {
    root = new Node();
    }

    // Time Complexity of insert operation is O(length of the word...)
    
    void insert(string word) {
    Node *node = root;
    
    // checks if the char already exist or not in the trie...

    for(int i=0;i<word.size();i++){
    if(!node->containsKey(word[i])){
    node->put(word[i],new Node());
    }

    // moves to the next trie .....
    node = node->get(word[i]);
    }

    // set last trie's flag to true..
    node->setEnd();
    }
    // Time Complexity of Search operation is O(length of the word...)

    bool search(string word) {
    Node* node = root;
    for(int i=0;i<word.size();i++){
    if(!node->containsKey(word[i])){
    return false;
    }
    node = node->get(word[i]);
    }
    return node->isEnd();
    }
    // Time Complexity of starts operation is O(length of the word...) 

    bool startsWith(string prefix) {
    Node* node = root;
    for(int i=0;i<prefix.size();i++){
    if(!node->containsKey(prefix[i])){
    return false;
    }
    node = node->get(prefix[i]);
    }
    return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
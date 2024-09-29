// Time Complexity : O(1);
// Space Complexity : O(N);

class AllOne {
public:
    
    struct Node {
    list<string>st;
    Node* next;
    Node* prev;
    int count;

    Node(int c){
    count = c;
    next = NULL;
    prev = NULL;
    }
    };

    unordered_map<string,Node*>mpp;
    Node* head;
    Node* last;

    AllOne() {
    head = new Node(0);
    last = head; 
    }

    Node* addNode(Node* prevNode,int ct){
    Node* newNode = new Node(ct);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if(prevNode->next != NULL){
    prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    if(prevNode == last){
    last = newNode;
    }
    return newNode;
    }

    void remove(Node* node){
    node->prev->next = node->next;
    if(node->next != NULL){
    node->next->prev = node->prev;
    }
    if(last == node){
    last = node->prev;
    }
    delete(node);
    }
    
    void inc(string key) {
    if(mpp.find(key) == mpp.end()){
    // check if there exist a node with count 1
    if(head->next == NULL || head->next->count != 1){
    addNode(head,1);
    }
    head->next->st.push_front(key);
    mpp[key] = head->next;
    } 
    else{
    Node* currNode = mpp[key];
    int countNode = currNode->count;
    if(currNode->next == NULL || currNode->next->
    count != countNode+1){
    addNode(currNode,countNode+1);
    }

    currNode->next->st.push_front(key);
    mpp[key] = currNode->next;
    currNode->st.remove(key);

    if(currNode->st.empty()){
    remove(currNode);
    }
    }
    }
    
     void dec(string key) {
        Node *curNode = mpp[key];
        int curCount = curNode->count;
    
        curNode->st.remove(key);
        if (curCount == 1) {
            mpp.erase(key);
        } 
        else {
            if (curNode->prev == head 
            || curNode->prev->count != curCount - 1) {
                addNode(curNode->prev, curCount - 1);
            }
            curNode->prev->st.push_front(key);
            mpp[key] = curNode->prev;
        }
        if (curNode->st.empty()) {
            remove(curNode);
        }
    }
    
    string getMaxKey() {
    if(last == head){
    return "";
    }  
    return last->st.front();
    }
    
    string getMinKey() {
    if(head->next == NULL){
    return "";
    } 
    return head->next->st.front();  
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
public:
    Node* copyRandomList(Node* head) {
    if(head == NULL){
    return NULL;
    } 
    unordered_map<Node*,Node*>mpp;
    Node* curr = head;
    Node* prev = NULL;
    Node* newHead = NULL;

    while(curr){
    Node* temp = new Node(curr->val);
    mpp[curr] = temp;

    if(newHead == NULL){
    newHead = temp;
    prev = newHead;
    }
    else{
    prev->next = temp;
    prev = temp;
    }
    curr = curr->next;
    }
    curr = head;
    Node* newCurr = newHead;

    while(curr){
    if(curr->random == NULL){
    newCurr->random = NULL;
    }
    else{
    newCurr->random = mpp[curr->random];
    }
    curr = curr->next;
    newCurr = newCurr->next;
    }
    return newHead;
    }
};


// Time Complexity : O(N);

// Debatable space complexity with O(n) or O(1)
// Space Complexity : O(1);

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* curr = head;

        // Step 1 - Insert nodes between original nodes
        while (curr != NULL) {
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }

        // Step 2 - Set the random pointers of the new nodes
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3 - Restore the original list and extract the copied list
        curr = head;
        Node* newHead = head->next;
        Node* copy = newHead;

        while (curr != NULL) {
            curr->next = curr->next->next;
            if (copy->next != NULL) {
                copy->next = copy->next->next;
            }
            curr = curr->next;
            copy = copy->next;
        }

        return newHead;
    }
};

// Approach-1 : Recursive Approach -

// T.C=O(N), S.C=O(N) ~ it taking stack space

class Solution
{
    public:
    
    int helper(Node* temp){
        
    if(temp == NULL){
    return 1;
    }
    int carry = helper(temp->next);
    temp->data += carry;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1;
    }
    
    Node* addOne(Node *head) 
    {
     int carry = helper(head);
     if(carry == 1){
         
     Node* newNode = new Node(1);
     newNode->next = head;
     head = newNode;
     }
     return head;
    }
};


User
Srinath Kumar
66 minutes ago

Approach-1 : Recursive Approach - T.C=O(N), S.C=O(N) ~ it taking stack space
int helper(Node* temp){
        if(temp==NULL){
            return 1;
        }
        int carry=helper(temp->next);
        temp->data+=carry;
        if(temp->data<10) return 0;
        temp->data=0;
        return 1;
    }
 
 

// Approach-2 : T.C=O(3N), S.C=O(1)


class Solution
{
    Node* reverse(Node* head){
        
    if(head == NULL || head->next == NULL){
    return head;
    }
    Node* fast = head;
    Node* curr = head;
    Node* prev= NULL;
    
    while(curr){
        
    fast = curr->next;
    curr->next = prev;
    prev = curr;
    curr = fast;
    }
    return prev;
    }
    public:
    Node* addOne(Node *head) 
    {
    head = reverse(head);
    int carry = 1;
    
    Node* temp = head;
    while(temp != NULL){
       
    temp->data = temp->data + carry;
    
    if(temp->data < 10){
    carry = 0;
    break;
    }
    else{
        
    temp->data = 0;
    carry = 1;
    }
    temp = temp->next;
    }
    if(carry == 1){
    
    head = reverse(head);
    Node* newNode = new Node(1);
    newNode->next = head;
    return newNode;
    }
    head = reverse(head);
    return head;
    }
};
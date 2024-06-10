// Time Complexity: O(N) + O(N/2) == O(N).
// space Space: O(N).

// Approch - 1 using vector

class Solution{
  public:
    bool checkPalindrome(vector<int>arr){
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            if(arr[s]!=arr[e]){
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        Node* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->data);
            temp=temp->next;
        }
        return checkPalindrome(arr);
        
    }
};


// Time Complexity: O(N) + O(N) == O(N).
// space Space: O(1).

// Approch - 2 changing to integer

class Solution{
  public:
    bool isPalindrome(Node *head)
    {
    int n=0;
    Node*temp = head;
    
    while(temp != NULL){
    n = (n*10) + temp->data; 
    temp = temp->next;
    }
    int oldNum = n;
    int rem = 0;
    int newNum = 0;
    
    while(n){
    int rem = n%10;
    newNum = newNum*10 + rem;
    n = n/10;
    }
    return (newNum == oldNum);
    }
};


// Approch - 3 

// Time Complexity: O (2* N) The algorithm traverses the linked list twice, dividing it into halves. During the first traversal, it reverses one-half of the list, and during the second traversal, it compares the elements of both halves. As each traversal covers N/2 elements, the time complexity is calculated as O(N/2 + N/2 + N/2 + N/2), which simplifies to O(2N), ultimately representing O(N). 

// Space Complexity: O(1) 


class Solution{
  public:
  
      Node* reverseLinkedList(Node* head) {
        Node* prev = NULL;
        Node* current = head;
        Node* nextNode = NULL;
        
        while (current != NULL) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
      if(head == NULL || head->next == NULL){
      return true;
      } 
      Node*slow = head;
      Node*fast = head;
      
      while(fast != NULL && fast->next != NULL){
          
      slow = slow->next;
      fast = fast->next->next;
      }
      Node*reverse = reverseLinkedList(slow);
      
      Node*first = head;
      Node*second = reverse;
      
      while(second!=NULL){
          
      if(first->data != second->data){
      return false;
      break;
      }
      second = second->next;
      first = first->next;
      }
      return true;
    }
};
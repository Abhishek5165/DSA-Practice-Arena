stackPush(int x): O(1)
Pushing an element onto the stack is done in constant time as it only involves creating a new node and adjusting pointers.

stackPop(): O(1)
Popping an element from the stack is also done in constant time as it only involves removing the top element and adjusting the pointer.

stackSize(): O(1)
Accessing the size of the stack is done in constant time because the size is maintained as a variable.

stackIsEmpty(): O(1)
Checking if the stack is empty is done in constant time by checking if the top pointer is NULL.

stackPeek(): O(1)
Peeking the top element is done in constant time because it only requires accessing the data of the top node.

_+_> Space Complexity: O(n) for the entire stack, where n is the number of elements in the stack.


#include<iostream>
using namespace std;

struct stackNode {
  int data;
  stackNode * next;
  int size;
  stackNode(int d) {
    data = d;
    next = NULL;
  }
};
struct stack {
  stackNode * top;
  int size;
  stack() {
    top = NULL;
    size = 0;
  }
  void stackPush(int x) {
    stackNode * element = new stackNode(x);
    element -> next = top;
    top = element;
    cout << "Element pushed" << "\n";
    size++;
  }
  int stackPop() {
    if (top == NULL) {
      return -1;
    }
    int topData = top -> data;
    stackNode * temp = top;
    top = top -> next;
    delete temp;
    size--;
    return topData;
  }
  int stackSize() {
    return size;
  }
  bool stackIsEmpty() {
    return top == NULL;
  }
  int stackPeek() {
    if (top == NULL) return -1;
    return top -> data;
  }
  void printStack() {
    stackNode * current = top;
    while (current != NULL) {
      cout << current -> data << " ";
      current = current -> next;
    }
  }
};
int main() {
  stack s;
  s.stackPush(10);
  cout << "Element popped: " << s.stackPop() << "\n";
  cout << "Stack size: " << s.stackSize() << "\n";
  cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n";
  cout << "stack's top element: " << s.stackPeek() << "\n";
  return 0;
}
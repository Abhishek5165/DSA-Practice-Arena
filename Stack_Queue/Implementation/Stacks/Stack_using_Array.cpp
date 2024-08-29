### Time Complexity:
1. **Push Operation (`push(int x)`):  
   - Time complexity is (O(1)).  
   - Reason: It involves only incrementing the `top` and assigning the value to the array.

2. **Pop Operation (`pop()`):  
   - Time complexity is (O(1)).  
   - Reason: It involves only decrementing the `top` and returning the value.

3. **Top Operation (`Top()`):  
   - Time complexity is (O(1)).  
   - Reason: It simply returns the value at the current `top` index.

4. **Size Operation (`Size()`):  
   - Time complexity is (O(1)).  
   - Reason: It involves only returning the value of `top + 1`.

### Space Complexity:
- **Space complexity is (O(n))**, where n is the maximum size of the stack (in this case, 1000).  
- Reason: The space complexity is determined by the size of the array used to store the stack elements, which is directly proportional to the size of the stack.


#include<bits/stdc++.h>

using namespace std;
class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }
  void push(int x) {
    top++;
    arr[top] = x;
  }
  int pop() {
    int x = arr[top];
    top--;
    return x;
  }
  int Top() {
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
};
int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}
// time complexity : O(n*m);
// space complexity : O(n*m);

class Solution {
public: vector < vector < int >> spiralMatrix(int m, int n, 
ListNode * head) {

    int top = 0, down = m - 1;
    int left = 0, right = n - 1;

    int direction = 0;

    vector < vector < int >> ans(m, vector < int > (n, -1));

    if (head == nullptr) {
      return ans;
    }

    ListNode * temp = head;

    while (temp != NULL) {

    if (direction == 0) {

        for (int i = left; i <= right; i++) {
          ans[top][i] = temp -> val;
          temp = temp -> next;
          if (temp == NULL)
            break;
        }
        top++;
      } 
    else if (direction == 1) {
        for (int i = top; i <= down; i++) {
          ans[i][right] = temp -> val;
          temp = temp -> next;
          if (temp == NULL)
            break;
        }
        right--;
      }
    else if (direction == 2) {
        for (int i = right; i >= left; i--) {
          ans[down][i] = temp -> val;
          temp = temp -> next;
          if (temp == NULL)
            break;
        }
        down--;
      } 
    else if (direction == 3) {
        for (int i = down; i >= top; i--) {
          ans[i][left] = temp -> val;
          temp = temp -> next;
          if (temp == NULL)
            break;
        }
        left++;
    }
    direction++;
    if(direction > 3){
    direction = 0;
    }
    }
    return ans;
  }
};
// time complexity : O(n*m);
// space complexity : O(n*m);

// In this approach, we will be using four loops to print all four sides of the matrix.

// 1st loop: This will print the elements from left to right.

// 2nd loop: This will print the elements from top to bottom.

// 3rd loop: This will print the elements from right to left.

// 4th loop: This will print the elements from bottom to top.


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int direction = 0;
        vector<int> ans;

        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;

        while (top <= down && left <= right) {

            if (direction == 0) {
                for (int i = left; i <= right; i++) {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            if (direction == 1) {
                for (int i = top; i <= down; i++) {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            if (direction == 2) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            if (direction == 3) {
                for (int i = down; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            direction++;
            if (direction > 3) {
                direction = 0;
            }
        }
        return ans;
    }
};
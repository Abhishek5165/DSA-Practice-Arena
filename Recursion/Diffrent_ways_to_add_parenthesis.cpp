// Time Complexity : O(n * 2^n);
// Space Complexity : O(n);

class Solution {
public:
    vector<int> solve(string expression) {
        vector<int> result;
        int n = expression.size();
        bool flag = false;
        for (int i = 0; i < n; i++) {

            if (expression[i] == '+' || expression[i] == '-' ||
                expression[i] == '*') {
                flag = true;
                vector<int> Left = solve(expression.substr(0, i));
                vector<int> Right = solve(expression.substr(i + 1));

                for (int &x : Left) {
                    for (int &y : Right) {
                        if (expression[i] == '+') {
                            result.push_back(x + y);
                        } 
                        else if (expression[i] == '-') {
                            result.push_back(x - y);
                        } 
                        else if (expression[i] == '*') {
                            result.push_back(x * y);
                        }
                    }
                }
            }
        }
       if(!flag){
        result.push_back(stoi(expression));
       }
       return result;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
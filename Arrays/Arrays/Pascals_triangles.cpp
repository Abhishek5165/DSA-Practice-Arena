// Variation - 1  In this case, we are given the row number r and the column number c, and we need to find out the element at position (r,c). 

// Time Complexity: O(c), where c = given column number.
// Space Complexity : O(1);

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}


// Variation - 2  Given the row number n. Print the n-th row of Pascal’s triangle.

// Time Complexity: O(n*r), where n is the given row number, and r is the column index which can vary from 0 to n-1.
// Space Complexity: O(1)

// Approch - 1 for printing the last Row of the pascals triangle....

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}

// Approch - 2 for printing the last Row of the pascals triangle....

// Time Complexity: O(N) where N = given row number. 
// Space Cpmplexity : O(1)

#include <bits/stdc++.h>
using namespace std;

void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}


// Variation - 3 Given an integer numRows, return the complete Pascal's triangle.

class Solution {
public:
    vector<int> solve(int R) {
        int ans = 1;
        vector<int> temp;
        temp.push_back(ans);

        for (int col = 1; col < R; col++) {
            ans = ans * (R - col);
            ans = ans / col;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>>ans;
    for(int i=1;i<=numRows;i++){
    ans.push_back(solve(i));
    }
    return ans;
    }
};
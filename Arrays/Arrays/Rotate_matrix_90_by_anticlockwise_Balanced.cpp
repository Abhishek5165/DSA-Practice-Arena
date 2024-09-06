// // Brute Force ......

// Time Complexity : O(N*N);
// Space Complexity : O(N*N);

void rotate(int matrix[][3]) {
  int n = 3;

  //Creating new matrix to store rotated values
  int temp[n][n];

  int ind = n - 1;
  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {
      temp[i][j] = matrix[j][ind];
    }
    ind--;
  }



// Time Complexity : O(N*N);
// Space Complexity : O(1);

class Solution{
public:	
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	   
	for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
	int temp = arr[i][j];
	arr[i][j] = arr[j][i];
	arr[j][i] = temp;
	}
	}
	for(int j=0;j<n;j++){
	for(int i=0;i<n/2;i++){
	int temp = arr[i][j];
	arr[i][j] = arr[n-i-1][j];
	arr[n-i-1][j] = temp;
	}
	}
	}
};
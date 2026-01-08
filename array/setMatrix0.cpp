#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    public:
        void setZeros(vector<vector <int>> &matrix) {
            
            int m = matrix.size();
            
            int n = matrix[0].size();
            
            
            for (int i = 0 ; i < m ; i++) {
                for (int j = 0 ; j < n ; j++) {
                    if (matrix[i][j] == 0) {
                        for (int row = 0 ; row < m ; row++) {
                            if (matrix[row][j] != 0) {
                                matrix[row][j] = -1;
                            }
                        }
                        for (int col = 0 ; col < n ; col++) {
                            if (matrix[i][col] != 0) {
                                matrix[i][col] = -1;
                            }
                        }
                        
                    }
                }
            }
            
            for (int i = 0 ; i < m ; i++) {
                for (int j = 0 ; j < n ; j++) {
                    if (matrix[i][j]==-1) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
        void setZerosBetter(vector<vector <int>> &matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            
            vector <int> row(m,0);
            vector <int> col(n,0);
            
            for (int i = 0 ; i < m ; i++) {
                for (int j = 0 ; j < n ; j++) {
                    if (matrix[i][j] == 0) {
                        row[i] = 1;
                        col[j] = 1;
                    }
                }
            }
            
            for (int i = 0 ; i < m ; i++) {
                for (int j = 0 ; j < n;  j++) {
                    if (row[i] == 1 || col[j] == 1) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
        void setZerosOptimal(vector <vector <int>> & matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;

        // Step 1: Mark zeros
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;

                    if (j != 0) {
                        matrix[0][j] = 0;
                    }
                    else {
                        col0 = 0;
                    }
                }
            }
        }
        
        // Step 2: Set zeros based on markers (process from end to avoid conflicts)
        for (int i = m - 1; i >= 0; i--) {  // Bug fix 1: Go from end to start
            for (int j = n - 1; j >= 1; j--) {  // Bug fix 2: Start from n-1, not 1
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {  // Bug fix 3: Add == 0
                    matrix[i][j] = 0;  // Bug fix 4: Use =, not ==
                }
            }
            
            // Bug fix 5: Handle column 0 here
            if (col0 == 0) {
                matrix[i][0] = 0;
            }
        }
    
    
           
    }
    
};



int main() {
    
     // Example matrix
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    
    // Create Solution object
    Solution sol;
    // Call function to modify matrix
    sol.setZerosOptimal(matrix);
    
    // Print final matrix
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    
    
    
    
    return 0;
}





#include <bits/stdc++.h>
using namespace std;


// Method 1 
// Brute Force Method
// Traverse the matrix and if mat[i][j]==0
// mark ith row and jth column non-zero elements as -1
// then do this for all the rest zero elements

// Then outside this loop make a loop and mark
// rest of the -1 element as 0


// Method 2
// We are making loops to mark -1 the same elements 
// Maintain a n size rowArray and m size columnArray  // initialized with zero
// Travese the complete matrix and if mat[i][j] == 0
// Mark rowAraay[i] as 1 and columnArray[j] = 1
// After that traverese the matrix again anf if (rowARRAY[i] == 1 || colArray[j] == 1) ==> mark zero


// Method 3 (Optimized)
// Instead of maintain seprate rowArray and ColArray we will maintain 
// 0th Row --> Row Array and 0th Col --> Column Array
// Now they collide at [0,0] position
// To solve this use a seperate variable for colArray 0th Position


// TRaverse the matrix if mat[i][j]==0
// mark (0th row) mat[0][j]==0 && (0th col) mat[i][0]==0

// After this traverse from last 
// (because if traversed from start then it may change value of 0th row and Col)
// ANd mark zero if (0thROw[i] == 0 || 0thCol[j] == 0) ==> mark zero

// Out of 0thRow and 0thCol mark 0thRow first then 0thCol


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int col0 = 1;

        //Step 1 Marking
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    if(j==0) {
                        col0 = 0;
                    }
                    else mat[0][j] = 0;
                    mat[i][0] = 0;  //ROW
                }
            }
        }

        //Step2 Marking except oth row and 0th col
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[0][j]==0 || mat[i][0]==0) mat[i][j]=0;
            }
        }

        //Step 3 Marking 0th Row
        if(mat[0][0] == 0){
            for(int i = 0 ; i < m ; i++) mat[0][i] = 0;
        }

        //Step 4 Marking 0th Col
        if(col0 == 0){
            for(int i = 0 ; i < n ; i++) mat[i][0] = 0;
        }
        
    }
};
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:

    // Transpose the matrix
    // Then Reverse each Columns (Row for Clockwise)
    
    void rotateby90(vector<vector<int>>& mat) {
        // m x n matrix
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }

        // Reverse each column
        for(int i = 0;i<n;i++){
            int tp = 0;
            int btm = n-1;
            while(tp <= btm){
                swap(mat[tp][i],mat[btm][i]);
                tp++;
                btm--;
            }
        }
    }
};
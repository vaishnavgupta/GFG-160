#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // First Find which is the possible starting row of the matrix
    // Traverse 0th ele of each row and find just large ele row
    // And then apply BS on previous row
    // See Coding Implementation


    // More Optimization --> In Row Detection Phase Use Binary Search

    
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        //finding row
        int rowIdx = -1;
        for(int i = 0;i<n;i++){
            if(mat[i][0] > x) {
                rowIdx = i;
                break;
            }
        }
        if(rowIdx == 0) return false;   // x smaller than mat[0][0]
        int searchRow;
        if(rowIdx == -1) {
            searchRow = n-1; // Last Row 
        }
        else searchRow = rowIdx - 1;

        // BS on search Row
        int lo = 0;
        int hi = m-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(mat[searchRow][mid] == x) return true;
            else if(mat[searchRow][mid] > x) {
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return false;
    }
};
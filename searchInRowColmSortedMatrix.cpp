#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Both row and column are sorted 
// Start From top right corner
// If x is big MOVE DOWN 
// Otherwise move MOVE LEFT 


class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size(); 
        int m = mat[0].size();
        int i = 0;
        int j = m-1; // Top Right Corner

        while(i<n && j<m){
            if(mat[i][j] == x){
                return true;
            }
            else if(mat[i][j] > x){
                //Move Left
                j--;
            }
            else{
                //Move Right
                i++;
            }
        }
        return false;
    }
};
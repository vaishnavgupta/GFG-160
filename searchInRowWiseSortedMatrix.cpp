#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Method 
    // Each Row is sorted
    // Means we can apply BS on each row
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            int lo=0;
            int hi=m-1;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(mat[i][mid] == x) return true;
                else if(mat[i][mid] > x) {
                    hi = mid - 1;
                }
                else lo = mid + 1;
            } 
        }
        return false;
    }
};
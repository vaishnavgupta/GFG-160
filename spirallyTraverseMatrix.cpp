//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:

    // Maintain four variables minr,minc,maxr,maxc
    // Traverse from L -> D -> R -> T
    // Simply apply conditions and after each loop 
    // update the values of variables
    // Check condition after each loop
    
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        int n = mat.size();     // n x m
        int m = mat[0].size();
        int minr = 0;
        int minc = 0;
        int maxr = n-1;
        int maxc = m-1;
        vector<int> ans;

       
        while(minr <= maxr && minc <= maxc){
            // Right
            for(int i = minc ; i<=maxc ; i++){
                ans.push_back(mat[minr][i]);
            }
            minr++;
            if(minr>maxr || minc>maxc) break;
            // Down
            for(int i = minr ; i<=maxr ; i++){
                ans.push_back(mat[i][maxc]);
            }
            maxc--;
            if(minr>maxr || minc>maxc) break;
            // Left
            for(int i = maxc ; i>=minc ; i--){
                ans.push_back(mat[maxr][i]);
            }
            maxr--;
            if(minr>maxr || minc>maxc) break;
            // Up
            for(int i = maxr ; i>=minr ; i--){
                ans.push_back(mat[i][minc]);
            }
            minc++;
        }
        return ans;
        
    }
};

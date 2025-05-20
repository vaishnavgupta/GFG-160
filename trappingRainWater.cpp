//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Formula of water at any idx
// total += min(leftMax,rightMax) - arr[i]

// M1 --> Using pge and nge arrays
// TC-O(n) & SC-O(n)
// find pge and nge arrays
// form third array curr which contains min of both
// if curr[k]>arr[k] add curr[k]-arr[k] in ans

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int wtr=0;
        int n = arr.size();
        vector<int> pge(n);
        pge[0]=-1;
        int mx = arr[0];
        for(int i=1;i<n;i++){
            pge[i] = mx;
            mx = max(mx,arr[i]);
        }
        vector<int> nge(n);
        pge[n-1]=-1;
        mx = arr[n-1];
        for(int i=n-2;i>=0;i--){
            nge[i] = mx;
            mx = max(mx,arr[i]);
        }
        vector<int> crr(n);
        crr[n-1]=-1;
        crr[0]=-1;
        for(int i=1;i<n-1;i++){
            crr[i] = min(nge[i],pge[i]);
        }
        for(int k=1;k<n-1;k++){
            if(crr[k]>arr[k]){
                wtr += crr[k]-arr[k];
            }
        }
        return wtr;
    }

    // Two Pointer l and r
    // Maintain lmax and rmax also
    // Always traverse the **SMALLER ONE**
    // traverse it and add lmax-arr[l] in case of left if lmax>arr[l]
    // similar for right

    int maxWater(vector<int> &arr) {
        int wtr=0;
        int n = arr.size();
        int l=0;
        int r=n-1;
        int lmax=0;
        int rmax=0;
        while(l<r){
            if(arr[l]<=arr[r]){ //traverse left(smaller)
                if(lmax>arr[l]){
                    //can have ans
                    wtr += lmax-arr[l];
                }
                else{
                    lmax = max(lmax,arr[l]);
                }
                l=l+1;
            }
            else { //traverse right(smaller)
                if(rmax>arr[r]){
                    //can have ans
                    wtr += rmax-arr[r];
                }
                else{
                    rmax = max(rmax,arr[r]);
                }
                r=r-1;
            }
            
        }
        return wtr;
    }
};
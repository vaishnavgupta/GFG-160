//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:

    // No of Missing at any idx = arr[i] - (i+1) 
    // if k> noOfMissing move RIGHT
    // else move left
    // When BS ends lo gives the upped bound
    // Means upto lo-1 elements are already traversed
    // We must have problem after or from lo
    // Therfore ans = lo+k


    int kthMissing(vector<int> &arr, int k) {
        int lo = 0;
        int hi = arr.size() - 1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int missing = arr[mid] - (mid+1);
            if(missing<k) lo = mid+1;
            else hi=mid-1;
        }
        return lo + k;

        /*
        ✅ Up to index lo - 1, there are fewer than k missing numbers.
        ✅ At index lo, the missing numbers become at least k.
        ✅ So, the kth missing positive number = k + lo.
        */
    }
};
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int peakElement(vector<int> &arr) {
        //  Check for length 1 and first element and last element
        //  if next ele is big see right
        //  if prev ele is big see left
        int n = arr.size();
        
        if(n == 1) return 0;

        if(arr[0]>arr[1]) return 0;

        if(arr[n-1]>arr[n-2]) return n-1;

        int lo = 1;
        int hi = n-2;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;

            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
                return mid;
            }
            else if(arr[mid] < arr[mid+1]){
                lo=mid+1;
            }
            else {
                hi=mid-1;
            }
        }
        return -1;
    }
};
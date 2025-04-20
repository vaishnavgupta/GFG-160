#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // Sorted Array
    // Find target in arr (binarySearch)
    // Make a prv and nxt variable and traverse until 
    // target is found
    // and increase the count
    
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int lo = 0;
        int hi = n-1;
        int mid = -1;
        bool found = false;
        while(lo <= hi){
            mid = (lo+hi)/2;
            if(arr[mid] == target){
                found = true;
                break;
            }
            else if(arr[mid] > target){
                hi = mid - 1;
            }
            else{
                lo = mid +1;
            }
        }
        if(found == false) return 0;
        int count = 1;
        int prev = mid-1;
        int nxt = mid+1;
        //Traversing after mid
        while(nxt<n && arr[nxt] == target){
            count++;
            nxt++;
        }
        //Traversing before mid
        while(prev>=0 && arr[prev] == target){
            count++;
            prev--;
        }
        return count;    
    }
};
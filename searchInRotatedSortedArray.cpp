#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    // As we know binary search divides array into two sorted halfs
    // We check if it is left or right sorted array
    // Then change lo and hi accordingly
    int search(vector<int>& arr, int key) {
       int n = arr.size();
       int lo = 0;
       int hi = n-1;
       bool found = false;
       while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(arr[mid] == key) {
                found = true;
                return mid;
            }
            //left part is sorted
            else if(arr[lo] <= arr[mid]){
                //Check if it exist there
                if(arr[lo] <= key && arr[mid] >= key) hi=mid-1;
                else lo=mid+1;  //not exist
            }
            else{
                //Rest Case
                if(arr[hi] >= key && arr[mid] <= key) lo=mid+1;
                else hi=mid-1;  //not exist
            }
        }
        return -1;
       }
    }
};

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:

    // Sorted Array --> Think About BS
    // In BS the array gets divided into two halfs
    // lo...mid && mid...hi
    // Now every time we check each half
    // And if it is sorted we compare its minimum element
    // And after that we will skip this half

    int findMin(vector<int>& arr) {
        int n = arr.size();
        int lo = 0;
        int hi = n-1;
        int mini = INT_MAX;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;

            //Check if left part is sorted
            if(arr[lo] <= arr[mid]){
                mini = min(mini,arr[lo]);
                lo = mid+1; //Skipping that part
            }
            //else right part is sorted
            else{
                mini = min(mini,arr[hi]);
                hi = mid-1; //Skipping that part
            }
        }
        return mini;
    }

    int findMinTwo(vector<int>& nums) {
        return *min_element(nums.begin(),nums.end());
    }
};
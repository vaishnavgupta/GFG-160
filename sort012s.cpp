//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  // DUTCH Flag Algorithm
  // Imp --> for 2 and 1 only change hi and mid respectively
  // but for 1 change lo and hi both
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int lo=0;
        int mid=0;
        int hi=n-1;

        while(mid<=hi){  //bcoz when lo increases mid also increase so only check mid and hi
            if(arr[mid] == 2){
                swap(arr[mid],arr[hi]);
                hi--;
            }
            else if(arr[mid] == 0){
                swap(arr[mid],arr[lo]);
                lo++;
                mid++; //Both Conditions
            }
            else{
                mid++;
            }
        }
    }
};

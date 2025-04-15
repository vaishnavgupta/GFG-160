//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// Two Pointer
// One Pointer j keeps track where the non zero element should be placed
// Other Pointer i traverses the array and finds any non zero element and swap it

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int j = 0;
        for(int i=0;i<n;i++){
            if(arr[i] != 0){
                swap(arr[j],arr[i]);
                j++;
            }
        }
    
    }
};
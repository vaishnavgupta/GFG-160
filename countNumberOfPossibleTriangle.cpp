#include <bits/stdc++.h>
using namespace std;

// Here we need to check the inequality
// Sort the array (why? --> we ONLY need to check arr[i]+arr[j]>arr[k] rest all automatically satisfied)
// Two Pointer Approach
// i=0; j=k-1
// check each formed pair if NO --> i++
// if YES --> REST all also works add j-i and do j--;

// TC --> O(n2) + O(nLogn) ==> O(n2)

class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int cnt=0;
        for(int k=n-1;k>=2;k--){
            int i=0;
            int j=k-1;
            while(i<j){
                if(arr[i]+arr[j] > arr[k]){
                    //Yes
                    cnt += (j-i);
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return cnt;
    }
};
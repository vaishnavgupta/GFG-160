#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:

    // Undferstand Problem Statement First
    // Here We know the range of possible answer
    // That is from 1 .... max(arr) - min(arr)
    // Hence think of BS on Answer
    // Make lo = 1 and hi = max(arr) - min(arr)
    // Find mid and then use a helper function to 
    // Sort the stalls array to apply greedy approch in helper func
    // check IF IT IS POSSIBLE that minDist can be mid
    // if Yes --> See if larger are possible lo=mid+1
    // if No --> See if lower are possible hi=mid-1 

    bool helper(vector<int> &stalls, int k,int mid){
        int prevCowIdx = 0;
        int cnt = 1;
        for(int i=1;i<stalls.size();i++){
            if(stalls[i] - stalls[prevCowIdx] >= mid){
                cnt++;
                prevCowIdx=i;
            }
            if(cnt==k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        int n = stalls.size();
        int ans = -1;
        sort(stalls.begin(),stalls.end());
        int lo=1;
        int hi=stalls[n-1] - stalls[0];
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            bool status = helper(stalls,k,mid);
            if(status){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;

    }
};
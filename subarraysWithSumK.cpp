#include <bits/stdc++.h>
using namespace std;

// if prefix sum + arr[i] is x at a particular index
// then find how many " x-k " are present 
// this will be equal to subarray with sum 

// T.C O(N + LOG N)  //FOR MAP
// SC O(N)

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        int n=arr.size();
        map<int,int> mp;
        int count=0;
        int preSum=0;
        mp[0]=1; // if arr[i]==k then req will be 0
                 // then to count this we put (0,1)
                 // in map                    
        for(int i=0;i<n;i++){
            
            preSum+=arr[i];
            int req=preSum-k;
            if(mp.find(req)!=mp.end()){
                count+=mp[req];
            }
            mp[preSum]++;
        }
        return count;
        
    }
};
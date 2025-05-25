#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Simialar to previous day question
    // longestSubarrayWithSumK
    // Treat 0 as -1 and the question changes to longest subaaray with sum 0

    int maxLen(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int preSum = 0;
        int mx = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == 0) arr[i] = -1;
            preSum += arr[i];
            if(preSum == 0){
                mx = max(mx,i+1);
            }
            if(mp.find(preSum) != mp.end()){
                int v = mp[preSum];
                mx = max(mx,i-v);
            }
            if(mp.find(preSum) == mp.end()){
                mp[preSum] = i;
            }
        }
        return mx;
    }
};
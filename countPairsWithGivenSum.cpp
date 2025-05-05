#include <bits/stdc++.h>
using namespace std;


// Here we use hash map to store count of different elements
// Also we use a set to store the pairs of idx of elements
// THis will help to avoid repetation of pairs
// And then return the size of the set

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        unordered_map<int,int> mp;
        set<pair<int,int>> st;

        for(int i=0;i<n;i++){
            int req = target - arr[i];
            if(mp[req] > 0){
                st.insert({min(arr[i],req),max(arr[i],req)});
            }
            mp[arr[i]]++;
        }
        return st.size();
        
    }
};
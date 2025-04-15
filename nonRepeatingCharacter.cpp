//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:

    //Hash map
    char nonRepeatingChar(string &s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[s[i]]++;
        }
        for(int i = 0 ; i < n ; i++){
            auto it = mp.find(s[i]);
            if(it->second == 1) return s[i];
        }
        return '$';
    }
};
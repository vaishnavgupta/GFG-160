#include <bits/stdc++.h>
using namespace std;


// First set i and j after k steps
// Then after setting then traverse a while loop j<n
// Then at each window remove arr[i] from set then i++ j++ 
// and then insert arr[j] in set

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int i=0;
        int j=k-1;
        int n = arr.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int l=0;l<k-1;l++) {
            mp[arr[l]]++;
        }
        while(j<n){
            mp[arr[j]]++;
            ans.push_back(mp.size());
            //Removing i from map
            if(mp[arr[i]] == 1){
                mp.erase(arr[i]);
            }
            else mp[arr[i]]--;
            j++;
            i++;
        }
        return ans;
    }
};
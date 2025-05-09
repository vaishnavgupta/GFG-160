#include <bits/stdc++.h>
using namespace std;

//  Store value and vector<int> to store index in a map
//  then we use two loops to traverse 
//  and third ele is -1 * arr[i]+arr[j]
//  search in map if it exist
//  also take care that its index is greater then i and j

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        unordered_map<int,vector<int>> mp;
        int n = arr.size();
        vector<vector<int>> ans;
        //Storing in map
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        //Search in map
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int req = -1 * (arr[i]+arr[j]);
                if(mp.find(req)!=mp.end()){
                    vector<int> vec = mp[req];
                    for(int k = vec.size()-1;k>=0;k--){
                        if(vec[k] <= j) break;  //All are smaller then j SKIP
                        ans.push_back({i,j,vec[k]});   // Otherwise push all possible k ele pairs
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
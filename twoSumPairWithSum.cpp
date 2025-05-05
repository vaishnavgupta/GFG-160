//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:

    // Method
    // Using hash map to store the elements
    // And then traverse the array and search for target-arr[i]
    // If exist return true otherwise false
    
    bool twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int> mp;
        // Storing in map
        for(int i=0;i<n;i++){
            mp[arr[i]] = i ;
        }
        // Searching in arr and in map
        for(int i=0;i<n;i++){
            int req = target - arr[i];
            if(mp.find(req) != mp.end()){
                int idx = mp[req];
                if(idx!=i) return true;
            }
        }
        return false;
    }


    // More Correct 
    // Storing and Searching in one loop
    // This helps in dealing with duplicate or similar elements

    bool twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int> mp;
        // Storing & Searching in map
        for(int i=0;i<n;i++){
            int req = target - arr[i];
            if(mp.find(req) !=  mp.end()){
                return true;
            }
            mp[arr[i]] = i ;
        }
        
        return false;
    }

};
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// Storing in map <string,vector<string>> for each sorted string as key
// Then search in the map and then append in ans vector


// This code may not preserve the correct order

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string,vector<string>> mp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            string curr = arr[i];
            sort(curr.begin(),curr.end());
            mp[curr].push_back(arr[i]);
        }
        //pushing in ans vector
        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }

    // Fixed --> Maintain correct order

    // Maintain an auxillary vector that preserves the order

    vector<vector<string>> anagramsCorrect(vector<string>& arr) {
        unordered_map<string,vector<string>> mp;
        
        vector<string> order;

        int n = arr.size();
        for(int i=0;i<n;i++){
            string curr = arr[i];
            sort(curr.begin(),curr.end());

            if(mp.find(curr) == mp.end()){  //Not in map yet
                order.push_back(curr);
            }

            mp[curr].push_back(arr[i]);
        }
        //pushing in ans vector
        vector<vector<string>> ans;
        for(auto it : order){     //   Traversing a/q to order vector to maintain order
            ans.push_back(mp[it]);
        }
        return ans;
    }

};
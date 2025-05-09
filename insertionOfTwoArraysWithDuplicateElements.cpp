#include <bits/stdc++.h>
using namespace std;


// Store elements of both arrays in set 
// Then travese the set and then push in ans vector
// that are common in both sets


class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> ans;
        set<int> stA;
        set<int> stB;
        for(int i=0;i<n;i++){
          stA.insert(a[i]);
        }
        for(int i=0;i<m;i++){
          stB.insert(b[i]);
        }
        for(auto it : stA){
          if(stB.find(it) != stB.end()) ans.push_back(it);
        }
        return ans;
    }
};
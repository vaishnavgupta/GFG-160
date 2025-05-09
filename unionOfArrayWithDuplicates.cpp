#include <bits/stdc++.h>
using namespace std;


// Storing elements of both the array in one set
// Then return the size of this set

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        set<int> st;
        for(int i=0;i<n;i++){
          st.insert(a[i]);
        }
        for(int i=0;i<m;i++){
          st.insert(b[i]);
        }
        
        return st.size();
        
    }
};
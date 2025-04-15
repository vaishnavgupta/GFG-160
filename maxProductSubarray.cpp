// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

// Observation
// There are 4 cases 1- All +ve , 2- Even -ve , 3- Odd -ve , 4 - Zeros
// All +ve and Even -ve will give full subarray as answer
// But odd -ve and zeros case are handled carefully

// for odd -ve remove that -ve that is decreasing the product more considering its shape also
// for 0 remove carefully

// Solution
// Calculate prefix and suffix product of array
// ans = max(ans, max(prefix,suffix))

// calculte both in one loop

class Solution {
    public:
      // Function to find maximum product subarray
      int maxProduct(vector<int> &arr) {
          int n = arr.size();
          int pre = 1;
          int suff = 1;
          int ans = INT_MIN;

          for(int i = 0 ; i < n ; ++i){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre = pre * arr[i];
            suff = suff * arr[n-i-1];

            ans = max( ans , max(suff,pre));
          }
          return ans;
      }
  };
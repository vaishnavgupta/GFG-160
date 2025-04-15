#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int minDiff = arr[n-1] - arr[0];
        for(int i=1;i<n;i++){
            if( (arr[i] - k) < 0) continue;
            minDiff = min(minDiff, (max( arr[n-1]-k , arr[i-1]+k ) - min( arr[0]+k , arr[i]-k )) );
        }
        return minDiff;
    }
};
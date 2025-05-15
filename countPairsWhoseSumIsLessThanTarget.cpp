#include <bits/stdc++.h>
using namespace std;


// First sort the array
// Then initialize i at beginning and j at the last
// then check i and j from last
// if big than target do j--
// if small then target add j-i to the result
// do till i<j

// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int i=0;
        int j=n-1;
        int cnt=0;
        while(i<j){
            int sum = arr[i] + arr[j];
            if(sum>=target) j--;
            else{  //sum<target
                cnt += j-i;
                i++;
            } 
        }
        return cnt;
    }
};
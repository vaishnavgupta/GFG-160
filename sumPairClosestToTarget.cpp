#include <bits/stdc++.h>
using namespace std;


// SOrt the array
// if big than target j--
// if small than target i++
// And after every time try updating the ans vector

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        if(n<2) return {};
        sort(arr.begin(),arr.end());
        int i = 0;
        int j = n-1;
        vector<int> ans;
        int minDiff = INT_MAX;
        
        while(i<j){
            int sum = arr[i] + arr[j];
            int diff = abs(sum - target);

            if (diff < minDiff) {   //close to target
                minDiff = diff;
                ans = {arr[i], arr[j]};
         } 
            else if (diff == minDiff) {
                // Check for maximum absolute difference between a and b
                if ((arr[j] - arr[i]) > (ans[1] - ans[0])) {
                    ans = {arr[i], arr[j]};
                }
            }
            if(sum>=target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
        
    }
};
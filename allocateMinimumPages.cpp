

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

  // BS On Answer
  // Start from maxEle (bcoz someone must take max ele) to SumOfArr
  // Find mid each time and with the help of helper function
  // if it is possible or not
  // If Possible store in ans and hi=mid-1;
  // Otherwise lo = mid + 1;

    bool helper(vector<int>& arr, int k,int mid){
        int cnt = 1;
        int currSum = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid) return false;   //one book>mid NOT POSSIBLE
            if(currSum + arr[i] > mid) {
                //to next
                cnt++;
                currSum = arr[i];

                if(cnt > k){
                    return false;   // Books Left but count is more
                }
            }
            else{
                // Add to currStud
                currSum+=arr[i]; 
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        if(k > arr.size()) return -1;
        int mxEle = *max_element(arr.begin(),arr.end());
        int lo = mxEle;
        int hi = accumulate(arr.begin(),arr.end(),0);
        int ans = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(helper(arr,k,mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};
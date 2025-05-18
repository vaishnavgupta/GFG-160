//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// Sliding Window Approach
// Add arr[i] to sum
// if sum is small then target then continue adding(ignore this case)
// else mark end to i and subtract till we got sum less than target

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int sum =0 ;
        int s=0;
        int e=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            //if(sum<target) ignore
            if(sum>=target){
                e = i;
                while(sum>target){
                    sum = sum-arr[s];
                    s++;
                }
                if(sum == target){
                    return {s+1,e+1}; //ans mark
                }
            }
        }
        return {-1};
    }
};
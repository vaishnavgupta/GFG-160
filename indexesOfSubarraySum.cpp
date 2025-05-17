//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// Apply 2 pointer approach
// Move i and j a/q to which makes it more near

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int i=0;
        int j=n-1;
        vector<int> sumUpto(n);
        int s=0;
        //forming sum upto array
        for(int i=0;i<n;i++){
            s+=arr[i];
            sumUpto[i]=s;
        }
        while(i<=j){
            int sum = sumUpto[j];
            if(i!=0){
                sum = sumUpto[j] - sumUpto[i-1];
            }
            if(sum==target){
                return {i+1,j+1};
            }
            else if(sum<target){
                return {-1};
            }
            else{
                int cmpJ = sum-arr[j];
                int cmpI = sum-arr[i];
                if(cmpJ-target <= cmpI-target){
                    j--;
                }else{
                    i++;
                }
            }
        }
        return {-1};
    }
};
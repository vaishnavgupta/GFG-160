#include<bits/stdc++.h>
using namespace std;

// Method 1 Using preProduct and suffProduct Arrays
// Handle edge cases
// TC-O(N) SC-0(N)

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> preProduct(n);
        int preP = 1;
        int suffP = 1;
        vector<int> suffProduct(n);

        for(int i=0;i<n;i++){
            preP = preP * arr[i];
            preProduct[i] = preP;
            suffP = suffP * arr[n-i-1];
            suffProduct[i] = suffP;
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(i==0){
                res[i] = suffProduct[i+1];
            }
            else if(i==n-1){
                res[i] = preProduct[i-1];
            }
            else{
                res[i] = preProduct[i-1] * suffProduct[i+1];
            }
        }

        return res;
    }

    // Method 2
    // There are two possiblle cases 
    // contains zero or not contains zero
    // if has one zero find its index (multiple zeros ==> all are 0)
    // if not have zero product/arr[i]
    // TC-O(N) SC-0(1)


    vector<int> productExceptSelfOptimized(vector<int>& arr) {
        int n = arr.size();
        int prod=1;
        int zeros=0;
        int zeroIdx = -1;

        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zeros++;
                zeroIdx = i;
            }
            else prod *= arr[i];
        }

        vector<int> res(n,0);

        if(zeros==0){
            for(int i=0;i<n;i++) res[i] = prod / arr[i];
        }
        //if one zero ==> all ele zero except arr[zeroIdx]
        else if(zeros==1){
            res[zeroIdx] = prod;
        }
        //if multiple zero ==> all zero (#Already in res#)
        return res;
    }
};
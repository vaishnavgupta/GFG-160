//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Approach
// Try for different values of i
// Means for a particular value of i apply two pointer approach
// Accordingly update the conditions
// When sum==target then check for pairs that can be formed using same elements (Simply check for duplicates)
// dry run case 1 2 2 2 3 4 target=7


class Solution {
  public:


    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0;i<n-2;i++){
            int left = i+1;
            int right = n-1;
            while(left < right){
                int sum = arr[i]+arr[left]+arr[right];
                if(sum < target) left++;
                else if(sum > target) right--;
                else{  //sum==target
                    cnt++;
                    //check for duplicates
                    int temp = left+1;
                    while(temp<right && arr[temp] == arr[temp-1]){
                        cnt++;
                        temp++;
                    }
                    right--; 
                }
            }
        } 
        return cnt;
    }
};
#include <bits/stdc++.h>
using namespace std;

// Sum all the elements of array
// At any time sum becomes -ve restore sum to 0
// Bonus - We can also find max sum subarray by pushing all the 
// elements and at any time it become -ve clear the vector
// also when you update the maxSum update maxVector also

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int maxSum = INT_MIN;
        int currSum = 0;
        for(int i=0;i<n;i++){
            currSum += arr[i];
            if(currSum < 0) currSum = 0;
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }

    // Preffered

    int maxSubarraySumPreffered(vector<int> &arr) {
        int n = arr.size();
        int currSum = arr[0];
        int maxSum = arr[0];
        for(int i = 1 ; i < n ; i++){
            currSum = max(arr[i],arr[i]+currSum);
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }

    /*


    //Kandane for minSumLinear
    currSum = arr[0];
    minSumLinear = arr[0];
    for(int i = 1 ; i < n ; ++i){
        currSum = min(arr[i], currSum + arr[i]);
        minSumLinear = min(minSumLinear, currSum);
    }

    */
};
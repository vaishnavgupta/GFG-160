#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:

  // M1 -> Brute Force
  // 1- Find maxSumSubarray by Kandane Algo
  // 2- Rotate the array by one step and the again find maxSumSubarray by kandane Algo
  // 3- Repeat until initail array gets obtained



  // M2 -> Optimal Approach
  // 1- There are two cases
  // First --> ans is normal maxSumSubarray
  // Second --> ans is circular maxSumSubarray

  // by obserwation we can proof that if circular array is maxSumSubarray (let sum S1) then remaining part 
  // is minSumSubarray(let sum S2)

  // Now S(total sum) = S1 + S2
  // By this we can easily find S1 if we find S2 (by Kandane)
  // See image in .md file

  // Corner case {-1,-1,-1}
    
  int maxSubarraySumCircular(vector<int>& arr) {
    int n = arr.size();
    int maxSumLinear;
    int minSumLinear;
    int maxSumCircular;
    int totalSum = 0;

    totalSum = accumulate(arr.begin(),arr.end(),0);

    //Kandane for maxSumLinear
    int currSum = arr[0];
    maxSumLinear = arr[0];
    for(int i = 1 ; i < n ; ++i){
        currSum = max(arr[i],arr[i]+currSum);
        maxSumLinear = max(maxSumLinear,currSum);
    }

    //Kandane for minSumLinear
    currSum = arr[0];
    minSumLinear = arr[0];
    for(int i = 1 ; i < n ; ++i){
        currSum = min(arr[i], currSum + arr[i]);
        minSumLinear = min(minSumLinear, currSum);
    }

    maxSumCircular = totalSum - minSumLinear;

    // Corner Case {-1,-1,-1}
    if (maxSumLinear >= 0){
        return max(maxSumLinear,maxSumCircular);
    }
    return maxSumLinear;
}
};
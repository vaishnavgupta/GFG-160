#include<bits/stdc++.h>
using namespace std;

class Solution {

    // We need to find only one pair of two lines which 
    // can hold maximum amount of water
    // the amt of water which can hold b/w two lines
    // is width * min(arr[i],arr[j])
    // This width would be max when we consider first and last element
    // ====>>> Hint of Two Pointer Approach

    // place i at 0 and j at n-1
    // calculate amount of water they can hold
    // and update max
    // always move small element **imp**
    // why small because we are in a hope that
    // we can get a larger element

    // TC- O(n)  SC - O(1)

  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int mxWater = 0;
        
        if(n==1) return 0;  //edge case

        int i=0;
        int j=n-1;
        while(i<j){
            int wtr = (j-i) * min(arr[i],arr[j]);
            mxWater = max(mxWater,wtr);

            if(arr[i]>arr[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return mxWater;
    }
};
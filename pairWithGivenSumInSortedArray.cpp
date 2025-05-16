#include <bits/stdc++.h>
using namespace std;


// Two Pointer Approach
// if sum is equal --> cnt++ & check karo kitne equal hai aur uske baad i++ par j fiix rahega
// else i++ (when need big ele) j--(need small ele)


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int cnt = 0;
        int i = 0;
        int j = n-1;
        while(i<j){
            if(arr[i]+arr[j]==target){
                cnt++;
                int currIdx = j-1;  //for duplicate ele
                while(currIdx>i && arr[currIdx]==arr[j]){
                    cnt++;
                    currIdx--;
                } 
                i++;
            }
            else if(arr[i]+arr[j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return cnt;
    }
};
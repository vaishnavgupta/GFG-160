#include <bits/stdc++.h>
using namespace std;

// Solution
// 1- Sort
// 2- count = 0;
// 3- negative continue else check it
// 4- return count+1


class Solution {
  public:
    // Function to find the smallest positive number missing from the array.

    // O ( n LOG N ) Approach

    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int count = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] > 0){
                if(i>0 && arr[i]==arr[i-1]) continue;
                if(arr[i] != count+1) break;
                else count++;
            }
        }
        return count+1;
    }

    // O (n) AND O(1) Approach Optimal

    // Consider like a chair game where chairs from 1 to n are placed
    // And we have to put element at its correct chair
    // We do this by swaping the elements until there correct position comes
    // Note - We only swap elements when they are in range from 1 to n 
    // otherwise error will come

    int missingNumberOptimal(vector<int> &arr) {
        int n = arr.size();
        for(int i = 0;i<n;i++){
            int ele = arr[i];
            int chair = ele - 1;
            //check if in range
            if(ele>=1 && ele<=n){
                if(arr[chair] != ele ){
                    swap(arr[chair],arr[i]);
                    i--;   // to again check the element if it has correct chair or not
                }
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i] != i+1) return i+1;
        }
        return n+1;  //case when all array ele are present 
    }

};
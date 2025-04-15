
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to find hIndex

    int hIndexLeetCode(vector<int>& citations) {
        int n = citations.size();
        //creting a array of n+1 size to store count
        vector<int> arr(n+1,0);
        for(int i=0;i<n;i++){
            if(citations[i] > n){
                arr[n]++;
            }
            else{
                arr[citations[i]]++;
            }
        }
        //checking which can be the ans
        int count=0;  //keep track of previous as well
        for(int j=n ; j>=0 ; j--){
            count = count + arr[j];
            if(count >= j){
                return j;
            }
        }
        return -1;
    }
    int hIndex(vector<int>& citations) {
        
    }
};
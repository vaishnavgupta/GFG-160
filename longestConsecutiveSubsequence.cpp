#include <bits/stdc++.h>

using namespace std;




class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mx = 1;
        int cnt = 1;
        for(int i=1;i<arr.size();i++){

            //Duplicates
            if (arr[i] == arr[i-1]) continue;
          	
            //Consecutive
            if(arr[i] == arr[i-1]+1) cnt++;
            else cnt=1;

            mx = max(mx,cnt);
        }
        return mx;
    }

    // Expected --> Hash Set
    // Using set to store all the elements 
    // Then traverse the array and then search in set if it is
    // the starting sequence of a subsequence
    // if yes we will search in set how many such elements exist

    int longestConsecutiveInSet(vector<int>& arr) {
        int n = arr.size();
        int mx = 0;
        unordered_set<int> st;  // makes TC --> O(n)
        for(int i=0;i<arr.size();i++){
            st.insert(arr[i]);
        }
        for(int i=0;i<n;i++){
            // currEle is starting ele of subsequence
            if(st.find(arr[i]) != st.end() && st.find(arr[i]-1) == st.end()){
                int curr = arr[i];
                int cnt = 0;
                while(st.find(curr) != st.end()){
                    //Remove to avoid recalculation
                    st.erase(curr);                     //CHANGE
                    cnt++;
                    curr++;
                    
                }
                mx = max(cnt,mx);
            }
        }
        return mx;
    }
};
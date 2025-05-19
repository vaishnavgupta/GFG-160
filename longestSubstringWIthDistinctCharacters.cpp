
#include <bits/stdc++.h>
using namespace std;

// Using Sliding Window WIth Two Pointer Approach
// Create a window with two pointers
// And a array of 26 size marked with false
// if visited start from left and mark all as visited till
// current element does not get false
// and then mark s[i] as visited
// after then update the ans


class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        vector<int> isVisited(26,-1); //-1 for false 1 for true
        int left = 0;
        int right = 0;
        int mx = 1;
        while(right<n){
            
            if(isVisited[s[right]-'a']==1){
                while(isVisited[s[right]-'a']==1){
                    //start from left and reduce window
                    isVisited[s[left]-'a'] = -1;
                    left++;
                }
            }
            //marking s[i] as visited
            isVisited[s[right]-'a'] = 1;

            //update ans
            mx = max(mx,right-left+1);
            right++;
        }
        return mx;
    }
};
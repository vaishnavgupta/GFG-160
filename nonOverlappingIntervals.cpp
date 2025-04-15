//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool cmp(vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        //Sorting According to ascending order of start time
        sort(intervals.begin(),intervals.end(),cmp);
        //Iterating the intervals array and counting the removal
        int c = 0;
        int prevEnd = intervals[0][1];
        for(int j = 1 ; j < intervals.size() ; j++){
            vector<int> curr = intervals[j];
            if(curr[0] < prevEnd){ //needs removal
                c++;
                prevEnd = min(prevEnd,curr[1]);  //to minimize further overlaps
            }
            else{  //no removal update prevEnd
                prevEnd = curr[1];
            }
        }
        return c;
    }
};
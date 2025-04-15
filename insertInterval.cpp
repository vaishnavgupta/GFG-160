
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++


//Finding the index after which insertion is to be done
//Then in the newArray just copy paste previous elements and apply same
//mergeInterval algo after i

bool cmp(vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,vector<int> &newInterval) {
        int idx = -1;
        for(int i = 0 ; i < intervals.size() ; i++){
            vector<int> currIntv = intervals[i];
            if(currIntv[1] >= newInterval[0] && currIntv[0] <= newInterval[1]){   //after && condition is to take care that when newInterval is smaller then intervals[0]
                idx = i;
                break;
            }
        }
        if(idx==-1){
            intervals.push_back(newInterval);
            sort(intervals.begin(),intervals.end(),cmp);   //to maintain Ascending Order
            return intervals;
        }
        vector<vector<int>> ans;
        for(int j = 0 ; j <= idx ; j++){
            ans.push_back(intervals[j]);
        }
        //Applying merge Intervals code

        //S1  Inserting newInterval first

        vector<int> lastIntvl = ans[ans.size()-1];
        //check if they overlap
        if(newInterval[0] <= lastIntvl[1]){
            ans[ans.size()-1][0] = min(newInterval[0],lastIntvl[0]);
            ans[ans.size()-1][1] = max(newInterval[1],lastIntvl[1]);
        }
        else{
            ans.push_back(newInterval);
        }

        //S2 Inserting rest 
        for(int j = idx+1 ; j < intervals.size();j++){
            vector<int> currIntvl = intervals[j];
            vector<int> lastIntvl = ans[ans.size()-1];
            //check if they overlap
            if(currIntvl[0] <= lastIntvl[1]){
                ans[ans.size()-1][0] = min(currIntvl[0],lastIntvl[0]);
                ans[ans.size()-1][1] = max(currIntvl[1],lastIntvl[1]);
            }
            else{
                ans.push_back(currIntvl);
            }
        }
        return ans;
    }
};
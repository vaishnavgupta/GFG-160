//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
bool cmp(vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}
class Solution {
  public:
    
    //Sort the vector<vector>> a/q to start time
    //Then we comapre each element of sorted intervals 
    //array with the last ele of ans array
    // and check the conditions
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        for(int i = 1 ; i < arr.size() ; i++){
            vector<int> currIntvl = arr[i];
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

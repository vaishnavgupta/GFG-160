//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Knuth Morris Algorithm

class Solution {
  public:

  // See WhiteBoard Under KMP Algo

  int longestPrefixSuffix(string &s) {
    int n = s.size();
    int pre = 0;
    int suff = 1;
    vector<int> lps(n,0);  //Initially 0
    
    while(suff < n){
        //pre and suff equal
        if(s[pre] == s[suff]){
            lps[suff] = pre + 1;
            pre++;suff++;
        }
        //not equal
        else{
            //When pre at 0 ==> pre-1 not exist
            if(pre==0) {
                lps[suff] = 0;
                suff++;
            }
            //Other cases
            else{
                pre = lps[pre-1];
        }
    }
}
  //ans last ele
  return lps[n-1];
}


vector<int> longestPrefixSuffixMOd(vector<int> &lps,string &s) {
  int n = s.size();
  int pre = 0;
  int suff = 1;
  
  while(suff < n){
      //pre and suff equal
      if(s[pre] == s[suff]){
          lps[suff] = pre + 1;
          pre++;suff++;
      }
      //not equal
      else{
          //When pre at 0 ==> pre-1 not exist
          if(pre==0) {
              lps[suff] = 0;
              suff++;
          }
          //Other cases
          else{
              pre = lps[pre-1];
      }
  }
}
//ans last ele
return lps;
}
    // Returns first match
    int searchFirstOccurence(string& pat, string& txt) {
        vector<int> lps(pat.size(),0);
        lps = longestPrefixSuffixMOd(lps,pat);

        int first = 0;
        int second = 0;
        while(first<txt.size() && second<pat.size()){
          if(pat[second] == txt[first]){
            first++;
            second++;                           //abcab
          }

          else{
            if(second == 0) first++; //Not possible

            else{
              second = lps[second-1];
            }
          }
        }

        if(second == pat.size()){  //Success
          return first - second;
        }
        return -1;
    }


    vector<int> searchAllOccurence(string& pat, string& txt) {
      vector<int> lps(pat.size(),0);
      lps = longestPrefixSuffixMOd(lps,pat);
      vector<int> ans;
      int first = 0;
      int second = 0;
      while(first<txt.size()){
        if(pat[second] == txt[first]){
          first++;
          second++;    
          //Check for a match
          if(second == pat.size()){
            ans.push_back(first-second);
            second = lps[second-1];  // Skip unnecessary comparision
          }
        }

        else{
          if(second == 0) first++; //Not possible

          else{
            second = lps[second-1];
          }
        }
      }

      return ans;
  }
};
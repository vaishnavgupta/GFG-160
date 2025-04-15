#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Observation
    // When we append original String twice we get the all possible
    // combinations of the concatenated string
    // eg - Then we will check if s2 is contained in that string
    // if yes then it is a possible rotation of the string


    //Gives TLE
    bool areRotations(string &s1, string &s2) {
        // given -> both string are of equal length
        string modified = s1 + s1; 
        if(modified.find(s2) != string::npos) {    //string::npos means END of string
            return true;
        }
        return false;
    }




    //KMP Method
    //Using above approach if string is concatenated twice all 
    //possible combinations can be generated
    //then search for s2 similar to done in KMP Algo

    void constructLPS(string& s,vector<int>& lps){
        int pre = 0;
        int suff = 1;
        int n = s.size();
        while(suff < n){
            if(s[pre] == s[suff]){
                lps[suff] = pre+1;
                suff++;pre++;
            }
            else{
                if(pre == 0){
                    lps[suff] = 0;
                    suff++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
    }

    bool areRotations(string &s1, string &s2) {
        string modified = s1+s2;
        //Search sr in modified by kmp
        vector<int> lps(s2.size(),0);
        constructLPS(s2,lps);
        int i = 0;
        int j = 0;
        while(i<modified.size() && j<s2.size()){
            if(s2[i] == modified[j]){
              i++;
              j++;                           //abcab
            }
  
            else{
              if(j == 0) i++; //Not possible
  
              else{
                j = lps[j-1];
              }
            }
          }
  
          if(j == s2.size()){  //Success
            return true;
          }
          return false;
    } 
};
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1!=n2) return false;

        sort(s1.begin(),s1.end());
        
        sort(s2.begin(),s2.end());

        if(s1 == s2) return true;
        return false;
    }

    //M2 using hash map (unordered) -> see Leetcode


    //M3 MOST OPTIMIZED O(n)
    bool areAnagramsOptimized(string& s1, string& s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1!=n2) return false;
        
        int alpha[26] = {0};  //for lowesize alphabets only
        
        for(int i=0;i<n1;i++){
            alpha[s1[i] - 'a']++;
            alpha[s2[i] - 'a']--;  // if equal they will cancel each other
        }

        //check
        for(int i=0;i<26;i++){
            if(alpha[i] != 0) return false;
        }
        return true;
    }
};
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:

    // Correct but give TLE-
    int minChar(string& s) {
        int n = s.size();
        string str = s;
        string revStr = s;
        reverse(revStr.begin(),revStr.end());
        int i = 0;
        int count = 0;
        while(i < n){
            if(str == revStr) return count;
            str = str.substr(0,i) + revStr[i] + str.substr(i);
            revStr = str;
            reverse(revStr.begin(),revStr.end());
            count++;i++;
        }
        return -1;
    }

    //mODIFIED VERSION OF Above Code
    
    //instead of modifying string every time
    //use a end pointer to tell that string is palindrome at that pint or not
    //to return we can use n - end - 1

    bool isPalin(string s,int e){
        //check s is palindrome from 0 to end
        int i = 0;
        int j = e;
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }

    int minCharModified(string& s) {
        int n = s.size();
        int end = n-1;
        while(end >= 0){
            if(isPalin(s,end)){
                return n - end - 1;
            }
            end--;
        }
        return -1;
    }


    //  Optimal Approch - KMP Algo
    //Why KMP --> here if we are able to find common prefix and suffix then we can check 
    //for palindrome

    //The observation is that the longest palindromic 
    //prefix becomes longest palindromic suffix of its reverse.

    //So create a combined array str + '#' + revStr
    //then we find the lps array of this modified string
    //now the lastElement of lps array gives count of largest common prefix-suffix
    //it means these number of ele are already present
    //What we need more ==> origStr.length() - lps[last]

    int longestPrefixSuffix(string s){
        int pre = 0;
        int suff = 1;
        vector<int> lps(s.size(),0);

        while(suff < s.size()){
            //equal
            if(s[pre] == s[suff]){
                lps[suff] = pre+1;
                suff++;pre++;
            }
            else{
                //check
                if(pre == 0) {
                    lps[suff] = 0 ;
                    suff++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
        return lps[s.size()-1];
    }

    int minCharOptimized(string& s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string modiied = s + '#' + rev;
        int lpsAns = longestPrefixSuffix(modiied);
        return s.size() - lpsAns;
    }
};



#include<bits/stdc++.h>
using namespace std;


/*
    Using Recusion to generate all the possible permutations
    And then using a set to store all the formed strings
    This will remove all the duplicate strings
    And then return them in vector

    For recursion start with empty string and orig string
    And then in each add one ele from orig string
    And then apply recursion
*/

class Solution {
  public:

    void helper(string ans, string orig, unordered_set<string>& st){
        //base case
        if(orig.size() == 0){
            st.insert(ans);
            return;
        }

        for(int i=0;i<orig.size();i++){
            char ch = orig[i];
            string left = orig.substr(0,i); // 0-->i-1 bcoz i is exclusive
            string right = orig.substr(i+1);  //i+1 --> last
            helper(ans+ch,left+right,st);
        }
    }

    
    vector<string> findPermutation(string &s) {
        unordered_set<string> st;
        vector<string> ans;
        helper("",s,st);
        //putting from set to vector
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};

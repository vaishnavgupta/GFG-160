#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        string str1,str2;
        string res = "";
        int sz1,sz2;
        if(n1 >= n2){
            str1=s1;
            str2=s2;
            sz1=n1;
            sz2=n2;
        }
        else{
            str1=s2;
            str2=s1;
            sz1=n2;
            sz2=n1;
        }
        int i=sz1-1;
        int j=sz2-1;

        while(i>=0 && j>=0){
            if( (str1[i]-'0') + (str2[j]-'0') == 0 ){
                res = "0" + res;
            }
            else if( (str1[i]-'0') + (str2[j]-'0') == 1 ){
                res = "1" + res;
            }
            else if( (str1[i]-'0') + (str2[j]-'0') == 2 ){
                res = "0" + res;
                if(i!=0) str1[i-1] = (((str1[i-1]-'0') + 1) + '0');
                else res = '1' + res;
            }
            else{
                res = "1" + res;
                if(i!=0) str1[i-1] = (((str1[i-1]-'0') + 1) + '0');
                else res = '1' + res;
            }
            i--;
            j--;
        }
        //for remaining i
        while(i>=0){
            if( (str1[i]-'0') == 0 ){
                res = "0" + res;
            }
            else if( (str1[i]-'0') == 1 ){
                res = "1" + res;
            }
            else if( (str1[i]-'0') == 2 ){
                res = "0" + res;
                if(i!=0) str1[i-1] = (((str1[i-1]-'0') + 1) + '0');
                else res = '1' + res;
            }
            else{
                res = "1" + res;
                if(i!=0) str1[i-1] = (((str1[i-1]-'0') + 1) + '0');
                else res = '1' + res;
            }
            i--;
        }
        return res;
    }

    //Optimzed Version left

    string addBinaryOptimized(string& s1, string& s2) {
        string res = "";
        int i = s1.length()-1;
        int j = s2.length()-1;
        int carry=0;
        while(i>=0 || j>=0 || carry){
            int sum = carry;
            if(i>=0) {
                sum+=(s1[i]-'0');
                i--;
            }
            if(j>=0) {
                sum+=(s2[j]-'0');
                j--;
            }
            res = char(sum%2+'0')+res;  //sum%2 vanish the carry 
            carry = sum/2;  // make carry 0 or 1
        }
        // formatting res to remove leading zeros
        i = 0;
        while(i<res.length() && res[i]=='0'){
            res.erase(0,1);
        }
        return res;
    }
};
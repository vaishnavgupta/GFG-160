
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// S1-> Remove whitespaces
// S2-> Check for sign
// S3-> Make number

class Solution {
  public:
    int myAtoi(char *s) {
        long num = 0;
        int sign = 1; //Default 1 for +

        int i = 0;
        while(s[i] == ' '){
            i++;
        }

        if(s[i] == '-'){
            sign = -1; 
            i++;
        }
        if(s[i] == '+'){
            i++;
        }
        while(s[i] >= '0' && s[i] <= '9'){
            num = num*10 + (s[i] - '0');
            if(sign*num >= INT_MAX) return INT_MAX;
            if(sign*num <= INT_MIN) return INT_MIN;
            i++;
        }
        return (int)sign*num;

    }
};
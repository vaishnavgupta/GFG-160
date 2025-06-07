#include<bits/stdc++.h>
using namespace std;

/*
    pow(x,n) = pow(x,n/2) * pow(x,n/2)   ---> Works for even Number
    pow(x,n) = pow(x,n/2) * pow(x,n/2) *  x  ---> Works for odd Number
    TC --> O(log n)
*/

class Solution {
  public:
    double power(double b, int e) {
        if(e == 0) return 1;
        if(e < 0) return 1.0 / power(b, -e);
        
        double ans = power(b,e/2);
        if(e%2 != 0){
            return ans * ans * b;
        }
        return ans * ans;
    }
};
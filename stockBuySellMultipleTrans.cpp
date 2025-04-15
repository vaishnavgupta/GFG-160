
#include <bits/stdc++.h>
using namespace std;

/*
    ** imp **

    First Solve Stock Buy Sell - Max One Transaction
    1- As you get profit sell it
    2- because if you wait then they will also add to give the same profit
*/


class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        int totalProfit = 0;

        for(int i = 1;i<n;i++){
            if(prices[i] > prices[i-1]){
                totalProfit += prices[i]-prices[i-1];
            }
        }
        
        return totalProfit;
    }
};
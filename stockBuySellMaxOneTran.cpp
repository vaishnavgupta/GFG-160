//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Taking two variables
    // minBuyCost --> Track of minimum buying cost of stock
    // maxProfit --> Calculate maxProfit that can be made on selling the stock
    
    int maximumProfit(vector<int> &prices) {
        int minCost = INT_MAX;
        int maxProfit = INT_MIN;
        for(int i =0 ;i<prices.size();i++){
            minCost = min(minCost,prices[i]);
            maxProfit = max(maxProfit,prices[i]-minCost);
        }
        return maxProfit;
    }
};
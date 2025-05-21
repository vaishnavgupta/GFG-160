#include <bits/stdc++.h>
using namespace std;

// Method 1


class Solution
{
public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> pref(n, 0);
        vector<int> suff(n, 0);

        // Initialize the ends of prefix and suffix array
        pref[0] = arr[0];
        suff[n - 1] = arr[n - 1];

        // Calculate prefix sum for all indices
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + arr[i];

        // Calculating suffix sum for all indices
        for (int i = n - 2; i >= 0; i--)
            suff[i] = suff[i + 1] + arr[i];

        // Checking if prefix sum is equal to suffix sum
        for (int i = 0; i < n; i++)
        {
            if (pref[i] == suff[i])
                return i;
        }

        // if equilibrium index doesn't exist
        return -1;
    }


    // Here instead of calculating both prefix and suffix array
    // we use the fact that pre(0..i-1) + arr[i] + suff(i+1..n-1) = totalSum
    // So suff(i+1..n-1) = totalSum - arr[i] - pre(0..i-1)

    int findEquilibriumOptimized(vector<int> &arr)
    {
        int totalSum = 0;
        int preSum=0;
        int n = arr.size();

        for (int ele: arr) {
            totalSum += ele;
        }

        for(int i=0;i<n;i++){
            int suffSum = totalSum - arr[i] - preSum;
            if(suffSum == preSum){
                return i;
            }
            preSum += arr[i];
        }
        return -1;
    }
    
};
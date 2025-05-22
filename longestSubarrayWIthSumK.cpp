#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Maintain a prefix sum and store it in map
    // As map<int,int>
    // then search for k - arr[i] in the map
    // if exist compare it with max lenght
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> mp;
        int mxlen = 0;
        int preSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            preSum += arr[i];
            if (preSum == k)
            {
                // complete is sol
                mxlen = max(mxlen, i + 1);
            }
            if (mp.find(preSum - k) != mp.end())
            {
                // exist update map
                int v = mp[preSum - k];

                mxlen = max(mxlen, i - v );
            }
            if(mp.find(preSum) == mp.end()){
                mp[preSum] = i;  //ONLY store first index
            }
        }
        return mxlen;
    }
};
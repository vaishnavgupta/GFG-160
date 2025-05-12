#include <bits/stdc++.h>
using namespace std;


// Simialar to count subarrays with sum k
// Instead of preSum find preXOR
// And update the map with preXOR values

//Derivation
//The idea is to use the properties of XOR. Let’s denote the XOR of all elements in the range [0, i] as A, 
//the XOR of all elements in the range [i+1, j] as B, and the XOR of all elements in the range [0, j] as C. 


//From the properties of XOR: C = A ⊕ B
//This implies: A = C ⊕ B

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        long cnt = 0 ;
        int preXOR = 0;
        unordered_map<int,int> mp;
        mp[0] = 1; //when ele XOR itself is k

        for(int i=0;i<arr.size();i++){
            preXOR = preXOR ^ arr[i];
            int reqXOR = preXOR ^ k;
            cnt += mp[reqXOR];
            mp[preXOR]++;
        }

        return cnt;
        
    }
};
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    //Approach 1 --> Merge the Two Arrays and then sort the complete
    // array and then return the (k-1)th element


    //Approach 2 -->  Priority Queue Approach
    // Push both array elements in a Min_Heap
    // And then remove first k-1 elements
    //And then return the kth element


    //Approach 3 --> Binary Serarch (**Required**)
    // Solve -- Median of two sorted arrays first (See Here)

    // Similar to Median of two sorted Arrays
    // There we take ele from arr1 and arr2 to form First Half and
    // then rest of the elements to form Second Half

    // Here we take k elements in FIRST HALF
    // and the ans will be  max(l1,l2) as in previous poroblem
    int kthElement(vector<int>& a, vector<int>& b, int k) {
            int n1 = a.size();
            int n2 = b.size();
            if(n1>n2) return kthElement(b,a,k);   //We want nums1 to be smaller
            int lo = max(0,k-n2);  // When K is large then we need to pick something
            int hi = min(k,n1);  //Because At max we take k elements 
            int left = k;  //Only K ele is required in left
            // left is number of ele in left side
            int totalEle = n1+n2;
            while(lo<=hi){
                int mid1 = lo+(hi-lo)/2;  //Ele to be taken from nums1
                int mid2= left - mid1;   //Ele to be taken from nums2
                int l1=INT_MIN;
                int l2=INT_MIN;
                int r1 = INT_MAX;
                int r2 = INT_MAX;   // jUST Dummy Values to reduce errors
                if(mid1 < n1) r1 = a[mid1];
                if(mid2 < n2) r2 = b[mid2];
                if(mid1-1 >= 0) l1 = a[mid1-1];
                if(mid2-1 >= 0) l2 = b[mid2-1];

                //Check
                if(l1<=r2 && l2<=r1){
                    //Correct Part
                   return max(l1,l2); //For all cases

                }
                else if(l1>r2) hi=mid1-1;
                else lo = mid1+1;
            }
            return 0;
    }
};
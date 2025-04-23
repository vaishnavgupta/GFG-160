#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:


        // Binary Serarch Approach
        // For Median we need to divide the sorted array in two equal halves 
        // Let us suppose size of final sorted array is 10
        // Means we need 5 in one part and 5 in the other

        // Try by picking 0 eles from arr1 and (5-0) from arr2 to from First 5 ele and rest as Second 5
        // Similary Try by picking 1 eles from arr1 and (5-1) from arr2 to from First 5 ele and rest as Second 5
        //  Upto 5 ele from arr1 and NO FROM arr2
        // We get a combination that suppose when we pick 3 from arr1 and (5-3=2) from arr2 in FIRST and remaining in SECOND
        // We get sorted part
        
        // How to determine that picked ele form valid symmetry??
        // Check if in First Part arr1[last] < SECOND PART arr2[first] 
        // aND if in First Part arr2[last] < SECOND PART arr1[first] 
        // tHEN THEY ARE VALID SORTED SYMMETRY


        // how to find median??
        // Let First Part arr1 as l1
        // Let First Part arr2 as l2
        // Let Sec Part arr1 as r1
        // Let Sec Part arr1 as r2
        // Median = [max(l1,l2) + min(r1,r2)] / 2


        // Binary Search Conditions (**Imp**)
        // If First Part arr1[last] < SECOND PART arr2[first] FAILS means MORE ELE reduce ==> hi=mid-1
        // if in First Part arr2[last] < SECOND PART arr1[first] FAILS means Less ELE increase ==> lo=mid+1
        
        
        // For odd
        // See Code

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n1 = nums1.size();
            int n2 = nums2.size();
            if(n1>n2) return findMedianSortedArrays(nums2,nums1);   //We want nums1 to be smaller
            int lo = 0;
            int hi = n1;
            int left = (n1+n2+1)/2;  //to incorporate odd arrays as well
            // left is number of ele in left side
            int totalEle = n1+n2;
            while(lo<=hi){
                int mid1 = lo+(hi-lo)/2;  //Ele to be taken from nums1
                int mid2= left - mid1;   //Ele to be taken from nums2
                int l1=INT_MIN;
                int l2=INT_MIN;
                int r1 = INT_MAX;
                int r2 = INT_MAX;   // jUST Dummy Values to reduce errors
                if(mid1 < n1) r1 = nums1[mid1];
                if(mid2 < n2) r2 = nums2[mid2];
                if(mid1-1 >= 0) l1 = nums1[mid1-1];
                if(mid2-1 >= 0) l2 = nums2[mid2-1];

                //Check
                if(l1<=r2 && l2<=r1){
                    //Correct Part
                    if(totalEle%2 == 1) return max(l1,l2); //For odd
                    else ((double)(max(l1,l2) + min(r1,r2))) / 2.0;
                }
                else if(l1>r2) hi=mid1-1;
                else lo = mid1+1;
            }
            return 0;
        }
        
    };
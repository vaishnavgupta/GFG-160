#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:

    // Optimal Solution 1

    // Take two pointers left(end of arr1) and right(start of arr2)
    // Now we compare both left and right and swap them if they are not in
    // correct place
    //But if they are in correct place means rest of arrays is also
    // in correct place. Simply break
    //Now sort both arrays 

    // T.C -> O(min(n,m)) + O(nlogn) + O(mlogn)

    void mergeArrays(vector<int>& a, vector<int>& b) {
        int left = a.size()-1;
        int right = 0;
        while(left >= 0 && right < b.size()){
            if(a[left] >= b[right] ) {
                swap(a[left],b[right]);
                left--;right++;
            }
            else{
                break;
            }
        }
        //Sort
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    }

    // Optimal Solution 2
    // Gap Method based on Shell Sort
    // Take initial gap as ceil(n+m / 2)
    // left=0 and right=gap
    // Compare and swap if not at correct place
    // When right is out of bound RESET ALL
    // gap=ceil(gap/2) and left=0 ang right=gap
    //Repeat when gap==1


    //TC -> O(logN) because divides by 2

    void swapAtIdx(vector<int>& a, vector<int>& b,int idx1,int idx2){
        if(a[idx1]>b[idx2]) swap(a[idx1],b[idx2]);
    }

    void mergeArraysOptimized(vector<int>& a, vector<int>& b) {
        int len = a.size()+b.size();
        int gap = ceil(len/2.0);
        
        while (gap>0)
        {
            int left = 0;
            int right = gap;
            while(right<len){
                //three cases
    
                //Case1 - left in a and right in b
                if(left<a.size() && right>=a.size()){
                    swapAtIdx(a,b,left,right-a.size());
                }
                //both in b
                else if(left>=a.size()){
                    swapAtIdx(a,b,left-a.size(),right-a.size());
                }
                //both in a
                else{
                    swapAtIdx(a,b,left,right);
                }
    
                left++;right++;
            }
            if(gap==1) break;
            gap = ceil(gap/2.0);
        }
        
    }
};

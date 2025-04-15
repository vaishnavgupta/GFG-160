#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // If we have 2 Sorted Array and we need to find number of such pairs
    // Let i is in array1 and j in array2
    // Now if arr1[i] > arr2[j] then all the elements after i in array 1 can form pair
    // with jth element of arr2
    // So add arr1.size() - i in ans And also do j++
    // else do i++

    // To get two sorted arrays we are using MergeSort Function and we can call our
    // function after the merge Calls

    int countAns = 0; //  Global

    int countInv(vector<int> &a,vector<int> &b){
        int i,j=0;
        int c=0;
        while(i<a.size() && j<b.size()){
            if(a[i] > b[j]){
                c += a.size() - i;
                j++;
            }
            else{
                i++;
            }
        }
        return c;
    }

    void merge(vector<int>& a , vector<int>& b , vector<int>& res){
        int i,j,k=0;
        while(i<a.size() && j<b.size()){
            if(a[i] < b[j]){
                res[k++] = a[i++];
            }
            else{
                res[k++] = b[j++];    
            }
            // left
            if(i == a.size()){
                while(j < b.size()){
                    res[k++] = b[j++];
                }
            }
            if(j == b.size()){
                while(i < a.size()){
                    res[k++] = a[i++];
                }
            }
        }
    }

    void mergeSort(vector<int>& v){
        //forming two arrays
        int n = v.size();
        if(n==1) return ;     //base case
        int n1 = n/2;
        int n2 = n-n/2;
        //Forming Arrys
        vector<int> a(n1) , b(n2);
        for(int i = 0 ; i < n1 ; i++){
            a[i] = v[i];
        }
        for(int j=0;j<n2;j++){
            b[j] = v[n1+j];
        }
        mergeSort(a);
        mergeSort(b);
        //Count Inversion
        countAns += countInv(a,b);
        //Merge
        merge(a,b,v);

    }

    int inversionCount(vector<int> &arr) {
        mergeSort(arr);
        return countAns;
    }
};
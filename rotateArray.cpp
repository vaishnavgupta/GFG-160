#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:


    void reversePart(vector<int>& arr, int s, int e){
        int i=s;
        int j=e;
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;  // New Value of d
        //Reversing 0 to d-1
        reversePart(arr,0,d-1);
        //Reversing d to n-1
        reversePart(arr,d,n-1);

        //Reversing the whole Array
        reversePart(arr,0,n-1);
    }
};
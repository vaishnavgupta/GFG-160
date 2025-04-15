
#include <bits/stdc++.h>
using namespace std;


// 1- From Last find pivot index.
// 2- Reverse from idx+1 to last.
// 3- From idx+1 find element just greater than arr[idx]
// 4- Swap idx and that element


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


    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int pivot = -1;
        for(int i = n-2 ; i>=0; i--){
            if(arr[i] < arr[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot == -1){ // No pivot means in sorted order
            reversePart(arr,0,n-1);
            return;
        }

        reversePart(arr,pivot+1,n-1);

        int j = -1;
        for(int i = pivot+1 ; i<n; i++){
            if(arr[i]>arr[pivot]) {
                j = i;
                break;
            }
        }
        swap(arr[pivot] , arr[j]);
    }
};
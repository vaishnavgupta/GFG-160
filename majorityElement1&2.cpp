#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        map<int,int> mp;
        vector<int> ans;
        int n = arr.size();
        for(int i = 0;i<n; i++){
            mp[arr[i]]++;
        }
        int oneThird = n / 3;
        for(auto it : mp){
            if(it.second > oneThird){
                ans.push_back(it.first);
            }
        }
        return ans;
    }


    // Optimized Approach
    // Moore's Voting Algorithm
    
    // First Solving for >n/2

    // PART 1
    // At most 1 element can be greater than n/2
    // Take a count and ele variable
    // Traverse the array and if ele comes increase the count
    // And if doesnot not decrease the count
    // Anytime when count gets zero(0) change the ele
    // Do this and find the last value of ele

    // PART 2
    // **IMP**
    // Now if majority element exist then this ele must be the answer
    // Otherwise no majority element exist
    // Check if majority ele exist or not

    vector<int> findMajority1(vector<int>& arr) {
        int cnt = 0;
        int ele;
        vector<int> ans;

        // PART 1
        for(int i = 0; i<arr.size();i++){
            if(cnt == 0){
                ele = arr[i];
                cnt = 1;
            }
            else if(arr[i] == ele) cnt++;
            else cnt--;
        }

        // PART 2
        int c = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] == ele) c++;
        }
        if(c > arr.size()/2){
            ans.push_back(ele);
            return ans;
        }
        return {-1};
    }

    // For n / 3


    vector<int> findMajorityOptimized(vector<int>& arr) {
        int n = arr.size();
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1 == 0 && arr[i]!=ele2){  // edge cases to deal with different elements
                cnt1=1;
                ele1 = arr[i];
            }
            else if(cnt2 == 0 && arr[i]!=ele1){
                cnt2=1;
                ele2 = arr[i];
            }
            else if(ele1 == arr[i]){
                cnt1++;
            }
            else if(ele2 == arr[i]){
                cnt2++;
            }
            
            else{
                cnt1--;
                cnt2--;
            }
        }
        int count1 = 0;
        int count2 = 0;
        for (int num : arr) {
            if (num == ele1) count1++;
            else if (num == ele2) count2++;
        }

        vector<int> ans;
        if (count1 > n / 3) ans.push_back(ele1);
        if (count2 > n / 3) ans.push_back(ele2);

        sort(ans.begin(), ans.end());  // Ensure increasing order
        return ans;
    }

};



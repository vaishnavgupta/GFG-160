#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Using a Queue to keep bfs order
// Push the root in the queue and then maintaining currLevel
// Increment currLevel after traversal is done from the particular level


class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        if(root == NULL) return {};
        queue<Node*> q;
        vector<vector<int>> ans;
        q.push(root);
        int currLevel = 0;

        while(q.size()>0){
            int len = q.size();
            ans.push_back({});
            for(int i=0;i<len;i++){
                Node* temp = q.front();
                ans[currLevel].push_back(temp->data);
                q.pop();

                //Add Left
                q.push(temp->left);
                //Add Right
                q.push(temp->right);
            }
            currLevel++;
        }
        return ans;
    }
};
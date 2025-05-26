#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Find effective value of k
// Place temp at k times and place tail
// store new head;
// tail-next = head;
// temp->next = null
// return newHead
// check effK == 0 condition everytime



class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (!head || k == 0) return head;
        Node* tail = head;
        Node* temp = head;
        int n = 0;
        Node* tA = head;
        while(tA!=NULL){
            if(tA->next == NULL) tail = tA;
            n++;
            tA = tA -> next;
        }
        int effK = k % n;
        if (effK == 0) return head;
        for(int i=1;i<effK;i++){
            temp = temp->next;
        }
        Node* newHead = temp->next;
        tail->next = head;
        temp->next = NULL;
        return newHead;
    }
};
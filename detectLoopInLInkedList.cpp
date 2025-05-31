#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

};
class Solution {
  public:
    
    // Put two pointers slow and fast pointers
    // slow increase by 1 and fast increase by 2
    // if slow and fast meet anywhere then LOOP is present
    // if fast comes to NULL ==> no Loop break

    bool detectLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
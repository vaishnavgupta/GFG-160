#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Method
// We will first check if loop exist (if not return )
// Then we will find the first element of the loop
// and also keep track of prev elem
// then we will point prev to NULL

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        
        Node* slow = head;
        Node* fast = head;
        bool flag = false;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                //loop exist 
                flag = true;
                break;
            }
        } 
        if(flag==false){
            return;
        }
        Node* temp = head;
        while(temp!=slow){
            temp = temp -> next;
            slow = slow -> next;
        }
        
        Node* loopStart = slow;
        Node* prev = loopStart;
        while(prev->next != loopStart) prev = prev->next;

        if(prev!=NULL) prev->next = NULL;
        return; 
    }
};
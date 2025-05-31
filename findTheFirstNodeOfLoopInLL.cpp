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
    // Same as detectLoopInLL
    // Detect loop in LL and if loop not exist return NULL
    // then if loop exist place a temp=head
    // then increase temp and slow by 1 
    // When they meet then it is the starting node of the loop
    
    Node* findFirstNode(Node* head) {
        Node* slow = head;
        Node* fast = head;
        bool flag = false;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                flag = true;
                break;
            }
        }
        
        if(flag == false) return NULL;

        //finding the first occurence of loop
        Node* temp = head;
        while(temp!=slow){
            temp = temp -> next;
            slow = slow -> next;
        }
        return temp;  //or slow
    }
};
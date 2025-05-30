#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    // Hashmap Map
    // We will use a map<Node*,Node*> and store old node corresponding to its new node
    // First simply create a new LL with val and next pointer 
    // then traverse both the LL and store <old,new> in map
    // and then finally traverse old LL and set random pointer of new LL

    // TC --> O(N)  SC-->O(N)

    Node *cloneLinkedList(Node *head) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        Node* t = head;

        unordered_map<Node*,Node*> mp;

        while(t!=NULL){
            Node* x = new Node(t->data);
            //map storage
            mp[t] = x;

            temp->next = x;
            temp = temp->next;
            t = t->next;
        }
        temp = dummy->next;
        t = head;
        
        //Setting random pointer
        for(auto it : mp){
            Node* a = it.first;
            Node* b = it.second;
            if(a->random==NULL){
                b->random = NULL;
            }
            else{
                b->random = mp[a->random];
            }
        }
        return dummy->next;
    }

    // See Copy for Explaination
    // Alternating Connections Methods
    // S1 - First simply create a new List with same val & next (Same as in previous)
    // S2 - Form alternate conections (orig-->dupl)
    // S3 - Join random pointers
    // S4 - Seperate both the list

    // TC --> O(N)  SC-->O(1)

    Node *cloneLinkedListOptimized(Node *head) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        Node* t = head;

        while(t!=NULL){
            Node* x = new Node(t->data);
            temp->next = x;
            temp = temp->next;
            t = t->next;
        }

        //S2 Alternate Conn
        dummy = dummy->next;
        Node* d = new Node(-1);
        t = d;
        Node* t1 = head;
        Node* t2 = dummy;
        while(t1){
            t->next = t1;
            t = t->next;
            t1 = t1->next;
            t->next = t2;
            t = t->next;
            t2 = t2->next;
        }
        d = d->next;

        //S3 Setting Random Pointers
        t = d;
        while(t!=NULL){
            if(t->random != NULL) t->next->random = t->random->next;    /* V IMP */
            t = t->next->next;
        }

        //S4 Seperating
        Node* d1=new Node(-1);
        Node* d2=new Node(-1);
        t1=d1;t2=d2;
        Node* trp=d;
        while(trp){
            t1->next=trp;
            trp=trp->next;
            t1=t1->next;
            t2->next=trp;
            trp=trp->next;
            t2=t2->next;
        }
        t1->next=NULL;
        t2->next=NULL;
        d1=d1->next;
        d2=d2->next;
        return d2; 
    }
};
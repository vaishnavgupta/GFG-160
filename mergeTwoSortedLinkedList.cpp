#include <bits/stdc++.h>
using namespace std;

// Link list Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


// Make a dummy node
// And after this make two nodes to travese LL1 and LL2 
// Add to the dummy node until sorted order is maintained 
// if any node points to null add 2nd LL to the dummy node

class Solution
{
public:
    Node *sortedMerge(Node *head1, Node *head2)
    {
        Node* dummy = new Node(-1);
        Node* tempC = dummy;
        Node* tempA = head1;
        Node* tempB = head2;

        while(tempA!=NULL && tempB!=NULL){
            if(tempA->data <= tempB->data){
                tempC->next = tempA;
                tempA = tempA->next;
            }
            else{
                tempC->next = tempB;
                tempB = tempB->next;
            }
            tempC = tempC -> next;
        }
        if(tempA==NULL){
            tempC -> next = tempB;
        }
        else{
            tempC -> next = tempA;
        }
        return dummy->next;
    }
};
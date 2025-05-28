#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// See reverseNodesInKGroupLEETCODE.cpp

// Maintain a temp and kthNode which contains first and the kthNode
// then store nextNode in nextNode and then break connections
// After this reverse the breaked LL
// The kthNode will become the head and temp be last node
// For first Group store kth Node as head
// then update prevNode and temp

class Solution
{
public:
    Node *reverseLL(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *nxt = head;

        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    Node *findKthNode(Node *head, int k)
    {
        Node *temp = head;
        int cnt = 1;
        while (temp != NULL)
        {
            if (cnt == k)
                return temp;
            temp = temp->next;
            cnt++;
        }
        return NULL;
    }
    Node *reverseKGroup(Node *head, int k)
    {
        Node* temp = head;
        Node* prevNode = NULL;
        Node* nextNode = NULL;

        while(temp!=NULL){
            Node* kthNode = findKthNode(temp,k);
            if(kthNode == NULL){  //NO GROUP AVAILABLE Just Reverse the rest
                if (prevNode) prevNode->next = reverseLL(temp);
                else{
                    return reverseLL(head);   //No Group Formed
                }
                break;
            }
            nextNode = kthNode->next;
            
            //Breaking and Reversing LL
            kthNode->next = NULL;
            reverseLL(temp);

            if(temp==head){ //firstGroup
                head = kthNode;
            }
            else{
                // connect prevGroups
                prevNode->next = kthNode;
            }

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
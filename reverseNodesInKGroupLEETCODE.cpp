
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nxt = head;

        while (curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    ListNode *findKthNode(ListNode *head, int k)
    {
        ListNode *temp = head;
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

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *nextNode = NULL;
        ListNode *prevNode = NULL;

        while (temp != NULL)
        {
            ListNode *kthNode = findKthNode(temp, k);
            if (kthNode == NULL)
            { // no groups available
                // edge case --> when length of LL is less than k --> no prevNode
                if (prevNode)
                    prevNode->next = temp;
                break;
            }
            // Storing for next group
            nextNode = kthNode->next;

            // breaking connections and passing to rev
            kthNode->next = NULL;
            reverseLL(temp);

            // after reversal dealing
            if (temp == head)
            {                   // first group
                head = kthNode; // after reverse kthNode become head
            }
            else
            { // after first groups
                // connect prevGroups
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
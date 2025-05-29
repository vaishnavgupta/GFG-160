#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Important Question
// Reverse each of the linked list
// then add them
// when you add maintain a carry variable that will keep the track of next carry
// To prevent leading zeros in the ans make a condition that if
// newNode formed have 0 value and carry is also zero
// then add NULL and break the LL
// after this reverse the ans LL and return

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

    // Function to trim leading zeros in linked list
    Node *trimLeadingZeros(Node *head)
    {
        while (head->next != nullptr && head->data == 0)
            head = head->next;
        return head;
    }

    Node *addTwoLists(Node *num1, Node *num2)
    {
        num1 = trimLeadingZeros(num1);
        num2 = trimLeadingZeros(num2);

        Node *h1 = reverseLL(num1);
        Node *h2 = reverseLL(num2);

        int carry = 0;
        Node *dummy = new Node(-1);

        Node *temp = dummy;

        while (h1 != NULL && h2 != NULL)
        {
            Node *t = new Node(-1);
            int x = h1->data + h2->data + carry;
            if (x >= 10)
            {
                carry = 1;
                x = x - 10;
            }
            else
                carry = 0;

            t->data = x;

            temp->next = t;
            h1 = h1->next;
            h2 = h2->next;
            temp = temp->next;
        }

        if (h2 == NULL)
        {
            while (h1 != NULL)
            {
                Node *t = new Node(-1);
                int x = h1->data + carry;
                if (x >= 10)
                {
                    carry = 1;
                    x = x - 10;
                }
                else
                    carry = 0;

                t->data = x;

                temp->next = t;
                h1 = h1->next;
                temp = temp->next;
            }
        }
        else if (h1 == NULL)
        {
            while (h2 != NULL)
            {
                Node *t = new Node(-1);
                int x = h2->data + carry;
                if (x >= 10)
                {
                    carry = 1;
                    x = x - 10;
                }
                else
                    carry = 0;

                t->data = x;

                temp->next = t;
                h2 = h2->next;
                temp = temp->next;
            }
        }

        //Check carry
        if (carry > 0) {
        temp->next = new Node(carry);
        temp = temp->next;
        }
        
        //Adding NULL
        temp->next = NULL;
        return reverseLL(dummy->next);
    
}
};
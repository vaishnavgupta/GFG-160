#include <bits/stdc++.h>
using namespace std;

// Using a doubly linked list and a map
// Create dummy head and tail Nodes
// then for put function if cap is left --> create new Node and push it after head
// also store key,Node* in the map
// if cap is not left remove tail->next and delete in map also  and rest is same

// for get func search in map and find Node address
// return the value from the Node address
// and then remove it and place it after head
// don't create new node just change its position

// We need two custom functions in this approach
// removeNode and insertAfterHead

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int k, int v)
    {
        key = k;
        val = v;
        next = nullptr; // Optional --> nullptr provides better type-safety
        prev = nullptr;
    }
};

class LRUCache
{
private:
public:
    int capacity;
    Node *head;
    Node *tail;
    unordered_map<int, Node *> mp;

    LRUCache(int cap)
    {
        capacity = cap;
        head = new Node(0, 0); // dummy head
        tail = new Node(0, 0); // dummy tail

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        else
        {
            Node *foundNode = mp[key];
            // placing it after head
            removeNode(foundNode);      // simply breaks its connections
            insertAfterHead(foundNode); // joins it after head
            return foundNode->val;
        }
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *foundNode = mp[key];
            foundNode->val = value;
            // placing it after head
            removeNode(foundNode);
            insertAfterHead(foundNode);
        }
        else
        {
            if (mp.size() == capacity)
            {
                // full -> delete then add
                Node *leastUsedNode = tail->prev; // ** imp **
                mp.erase(leastUsedNode->key);
                removeNode(leastUsedNode);
            }
            Node *newNode = new Node(key, value);
            mp[key] = newNode;
            insertAfterHead(newNode);
        }
    }

    void removeNode(Node *node)
    {
        Node *nextNode = node->next;
        Node *prevNode = node->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node *node)
    {
        Node *nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};



/**
class ListNode
{
 * Definition for doubly-linked list.
 *  public:
 *      int data;
 *      ListNode *prev;
 *      ListNode *next;
 *      ListNode() : data(0), prev(nullptr), next(nullptr) {}
 *      ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
 *      ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};
*/

class Solution {
public:
    ListNode* insertBeforeTail(ListNode* head, int X) {
        // Your code goes here



        ListNode* newNode = new ListNode(X);

        if (head == nullptr) {
            return newNode;
        }

        ListNode* temp = head;
        if (head->next == nullptr) {
                newNode->next = temp;
                temp->prev = newNode;
                head = newNode;

                return head;
        }

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        ListNode* prevNode = temp->prev;

        prevNode->next = newNode;
        newNode->next = temp;
        newNode->prev = prevNode;
        temp->prev = newNode;

        return head;
    }
};


int main() {
    vector<int> arr = {2, 5, 8, 7};

    // Create nodes
    Node* head = new Node(arr[0]);
    Node* second = new Node(arr[1]);
    Node* third = new Node(arr[2]);
    Node* fourth = new Node(arr[3]);

    // Linking nodes
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;

    // Traverse forward
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " <-> ";
        temp = temp->next;
    }

    cout << " -> NULL\n";

    return 0;
}

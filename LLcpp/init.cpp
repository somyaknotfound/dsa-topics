#include <bits/stdc++.h>

using namespace std;


class ListNode {
    
    
    public:
    
    int data;
    ListNode* next;
    
    
    ListNode() {
        data = 0;
        next = nullptr;
        
    }
    
    ListNode(int x) {
        data = x;
        next = nullptr;
    }
    
    ListNode(int x, ListNode* nextNode) {
        data = x;
        next = nextNode;    
    }
    
    
};


class Solution {
    
    public:
    // insert at  head 
    ListNode* insertAtHead(ListNode*& head,int X ) {
        ListNode* newNode = new ListNode(X);
        newNode-> next = head;
        head = newNode;
        
        
        return head;
        
        
    }
    
    ListNode* insertAtTail(ListNode *& head , int x) {
        ListNode* newNode = new ListNode(x);
        
        if (head == nullptr) {
            head = newNode;
            return head;
            
        }
        
        ListNode* temp = head;
        
        while (temp->next != nullptr) {
            temp = temp-> next;
            
        }
        temp->next = newNode;
        return head;
        
    }
    
    ListNode* deleteNode(ListNode *& head , int value) {
        if (head == nullptr) return head;
        
        if (head->data == value) {
            ListNode* temp = head;
            head = temp->next;
            delete temp;
            return head;
            
        }
        
        ListNode* temp = head;
        
        while (temp->next!= nullptr && temp->next->data != value) {
            temp = temp->next;
            
        }
        
        if (temp->next != nullptr) {
            ListNode* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;
            
        }
        
        return head;
    }
    
    bool search(ListNode* head, int key) {
        ListNode* temp = head;
        
        while (temp != nullptr) {
            if (temp->data == key) return true;
            temp = temp->next;
            
        }
        
        return false;
        
    }
    
    
    
    
    
    
    void printList(ListNode* head) {
        ListNode* temp = head;
        
        while (temp!= nullptr) {
            cout << temp->data<< " -> ";
            temp = temp->next;
            
        }
        
        cout << "NULL" << endl;
    }
};



int main() {
    Solution obj;
    ListNode* head = nullptr;

    // Insert at head
    obj.insertAtHead(head, 30);
    obj.insertAtHead(head, 20);
    obj.insertAtHead(head, 10);

    cout << "After InsertAtHead: ";
    obj.printList(head);

    // Insert at tail
    obj.insertAtTail(head, 40);
    obj.insertAtTail(head, 50);

    cout << "After InsertAtTail: ";
    obj.printList(head);

    // Search
    cout << "\nSearching 30: ";
    if (obj.search(head, 30))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    // Delete
    obj.deleteNode(head, 20);

    cout << "After deleting 20: ";
    obj.printList(head);
    
    
    cout << "Now Searching for 20: ";
    if (obj.search(head,20)) {
        cout << "FOund" << endl;
    } else {
        cout <<"Not Found" << endl;
    }

    return 0;
}

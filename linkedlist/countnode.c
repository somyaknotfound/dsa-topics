#include<stdio.h>

struct Node 

{
    int data;
    struct Node *next;
};



int count(struct Node* head) {
    if (head==0) {
        return 0;
    }

    else {
        return count(head->next) +1;
    }

    // remove else 

    //  if(p!=null)
}

#include<stdio.h>

struct Node 

{
    int data;
    struct Node *next;
};

int add( struct Node* p) {
    int sum = 0 ;

    while(p) {
        sum+=p->data;
        p = p->next;
    }

    return sum;

}


int addr(struct Node* p) {
    if (p==0) {
        return 0;
    }

    else {
        return add(p->next)+p->data;
    }
}



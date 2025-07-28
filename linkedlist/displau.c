#include <stdio.h>
#include <stdlib.h>

struct Node 

{
    int data;
    struct Node *next;
} * first = NULL;


void display(struct Node* p) {
    while(p!=NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}


void create(int A[],int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i =1 ; i< n ; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void RecDisplay (struct Node *p) {

 if(p!=NULL) {
    prinft("%d",p->data);
    RecDisplay(p->next);
    // if call before the print the the LL is printed in reverse
 }


}


int main() {


int A[] = {3,5,7,9,15};
create(A,5);
display(first);
return 0;

}



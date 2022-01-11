#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int d;
    struct node *next;
};

struct que{
    struct node *front;
    struct node *back;
};

struct node* new_node(int t){
    struct node *n;
    n = malloc(sizeof(struct node));
    n->d = t;
    n->next = NULL;
    return n;
}

struct que* new_q(){
    struct que *q;
    q->front = NULL;
    q->back = NULL;
    return q;
}

int is_emp(struct que *q){
    if(q->front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(struct que *q, struct node *n){
    if(is_emp(q)){
        q->front = n;
        q->back = n;
    }
    else{
        q->back->next = n;
        q->back = n;
    }
}

int deque(struct que *q){
    if(is_emp(q)){
        printf("Queue is empty\n");
        return -100;
    }
    else{
        int x = q->front->d;
        struct node *n;
        n = q->front;
        q->front = q->front->next;
        n->next = NULL;
        free(n);
        return x;
    }
}

int fro(struct que *q){
    if(is_emp(q)){
        printf("Queue is empty\n");
    }
    else{
        int t = q->front->d;
        printf("Front element : %d\n", t);
    }
}

void display(struct que *q){
    struct node *t;
    t = q->front;
    while(t->next != NULL){
        printf("%d\n", t->d);
        t = t->next;
    }
    //printf("%d\n", t->d);
}

int main()
{
    struct node *n1, *n2, *n3, *n4, *n5, *n6;
    struct que *q;
    n1 = new_node(2);
    n2 = new_node(89);
    n3 = new_node(7);
    n4 = new_node(8);
    
    n5 = new_node(75);
    n6 = new_node(950);
    q = new_q();
    enque(q,n1);
    enque(q,n2);
    enque(q,n3);
    enque(q,n4);
    enque(q,n5);
    //enque(q,n6);
    display(q);
    //deque(q);
    //deque(q);
    //fro(q);
    //display(q);
}
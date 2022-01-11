#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
   
    int element;
    struct node* next;

};
void insertion_link_list(int data,struct node **p){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->element =data;
    newnode->next= (*p);
    (*p) = newnode;
    
}

int main(){
    struct node* header=malloc(sizeof(struct node));
    header->element=27;
    header->next=NULL;
    struct node *e2=malloc(sizeof(struct node));
    e2->element=40;
    e2->next=NULL;
    header->next=e2;
    struct node *e3=malloc(sizeof(struct node));
    e3->element=90;
    e3->next=NULL;
    e2->next=e3;
    //insertion_link_list(30,e2);
    struct node* e4=malloc(sizeof(struct node));
    e4->element =150;
    e4->next=NULL;
    e3->next = e4;

    struct node* e5=malloc(sizeof(struct node));
    e5->element =200;
    e5->next=NULL;
    e4->next = e5;
    insertion_link_list(900,&header);
struct node *r;
int c=0,m=0;
r=header;

    
    struct node *k;
    k=header;
    while(k!=NULL){
        m=m+1;
        if (m==3){
        printf("The 3rd node element of a linked list is %d \n",k->element);
        }
        
        k=k->next;
    }
        while(r!=NULL){
        printf("The elements of a linked list is %d \n",r->element);
        c=c+1;
        r=r->next;
    }
printf("The NO OF NODES IN A LINKED LIST IS %d \n",c);
}
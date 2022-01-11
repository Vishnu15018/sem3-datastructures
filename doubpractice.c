#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
   
    int element;
    struct node* next;
    struct node* pre;

};
void insertion_link_list_head(int data,struct node **p){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->element =data;
    newnode->pre=NULL;
    newnode->next= (*p);
    (*p)->pre=newnode;
    (*p) = newnode;
    
}
void insertion_link_list_k(int da,struct node *q){
int m;
        
    struct node *k;
    k=NULL;
    while(q!=NULL){
        m=m+1;
        if(m==4){
              k=q;
               break;
        }
        q=q->next;
    }
    struct node* newnode2=malloc(sizeof(struct node));
    newnode2->element =da;
    newnode2->pre=q;
    newnode2->next= q->next;
    (q->next)->pre=newnode2;
    q->next=newnode2;
    
}
void deletion_link_list_position(struct node **head,int k){
    struct node *current=*head;
    struct node *previous=*head;
    if(*head ==NULL){
        printf("The list is already empty");
    }
    else if(k==1){
        (*head)=current->next;
        free(current);
        current==NULL;
    }
    else{
        while(k!=1){
            
            current=current->next;
            k--;
        }

        (current->pre)->next=current->next;
        (current->next)->pre = current->pre;
        free(current);
        current=NULL;
    }

 
}



int main(){
    struct node* header=malloc(sizeof(struct node));
    header->element=27;
    header->next=NULL;
    header->pre=NULL;
    struct node *e2=malloc(sizeof(struct node));
    e2->element=40;
    e2->next=NULL;
    e2->pre=header;
    header->next=e2;
    struct node *e3=malloc(sizeof(struct node));
    e3->element=90;
    e3->next=NULL;
    e2->next=e3;
    e3->pre=e2;
    //insertion_link_list(30,e2);
    struct node* e4=malloc(sizeof(struct node));
    e4->element =150;
    e4->next=NULL;
    e3->next = e4;
    e4->pre=e3;

    struct node* e5=malloc(sizeof(struct node));
    e5->element =200;
    e5->next=NULL;
    e4->next = e5;
    e5->pre=e4;
    insertion_link_list_head(900,&header);
    //insertion_link_list_k(500,header);
    //deletion_link_list_position(&header,1);
    deletion_link_list_position(&header,2);

struct node *r;
int c=0,m=0;
r=header;
//printf("The elements of a linked list is %d \n",header->element);

    

        while(r!=NULL){
        printf("The elements of a linked list is %d \n",r->element);
        c=c+1;
        r=r->next;
    }
printf("The NO OF NODES IN A LINKED LIST IS %d \n",c);
}
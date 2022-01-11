#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
   
    int element;
    struct node* next;

};
void insert(struct node **head,int data,int k){
    if(k==0){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->element=data;
    newnode->next=(*head);
    *head=newnode;
    }
    else{
        struct node *p=NULL,*q;
        int i=0;
        q=(*head);
        while(q){
            i=i+1;
            if(i==k){
                p=q;
            }
            q=q->next;
            
        }
        struct node *newnode = malloc(sizeof(struct node));
        newnode->element=data;
        newnode->next=p->next;
        p->next=newnode;

    }
}
void Display(struct node* r){
    while(r!=NULL){
        printf("The elements of a linked list is %d \n",r->element);
        r=r->next;
    }

}
int main(){
    struct node* header=NULL;

        for(int i=0;i<5;i++){
        int a=0;
        printf("Enter the elements of a linked list: ");
        scanf("%d",&a);
        insert(&header,a,i);
    }
    Display(header);
    
}
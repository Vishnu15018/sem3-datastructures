#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
   
    float coeff;
    int expo;
    struct node* next;

};
void insert(struct node **head,float data1,int data2,int k){
    if(k==0){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->coeff=data1;
    newnode->expo=data2;
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
          newnode->coeff=data1;
          newnode->expo=data2;
        newnode->next=p->next;
        p->next=newnode;

    }
}

void Display(struct node *r){
    if(r==NULL){
        printf("The resultant linked list is empty\n");
    }
    while(r){
        printf("The exponent  of a resulting ploynomial is %d \n",r->expo);
        printf("The coefficient  of a resulting ploynomial is %f \n",r->coeff);
        r=r->next;
    }

}
struct node* polyadd(struct node *ptr1 , struct node *ptr2){
    struct node *sumpoly=NULL;
    int i=0;
 while(ptr1!=NULL && ptr2!=NULL){
    if(ptr1->expo == ptr2->expo){

        insert(&sumpoly,ptr1->coeff+ptr2->coeff,ptr1->expo,i);
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        i=i+1;
    }
    else if(ptr1->expo > ptr2->expo){

        insert(&sumpoly,ptr1->coeff,ptr1->expo,i);
        ptr1=ptr1->next;
        i=i+1;
    }
    else if(ptr1->expo < ptr2->expo){

       insert(&sumpoly,ptr2->coeff,ptr2->expo,i);
      
        ptr2=ptr2->next;
        i=i+1;
    }
  }
  while (ptr1!=NULL)
  {
      insert(&sumpoly,ptr1->coeff,ptr1->expo,i);
      ptr1=ptr1->next;
      i=i+1;
  }
  while (ptr2!=NULL)
  {    insert(&sumpoly,ptr2->coeff,ptr2->expo,i);
       ptr2=ptr2->next;
       i=i+1;
  }
   return sumpoly;


}

int main(){
    struct node *poly1=NULL;
    struct node *poly2=NULL;
    int n1=0;
    
    printf("Enter the no of terms of a polynomial-1: ");
    scanf("%d",&n1);
    printf(" Enter the exponents of a polynomial in decresing order\n ");
    for(int i=0;i<n1;i++){
        float a=0;
        int b=0;
        printf("Enter the exponent   of a polynomial-1: ");
        scanf("%d",&b);
        printf("Enter the coefficient  of a polynomial-1: ");
        scanf("%f",&a);

        insert(&poly1,a,b,i);
    }
    int  n2=0;
    printf("For polynomial -2\n");
    printf("Enter the no of terms of a polynomial-2: ");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        float a=0;
        int b=0;
        printf("Enter the exponent   of a polynomial-2: ");
        scanf("%d",&b);
        printf("Enter the coefficient  of a polynomial-2: ");
        scanf("%f",&a);

        insert(&poly2,a,b,i);
    }
    
    Display(polyadd(poly1,poly2));
    

}
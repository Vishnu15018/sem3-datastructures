#include<iostream>
using namespace std;
class node
{
   public:
    int element;
    node *nxtptr;

};
class Queue
{
    private:
     node* frontptr;
     node* backptr;
    public:
    void create_empt_queue(){
        frontptr=NULL;
        backptr=NULL;
    }
    int IsEmpty(){
        if(frontptr==NULL && backptr==NULL)
             return 1;
        else 
             return 0;

    }
    void enque(int data){
        if(IsEmpty()){
            node* newptr=new node();
            newptr->element=data;
            newptr->nxtptr=NULL;
            frontptr=newptr;
            backptr=newptr;
        }
        else{
            node* newptr=new node();
            newptr->element=data;
            newptr->nxtptr=backptr->nxtptr;
            backptr->nxtptr=newptr;
            backptr=newptr;
        }
    }
    void deque(){
        if(IsEmpty()){
            cout<< "EMPTY"<<endl;
        
        }
        else if(frontptr==backptr){
            node* p=frontptr;
            frontptr=NULL;
            backptr=NULL;
            p->nxtptr=NULL;
            int x=p->element;
            delete p;
            p=NULL;
           cout<<x<<endl;
        }
        else{
            node* p=frontptr;
            frontptr=frontptr->nxtptr;
            p->nxtptr=NULL;
            int x = p->element;
            delete p;
            p=NULL;
            cout<<x<<endl;

        }
    
    }
    void peek(){
        if(IsEmpty()){
            cout<< "EMPTY"<<endl;
            
        }
        else
            cout<<frontptr->element<<endl;
    }
    void show(){
        if(IsEmpty())
            cout<< "EMPTY"<<endl;
        else{
        node* q=frontptr;
        while(q!=NULL){
            std::cout<<q->element<<" ";
            q=q->nxtptr;
        }
        }
    }
};
int main(){
    Queue q1;
    q1.create_empt_queue();
    int n=1;
    int a=0;
    while(n){
        std::cout<<"Enter a value from 0,1,2,3,4"<<endl;
        scanf("%d",&n);
        switch (n)
        {
        case  0:
            break;
        case 1:
            std::cout<<"Enter the positive elements for  queue 1 "<<endl;
            scanf("%d",&a);
            if(a>0)
                q1.enque(a);
            break;
        case 2:
            q1.deque();
            break;
        case 3:
            q1.peek();
            break;
        case 4:
            q1.show();
            std::cout<<endl;
            break;
        }

    }
}
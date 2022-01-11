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
    int deque(){
        if(IsEmpty()){
            //cout<< "EMPTY"<<endl;
            return -1;
        
        }
        else if(frontptr==backptr){
            node* p=frontptr;
            frontptr=NULL;
            backptr=NULL;
            p->nxtptr=NULL;
            int x=p->element;
            delete p;
            p=NULL;
            return x;
           //cout<<x<<endl;
        }
        else{
            node* p=frontptr;
            frontptr=frontptr->nxtptr;
            p->nxtptr=NULL;
            int x = p->element;
            delete p;
            p=NULL;
            //cout<<x<<endl;
            return x;

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
void problem_routine(Queue *q1,int* arr,int k){
    int c=0,ele=0;
    while(arr[k]){
        ele=q1->deque();
        arr[ele]--;
        if(arr[ele]>0){
            q1->enque(ele);
        }
        c++;
    }
    std::cout<<"Iterations required "<<c<<endl;
}
int check_constraints(int T,int n,int *arr,int k){
       int c=0;
       for(int i=0;i<n;i++){
           if(!(arr[i]>=1 && arr[i]<=1000000000)){
                 c++;
                 break;
           }
       }
       if((T>=1&& T<=10)&&(n>=1 && n<=100000) && (c==0) && (k>=0 && k<n))
               return 1;
        else  
               return 0;
}
int main(){
    Queue q1;
    q1.create_empt_queue();
    int T=1,n=0,k=0,c1;
    int *arr=new int[n];
    std::cout<<"Enter the no of test cases"<<endl;
    scanf("%d",&T);
    while(T){
        while(!c1){
            std::cout<<"Enter the size of array"<<endl;
            scanf("%d",&n);
            std::cout<<"Enter the k value"<<endl;
            scanf("%d",&k);
            std::cout<<"Enter the elements of an array"<<endl;
            for(int i=0;i<n;i++){
                scanf("%d",arr+i);
            }
            c1=check_constraints(T,n,arr,k);
        }
        for(int i=0;i<n;i++){
            q1.enque(i);
        }
        Queue *ptr=&q1;
        problem_routine(ptr,arr,k);
        T--;
    }
    
}
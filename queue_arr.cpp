#include<iostream>
using namespace std;
class Queue
{
   public:
      int size;
      int front,rear;
      int *arr = new int[size];
    void create_empty_queue(int capacity){
          size=capacity;
          front=-1;
          rear=-1;
    }
    int IsEmpty(){
        if(front==-1 && rear==-1)
            return 1;
        return 0;
    }
    int IsFull(){
        if(rear== (size-1))
            return 1;
        return 0;
    }
    void enque(int data){
        if(IsFull()){
            std::cout<<"QUEUE FULL"<<endl;
            
        }        
        else if(IsEmpty()){
            front++;
            rear++;
            arr[rear]=data;
        }
        else{
            arr[++rear]=data;
        }
    }
    int  deque(){
        if(IsEmpty())
           //std::cout<<"EMPTY QUEUE"<<endl;
           return -1;
        else if(front==rear){
            int x=arr[front];
            front=-1;
            rear=-1;
            //std::cout<<x<<endl;
             return x;
        }
        else{
            int x=arr[front];
            front++;
           // std::cout<<x<<endl;
           return x;
        }
    }
    void peek(){
        if(IsEmpty()){
            std::cout<<"EMPTY QUEUE"<<endl;
        
        }
        else{
            std::cout<<arr[front]<<endl;
        }

    }
    void show(){
        if(IsEmpty()){
            std::cout<<"EMPTY QUEUE"<<endl;
            return;
        }
        else{
            int k=front;
            while(!(k==rear+1)){
                std::cout<<arr[k]<<" ";
                k++;
            }
            
        }
    }

};
int main(){
    Queue q1;
    std::cout<<"Enter the size of a stack"<<endl;
    int size=0;
    scanf("%d",&size);
    q1.create_empty_queue(size);
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
           std::cout<< q1.deque()<<endl;
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
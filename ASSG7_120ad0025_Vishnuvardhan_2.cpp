#include<iostream>
using namespace std;
class stack{
 private:
 int top;
 int size;
 int *arr=new int[size];
 public :
 void create_empty_stack(int capacity){
 size=capacity;
 top=-1;

 }
 int size_stack(){
 return size;
 }
 int IsEmpty(){
 return (top==-1);
 }
 int IsFull(){
 return (top == (size - 1));
 }
 void push(int data){
 if(IsFull())
 std::cout<<"The stack is Full Stack Overflow"<<endl;
 else
 arr[ ++top ]=data;


 }
 void pop(){
 if(IsEmpty())
 std::cout<<"The Stack is Empty"<<endl;
 else{
 int x=arr[top];
 top--;
 std::cout<<"Poped Element is "<<x<<endl;
 //return x;
 }

 }
 void peek(){
 if(IsEmpty()){
 std::cout<<"The stack is Empty"<<endl;
 }
 else{
 std::cout<<arr[top]<<endl;
 }
 }
 void display(){
 if(IsEmpty())

 std::cout<<"stack is empty"<<endl;

 else{

 for(int i=top;i!=-1;i--){
 //std::cout<<"The elements of a stack are "<< pop()<<endl;
     peek();
 }
 }
 }
};
int main(){
    int n=0;
    cout<<"Enter the no of stacks needed to be inserted in an array"<<endl;
    scanf("%d",&n);
    stack ptr[n];
 
 int size=0;
 for(int i=0;i<n;i++){
      cout<<"Enter the size of a stack "<<i+1<<" :"<<endl;
      scanf("%d",&size);
      (ptr[i]).create_empty_stack(size);
 }

 int c=1;
 int k=0;
 string adtstack;
 while(c==1){
     cout<<"Enter the stack number to perform operations"<<endl;
    scanf("%d",&k);
     

     if(k>n){
         cout<<"Enter valid stack Number"<<endl;
     }
     else{
    cout<<"enter the adt operation for "<<k<<"th stack : "<<endl;
    
     cin>>adtstack;
     if(adtstack=="push"){
         int p;
         cout<<"Enter the element for push operation : "<<endl;
         cin>>p;
         (ptr[k-1]).push(p);
     }
     else if(adtstack=="pop"){
         ptr[k-1].pop();
     }
     else if(adtstack=="peek"){
         ptr[k-1].peek();
     }
     else if(adtstack=="display"){
         ptr[k-1].display();

     }
     }
     cout<<"Enter 1 for to take another input ,for exit enter 0"<<endl;
     scanf("%d",&c);

 }



}
#include<iostream>
using namespace std;
void swap(int *a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;

}
void insertion_sort(int *arr,int n){
    int temp;
    for(int i=1;i<n;i++){
           temp=arr[i];
           for(int j=i-1;j>=0 && temp< arr[j];j-- ){
               arr[j+1]=arr[j];
               arr[j]=temp;
           }
    }
}
void selection_sort(int* arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(arr[j]<arr[i]){
                swap(&arr[i],&arr[j]);
            }
        }
    }
    
}
void bubblesort(int *arr,int n){
    int c=1;
    while(c){
       c=0;
       for(int i=0;i<n-1;i++){
           if(arr[i]>arr[i+1]){
               swap(&arr[i],&arr[i+1]);
               c=c+1;
           }
       } 
    }
}
int main(){
    int arr[10]={5,1,3,4,2,5,7,8,0,6};
    
    insertion_sort(arr,10);
    for(int i=0;i<10;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<endl;
}
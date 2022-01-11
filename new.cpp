#include<iostream>
using namespace std;
int  factorial(int n){
    if(n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }

}
void factorial(char *a){
printf("\n %s \n ",a);

}
int main(){
    int base=2,value=1;
    int exponent = 2;
    int num=5;
    

    for (int  i = 0; i < exponent; i++)
    {
        /* code */value = value*2;
    }

    cout<<"factorial of  "<< num << "is" << factorial(num); 
    cout<<factorial("vishnu");
}
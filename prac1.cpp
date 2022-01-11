#include<iostream>
using namespace std;
int fun(int n){
    cout<<n;

    if(n>2){
        fun(n-1);
        fun(n-2);
        fun(n-3);

    }
    cout<<n;
}
int fun1(int n){
    //return n;
    if(n>2){
        fun1(n-1);
        fun1(n-2);
        fun1(n-3);

    }
    return n;
}
int main(){
    fun(5);
    cout<<endl;
    cout<<fun1(5);
}
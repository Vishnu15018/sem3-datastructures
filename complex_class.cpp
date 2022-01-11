#include <iostream>

using namespace std;
class complex{
    public:
    double real;
    double img;
    
    void set(double a, double b){
        real=a;
        img = b;
    }
    void print(){
        cout<<real<<"+ i"<<img<<endl;;
    }
    complex operator + (complex par){
        complex sum;
        sum.real=real+par.real;
        sum.img=img+par.img;
        return sum;
    }
    complex operator - (complex par){
        complex sub;
        sub.real=real - par.real;
        sub.img=img - par.img;
        return sub;
    }
    complex operator * (complex par){
        complex mul;
        mul.real=real* (par.real) - (img * par .img);
        mul.img=real* (par.img) + (img * par.real);
        return mul;
    }
};

int main()
{
    complex c1;
    c1.set(4,5);
    complex c2;
    c2.set(5,6);
    complex c3;
    c3.set(4,8);
    complex c4;
    c4=c1 + c2*c3;
    c4.print();


    return 0;
}
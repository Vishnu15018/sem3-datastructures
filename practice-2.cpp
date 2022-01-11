#include<iostream>
using namespace std;
class Circle
{
   private:
       double radius;
   public:
       void store(double r)
       {radius=r;}
       double area(){
           return (3.14*radius*radius);
       }
       double display(){
           return radius;
       }
};
int main(void){
    Circle c1;
    c1.store(30.456);
    cout<<"The radius of the circle is = " << c1.display() <<endl;
    cout<<"The area of the circle is = " << c1.area() <<endl;

}
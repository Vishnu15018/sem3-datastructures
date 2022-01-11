#include<iostream>
using namespace std;
float extvar=20;
class Rectangle
{
    private:
       float length;
       float width;
    public:
       //void set(float l,float w);
       Rectangle(float l,float w);
       int area(){
           return length*width;
       }
};
/*void Rectangle::set(float l,float w){
    width=w;
    length=l;
}*/
Rectangle::Rectangle(float l,float w){
    length=l;
    width= w;
}
int main(void){
    Rectangle r1(12,20);
    //r1.set(12,extvar);
    Rectangle *r2 = new Rectangle(11,20);
    Rectangle *r3=&r1;
    std::cout<< "The area is" << r2->area()<<endl;
    std::cout<< "The area is" << r3->area()<<endl;
}
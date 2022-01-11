#include<iostream>
using namespace std;
float extvar=20;
class Rectangle
{
    private:
       float length;
       float width;
    public:
       void set(float l,float w);
       int area(){
           return length*width;
       }
};
void Rectangle::set(float l,float w){
    width=w;
    length=l;
}
int main(void){
    Rectangle r1;
    r1.set(12,extvar);
    std::cout<< "The area is" << r1.area()<<endl;
}
#include<iostream>
#include<conio.h>
using namespace std;
class student{
    private:
    int id;
    int age;
    int dob;
    std:: string str1;
    public:
    friend void operator >> (istream &in , student &s1){
        std::cout<<"Enter id , age , dob{DDMMYYYY},name respectively"<<endl;
        in>>s1.id>>s1.age>>s1.dob>>s1.str1;

    }
    friend void operator <<(ostream &out,student &s1){
        out<<"ID"<<s1.id<<" AGE"<<s1.age<<" DOB"<<s1.dob<<" NAME"<<s1.str1 <<endl;
    }
};
int main(){
    student s1;
    cin>>s1;
    cout<<s1;
}